
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 * CONSTANTS AND TYPE DEFINITIONS
 * ============================================================ */

#define TAM 256 // ASCII table size

/// @brief Range: [0, 255]
typedef unsigned char Uchar;

typedef struct node Node;
typedef struct priority_list Priority_List;

struct node {
  Uchar character;
  int frequency;
  Node *right, *left, *next;
};

struct priority_list {
  Node *front;
  Node *tail;
};

/* ============================================================
 * FUNCTION PROTOTYPES
 * ============================================================ */

// --- File Reading & Frequency Table ---
Uchar *readFile(char *fileName);
void initTable(int table[]);
void fillFrequencyTable(Uchar *text, int table[]);
void displayTable(int table[]);

// --- Sorted List Management ---
void initList(Priority_List *list);
Node *createNode(Uchar character, int frequency);
void insertIntoList(int table[], Priority_List *list);
void insertSorted(Priority_List *list, Node *node);
void removeFromList(Priority_List *list);

// --- Huffman Tree Construction ---
Node *buildHuffmanTree(Priority_List *list);
int treeHeight(Node *root);

// --- Dictionary & Encoding ---
Uchar **allocateDictionary(int height);
void generateDictionary(Uchar **dictionary, Node *root, char *path, int height);
void displayDictionary(Uchar **dictionary);
int encodedSize(Uchar *text, Uchar **dictionary);
Uchar *encodeText(Uchar *text, Uchar **dictionary);

// --- File Writing & Compression ---
void writeHuffmanTree(Node *root, FILE *file);
void compressFile(Uchar *text, Node *root);

// --- Decompression ---
Node *rebuildHuffmanTree(FILE *file);
void decompress(char *fileName);

// --- Memory Management ---
void freeTree(Node **refRoot);
void freeDictionary(Uchar ***refDictionary);

// --- Debug / Display ---
void displayTree(Node *root);

/* ============================================================
 * MAIN ENTRY POINT
 * ============================================================ */

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  int option;
  printf("========================================\n");
  printf("     HUFFMAN COMPRESSOR / DECOMPRESSOR\n");
  printf("========================================\n");
  printf("1 - Compress file (Texto.txt -> compactado.huf)\n");
  printf("2 - Decompress file (compactado.huf)\n");
  printf("Choice: ");
  scanf("%d", &option);
  getchar(); // consume newline

  if (option == 1) {
    /* --------------------------------------------------------
     * COMPRESSION PIPELINE
     * 1. Read source text
     * 2. Build frequency table
     * 3. Build sorted list & Huffman tree
     * 4. Generate encoding dictionary
     * 5. Encode text and write a single binary file
     *    (Huffman tree header + bit-packed data)
     * -------------------------------------------------------- */
    Uchar **dictionary;
    Uchar *text, *encoded;
    char path[] = "";
    char *fileName = "Texto.txt";
    Priority_List sortedList;
    Node *root;
    int table[TAM], height;

    text = readFile(fileName);
    if (strlen((char *)text) == 0) {
      printf("File is empty - nothing to compress.\n");
      free(text);
      return EXIT_SUCCESS;
    }
    initTable(table);
    fillFrequencyTable(text, table);
    displayTable(table);

    initList(&sortedList);
    insertIntoList(table, &sortedList);
    root = buildHuffmanTree(&sortedList);

    height = treeHeight(root);
    dictionary = allocateDictionary(height);
    generateDictionary(dictionary, root, path, height);
    displayDictionary(dictionary);

    encoded = encodeText(text, dictionary);
    printf("Encoded text: %s\n", encoded);
    compressFile(encoded, root);

    displayTree(root);

    freeTree(&root);
    freeDictionary(&dictionary);
    free(text);
    free(encoded);
    text = NULL;
    encoded = NULL;

    if (!root && !dictionary && !text && !encoded) {
      printf("\n\nMemory freed successfully!\n");
    } else {
      printf("Memory leak detected!\n");
    }
  } else if (option == 2) {
    /* --------------------------------------------------------
     * DECOMPRESSION PIPELINE
     * 1. Rebuild Huffman tree from the compressed file header
     * 2. Read compressed bitstream
     * 3. Traverse tree according to bits (0=left, 1=right)
     * 4. Output original characters when reaching leaf nodes
     * -------------------------------------------------------- */
    printf("\n--- Decompressed text ---\n");
    decompress("compactado.huf");
    printf("\n-------------------------\n");
  } else {
    printf("Invalid option!\n");
  }

  return 0;
}

/* ============================================================
 * FILE READING & FREQUENCY TABLE
 * ============================================================ */

