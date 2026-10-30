/*
 *	Binary Search Tree in C
 *
 *		 ( 6 )
 *	     /   \
 *	 ( 2 )   ( 7 )
 * 	 /   \		\
 *( 1 )   ( 4 )	( 8 )
 *		 /   \
 *	 ( 3 )	 ( 5 )
 */

#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE;

typedef struct EdgeNode {
  KEY_TYPE key;
  struct EdgeNode *left, *right;
} Node, *NodePointer; // Node is the structure and NodePointer points to Node

int maximum(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int height(NodePointer node) {
  if (node == NULL) // Equivalent to writing if (!node)
    return 0;
  return 1 +
         maximum(
             height(node->left),
             height(
                 node->right)); // Compare the left and right subtrees to
                                // determine which subtree is taller
}

NodePointer binarySearchTree(KEY_TYPE key, NodePointer root) {
  if (!root)
    return NULL;
  if (root->key == key)
    return root;
  if (root->key < key)
    binarySearchTree(key, root->right);
  else
    binarySearchTree(key, root->left);
}

NodePointer linearSearchTree(KEY_TYPE key, NodePointer current) {
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

NodePointer createNode(KEY_TYPE key) {
  NodePointer node = (NodePointer)malloc(sizeof(Node));
  node->left = NULL;
  node->right = NULL;
  node->key = key;
  return node;
}

bool insert(KEY_TYPE key, NodePointer current) {
  NodePointer previous;
  // Traverse right or left until a NULL position is found
  // (empty)
  while (current != NULL) {
    previous = current;
    if (current->key < key)
      current = current->right;
    else
      current = current->left;
  }
  current = createNode(key); // Reuse the current variable, which was available
  if (previous->key < key)
    previous->right = current;
  else
    previous->left = current;
  return true;
}

NodePointer findParentNode(KEY_TYPE key, NodePointer current) {
  NodePointer parentNode = current;
  while (current != NULL) {
    if (current->key == key)
      return parentNode;
    parentNode = current;
    if (current->key < key)
      current = current->right;
    else
      current = current->left;
  }
  return parentNode;
}

NodePointer predecessorNode(NodePointer current) {
  current = current->left;
  while (current->right != NULL)
    current = current->right;
  return current;
}

bool remove(KEY_TYPE key, NodePointer root) {
  NodePointer current, parentNode, replacement, replacementParent;
  replacement = NULL;
  current = binarySearchTree(key, root);
  if (current == NULL)
    return false; // The key was not found
  parentNode = findParentNode(key, root);
  if (current->left == NULL || current->right == NULL) { // If the node has zero or one child
    if (current->left == NULL)
      replacement = current->right;
    else
      replacement = current->left;
    if (parentNode == NULL) { // The root is the only node without a parent
      root = replacement;
    } else {
      if (key < parentNode->key)
        parentNode->left = replacement;
      else
        parentNode->right = replacement;
    }
    free(current);
  } else {
    replacement = predecessorNode(current);
    current->key = replacement->key;
    if (replacement->left != NULL)
      current->left = replacement->left;
    else
      current->left = NULL;
    free(replacement);
  }
  return true;
}

void preorder(NodePointer node) { // R - E - D
  if (!node)
    return;
  printf("%d, ", node->key);
  preorder(node->left);
  preorder(node->right);
}

void postorder(NodePointer node) { // E - D - R
  if (!node)
    return;
  postorder(node->left);
  postorder(node->right);
  printf("%d, ", node->key);
}

void inorder(NodePointer node) { // E - R - D
  if (!node)
    return;
  inorder(node->left);
  printf("%d, ", node->key);
  inorder(node->right);
}

// This function is not working
bool insertRecursive(KEY_TYPE key, NodePointer node) {
  NodePointer previous;
  if (!node) {
    node = createNode(key);
  } else {
    previous = node;
    if (key < node->key)
      insertRecursive(key, node->left);
    else
      insertRecursive(key, node->right);
  }
  if (previous->key < key)
    previous->right = node;
  else
    previous->left = node;
  return true;
}

int main() {
  NodePointer treeRoot = createNode(6);

  insert(2, treeRoot);
  insert(1, treeRoot);
  insert(4, treeRoot);
  insert(7, treeRoot);
  insert(8, treeRoot);
  insert(3, treeRoot);
  insert(5, treeRoot);

  int targetValue = 7;
  if (binarySearchTree(targetValue, treeRoot))
    printf("Search: %d\n", binarySearchTree(targetValue, treeRoot)->key);
  else
    printf("Not found\n");

  remove(4, treeRoot);

  printf("Preorder: ");
  preorder(treeRoot);
  printf("\n");
  printf("Inorder: ");
  inorder(treeRoot);
  printf("\n");
  printf("Postorder: ");
  postorder(treeRoot);

  printf("\nHeight: %d\n", height(treeRoot));
  return 0;
}