/*
 *	Utiliza a classe TreeNode
 */
public class BinarySearchTree {

  public static void main(String[] args) {
    TreeNode Tree = new TreeNode(45);
    insertIntoTree(Tree, 56);
    insertIntoTree(Tree, 67);
    insertIntoTree(Tree, 24);
    insertIntoTree(Tree, 61);
    insertIntoTree(Tree, 52);

    System.out.print("Pre : ");
    preOrder(Tree);
    System.out.print("\nEm  : ");
    inOrder(Tree);
    System.out.print("\nPos : ");
    postOrder(Tree);

    deleteFromTree(Tree, 45);
    deleteFromTree(Tree, 24);
    deleteFromTree(Tree, 56);

    System.out.println("\n");

    System.out.print("Pre : ");
    preOrder(Tree);
    System.out.print("\nEm  : ");
    inOrder(Tree);
    System.out.print("\nPos : ");
    postOrder(Tree);

    System.out.println("\n");

    int key = 56;
    if (binarySearch(Tree, key) != null) System.out.println("\nFound key: " + key);
    else System.out.println("\nKey not found: " + key);

    System.out.println("Tree height: " + treeHeight(Tree));
  }

  public static TreeNode binarySearch(TreeNode no, int key) {
    while (no != null) {
      if (no.getKey() == key) return no;
      if (key > no.getKey()) no = no.getRight();
      else no = no.getLeft();
    }
    return null;
  }

  public static TreeNode findParentNode(TreeNode current, int ch) {
    TreeNode parentNode = null;
    while (current != null) {
      if (current.getKey() == ch) return parentNode;
      parentNode = current;
      if (current.getKey() < ch) current = current.getRight();
      else current = current.getLeft();
    }
    return parentNode;
  }

  public static TreeNode predecessor(TreeNode current) {
    current = current.getLeft();
    while (current.getRight() != null) current = current.getRight();
    return current;
  }

  public static boolean deleteFromTree(TreeNode no, int key) {
    TreeNode current, parentNode, replacement;
    replacement = null;
    current = binarySearch(no, key);
    if (current == null) return false; // The key was not found
    parentNode = findParentNode(no, key);
    if (current.getLeft() == null || current.getRight() == null) { // Se tem 0 ou 1 child
      if (current.getLeft() == null) {
        replacement = current.getRight();
      } else {
        replacement = current.getLeft();
      }
      if (parentNode == null) { // The root is the only node without a parent
        no.setKey(replacement.getKey());
        no.setLeft(replacement.getLeft());
        no.setRight(replacement.getRight());
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

  public static void preOrder(TreeNode no) {
    if (no != null) {
      System.out.print(no.getKey() + ", ");
      preOrder(no.getLeft());
      preOrder(no.getRight());
    }
  }

  public static void postOrder(TreeNode no) {
    if (no != null) {
      postOrder(no.getLeft());
      postOrder(no.getRight());
      System.out.print(no.getKey() + ", ");
    }
  }

  public static void inOrder(TreeNode no) {
    if (no != null) {
      inOrder(no.getLeft());
      System.out.print(no.getKey() + ", ");
      inOrder(no.getRight());
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