/// @brief Reads an entire file into a dynamically allocated buffer
Uchar *readFile(char *fileName) {
  FILE *file = fopen(fileName, "rb");

  if (!file) {
    printf("File not found!\n");
    exit(EXIT_FAILURE);
  }

  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  Uchar *text = (Uchar *)calloc(fileSize + 1, sizeof(Uchar));
  if (!text) {
    fclose(file);
    exit(EXIT_FAILURE);
  }

  int i = 0, ch;
  while ((ch = fgetc(file)) != EOF) {
    text[i++] = (Uchar)ch;
  }
  fclose(file);
  printf("%s", text);
  return text;
}

/// @brief Initializes the frequency table with zeros
void initTable(int table[]) {
  for (int i = 0; i < TAM; i++)
    table[i] = 0;
}

/// @brief Fills the frequency table based on the input text
void fillFrequencyTable(Uchar *text, int table[]) {
  int count = 0;
  for (int i = 0; i < (int)strlen((char *)text); i++) {
    table[text[i]]++;
    count++;
  }
  printf("Total characters: %d\n", count);
}

/// @brief Displays all characters with frequency > 0
void displayTable(int table[]) {
  printf("\n---- FREQUENCY TABLE ----\n");
  for (int i = 0; i < TAM; i++) {
    if (table[i] != 0) {
      if (i >= 32 && i <= 126)
        printf("Character: %c | Frequency: %d\n", i, table[i]);
      else
        printf("Character: [%d] | Frequency: %d\n", i, table[i]);
    }
  }
}

/* ============================================================
 * SORTED LIST MANAGEMENT
 * ============================================================ */

/// @brief Initializes an empty linked list
void initList(Priority_List *list) { list->front = list->tail = NULL; }

/// @brief Allocates a new tree/list node
Node *createNode(Uchar character, int frequency) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    exit(EXIT_FAILURE);
  }
  newNode->character = character;
  newNode->frequency = frequency;
  newNode->right = newNode->left = newNode->next = NULL;
  return newNode;
}

/// @brief Creates nodes for all characters with freq > 0 and inserts them
/// sorted
void insertIntoList(int table[], Priority_List *list) {
  for (int i = 0; i < TAM; i++) {
    if (table[i] != 0) {
      Node *newNode = createNode((Uchar)i, table[i]);
      insertSorted(list, newNode);
    }
  }
}

/// @brief Inserts a node in ascending order by frequency
void insertSorted(Priority_List *list, Node *node) {
  if (!list->front) {
    list->front = node;
    list->tail = node;
    return;
  }

  Node *aux = list->front;
  Node *prev = NULL;

  while (aux != NULL && aux->frequency <= node->frequency) {
    prev = aux;
    aux = aux->next;
  }

  if (!prev) {
    node->next = list->front;
    list->front = node;
  } else if (!aux) {
    prev->next = node;
    list->tail = node;
  } else {
    prev->next = node;
    node->next = aux;
  }
}

/// @brief Removes the front node from the list (does NOT free memory)
/// @warning Error 0001 - Attempt to remove from an empty list
void removeFromList(Priority_List *list) {
  if (!list->front) {
    printf("ERR0: 0001\n");
    exit(EXIT_FAILURE);
  }
  list->front = list->front->next;
}

/* ============================================================
 * HUFFMAN TREE CONSTRUCTION
 * ============================================================ */

/// @brief Builds the Huffman tree from the sorted frequency list
/// @details Repeatedly removes the two lowest-frequency nodes, creates
/// a new internal node with '*' marker and sum of frequencies, and
/// inserts it back into the list until only one node remains (the root).
/// @warning Error 0010 - NULL list pointer
Node *buildHuffmanTree(Priority_List *list) {
  if (!list) {
    printf("ERR0: 0010\n");
    exit(EXIT_FAILURE);
  }

  while (list->front != list->tail) {
    Node *node1 = list->front;
    Node *node2 = node1->next;

    Node *newNode = createNode('*', node1->frequency + node2->frequency);
    newNode->left = node1;
    newNode->right = node2;

    removeFromList(list);
    removeFromList(list);
    insertSorted(list, newNode);
  }
  return list->front;
}

/// @brief Computes the height of the Huffman tree recursively
/// @details The tree height determines the maximum bit-length of any code.
int treeHeight(Node *root) {
  if (!root) {
    return -1;
  }

  int left = treeHeight(root->left);
  int right = treeHeight(root->right);

  return (left > right) ? left + 1 : right + 1;
}

/* ============================================================
 * ENCODING DICTIONARY
 * ============================================================ */

