import io
import sys


class BitArray:
    """
    Class for manipulating bits like an array
    """

    ENDIAN_TYPE = "big"
    bits = []
    output = bytearray()

    def __init__(self, input_data=None, endian="big"):
        self.ENDIAN_TYPE = endian
        # If provided a bytearray, it converts
        # The same for a list of bits
        if input_data:
            for byte in input_data:
                bitstring = "{:08b}".format(byte)
                for bit in range(len(bitstring)):
                    self.append(bit)

    def append(self, bit):
        """
        Adds a bit to the list
        """
        self.bits.append(int(bit))

    def fromint(self, value):
        """
        Converts an integer to bits and 
        adds them to the list
        """
        bitstring = "{:08b}".format(value)
        for bit in bitstring:
            self.append(int(bit, 2))

    def frombytes(self, byte):
        """
        Converts a byte to bits and 
        adds them to the list
        """
        bitstring = "{:08b}".format(int.from_bytes(byte, self.ENDIAN_TYPE))
        for bit in bitstring:
            self.append(int(bit, 2))

    def dump(self):
        """
        Transforms the list with the bits into 
        a bytearray and returns its value
        """
        self.output = bytearray()
        bits_in_a_byte = 8
        for i in range(len(self.bits) // (bits_in_a_byte)):
            bitstring = ""
            readed_bits = self.bits[i * bits_in_a_byte : i * bits_in_a_byte + 8]
            for bit in readed_bits:
                bitstring += str(bit)
            byte = int(bitstring, 2)
            self.output.append(byte)
        return self.output


class LZ77:
    # Maximum compression window size
    MAX_WINDOW_SIZE = 0

    # Maximum cursor distance for occurrence query
    MAX_LOOKAHEAD_BUFFER = 0

    # Enables compression debugging
    ENABLE_DEBUG = True

    # Current position cursor
    CURSOR = 0

    # Binary reading type (ENDIAN)
    ENDIAN_TYPE = "big"

    # Input data
    data = None

    def __init__(self, window_size=400, lookahed_buffer=15, endian="big", verbose=True):
        self.MAX_WINDOW_SIZE = window_size
        self.MAX_LOOKAHEAD_BUFFER = lookahed_buffer
        self.ENDIAN_TYPE = "big"
        self.ENABLE_DEBUG = verbose

    def find_longest_match(self):
        """
        Finds the largest occurrence that matches the queried string,
        starting from the current cursor position (current_position),
        and then searching the existing history within the window to find a compatible occurrence.
        """
        # Defines the limit address of the buffer based on the current cursor position.
        end_of_buffer = min(self.CURSOR + self.MAX_LOOKAHEAD_BUFFER, len(self.data) + 1)
        # Defines the distance and size of the best occurrence for it.
        # Initial state (no occurrence found)
        best_match_distance = -1
        best_match_length = -1

        # Traverses the file starting from the cursor
        # Optimization: Only valid occurrences will be considered
        # If the size is 2 or greater, it goes directly to the output
        # Any occurrences of size 1
        # (8 bits decompressed are better than 13 bits for the flag
        # distance and size)
        for i in range(self.CURSOR + 2, end_of_buffer):
            # Stores the cursor position at the beginning of the occurrence
            # Respecting the maximum window size
            start_index = max(0, self.CURSOR - self.MAX_WINDOW_SIZE)
            # Stores the occurrence to be searched
            ocurrence = self.data[self.CURSOR : i]

            # Traverses the file from the beginning of the occurrence
            # in search of the largest compatible string existing in the file
            for j in range(start_index, self.CURSOR):
                compatible_chain_length = len(ocurrence) // (self.CURSOR - j)
                compatible_chain_last = len(ocurrence) % (self.CURSOR - j)
                compatible_chain = self.data[j : self.CURSOR]
                compatible_chain *= compatible_chain_length
                compatible_chain += self.data[j : j + compatible_chain_last]

                # If a compatible string is found and
                # its size is LARGER than the last
                # result defined as the best
                # then accepts it as the best option.
                if compatible_chain == ocurrence and len(ocurrence) > best_match_length:
                    best_match_distance = self.CURSOR - j
                    best_match_length = len(ocurrence)

        # If an occurrence is found, it returns the best option.
        if best_match_distance > 0 and best_match_length > 0:
            return (best_match_distance, best_match_length)

        return False

    def decompress(self, input_data):
        """
        Given a compressed input file, its content is decompressed back to its original format and 
        written to the output file if one is provided. If no output file is provided, 
        the decompressed data is returned as a string.
        """
        # Sets the initial position of the CURSOR to be 0.
        # That is, the beginning of the file.
        self.CURSOR = 0
        # Transforms the bytearray of compressed data into
        # a list of bits to facilitate manipulation.
        self.data = BitArray(input_data).bits
        # Defines the compression window.
        # as a bytearray.
        lz_window = bytearray()

        # Reads the file while the size of the list
        # of bits is greater than 8.
        while len(self.data) >= 9:
            # Reads the flag that indicates whether there is or not
            # compression and then deletes it.
            # from the buffer.
            flag = self.data.pop(0)

            # If the bit flag is 0, then simply copies
            # the value to the decompression window
            if not flag:
                # Transforms 8 bits into a byte.
                byte = 0
                for i in self.data[0:8]:
                    byte = (byte << 1) | i
                # If the byte 0xFF is found
                # finishes decompression.
                if byte == 0xFF:
                    break
                # Adds the byte to the window.
                lz_window.append(byte)
                # Deletes the byte from the buffer as it has been
                # read.
                del self.data[0:8]

            # If the bit flag is 1, then search for the
            # chain indicated by the LZ pair in the window.
            # decompression window.
            else:
                # Transforms the bits of the first byte.
                byte1 = 0
                for i in self.data[0:8]:
                    byte1 = (byte1 << 1) | i

                # Transforms the bits of the second byte.
                byte2 = 0
                for i in self.data[8:16]:
                    byte2 = (byte2 << 1) | i

                # Deletes both the read bytes from the buffer.
                del self.data[0:16]

                # Performs bitshift to separate the bits.
                # distance bits from size bits.
                distance = (byte1 << 4) | (byte2 >> 4)
                length = byte2 & 0xF

                # Copies the indicated string to the current position.
                # in the decompression window cursor position.
                for i in range(length):
                    try:
                        lz_window.append(lz_window[-distance])
                    except IndexError:
                        continue

        # Returns the decompressed input file.
        return lz_window

    def compress(self, input_data):
        """
         Provided the input file, its content is compressed using a simple LZ77 compression algorithm.

         The compression format follows this pattern:
         - A 0 bit followed by 8 bits (1 byte per character) when there are no previous occurrences in the compression window.
         - A 1 bit followed by a 12-bit pointer (distance from the start of the occurrence to the current cursor position) and an additional 4 bits (responsible for the occurrence size).

         If the output file is provided, the compressed data will be written in binary format to it. Otherwise, a bitarray will be returned.

         If the verbose parameter is enabled, the compression description is displayed.
        """
        # Sets the initial position of the CURSOR to be 0.
        # That is, the beginning of the file.
        self.CURSOR = 0
        # Converts the inserted text into a bytearray.
        # So that it can be read as a binary file.
        self.data = bytearray(input_data.encode())
        # Defines the compression window.
        # as a list of bits to facilitate manipulation.
        # the manipulation.
        lz_window = BitArray(endian=self.ENDIAN_TYPE)

        # Traverses the entire file.
        while self.CURSOR < len(self.data):
            # Search for the best and largest occurrence
            # Compatible with the existing occurrence
            # At the current cursor
            match = self.find_longest_match()

            # If any occurrence is found, add the LZ pair.
            if match:
                # The LZ pair is composed of bit flag 1, followed by 12 bits
                # For distance and 4 bits for the occurrence size.
                (best_match_distance, best_match_length) = match
                # First nibble of the distance.
                x = (best_match_distance >> 0x4).to_bytes(1, self.ENDIAN_TYPE)
                # Second nibble of the distance plus the size.
                # Forming the LZ pair this way.
                y = (((best_match_distance & 0xF) << 4) | best_match_length).to_bytes(
                    1, self.ENDIAN_TYPE
                )

                lz_window.append(1)
                lz_window.frombytes(x)
                lz_window.frombytes(y)

                # If debug is active, it displays the information of the found chain.

                if self.ENABLE_DEBUG:
                    print(
                        "<COMPRESSED, {}, {}>".format(
                            best_match_distance, best_match_length
                        )
                    )

                # Increments the cursor position.
                self.CURSOR += best_match_length
            else:
                # If no occurrence was found.
                # Adds the read byte to the output buffer.
                # Preceded by the flag bit 0 = uncompressed.,
                # That is, it will be in its natural state.
                # Without compression.
                lz_window.append(0)
                lz_window.fromint(self.data[self.CURSOR])

                # If debug is active, it displays the decompressed byte.
                if self.ENABLE_DEBUG:
                    print("<UNCOMPRESSED, {:c}>".format(self.data[self.CURSOR]))

                # Increments the cursor position by 1.
                self.CURSOR += 1

        # Adds the byte 0xFF with the decompression flag.
        # to indicate the end of the compressed file.
        lz_window.append(0)
        lz_window.fromint(0xFF)

        # Returns the compressed input file.
        return lz_window.dump()


# Input to be compressed with LZ.
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

if __name__ == "__main__":
    lz = LZ77(verbose=False)
    print("Input:")
    entrada = bytearray(input_text.encode())
    print(entrada)
    print("Tamanho: {}".format(sys.getsizeof(entrada)))
    print("\n---\n")
    compressed = lz.compress(input_text)
    print("Data compressed with LZ77:")
    print(compressed)
    print("Tamanho: {}".format(sys.getsizeof(compressed)))
    print("\n---\n")
    decompressed = lz.decompress(compressed)
    print("Data uncompressed with LZ77:")
    print(decompressed)
    print("Tamanho: {}".format(sys.getsizeof(decompressed)))
    print("\n---\n")
