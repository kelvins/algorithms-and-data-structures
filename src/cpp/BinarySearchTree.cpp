#include <iostream>

/*
 * Structure for a binary tree node
 */
struct Node {
  int data;     ///< The integer data value stored in the node.
  Node *left;   ///< Pointer to the left child node.
  Node *right;  ///< Pointer to the right child node.

  /**
   * Constructor to create a new node with the given data.
   *
   * @param value the data value for the new node.
   */
  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
 public:
  BinarySearchTree() : root(nullptr) {}

  Node *find(int x) const { return _find(this->root, x); }

  void insert(int x) { _insert(&(this->root), x); }

  void deleteNode(int x) { _delete(&(this->root), x); }

  void preorderTraversal() const { _printPreorder(this->root); }

  void inorderTraversal() const { _printInorder(this->root); }

  void postorderTraversal() const { _printPostorder(this->root); }

 private:
  Node *root;

  /**
   * @brief Find a node with a specific value in the binary search tree.
   *
   * This function searches the binary search tree starting from the given root
   * node for a node that contains the specified value `x`. If a node with the
   * value `x` is found, a pointer to that node is returned. If no such node
   * exists in the tree, the function returns `nullptr`.
   *
   * @param root A pointer to the root node of the binary search tree.
   * @param x The value to search for in the tree.
   * @return A pointer to the node containing the value `x`, or `nullptr` if not
   * found.
   */
  Node *_find(Node *root, int x) const {
    if (!root || root->data == x) {
      return root;
    }
    if (x < root->data) {
      return _find(root->left, x);
    } else {
      return _find(root->right, x);
    }
  }

  /**
   * @brief Inserts a new node with the specified value into the binary search
   * tree.
   *
   * This function inserts a new node containing the value `x` into the binary
   * search tree. It traverses the tree starting from the given root node
   * (passed as a pointer to a pointer) and inserts the new node at the
   * appropriate position based on the value `x`.
   *
   * @param root A pointer to a pointer to the root node of the binary search
   * tree.
   * @param x The value to insert into the tree.
   * @return A pointer to the updated root node of the tree after the insertion.
   */
  Node *_insert(Node **root, int x) {
    if (!(*root)) {
      *root = new Node(x);
    } else if (x <= (*root)->data) {
      (*root)->left = _insert(&((*root)->left), x);
    } else {
      (*root)->right = _insert(&((*root)->right), x);
    }
    return *root;
  }

  /**
   * @brief Deletes a node with the specified value from the binary search tree.
   *
   * This function deletes a node containing the value `x` from the binary
   * search tree. It traverses the tree starting from the given root node and
   * removes the node with the specified value if it exists.
   *
   * After the deletion, the function may adjust the tree structure to maintain
   * its binary search tree properties.
   *
   * @param root A pointer to a pointer to the root node of the binary search
   * tree.
   * @param x The value to delete from the tree.
   * @return A pointer to the updated root node of the tree after the deletion.
   */
  Node *_delete(Node **root, int x) {
    if (!(*root)) {
      return nullptr;
    }

    if (x < (*root)->data) {
      (*root)->left = _delete(&((*root)->left), x);
    } else if (x > (*root)->data) {
      (*root)->right = _delete(&((*root)->right), x);
    } else {
      // Case 1: Leaf node
      if (!((*root)->left) && !((*root)->right)) {
        delete *root;
        *root = nullptr;
      }

      // Case 2: Only one child
      else if (!((*root)->left)) {
        Node *tmp = *root;
        *root = (*root)->right;
        delete tmp;
      } else if (!((*root)->right)) {
        Node *tmp = *root;
        *root = (*root)->left;
        delete tmp;
      }

      // Case 3: Two children
      else {
        // Could've been <<< Node *tmp = _find_max((*root)->left); >>>
        Node *tmp = _find_min((*root)->right);
        (*root)->data = tmp->data;
        (*root)->right = _delete(&((*root)->right), tmp->data);
      }
    }
    return *root;
  }

  /**
   * @brief Find the minimum node value in the binary search tree.
   *
   * This function searches the binary search tree starting from the given root
   * node and returns a pointer to the node with the minimum value. The minimum
   * value is found by recursively traversing the left child nodes until the
   * smallest value is located.
   *
   * @param root A pointer to the root node of the binary search tree.
   * @return A pointer to the node with the minimum value in the tree.
   */
  Node *_find_min(Node *root) const {
    while (root && root->left) {
      root = root->left;
    }
    return root;
  }

  /**
   * @brief Find the maximum node value in the binary search tree.
   *
   * This function searches the binary search tree starting from the given root
   * node and returns a pointer to the node with the maximum value. The maximum
   * value is found by recursively traversing the right child nodes until the
   * largest value is located.
   *
   * @param root A pointer to the root node of the binary search tree.
   * @return A pointer to the node with the minimum value in the tree.
   */
  Node *_find_max(Node *root) const {
    while (root && root->right) {
      root = root->right;
    }
    return root;
  }

  /**
   * @brief Prints the elements of the binary search tree in preorder traversal.
   *
   * The preorder traversal visits the current node first, followed by its left
   * and right children - recursively.
   *
   * @param root A pointer to the root node of the binary search tree.
   */
  void _printPreorder(Node *root) const {
    if (root) {
      std::cout << root->data << '\n';
      _printPreorder(root->left);
      _printPreorder(root->right);
    }
  }

  /**
   * @brief Prints the elements of the binary search tree in inorder traversal.
   *
   * The inorder traversal visits the left child, followed by the current node,
   * and then the right child recursively.
   *
   * @param root A pointer to the root node of the binary search tree.
   */
  void _printInorder(Node *root) const {
    if (root) {
      _printInorder(root->left);
      std::cout << root->data << '\n';
      _printInorder(root->right);
    }
  }

  /**
   * @brief Prints the elements of the binary search tree in postorder
   * traversal.
   *
   * The postorder traversal visits the left and right children first, followed
   * by the current node.
   *
   * @param root A pointer to the root node of the binary search tree.
   */
  void _printPostorder(Node *root) const {
    if (root) {
      _printPostorder(root->left);
      _printPostorder(root->right);
      std::cout << root->data << '\n';
    }
  }
};

int main(int argc, char *argv[]) {
  auto bst = BinarySearchTree();

  int arr[] = {30, 20, 10, 50, 40, 45, 80, 90};
  for (const auto &e : arr) {
    bst.insert(e);
  }

  std::cout << "inorder traversal:\n";
  bst.inorderTraversal();
  std::cout << "preorder traversal:\n";
  bst.preorderTraversal();
  std::cout << "postorder traversal:\n";
  bst.postorderTraversal();

  bst.deleteNode(50);
  std::cout << "preorder traversal:\n";
  bst.preorderTraversal();

  return 0;
}
