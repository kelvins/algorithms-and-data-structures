/*
 *	Utiliza a classe No 
 */
public class ArvoreDeBuscaBinaria {

	public static void main(String [] args){
		No Arvore = new No(45);
		insereArvore(Arvore, 56);
		insereArvore(Arvore, 67);
		insereArvore(Arvore, 24);
		insereArvore(Arvore, 61);
		insereArvore(Arvore, 52);
		
		System.out.print("Pre : ");
		preOrdem(Arvore);
		System.out.print("\nEm  : ");
		emOrdem(Arvore);
		System.out.print("\nPos : ");
		posOrdem(Arvore);
		
		excluiArvore(Arvore, 45);
		excluiArvore(Arvore, 24);
		excluiArvore(Arvore, 56);
		
		System.out.println("\n");

		System.out.print("Pre : ");
		preOrdem(Arvore);
		System.out.print("\nEm  : ");
		emOrdem(Arvore);
		System.out.print("\nPos : ");
		posOrdem(Arvore);

		System.out.println("\n");
		
		int chave = 56;
		if(buscaBinaria(Arvore, chave) != null)
			System.out.println("\nEncontrou a chave " + chave);
		else
			System.out.println("\nNao encontrou a chave " + chave);
		
		System.out.println("Altura da arvore : " + alturaArvore(Arvore) );
	}
	
	public static No buscaBinaria(No no, int chave){
		while(no != null){
			if(no.getChave() == chave)
				return no;
			if(chave > no.getChave())
				no = no.getDir();
			else
				no = no.getEsq();
		}
		return null;
	}
	
	public static No buscaNoPai(No atual, int ch){
		No noPai = null;
		while( atual != null ){
			if( atual.getChave() == ch )
				return noPai;
			noPai = atual;
			if( atual.getChave() < ch )
				atual = atual.getDir();
			else
				atual = atual.getEsq();
		}
		return noPai;
	}

	public static No maiorAesquerda(No atual){
		atual = atual.getEsq();
		while( atual.getDir() != null )
			atual = atual.getDir();
		return atual;
	}
	
	public static boolean excluiArvore(No no, int chave){
		No atual, noPai, substituto;
		substituto = null;
		atual = buscaBinaria(no, chave);
		if( atual == null ) return false; // Não encontrou a chave
		noPai = buscaNoPai(no, chave);
		if( atual.getEsq() == null || atual.getDir() == null ){ // Se tem 0 ou 1 filho
			if( atual.getEsq() == null ){
				substituto = atual.getDir();
			}else{
				substituto = atual.getEsq();
			}
			if( noPai == null ){ // Único que não tem pai é a raiz
				no.setChave(substituto.getChave());
				no.setEsq(substituto.getEsq());
				no.setDir(substituto.getDir());
			}else{
				if(chave < noPai.getChave())
					noPai.setEsq(substituto);
				else
					noPai.setDir(substituto);
			}
		}else{
			substituto = maiorAesquerda(atual);
			atual.setChave(substituto.getChave());
			if( substituto.getEsq() != null )
				atual.setEsq(substituto.getEsq());
			else
				atual.setEsq(null);
		}
		
		return true;
	}
	
	public static void insereArvore(No arvore, int chave){
		No anterior = arvore;
		while(arvore != null){
			anterior = arvore;
			if(arvore.getChave() < chave)
				arvore = arvore.getDir();
			else
				arvore = arvore.getEsq();
		}
		No novo = new No(chave);
		if(anterior.getChave() < chave)
			anterior.setDir(novo);
		else
			anterior.setEsq(novo);
	}
	
	public static void preOrdem(No no){
		if(no != null){
			System.out.print(no.getChave() + ", ");
			preOrdem(no.getEsq());
			preOrdem(no.getDir());
		}
	}	
	
	public static void posOrdem(No no){
		if(no != null){
			posOrdem(no.getEsq());
			posOrdem(no.getDir());
			System.out.print(no.getChave() + ", ");
		}
	}
	
	public static void emOrdem(No no){
		if(no != null){
			emOrdem(no.getEsq());
			System.out.print(no.getChave() + ", ");
			emOrdem(no.getDir());
		}
	}
	
	public static int max(int a, int b){
		if(a > b)
			return a;
		return b;
	}
	
	public static int alturaArvore(No arvore){
		if(arvore == null)
			return 0;
		return 1 + max( alturaArvore(arvore.getEsq()), alturaArvore(arvore.getDir()) );
	}
	
}
