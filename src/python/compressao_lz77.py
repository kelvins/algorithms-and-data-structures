import os
import sys
import math
from bitarray import bitarray

# Tamanho máximo da janela de compressão
MAX_WINDOW_SIZE = 400

# Distância máxima do cursor para consulta de ocorrências
lookahead_buffer_size = 15

def compress(input_file_path, verbose=False):
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
	
	data = None
	i = 0
	output_buffer = bitarray(endian='big')

	# Lê o arquivo de entrada 
	try:
		with open(input_file_path, 'rb') as input_file:
			data = input_file.read()
	except IOError:
		print 'Could not open input file ...'
		raise

	while i < len(data):

		# Procura pela maior ocorrência compativel com o cursor atual
		match = findLongestMatch(data, i)

		if match: 
				# Adiciona a flag bit 1, seguida por 12 bits para distância e 4 bits para
				# o tamanho da ocorrência.
			(bestMatchDistance, bestMatchLength) = match

			output_buffer.append(True)
			output_buffer.frombytes(chr(bestMatchDistance >> 4))
			output_buffer.frombytes(chr(((bestMatchDistance & 0xf) << 4) | bestMatchLength))

			if verbose:
				print "<1, %i, %i>" % (bestMatchDistance, bestMatchLength),

			i += bestMatchLength

		else:
    		# Se nenhuma ocorrência for encontrada. Retorna a flag bit 0, seguida de 8 bits com
			# para o caractere em questão. 
			output_buffer.append(False)
			output_buffer.frombytes(data[i])
				
			if verbose:
				print "<0, %s>" % data[i],

			i += 1

	# Preenche o buffer com zeros até que o numero de bits não seja múltiplo de 8		
	output_buffer.fill()
	# Escreve os dados comprimidos dentro de um arquivo binário, caso um arquivo
	# de saída tenha sido fornecido.

	# Se um arquivo de saída não for fornecido, retorna os dados comprimidos. 
	print("\n")
	return output_buffer

def findLongestMatch(data, current_position):
	""" 
		Encontra a maior ocorrência compatível com a cadeia consultada iniciando
		da posição atual do cursor: current_position; e posteriomente
		consultando o histórico existente dentro da janela para encontrar
		uma ocorrência compatível.
	"""
	end_of_buffer = min(current_position + lookahead_buffer_size, len(data) + 1)

	best_match_distance = -1
	best_match_length = -1

	# Otimização: Somente serão consideradas cadeias válidas se o tamanho for
	# 2 ou maior, e encaminha direto para saída quaisquer cadeias de tamanho 1
	# (8 bits decomprimidos é melhor do que 13 bits para flag, distância e tamanho)
	for j in range(current_position + 2, end_of_buffer):

		start_index = max(0, current_position - MAX_WINDOW_SIZE)
		substring = data[current_position:j]

		for i in range(start_index, current_position):

			repetitions = len(substring) / (current_position - i)

			last = len(substring) % (current_position - i)

			matched_string = data[i:current_position] * repetitions + data[i:i+last]

			if matched_string == substring and len(substring) > best_match_length:
				best_match_distance = current_position - i 
				best_match_length = len(substring)

	if best_match_distance > 0 and best_match_length > 0:
		return (best_match_distance, best_match_length)
	return None

def decompress(input_file_path):
    """
		Fornecido um arquivo de entrada comprimido, o seu conteúdo é descomprimido de
		volta ao seu formato original, e escrito no arquivo de saída caso este seja
		também fornecido. Se nenhum arquivo de saída for forncedido, os dados
		descomprimidos são retornados como uma string
	"""
	data = bitarray(endian='big')
	output_buffer = []

	# Lê o arquivo de entrada
	'''try:
		with open(input_file_path, 'rb') as input_file:
			data.fromfile(input_file)
	except IOError:
		print 'Could not open input file ...'
		raise'''
	data = input_file_path

	while len(data) >= 9:
		flag = data.pop(0)

		if not flag:
			byte = data[0:8].tobytes()

			output_buffer.append(byte)
			del data[0:8]
		else:
			byte1 = ord(data[0:8].tobytes())
			byte2 = ord(data[8:16].tobytes())

			del data[0:16]
			distance = (byte1 << 4) | (byte2 >> 4)
			length = (byte2 & 0xf)

			for i in range(length):
				try:
					output_buffer.append(output_buffer[-distance])
				except IndexError:
					continue


	out_data =  ''.join(output_buffer)
	return out_data

input_file_path = 'input.txt'
compressed_data = compress(input_file_path,verbose=True)


decompressed_data = decompress(compressed_data)
print(decompressed_data)