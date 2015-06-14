
/*
 * Utiliza a classe NoPilha
 */

public class Pilha {

	public static void main(String [] args){
		NoPilha vPilha = new NoPilha(6);
		
		vPilha = inserePilha(vPilha, 8);
		vPilha = inserePilha(vPilha, 0);
		vPilha = inserePilha(vPilha, 1);
		vPilha = inserePilha(vPilha, 5);
		vPilha = inserePilha(vPilha, 7);
		mostraPilha(vPilha);

		vPilha = removePilha(vPilha);
		vPilha = removePilha(vPilha);
		vPilha = removePilha(vPilha);
		mostraPilha(vPilha);
	}
	
	public static NoPilha inserePilha(NoPilha pilha, int chave){
		NoPilha novo = new NoPilha(chave);
		novo.setProx(pilha);
		return novo;
	}
	
	public static void mostraPilha(NoPilha pilha){
		System.out.println("\nPilha:");
		while(pilha != null){
			System.out.println("[ " + pilha.getChave() + " ] ");
			pilha = pilha.getProx();
		}
	}
	
	public static NoPilha removePilha(NoPilha pilha){
		pilha = pilha.getProx();
		return pilha;
	}
}