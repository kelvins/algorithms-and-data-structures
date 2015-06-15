
/*
 * Utiliza a classe NoPilha
 */

public class Pilha {

	public static void main(String [] args){
		NoPilha vPilha = new NoPilha(6);
		
		inserePilha(vPilha, 8);
		inserePilha(vPilha, 0);
		inserePilha(vPilha, 1);
		inserePilha(vPilha, 5);
		inserePilha(vPilha, 7);
		
		mostraPilha(vPilha);
		
		removePilha(vPilha);
		removePilha(vPilha);
		removePilha(vPilha);
		removePilha(vPilha);
		
		mostraPilha(vPilha);
	}
	
	public static void inserePilha(NoPilha pilha, int chave){
		while(pilha.getProx() != null){
			pilha = pilha.getProx();
		}
		NoPilha novo = new NoPilha(chave);
		pilha.setProx(novo);
	}
	
	public static void mostraPilha(NoPilha pilha){
		System.out.println("\nPilha:");
		while(pilha != null){
			System.out.print("[ " + pilha.getChave() + " ]-");
			pilha = pilha.getProx();
		}
	}
	
	public static void removePilha(NoPilha pilha){
		NoPilha anterior = pilha;
		while(pilha.getProx() != null){
			anterior = pilha;
			pilha = pilha.getProx();
		}
		anterior.setProx(null);
	}
}