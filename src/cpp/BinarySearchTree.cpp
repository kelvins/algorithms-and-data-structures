#include <iostream>

/*
 * Structure for a binary tree node
 */

struct Node {
    int data;       // data value stored in the node
    Node* left;     // pointer to the left child node
    Node* right;    // pointer to the right child node

    /**
     * Constructor to create a new node with the given data.
     * 
     * @param value the data value for the new node.
     */

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};



/**
 * Function to insert a new node into the binary tree.
 *
 * @param root  pointer to the root of the binary tree.
 * @param value the value to be inserted.
 *
 * @return pointer to the root of the modified binary tree.
 */

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}



/**
 * Function for an in-order traversal of the binary tree (Left-Root-Right).
 *
 * @param root pointer to the root of the binary tree.
 */

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}



/**
 * Function for a pre-order traversal of the binary tree (Root-Left-Right).
 *
 * @param root pointer to the root of the binary tree.
 */

void preOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}



/**
 * Function for a post-order traversal of the binary tree (Left-Right-Root).
 *
 * @param root pointer to the root of the binary tree.
 */

void postOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}



int main() {
    Node* root = nullptr;

    // insert elements into the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // in-order traversal
    std::cout << "In-order traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // pre-order traversal
    std::cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // post-order traversal
    std::cout << "Post-order traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