/// @brief Allocates the dictionary matrix [256][tree_height]
/// @details Each character gets a string to store its Huffman code.
/// A pointer-to-pointer (Uchar**) represents the 2D matrix dynamically.
Uchar **allocateDictionary(int height) {
  Uchar **dictionary = (Uchar **)malloc(TAM * sizeof(Uchar *));
  if (dictionary) {
    for (int i = 0; i < TAM; i++) {
      dictionary[i] = (Uchar *)calloc(height + 1, sizeof(Uchar));
    }
    return dictionary;
  } else {
    printf("ERR0 0011\n");
    exit(EXIT_FAILURE);
  }
}

/// @brief Traverses the tree to generate Huffman codes for each leaf
/// @details Walks the tree recursively. Appends '0' for left branches
/// and '1' for right branches. When a leaf is reached, the accumulated
/// path is copied into the dictionary at the character's index.
void generateDictionary(Uchar **dictionary, Node *root, char *path,
                        int height) {
  char left[height + 1], right[height + 1];

  if (!root->left && !root->right) {
    strcpy((char *)dictionary[root->character], path[0] != '\0' ? path : "0");
  } else {
    strcpy(left, path);
    strcpy(right, path);
    strcat(left, "0");
    strcat(right, "1");

    generateDictionary(dictionary, root->left, left, height);
    generateDictionary(dictionary, root->right, right, height);
  }
}

/// @brief Displays the encoding dictionary
void displayDictionary(Uchar **dictionary) {
  for (int i = 0; i < TAM; i++) {
    if (strlen((char *)dictionary[i]) > 0) {
      if (i >= 32 && i <= 126)
        printf("%c: %s\n", i, dictionary[i]);
      else
        printf("[%d]: %s\n", i, dictionary[i]);
    }
  }
}

/* ============================================================
 * TEXT ENCODING
 * ============================================================ */

/// @brief Calculates the total size of the encoded bit-string
int encodedSize(Uchar *text, Uchar **dictionary) {
  int size = 0;
  int i = 0;

  while (text[i] != '\0') {
    size += strlen((char *)dictionary[text[i]]);
    i++;
  }
  return size;
}

/// @brief Encodes the original text using the Huffman dictionary
/// @details Concatenates the bit-code for each character. Note that
/// the result is still a string of '0' and '1' characters, not actual bits.
Uchar *encodeText(Uchar *text, Uchar **dictionary) {
  int size = encodedSize(text, dictionary);
  Uchar *encoded = (Uchar *)calloc(size + 1, sizeof(Uchar));
  if (!encoded) {
    exit(EXIT_FAILURE);
  }

  int pos = 0, i = 0, k = 0;
  while (text[i] != '\0') {
    k = 0;
    while (dictionary[text[i]][k] != '\0') {
      encoded[pos++] = dictionary[text[i]][k++];
    }
    i++;
  }
  encoded[size] = '\0';
  return encoded;
}

/* ============================================================
 * FILE WRITING & COMPRESSION
 * ============================================================ */

/// @brief Writes the Huffman tree to a file in pre-order
/// @details Traverses root-left-right. NULL pointers are written as
/// a marker node ('*', freq=-1) so the tree can be rebuilt later.
void writeHuffmanTree(Node *root, FILE *file) {
  if (!root) {
    Uchar marker = '*';
    int nullFreq = -1;
    fwrite(&marker, sizeof(Uchar), 1, file);
    fwrite(&nullFreq, sizeof(int), 1, file);
    return;
  }

  fwrite(&root->character, sizeof(Uchar), 1, file);
  fwrite(&root->frequency, sizeof(int), 1, file);
  writeHuffmanTree(root->left, file);
  writeHuffmanTree(root->right, file);
}

/// @brief Writes the compressed output as a single file
/// @details The Huffman tree is serialized first as the file header, followed
/// by the bit-packed data. Uses bitwise operations to pack 8 '0'/'1'
/// characters into one byte. The last byte of the file stores how many bits of
/// the previous byte are valid.
/// @warning Error 0100 - Could not open output file
void compressFile(Uchar *text, Node *root) {
  FILE *file = fopen("compactado.huf", "wb");

  if (!file) {
    printf("ERR0 0100\n");
    exit(EXIT_FAILURE);
  }

  writeHuffmanTree(root, file);

  Uchar mask, byte = 0;
  int i = 0, j = 7;

  while (text[i] != '\0') {
    mask = 1;
    if (text[i] == '1') {
      mask <<= j;
      byte |= mask;
    }
    j--;

    if (j < 0) {
      fwrite(&byte, sizeof(Uchar), 1, file);
      byte = 0;
      j = 7;
    }
    i++;
  }

  if (j != 7) {
    fwrite(&byte, sizeof(Uchar), 1, file);
  }

  Uchar lastBits = (j == 7) ? 8 : (Uchar)(7 - j);
  fwrite(&lastBits, sizeof(Uchar), 1, file);
  fclose(file);
}

