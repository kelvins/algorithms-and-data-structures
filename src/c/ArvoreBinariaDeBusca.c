/*
*	Binary Search Tree in C
*	Kelvin Salton do Prado - 2015
*
*		 ( 6 )
*	     /   \
*	 ( 2 )   ( 7 )
* 	 /   \		\
*( 1 )   ( 4 )	( 8 )
*		 /   \
*	 ( 3 )	 ( 5 )
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int KEYTYPE;

typedef struct NODE {
    KEYTYPE key;
    struct NODE *left, *right;
} NODE, *NODEPTR;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int height(NODEPTR node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

NODEPTR binarySearch(KEYTYPE key, NODEPTR root) {
    if (!root)
        return NULL;
    if (root->key == key)
        return root;
    if (root->key < key)
        return binarySearch(key, root->right);
    else
        return binarySearch(key, root->left);
}

NODEPTR binarySearchLinear(KEYTYPE key, NODEPTR current) {
    while (current != NULL) {
        if (current->key == key)
            return current;
        if (current->key < key)
            current = current->right;
        else
            current = current->left;
    }
    return NULL;
}

NODEPTR createNode(KEYTYPE key) {
    NODEPTR node = (NODEPTR)malloc(sizeof(NODE));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return node;
}

bool insert(KEYTYPE key, NODEPTR current) {
    NODEPTR parent;
    // Traverse the tree to the right or left until an empty position is found
    while (current != NULL) {
        parent = current;
        if (current->key < key)
            current = current->right;
        else
            current = current->left;
    }
    // Use the 'current' variable because it was available
    current = createNode(key);
    if (parent->key < key)
        parent->right = current;
    else
        parent->left = current;
    return true;
}

NODEPTR findParent(KEYTYPE key, NODEPTR current) {
    NODEPTR parent = current;
    while (current != NULL) {
        if (current->key == key)
            return parent;
        parent = current;
        if (current->key < key)
            current = current->right;
        else
            current = current->left;
    }
    return parent;
}

NODEPTR findLargestLeft(NODEPTR current) {
    current = current->left;
    while (current->right != NULL)
        current = current->right;
    return current;
}

bool deleteNode(KEYTYPE key, NODEPTR root) {
    NODEPTR current, parent, substitute, parentSubstitute;
    substitute = NULL;
    current = binarySearch(key, root);
    if (current == NULL)
        return false; // Key not found
    parent = findParent(key, root);
    if (current->left == NULL || current->right == NULL) { // If it has 0 or 1 child
        if (current->left == NULL)
            substitute = current->right;
        else
            substitute = current->left;
        if (parent == NULL) { // Only the root has no parent
            root = substitute;
        } else {
            if (key < parent->key)
                parent->left = substitute;
            else
                parent->right = substitute;
        }
        free(current);
    } else {
        substitute = findLargestLeft(current);
        current->key = substitute->key;
        if (substitute->left != NULL)
            current->left = substitute->left;
        else
            current->left = NULL;
        free(substitute);
    }
    return true;
}

void preorder(NODEPTR node) { // Root - Left - Right
    if (!node)
        return;
    printf("%d, ", node->key);
    preorder(node->left);
    preorder(node->right);
}

void postorder(NODEPTR node) { // Left - Right - Root
    if (!node)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d, ", node->key);
}

void inorder(NODEPTR node) { // Left - Root - Right
    if (!node)
        return;
    inorder(node->left);
    printf("%d, ", node->key);
    inorder(node->right);
}

int main() {
    NODEPTR treeRoot = createNode(6);

    insert(2, treeRoot);
    insert(1, treeRoot);
    insert(4, treeRoot);
    insert(7, treeRoot);
    insert(8, treeRoot);
    insert(3, treeRoot);
    insert(5, treeRoot);

    int searchValue = 7;
    NODEPTR foundNode = binarySearch(searchValue, treeRoot);
    if (foundNode)
        printf("Search: %d\n", foundNode->key);
    else
        printf("Not found\n");

    deleteNode(4, treeRoot);

    printf("Preorder: ");
    preorder(treeRoot);
    printf("\n");

    printf("Inorder: ");
    inorder(treeRoot);
    printf("\n");

    printf("Postorder: ");
    postorder(treeRoot);
    printf("\n");

    printf("Height: %d\n", height(treeRoot));
    return 0;
}
