/*
 *	Utiliza a classe No
 */


public class ArvoreBinaria {


    public static void main(String[] args) {
        No raiz = new No(9);

        inserir(raiz, 3);
        inserir(raiz, 4);
        inserir(raiz, 6);
        inserir(raiz, 7);
        inserir(raiz, 8);
        inserir(raiz, 10);
        inserir(raiz, 13);
        inserir(raiz, 14);

        System.out.println();

        System.out.printf("Em ordem: ");
        emOrdem(raiz);
        System.out.println();

        System.out.printf("Pós-fixado: ");
        posFixado(raiz);
        System.out.println();

        System.out.printf("Pré-fixado: ");
        preFixado(raiz);
        System.out.println();

        System.out.println("Remove Valor: "+ removeValorMinimoDaArvore(raiz));
        System.out.println("Altura Arvore: "+AlturaArvore(raiz));
    }


    public static void inserir(No node, int valor) {
        if (node != null) {
            if (valor < node.getChave()) {
                if (node.getEsq() != null) {
                    inserir(node.getEsq(), valor);
                } else {
                    System.out.println("  Inserindo " + valor + " a esquerda de " + node.getChave());
                    node.setEsq(new No(valor)); ;
                }
            } else if (valor > node.getChave()) {
                if (node.getDir() != null) {
                    inserir(node.getDir(), valor);
                } else {
                    System.out.println("  Inserindo " + valor + " a direita de " + node.getChave());
                    node.setDir(new No(valor));
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

    public static int AlturaArvore(No no){

        if(no == null){
            return -1;
        }
        else{

            int esquerda = AlturaArvore(no.getEsq());
            int direita = AlturaArvore(no.getDir());

            if(esquerda < direita ){
                return direita+1;
            }
            else{
                return esquerda+1;
            }
        }
    }

}



