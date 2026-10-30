import sys


class BitArray:
    """Store and manipulate a sequence of bits."""

    ENDIAN_TYPE = "big"
    bits = []
    output = bytearray()

    def __init__(self, input_data=None, endian="big"):
        self.ENDIAN_TYPE = endian
        # If a bytearray is provided, convert
        # it to a list of bits
        if input_data:
            for byte in input_data:
                bitstring = "{:08b}".format(byte)
                for bit in range(len(bitstring)):
                    self.append(bit)

    def append(self, bit):
        """Append a bit to the bit array."""
        self.bits.append(int(bit))

    def fromint(self, value):
        """Convert an integer to bits and append them to the bit array."""
        bitstring = "{:08b}".format(value)
        for bit in bitstring:
            self.append(int(bit, 2))

    def frombytes(self, byte):
        """Convert a byte to bits and append them to the bit array."""
        bitstring = "{:08b}".format(int.from_bytes(byte, self.ENDIAN_TYPE))
        for bit in bitstring:
            self.append(int(bit, 2))

    def dump(self):
        """Convert the bit array to a bytearray and return it."""
        self.output = bytearray()
        bits_in_a_byte = 8
        for i in range(len(self.bits) // (bits_in_a_byte)):
            bitstring = ""
            read_bits = self.bits[i * bits_in_a_byte : i * bits_in_a_byte + 8]
            for bit in read_bits:
                bitstring += str(bit)
            byte = int(bitstring, 2)
            self.output.append(byte)
        return self.output


class LZ77:
    # Maximum compression window size
    MAX_WINDOW_SIZE = 0

    # Maximum cursor distance for looking up matches
    MAX_LOOKAHEAD_BUFFER = 0

    # Enable compression debugging
    ENABLE_DEBUG = True

    # Current cursor position
    CURSOR = 0

    # Binary reading byte order (endianness)
    ENDIAN_TYPE = "big"

    # Input data
    data = None

    def __init__(
        self, window_size=400, lookahead_buffer=15, endian="big", verbose=True
    ):
        self.MAX_WINDOW_SIZE = window_size
        self.MAX_LOOKAHEAD_BUFFER = lookahead_buffer
        self.ENDIAN_TYPE = "big"
        self.ENABLE_DEBUG = verbose

    def find_longest_match(self):
        """Find the longest match starting at the current cursor position.

        Search the history within the window for a compatible sequence.
        """
        # Set the buffer limit based on the current cursor
        end_of_buffer = min(self.CURSOR + self.MAX_LOOKAHEAD_BUFFER, len(self.data) + 1)
        # Set the best match distance and length to their
        # initial values (no match found)
        best_match_distance = -1
        best_match_length = -1

        # Scan the file starting at the cursor
        # Optimization: only matches of length 2 or more are considered
        # and sent to the output; any
        # one-character matches
        # (8 uncompressed bits are better than 13 bits for the flag,
        # distance, and length)
        for i in range(self.CURSOR + 2, end_of_buffer):
            # Store the cursor position at the start of the match
            # while respecting the maximum window size
            start_index = max(0, self.CURSOR - self.MAX_WINDOW_SIZE)
            # Store the match being searched for
            occurrence = self.data[self.CURSOR : i]

            # Scan the file from the start of the match
            # for the longest compatible sequence in the file
            for j in range(start_index, self.CURSOR):
                compatible_chain_length = len(occurrence) // (self.CURSOR - j)
                compatible_chain_last = len(occurrence) % (self.CURSOR - j)
                compatible_chain = self.data[j : self.CURSOR]
                compatible_chain *= compatible_chain_length
                compatible_chain += self.data[j : j + compatible_chain_last]

                # If a compatible sequence is found and
                # its length is GREATER than that of the last
                # best result
                # then accept it as the best match.
                if (
                    compatible_chain == occurrence
                    and len(occurrence) > best_match_length
                ):
                    best_match_distance = self.CURSOR - j
                    best_match_length = len(occurrence)

        # If a match was found, return the best one.
        if best_match_distance > 0 and best_match_length > 0:
            return (best_match_distance, best_match_length)

        return False

    def decompress(self, input_data):
        """Decompress input data and return the original byte sequence.

        If an output file is provided, write the decompressed data to it.
        """
        # Set the initial CURSOR position to 0
        # (the start of the file)
        self.CURSOR = 0
        # Convert the compressed data bytearray into
        # a list of bits for easier manipulation
        self.data = BitArray(input_data).bits
        # Define the decompression window
        # as a bytearray
        lz_window = bytearray()

        # Read the file while the list
        # contains more than 8 bits
        while len(self.data) >= 9:
            # Read the flag indicating whether the data is
            # compressed, then remove it
            # from the buffer
            flag = self.data.pop(0)

            # If the flag is 0, just copy
            # the value to the decompression window
            if not flag:
                # Convert 8 bits to a byte
                byte = 0
                for i in self.data[0:8]:
                    byte = (byte << 1) | i
                # If byte 0xFF is found,
                # stop decompression
                if byte == 0xFF:
                    break
                # Add the byte to the window
                lz_window.append(byte)
                # Remove the byte from the buffer because it was
                # read
                del self.data[0:8]

            # If the flag is 1, look for
            # the sequence indicated by the LZ pair in the
            # decompression window
            else:
                # Convert the bits of the first byte
                byte1 = 0
                for i in self.data[0:8]:
                    byte1 = (byte1 << 1) | i

                # Convert the bits of the second byte
                byte2 = 0
                for i in self.data[8:16]:
                    byte2 = (byte2 << 1) | i

                # Remove both bytes read from the buffer
                del self.data[0:16]

                # Shift bits to separate the
                # distance bits from the length bits
                distance = (byte1 << 4) | (byte2 >> 4)
                length = byte2 & 0xF

                # Copy the indicated sequence to the current position
                # of the cursor in the decompression window
                for i in range(length):
                    try:
                        lz_window.append(lz_window[-distance])
                    except IndexError:
                        continue

        # Return the decompressed input data
        return lz_window

    def compress(self, input_data):
        """Compress input data using a simple LZ77 algorithm.

        A literal uses a zero flag and eight data bits. A match uses a one
        flag, twelve distance bits, and four length bits. If an output file
        is provided, write the compressed data in binary format. Otherwise,
        return a bit array. When verbose mode is enabled, print compression
        details.
        """
        # Set the initial CURSOR position to 0
        # (the start of the file)
        self.CURSOR = 0
        # Convert the input text to a bytearray
        # so it can be read as a binary file
        self.data = bytearray(input_data.encode())
        # Define the compression window
        # as a list of bits for easier
        # manipulation
        lz_window = BitArray(endian=self.ENDIAN_TYPE)

        # Scan the entire file
        while self.CURSOR < len(self.data):
            # Find the longest match
            # compatible with the data at
            # the current cursor
            match = self.find_longest_match()

            # If a match is found, add the LZ pair
            if match:
                # The LZ pair consists of a flag bit 1, followed by 12 bits
                # for distance and 4 bits for match length.
                best_match_distance, best_match_length = match
                # First nibble of the distance
                x = (best_match_distance >> 0x4).to_bytes(1, self.ENDIAN_TYPE)
                # Second distance nibble combined with the length
                # to form the LZ pair
                y = (((best_match_distance & 0xF) << 4) | best_match_length).to_bytes(
                    1, self.ENDIAN_TYPE
                )

                lz_window.append(1)
                lz_window.frombytes(x)
                lz_window.frombytes(y)

                # If debugging is enabled, display information about the
                # match found
                if self.ENABLE_DEBUG:
                    print(
                        "<COMPRESSED, {}, {}>".format(
                            best_match_distance, best_match_length
                        )
                    )

                # Advance the cursor
                self.CURSOR += best_match_length
            else:
                # If no match was found,
                # add the byte read to the output buffer
                # preceded by flag bit 0 (uncompressed),
                # meaning it remains in its original state
                # without compression
                lz_window.append(0)
                lz_window.fromint(self.data[self.CURSOR])

                # If debugging is enabled, display the uncompressed byte
                if self.ENABLE_DEBUG:
                    print("<UNCOMPRESSED, {:c}>".format(self.data[self.CURSOR]))

                # Advance the cursor by 1
                self.CURSOR += 1

        # Add byte 0xFF with the decompression flag
        # to mark the end of the compressed file
        lz_window.append(0)
        lz_window.fromint(0xFF)

        # Return the compressed input data
        return lz_window.dump()


# Input to be compressed with LZ
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
    input = bytearray(input_text.encode())
    print(input)
    print("Size: {}".format(sys.getsizeof(input)))
    print("\n---\n")
    compressed = lz.compress(input_text)
    print("LZ77-compressed data:")
    print(compressed)
    print("Size: {}".format(sys.getsizeof(compressed)))
    print("\n---\n")
    decompressed = lz.decompress(compressed)
    print("LZ77-decompressed data:")
    print(decompressed)
    print("Size: {}".format(sys.getsizeof(decompressed)))
    print("\n---\n")