/* ============================================================
 * DECOMPRESSION
 * ============================================================ */

/// @brief Rebuilds the Huffman tree from a binary file
/// @details Reads nodes in pre-order. A node with frequency -1 signals
/// a NULL pointer. Otherwise, a new node is created and its children
/// are rebuilt recursively.
Node *rebuildHuffmanTree(FILE *file) {
  Uchar character;
  int frequency;

  if (fread(&character, sizeof(Uchar), 1, file) != 1 ||
      fread(&frequency, sizeof(int), 1, file) != 1 || frequency == -1) {
    return NULL;
  }

  Node *root = createNode(character, frequency);
  root->left = rebuildHuffmanTree(file);
  root->right = rebuildHuffmanTree(file);
  return root;
}

/// @brief Decompresses a single compressed file back to the original text
/// @details Rebuilds the Huffman tree from the file header, then reads the
/// bit-packed data testing each bit from MSB to LSB. Bit 1 -> go right,
/// Bit 0 -> go left. When a leaf is reached, the character is printed and
/// traversal restarts from the root. The last byte of the data stores how
/// many bits of the previous byte are valid, so padding bits are ignored.
/// The tree is freed before returning.
/// @warning Error 1000 - Could not open compressed file
void decompress(char *fileName) {
  FILE *file = fopen(fileName, "rb");

  if (!file) {
    printf("ERR0 1000\n");
    exit(EXIT_FAILURE);
  }

  Node *root = rebuildHuffmanTree(file);
  if (!root) {
    fclose(file);
    printf("Error: invalid or empty tree header\n");
    return;
  }

  long dataStart = ftell(file);
  fseek(file, 0, SEEK_END);
  long dataSize = ftell(file) - dataStart;
  fseek(file, dataStart, SEEK_SET);

  if (dataSize <= 0) {
    freeTree(&root);
    fclose(file);
    return;
  }

  Uchar *bytes = (Uchar *)malloc((size_t)dataSize * sizeof(Uchar));
  if (!bytes) {
    fclose(file);
    exit(EXIT_FAILURE);
  }
  fread(bytes, sizeof(Uchar), (size_t)dataSize, file);
  fclose(file);

  long dataCount = dataSize - 1;
  Uchar lastBits = bytes[dataSize - 1];
  if (lastBits < 1 || lastBits > 8) {
    lastBits = 8;
  }

  if (!root->left && !root->right) {
    long totalBits = (dataCount > 0) ? ((dataCount - 1) * 8 + lastBits) : 0;
    for (long k = 0; k < totalBits; k++) {
      printf("%c", root->character);
    }
    free(bytes);
    freeTree(&root);
    return;
  }

  Node *aux = root;
  for (long b = 0; b < dataCount; b++) {
    int numBits = (b == dataCount - 1) ? (int)lastBits : 8;
    for (int i = 7; i >= 8 - numBits; i--) {
      if (bytes[b] & (1 << i)) {
        aux = aux->right;
      } else {
        aux = aux->left;
      }

      if (!aux->right && !aux->left) {
        printf("%c", aux->character);
        aux = root;
      }
    }
  }
  free(bytes);
  freeTree(&root);
}

/* ============================================================
 * MEMORY MANAGEMENT
 * ============================================================ */

/// @brief Recursively frees all nodes of the Huffman tree
void freeTree(Node **refRoot) {
  Node *root = *refRoot;
  if (!root)
    return;

  freeTree(&root->left);
  freeTree(&root->right);
  free(root);
  *refRoot = NULL;
}

/// @brief Frees the dictionary matrix
void freeDictionary(Uchar ***refDictionary) {
  Uchar **dictionary = *refDictionary;
  for (int i = 0; i < TAM; i++) {
    free(dictionary[i]);
  }
  free(dictionary);
  *refDictionary = NULL;
}

/* ============================================================
 * DEBUG / DISPLAY
 * ============================================================ */

/// @brief Prints all leaf nodes of the tree (character + frequency)
void displayTree(Node *root) {
  if (!root) {
    return;
  }

  if (!root->right && !root->left) {
    if (root->character >= 32 && root->character <= 126)
      printf("Leaf: %c | Freq: %d\n", root->character, root->frequency);
    else
      printf("Leaf: [%d] | Freq: %d\n", root->character, root->frequency);
  }
  displayTree(root->left);
  displayTree(root->right);
}
