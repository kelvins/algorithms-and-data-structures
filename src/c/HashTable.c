/**
 * @file HashTable.c
 * @brief Hash Table implementation with separate chaining
 * 
 * Time Complexity:
 * - Insert: O(1) averege, O(n) worst
 * - Search: O(1) averege, O(n) worst
 * - Delete: O(1) averege, O(n) worst
 * 
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*Node for linked list (handles collision)*/
typedef struct node {
    int value;
    struct node *next;
}Node;

/*Hash table structure*/
typedef struct hashtable {
    Node **table;   // Array of linked list
    size_t size;    // Table size
}HashTable;

/* ============ FUNCTION DECLARATIONS ============ */

// Creates new hash table with given size
HashTable* initHashTable(size_t size);

/// @brief Hash function maps value to table index
/// @param size_of_hashTable size of the hash table
/// @param value value to be inserted
/// @return index of the table
size_t hash(size_t size_of_hashTable, int value);

/// @brief Removes value from table (allows duplicates)
/// @param hashTable pointer to hash table
/// @param value value that you want to remove
/// @return 0 on success, -1 if not found
int hashTableRemove(HashTable *hashTable, int value);

/// @brief Creates new linked list node
/// @param value value to be inserted
/// @return pointer to created node
Node* createNode(int value);

/// @brief Finds value on the hash table
/// @param hashTable pointer to hash table
/// @param value value to be searched
/// @return A pointer to Node's value on success, NULL if not found
Node* hashTableFind(HashTable *hashTable, int value);

/// @brief Inserts value in table (allow duplicates)
/// @param hashTable pointer to hash table
/// @param value value to be inserted
void hashTableInsert(HashTable *hashTable, int value);

/// @brief Print only occupied buckets
/// @param hashTable pointer to hash table
void printHashTable(HashTable *hashTable);

/// @brief Print all buckets (including empty)
/// @param hashTable pointer to hash table
void printAllHashTable(HashTable *hashTable);

/// @brief Prints specific bucket index
/// @param hashTable pointer to hash table
/// @param index index to be printed
void printIndexHashTable(HashTable *hashTable, size_t index);

/// @brief Removes all elements but keeps table structure
/// @param hashTable pointer to hash table
void cleanHashTable(HashTable *hashTable);

/// @brief Frees all memory and sets pointer to NULL
/// @param[in,out] hashTable Address of hash table pointer. Modified to NULL on success
void destroyHashTable(HashTable **hashTable);

int main() {

    // EXAMPLE USAGE

    HashTable *ht = initHashTable(10);
    
    hashTableInsert(ht, 42);
    hashTableInsert(ht, 52); // Collision with 42's bucket
    hashTableInsert(ht, -5);

    printHashTable(ht);

    cleanHashTable(ht);
    destroyHashTable(&ht);
    
    return 0;
}

/* ============ IMPLEMENTATIONS ============ */

// Hash function using multiplicative method
size_t hash(size_t size_of_hashTable, int value) {
    unsigned int u_val = (unsigned int) (value < 0 ? -value : value);
    size_t index = u_val * 97 + 10213;
    return (size_t) index % size_of_hashTable;
}

HashTable* initHashTable(size_t size) {
    HashTable *newHashTable = (HashTable*) malloc (sizeof(HashTable));
    
    if (!newHashTable) {
        fprintf(stderr, "Malloc Error: could not allocate HashTable");
        exit(EXIT_FAILURE);
    }

    newHashTable->table = (Node**) calloc (size, sizeof(Node)); // calloc zeroes memory
    newHashTable->size = size;

    if (!newHashTable->table) {
        fprintf(stderr, "Malloc Error: could not allocate HashTable->table");
        free(newHashTable);
        exit(EXIT_FAILURE);
    }

    return newHashTable;
}

int hashTableRemove(HashTable *hashTable, int value) {
    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized\n");
        return -1;
    }

    size_t index = hash(hashTable->size, value);
    Node *temp = hashTable->table[index];
    Node *prev = NULL;

    while (temp) {
        
        if (temp->value == value) {
            // Remove from list
            if (!prev) {
               hashTable->table[index] = temp->next;
               
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return 0;
        }
        
        prev = temp;
        temp = temp->next;
    }
    return -1;  // Not found
}

Node* createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    
    if (!newNode) {
        fprintf(stderr, "Could not create a new node");
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}

Node* hashTableFind(HashTable *hashTable, int value) {
    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized");
        return NULL;
    }

    size_t index = hash(hashTable->size, value);
    Node *aux = hashTable->table[index];

    while (aux) {   // while aux != NULL 
        
        if (aux->value == value)
            return aux;
        
        aux = aux->next;
    }
    return NULL;
}

void hashTableInsert(HashTable *hashTable, int value) {

    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized");
        return;
    }

    size_t index = hash(hashTable->size, value);
    Node *newNode = createNode(value);
    
    if (!newNode) {
        fprintf(stderr, "Can not insert null node");
        return;
    }

    // Insert at head of linked list
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

void printHashTable(HashTable *hashTable) {
     if (!hashTable) {
        return;
    }

    for (size_t i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i] != NULL) {
            Node *temp = hashTable->table[i];

            printf("Index %zu: ", i);
            while (temp != NULL) {
                printf("-> %d", temp->value);
                temp = temp->next;
            }
            puts("\n");
        }
    }
}

void printAllHashTable(HashTable *hashTable) {
    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized");
        return;
    }
    
    for (size_t i = 0; i < hashTable->size; i++) {
        Node *temp = hashTable->table[i];
        printf("Index %zu ", i);
        
        while (temp) {
            printf("-> %d", temp->value);
            temp = temp->next;
        }
        puts("\n");
    }
}

void printIndexHashTable(HashTable *hashTable, size_t index) {
    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized");
        return;
    }
    
    Node *temp = hashTable->table[index];
    
    printf("Index %zu ", index);

    while (temp) {
        
        printf("-> %d", temp->value);
        temp = temp->next;
    }
}

void cleanHashTable(HashTable *hashTable) {
    if (!hashTable || !hashTable->table) {
        fprintf(stderr, "HashTable not initialized");
        return;
    }

    for (size_t i = 0; i < hashTable->size; i++) {
        if (hashTable->table[i]) {
            Node *temp = hashTable->table[i];
            Node *next = NULL;

            while (temp) {
                next = temp->next;
                free(temp);
                temp = next;
            }
            hashTable->table[i] = NULL;
        }
    }
}

void destroyHashTable(HashTable **hashTable) {
    if (!hashTable) {
        fprintf(stderr, "HashTable not initialized");
        return;
    }

    HashTable *h = *hashTable;

    if (!h) {
        *hashTable = NULL;
        return;
    }
    if (!h->table) {
        free(h);
        *hashTable = NULL;
        return;
    }

    for (size_t i = 0; i < h->size; i++) {
        if (h->table[i]) {
            Node *temp = h->table[i];
            Node *next = NULL;

            while (temp) {
                next = temp->next;
                free(temp);
                temp = next;
            }
        }
    }
    
    free(h->table);
    free(h);
    *hashTable = NULL;
}
