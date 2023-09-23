#include <stdio.h>
#include <stdlib.h>

// This is an unbalanced binary tree.

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* newNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value <= root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

int search(struct Node* root, int value) {
    if (root == NULL) {
        printf(" Value [%d] not found.\n", value);
    } else if (root->value == value) {
        printf(" Value [%d] found.\n", value);
    } else if (value <= root->value) {
        return search(root->left, value);
    } else if (value >= root->value) {
        return search(root->right, value);
    }
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;
    printf("[%d]", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("[%d]", root->value);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("[%d]", root->value);
}

void levelOrder(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {
        printf("[%d]", root->value);
    } else {
        levelOrder(root->left, level - 1);
        levelOrder(root->right, level - 1);
    }
}

void printLevelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 0; i < h; i++) {
        levelOrder(root, i);
    }
}

struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            struct Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if (root == NULL) {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

int main(void) {
    struct Node* root;
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 33);
    root = insert(root, 4);
    root = insert(root, 57);
    root = insert(root, 6);
    root = insert(root, 12);

    search(root, 33);
    search(root, 23);

    printf("\n Preorder: ");
    preorder(root);

    printf("\n Inorder: ");
    inorder(root);

    printf("\n Postorder: ");
    postorder(root);

    printf("\n Levelorder: ");
    printLevelOrder(root);

    root = deleteNode(root, 7);

    printf("\n Levelorder after deleting 7: ");
    printLevelOrder(root);

    root = deleteNode(root, 6);

    printf("\n Levelorder after deleting 6: ");
    printLevelOrder(root);

    return 0;
}
