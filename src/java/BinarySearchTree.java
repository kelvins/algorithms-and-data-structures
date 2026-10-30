/*
 *	Uses the TreeNode class.
 */
public class BinarySearchTree {

  public static void main(String[] args) {
    TreeNode tree = new TreeNode(45);
    insertIntoTree(tree, 56);
    insertIntoTree(tree, 67);
    insertIntoTree(tree, 24);
    insertIntoTree(tree, 61);
    insertIntoTree(tree, 52);

    System.out.print("Preorder: ");
    preOrder(tree);
    System.out.print("\nInorder: ");
    inOrder(tree);
    System.out.print("\nPostorder: ");
    postOrder(tree);

    deleteFromTree(tree, 45);
    deleteFromTree(tree, 24);
    deleteFromTree(tree, 56);

    System.out.println("\n");

    System.out.print("Preorder: ");
    preOrder(tree);
    System.out.print("\nInorder: ");
    inOrder(tree);
    System.out.print("\nPostorder: ");
    postOrder(tree);

    System.out.println("\n");

    int key = 56;
    if (binarySearch(tree, key) != null) System.out.println("\nFound key: " + key);
    else System.out.println("\nKey not found: " + key);

    System.out.println("Tree height: " + treeHeight(tree));
  }

  public static TreeNode binarySearch(TreeNode node, int key) {
    while (node != null) {
      if (node.getKey() == key) return node;
      if (key > node.getKey()) node = node.getRight();
      else node = node.getLeft();
    }
    return null;
  }

  public static TreeNode findParentNode(TreeNode current, int key) {
    TreeNode parentNode = null;
    while (current != null) {
      if (current.getKey() == key) return parentNode;
      parentNode = current;
      if (current.getKey() < key) current = current.getRight();
      else current = current.getLeft();
    }
    return parentNode;
  }

  public static TreeNode predecessor(TreeNode current) {
    current = current.getLeft();
    while (current.getRight() != null) current = current.getRight();
    return current;
  }

  public static boolean deleteFromTree(TreeNode node, int key) {
    TreeNode current, parentNode, replacement;
    replacement = null;
    current = binarySearch(node, key);
    if (current == null) return false; // The key was not found
    parentNode = findParentNode(node, key);
    if (current.getLeft() == null || current.getRight() == null) { // The node has zero or one child
      if (current.getLeft() == null) {
        replacement = current.getRight();
      } else {
        replacement = current.getLeft();
      }
      if (parentNode == null) { // The root is the only node without a parent
        node.setKey(replacement.getKey());
        node.setLeft(replacement.getLeft());
        node.setRight(replacement.getRight());
      } else {
        if (key < parentNode.getKey()) parentNode.setLeft(replacement);
        else parentNode.setRight(replacement);
      }
    } else {
      replacement = predecessor(current);
      current.setKey(replacement.getKey());
      if (replacement.getLeft() != null) current.setLeft(replacement.getLeft());
      else current.setLeft(null);
    }

    return true;
  }

  public static void insertIntoTree(TreeNode tree, int key) {
    TreeNode previous = tree;
    while (tree != null) {
      previous = tree;
      if (tree.getKey() < key) tree = tree.getRight();
      else tree = tree.getLeft();
    }
    TreeNode newNode = new TreeNode(key);
    if (previous.getKey() < key) previous.setRight(newNode);
    else previous.setLeft(newNode);
  }

  public static void preOrder(TreeNode node) {
    if (node != null) {
      System.out.print(node.getKey() + ", ");
      preOrder(node.getLeft());
      preOrder(node.getRight());
    }
  }

  public static void postOrder(TreeNode node) {
    if (node != null) {
      postOrder(node.getLeft());
      postOrder(node.getRight());
      System.out.print(node.getKey() + ", ");
    }
  }

  public static void inOrder(TreeNode node) {
    if (node != null) {
      inOrder(node.getLeft());
      System.out.print(node.getKey() + ", ");
      inOrder(node.getRight());
    }
  }

  public static int max(int a, int b) {
    if (a > b) return a;
    return b;
  }

  public static int treeHeight(TreeNode tree) {
    if (tree == null) return 0;
    return 1 + max(treeHeight(tree.getLeft()), treeHeight(tree.getRight()));
  }
}
