/*
 *	Utiliza a classe TreeNode
 */

public class ArvoreBinaria {

  public static void main(String[] args) {
    TreeNode root = new TreeNode(9);

    insert(root, 3);
    insert(root, 4);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 10);
    insert(root, 13);
    insert(root, 14);

    System.out.println();

    System.out.printf("Inorder: ");
    inOrder(root);
    System.out.println();

    System.out.printf("Postorder: ");
    postOrder(root);
    System.out.println();

    System.out.printf("Preorder: ");
    preOrder(root);
    System.out.println();

    System.out.println("Removed value: " + removeMinimumFromTree(root));
    System.out.println("Tree height: " + treeHeight(root));
  }

  public static void insert(TreeNode node, int value) {
    if (node != null) {
      if (value < node.getKey()) {
        if (node.getLeft() != null) {
          insert(node.getLeft(), value);
        } else {
          System.out.println("  Inserting " + value + " to the left of " + node.getKey());
          node.setLeft(new TreeNode(value));
          ;
        }
      } else if (value > node.getKey()) {
        if (node.getRight() != null) {
          insert(node.getRight(), value);
        } else {
          System.out.println("  Inserting " + value + " to the right of " + node.getKey());
          node.setRight(new TreeNode(value));
        }
      }
    }
  }

  public static void preOrder(TreeNode no) {
    if (no != null) {
      System.out.print(no.getKey() + " ");
      preOrder(no.getLeft());
      preOrder(no.getRight());
    }
  }

  public static void postOrder(TreeNode no) {
    if (no != null) {
      postOrder(no.getLeft());
      postOrder(no.getRight());
      System.out.print(no.getKey() + " ");
    }
  }

  public static void inOrder(TreeNode no) {
    if (no != null) {
      inOrder(no.getLeft());
      System.out.print(no.getKey() + " ");
      inOrder(no.getRight());
    }
  }

  public static TreeNode removeMinimumFromTree(TreeNode node) {
    if (node == null) {
      System.out.println("  ERROR ");
    } else if (node.getLeft() != null) {
      node.setLeft(removeMinimumFromTree(node.getLeft()));
      return node;
    } else {
      return node.getRight();
    }
    return null;
  }

  public static int treeHeight(TreeNode no) {

    if (no == null) {
      return -1;
    } else {

      int left = treeHeight(no.getLeft());
      int right = treeHeight(no.getRight());

      if (left < right) {
        return right + 1;
      } else {
        return left + 1;
      }
    }
  }
}
