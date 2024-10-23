#include <iostream>

using namespace std;

// Create a class for the BinaryTree
class BinaryTree {
  // Create a struct for the TreeNode
  struct TreeNode {
    // Variables for the TreeNode
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor for the TreeNode
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
  };

  // Private Variables and Functions
private:
  TreeNode *root;

  // Insert Function
  TreeNode *insert(TreeNode *root, int value) {
    if (root == nullptr)
      return new TreeNode(value);

    if (value < root->data)
      root->left = insert(root->left, value);
    else
      root->right = insert(root->right, value);

    return root;
  }

  // Print Inorder Function
  void printInorder(TreeNode *head) {
    if (head != nullptr) {
      printInorder(head->left);
      cout << head->data << " ";
      printInorder(head->right);
    }
  }

  // Print Preorder Function
  void printPreorder(TreeNode *head) {
    if (head != nullptr) {
      cout << head->data << " ";
      printPreorder(head->left);
      printPreorder(head->right);
    }
  }

  // Print Postorder Function
  void printPostorder(TreeNode *head) {
    if (head != nullptr) {
      printPostorder(head->left);
      printPostorder(head->right);
      cout << head->data << " ";
    }
  }

  // Public Functions
public:
  // Constructor
  BinaryTree() : root(nullptr) {}

  // Insert Function
  void insert(int value) { root = insert(root, value); }

  // Print Inorder Function
  void printInorder() {
    printInorder(root);
    cout << endl;
  }

  // Print Preorder Function
  void printPreorder() {
    printPreorder(root);
    cout << endl;
  }

  // Print Postorder Function
  void printPostorder() {
    printPostorder(root);
    cout << endl;
  }
};

int main() {
  // Create tree
  BinaryTree binaryTree;

  binaryTree.insert(10);
  binaryTree.insert(6);
  binaryTree.insert(15);
  binaryTree.insert(3);
  binaryTree.insert(8);
  binaryTree.insert(20);

  cout << "InOrder: ";
  binaryTree.printInorder();

  cout << "PreOrder: ";
  binaryTree.printPreorder();

  cout << "PostOrder: ";
  binaryTree.printPostorder();

  return 0;
}
