import io
import sys

class BitArray:
    """
        Classe para manipular bits como um array
    """
    ENDIAN_TYPE = 'big'
    bits = []
    output = bytearray()

    def __init__(self, input_data=None, endian='big'):
        self.ENDIAN_TYPE = endian
        # Se fornecido um bytearray converte
        # o mesmo para lista de bits
        if input_data:
            for byte in input_data:
                bitstring = "{:08b}".format(byte)
                for bit in range(len(bitstring)):
                    self.append(bit)

    def append(self, bit):
        """
            Adiciona um bit à lista
        """
        self.bits.append(int(bit))

    def fromint(self, value):
        """
            Converte um inteiro para bits
            e adiciona-os à lista
        """
        bitstring = '{:08b}'.format(value)
        for bit in bitstring:
            self.append(int(bit, 2))

    def frombytes(self, byte):
        """
            Converte um byte para bits
            e adiciona-os à lista
        """
        bitstring = "{:08b}".format(
            int.from_bytes(byte, self.ENDIAN_TYPE)
        )
        for bit in bitstring:
            self.append(int(bit, 2))

    def dump(self):
        """
            Transforma à lista com os bits em um
            bytearray e retorna seu valor
        """
        self.output = bytearray()
        bits_in_a_byte = 8
        for i in range(len(self.bits) // (bits_in_a_byte)):
            bitstring = ''
            readed_bits = self.bits[i * bits_in_a_byte: i * bits_in_a_byte + 8]
            for bit in readed_bits:
                bitstring += str(bit)
            byte = int(bitstring, 2)
            self.output.append(byte)
        return self.output


class LZ77:
    # Tamanho máximo da janela de compressão
    MAX_WINDOW_SIZE = 0

    # Distância máxima do cursor para consulta de ocorrências
    MAX_LOOKAHEAD_BUFFER = 0

    # Ativa o debug da compressão
    ENABLE_DEBUG = True

    # Cursor da Posição atual
    CURSOR = 0

    # Tipo de leitura binária (ENDIAN)
    ENDIAN_TYPE = 'big'

    # Dados de Entrada
    data = None

    def __init__(
            self,
            window_size=400,
            lookahed_buffer=15,
            endian='big',
            verbose=True):
        self.MAX_WINDOW_SIZE = window_size
        self.MAX_LOOKAHEAD_BUFFER = lookahed_buffer
        self.ENDIAN_TYPE = 'big'
        self.ENABLE_DEBUG = verbose

    def find_longest_match(self):
        """
            Encontra a maior ocorrência compatível com a cadeia consultada iniciando
            da posição atual do cursor: current_position; e posteriomente
            consultando o histórico existente dentro da janela para encontrar
            uma ocorrência compatível.
        """
        # Define o endereço limite do buffer baseado no cursor atual
        end_of_buffer = min(
            self.CURSOR + self.MAX_LOOKAHEAD_BUFFER,
            len(self.data) + 1
        )
        # Define a distancia e o tamanho da melhor ocorrencia para seu
        # estado inicial (nenhum ocorrencia encontrada)
        best_match_distance = -1
        best_match_length = -1

        # Percorre o arquivo a partir do cursor
        # Otimização: Somente serão consideradas ocorrencias válidas
        # se o tamanho for 2 ou maior, e encaminha direto para saída
        # quaisquer ocorrencias de tamanho 1
        # (8 bits decomprimidos é melhor do que 13 bits para flag,
        # distância e tamanho)
        for i in range(self.CURSOR + 2, end_of_buffer):
            # Armazena a posição do cursor no inicio da ocorrência
            # respeitando o tamanho máximo da janela
            start_index = max(0, self.CURSOR - self.MAX_WINDOW_SIZE)
            # Armazena a ocorrencia a ser pesquisada
            ocurrence = self.data[self.CURSOR:i]

            # Percorre o arquivo apartir do início da ocorrência
            # em busca da maior cadeia compativel existente no arquivo
            for j in range(start_index, self.CURSOR):
                compatible_chain_length = len(ocurrence) // (self.CURSOR - j)
                compatible_chain_last = len(ocurrence) % (self.CURSOR - j)
                compatible_chain = self.data[j:self.CURSOR]
                compatible_chain *= compatible_chain_length
                compatible_chain += self.data[j:j + compatible_chain_last]

                # Se alguma cadeia compativel for encontrada e
                # seu tamanho for MAIOR que o do ultimo
                # resultado definido como melhor
                # então aceita a mesma como sendo a melhor opção.
                if compatible_chain == ocurrence and len(
                        ocurrence) > best_match_length:
                    best_match_distance = self.CURSOR - j
                    best_match_length = len(ocurrence)

        # Se alguma ocorrência foi encontrada retorna a melhor opção.
        if best_match_distance > 0 and best_match_length > 0:
            return (best_match_distance, best_match_length)

        return False

    def decompress(self, input_data):
        """
            Fornecido um arquivo de entrada comprimido, o seu conteúdo é descomprimido de
            volta ao seu formato original, e escrito no arquivo de saída caso este seja
            também fornecido. Se nenhum arquivo de saída for forncedido, os dados
            descomprimidos são retornados como uma string
        """
        # Define a posição inicial do CURSOR como sendo 0
        # ou seja inicio do arquivo
        self.CURSOR = 0
        # Transforma o bytearray de dados comprimidos em
        # uma lista de bits para facilita a manipulação
        self.data = BitArray(input_data).bits
        # Define o janela de compressão
        # como sendo um bytearray
        lz_window = bytearray()

        # Le o arquivo enquanto o tamanho da lista
        # de bits for maior que 8
        while len(self.data) >= 9:
            # Le a flag que indica se há ou não
            # compressão e em seguida exclui a mesma
            # do buffer
            flag = self.data.pop(0)

            # Se a bit flag for 0 então apenas copia
            # o valor para a janela de descompressão
            if not flag:
                # Transforma 8 bits em um byte
                byte = 0
                for i in self.data[0:8]:
                    byte = (byte << 1) | i
                # Se o byte 0xFF for encontrado
                # finaliza a descompressão
                if byte == 0xFF:
                    break
                # Adiciona o byte a janela
                lz_window.append(byte)
                # Exclui o byte do buffer já que foi
                # lido
                del self.data[0:8]

            # Se a bit flag for 1 então procura pela
            # cadeia indicada pelo par LZ na janela
            # de decompressão
            else:
                # Transforma os bits do primeiro byte
                byte1 = 0
                for i in self.data[0:8]:
                    byte1 = (byte1 << 1) | i

                # Transforma os bits do segundo byte
                byte2 = 0
                for i in self.data[8:16]:
                    byte2 = (byte2 << 1) | i

                # Exclui ambos os bytes lidos do buffer
                del self.data[0:16]

                # Executa o bitshift pra separar os bits
                # de distancia dos bits de tamanho
                distance = (byte1 << 4) | (byte2 >> 4)
                length = (byte2 & 0xf)

                # Copia a cadeia indicada para a posição atual
                # do cursor na janela de decompressão
                for i in range(length):
                    try:
                        lz_window.append(lz_window[-distance])
                    except IndexError:
                        continue

        # Retorna o arquivo de entrada descomprimido
        return lz_window

    def compress(self, input_data):
        """
            Fornecido o arquivo de entrada, seu contéudo é comprimido aplicando um algoritmo
            de compressão LZ77 simples.
            O formato de compressão tem o seguinte padrão:
            - bit de valor 0 seguido por 8 bits (1 byte por caracter) quando não existem ocorrências
            prévias na janela de compressão.
            - bit de valor 1 seguido pelo ponteiro de 12 bits (distância entre o inicio da ocorrência
            até a posição atual do cursor) e mais 4 bits (responsaveis pelo tamanho da ocorrência)

            Se o arquivo de saída for fornecido, os dados comprimidos serão escritos em
            formato binário dentro do mesmo. Do contrário será retornado um bitarray.

            Se o parâmetro verbose estiver habilitado, a descrição da compressão é exibida.
        """
        # Define a posição inicial do CURSOR como sendo 0
        # ou seja inicio do arquivo
        self.CURSOR = 0
        # Transforma o texto inserido em um bytearray
        # para que possa ser lido como um arquivo binário
        self.data = bytearray(input_data.encode())
        # Define a janela de compressão
        # como sendo um lista de bits para facilitar
        # a manipulação
        lz_window = BitArray(endian=self.ENDIAN_TYPE)

        # Percorre o arquivo inteiro
        while self.CURSOR < len(self.data):

            # Procura pela melhor e maior ocorrência
            # compativel com a ocorrência existente
            # no cursor atual
            match = self.find_longest_match()

            # Se alguma ocorrência for encontrada adiciona o par LZ
            if match:
                # o PAR LZ é constituido da bit flag 1, seguida por 12 bits
                # para distância e 4 bits para o tamanho da ocorrência.
                (best_match_distance, best_match_length) = match
                # Primeiro nibble da distancia
                x = (best_match_distance >> 0x4).to_bytes(1, self.ENDIAN_TYPE)
                # Segundo nibble da distancia acrescido do tamanho
                # formando assim o par LZ
                y = (((best_match_distance & 0xf) << 4) |
                     best_match_length).to_bytes(1, self.ENDIAN_TYPE)

                lz_window.append(1)
                lz_window.frombytes(x)
                lz_window.frombytes(y)

                # Se o debug estiver ativo, exibe as informações da cadeia
                # encontrada
                if self.ENABLE_DEBUG:
                    print("<COMPRESSED, {}, {}>".format(
                        best_match_distance, best_match_length))

                # Incrementa a posição do cursor
                self.CURSOR += best_match_length
            else:
                # Se nenhuma ocorrência foi encontrada
                # adiciona ao buffer de saída o byte lido
                # precedido da bit flag 0 = descomprimido,
                # ou seja, ele estará em seu estado natural
                # sem compressão
                lz_window.append(0)
                lz_window.fromint(self.data[self.CURSOR])

                # Se o debug estiver ativo, exibe o byte decomprimido
                if self.ENABLE_DEBUG:
                    print("<UNCOMPRESSED, {:c}>".format(
                        self.data[self.CURSOR]))

                # Incrementa em 1 a posição do cursor
                self.CURSOR += 1

        # Adiciona o byte 0xFF com a flag de decompressão
        # para indicar o fim do arquivo comprimido
        lz_window.append(0)
        lz_window.fromint(0xFF)

        # Retorna o arquivo de entrada comprimido
        return lz_window.dump()


# Entrada a ser comprimida com LZ
input_text = '''Lorem Ipsum is simply dummy\
 text of the Lorem Ipsum printing and typesetting industry.\
 Lorem Ipsum has been the industry's standard dummy\
 text ever since the 1500s, when an unknown printer\
 took a galley of type and scrambled it to make a\
 type specimen book. It has survived not only\
 five centuries, but also the leap into electronic\
 typesetting, remaining essentially unchanged. \
 It was popularised in the 1960s with the release\
 of Letraset sheets containing Lorem Ipsum passages, \
 and more recently with desktop publishing software \
 like Aldus PageMaker including versions of Lorem Ipsum.\
 Contrary to popular belief, Lorem Ipsum is not simply random text.\
 It has roots in a piece of classical Latin literature from 45 BC,\
 making it over 2000 years old. Richard McClintock, a Latin professor\
 at Hampden-Sydney College in Virginia, looked up one of the more\
 obscure Latin words, consectetur, from a Lorem Ipsum passage, \
 and going through the cites of the word in classical literature,\
 discovered the undoubtable source. Lorem Ipsum comes from sections\
 1.10.32 and 1.10.33 of "de Finibus Bonorum et Malorum" \
 (The Extremes of Good and Evil) by Cicero, written in 45 BC.\
 This book is a treatise on the theory of ethics, very popular\
 during the Renaissance. The first line of Lorem Ipsum,\
 "Lorem ipsum dolor sit amet..", comes from a line in\
 section 1.10.32."'''

if __name__ == '__main__':
    lz = LZ77(verbose=False)
    print("Entrada:")
    entrada = bytearray(input_text.encode())
    print(entrada)
    print('Tamanho: {}'.format(sys.getsizeof(entrada)))
    print("\n---\n")
    compressed = lz.compress(input_text)
    print("Dados Comprimidos com LZ77:")
    print(compressed)
    print('Tamanho: {}'.format(sys.getsizeof(compressed)))
    print("\n---\n")
    decompressed = lz.decompress(compressed)
    print("Dados descomprimidos com LZ77:")
    print(decompressed)
    print('Tamanho: {}'.format(sys.getsizeof(decompressed)))
    print("\n---\n")
