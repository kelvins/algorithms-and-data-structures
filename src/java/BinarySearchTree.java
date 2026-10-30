/*
 *	Utiliza a classe No
 */
public class ArvoreDeSearchBinaria {

  public static void main(String[] args) {
    No Tree = new No(45);
    insereArvore(Tree, 56);
    insereArvore(Tree, 67);
    insereArvore(Tree, 24);
    insereArvore(Tree, 61);
    insereArvore(Tree, 52);

    System.out.print("Pre : ");
    preOrdem(Tree);
    System.out.print("\nEm  : ");
    emOrdem(Tree);
    System.out.print("\nPos : ");
    posOrdem(Tree);

    excluiArvore(Tree, 45);
    excluiArvore(Tree, 24);
    excluiArvore(Tree, 56);

    System.out.println("\n");

    System.out.print("Pre : ");
    preOrdem(Tree);
    System.out.print("\nEm  : ");
    emOrdem(Tree);
    System.out.print("\nPos : ");
    posOrdem(Tree);

    System.out.println("\n");

    int key = 56;
    if (buscaBinaria(Tree, key) != null) System.out.println("\nEncontrou a key " + key);
    else System.out.println("\nNao encontrou a key " + key);

    System.out.println("Altura da arvore : " + alturaArvore(Tree));
  }

  public static No buscaBinaria(No no, int key) {
    while (no != null) {
      if (no.getChave() == key) return no;
      if (key > no.getChave()) no = no.getDir();
      else no = no.getEsq();
    }
    return null;
  }

  public static No buscaNoPai(No current, int ch) {
    No noPai = null;
    while (current != null) {
      if (current.getChave() == ch) return noPai;
      noPai = current;
      if (current.getChave() < ch) current = current.getDir();
      else current = current.getEsq();
    }
    return noPai;
  }

  public static No maiorAesquerda(No current) {
    current = current.getEsq();
    while (current.getDir() != null) current = current.getDir();
    return current;
  }

  public static boolean excluiArvore(No no, int key) {
    No current, noPai, replacement;
    replacement = null;
    current = buscaBinaria(no, key);
    if (current == null) return false; // The key was not found
    noPai = buscaNoPai(no, key);
    if (current.getEsq() == null || current.getDir() == null) { // Se tem 0 ou 1 child
      if (current.getEsq() == null) {
        replacement = current.getDir();
      } else {
        replacement = current.getEsq();
      }
      if (noPai == null) { // The root is the only node without a parent
        no.setChave(replacement.getChave());
        no.setEsq(replacement.getEsq());
        no.setDir(replacement.getDir());
      } else {
        if (key < noPai.getChave()) noPai.setEsq(replacement);
        else noPai.setDir(replacement);
      }
    } else {
      replacement = maiorAesquerda(current);
      current.setChave(replacement.getChave());
      if (replacement.getEsq() != null) current.setEsq(replacement.getEsq());
      else current.setEsq(null);
    }

    return true;
  }

  public static void insereArvore(No arvore, int key) {
    No previous = arvore;
    while (arvore != null) {
      previous = arvore;
      if (arvore.getChave() < key) arvore = arvore.getDir();
      else arvore = arvore.getEsq();
    }
    No new = new No(key);
    if (previous.getChave() < key) previous.setDir(new);
    else previous.setEsq(new);
  }

  public static void preOrdem(No no) {
    if (no != null) {
      System.out.print(no.getChave() + ", ");
      preOrdem(no.getEsq());
      preOrdem(no.getDir());
    }
  }

  public static void posOrdem(No no) {
    if (no != null) {
      posOrdem(no.getEsq());
      posOrdem(no.getDir());
      System.out.print(no.getChave() + ", ");
    }
  }

  public static void emOrdem(No no) {
    if (no != null) {
      emOrdem(no.getEsq());
      System.out.print(no.getChave() + ", ");
      emOrdem(no.getDir());
    }
  }

  public static int max(int a, int b) {
    if (a > b) return a;
    return b;
  }

  public static int alturaArvore(No arvore) {
    if (arvore == null) return 0;
    return 1 + max(alturaArvore(arvore.getEsq()), alturaArvore(arvore.getDir()));
  }
}
