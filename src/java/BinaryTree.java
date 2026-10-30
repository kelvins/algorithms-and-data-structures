/*
 *	Utiliza a classe No
 */

public class ArvoreBinaria {

  public static void main(String[] args) {
    No root = new No(9);

    insert(root, 3);
    insert(root, 4);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 10);
    insert(root, 13);
    insert(root, 14);

    System.out.println();

    System.out.printf("Em order: ");
    emOrdem(root);
    System.out.println();

    System.out.printf("Pós-fixado: ");
    posFixado(root);
    System.out.println();

    System.out.printf("Pré-fixado: ");
    preFixado(root);
    System.out.println();

    System.out.println("Remove Valor: " + removeValorMinimoDaArvore(root));
    System.out.println("Altura Tree: " + AlturaArvore(root));
  }

  public static void insert(No node, int value) {
    if (node != null) {
      if (value < node.getChave()) {
        if (node.getEsq() != null) {
          insert(node.getEsq(), value);
        } else {
          System.out.println("  Inserindo " + value + " a left de " + node.getChave());
          node.setEsq(new No(value));
          ;
        }
      } else if (value > node.getChave()) {
        if (node.getDir() != null) {
          insert(node.getDir(), value);
        } else {
          System.out.println("  Inserindo " + value + " a right de " + node.getChave());
          node.setDir(new No(value));
        }
      }
    }
  }

  public static void preFixado(No no) {
    if (no != null) {
      System.out.print(no.getChave() + " ");
      preFixado(no.getEsq());
      preFixado(no.getDir());
    }
  }

  public static void posFixado(No no) {
    if (no != null) {
      posFixado(no.getEsq());
      posFixado(no.getDir());
      System.out.print(no.getChave() + " ");
    }
  }

  public static void emOrdem(No no) {
    if (no != null) {
      emOrdem(no.getEsq());
      System.out.print(no.getChave() + " ");
      emOrdem(no.getDir());
    }
  }

  public static No removeValorMinimoDaArvore(No node) {
    if (node == null) {
      System.out.println("  ERROR ");
    } else if (node.getEsq() != null) {
      node.setEsq(removeValorMinimoDaArvore(node.getEsq()));
      return node;
    } else {
      return node.getDir();
    }
    return null;
  }

  public static int AlturaArvore(No no) {

    if (no == null) {
      return -1;
    } else {

      int left = AlturaArvore(no.getEsq());
      int right = AlturaArvore(no.getDir());

      if (left < right) {
        return right + 1;
      } else {
        return left + 1;
      }
    }
  }
}
