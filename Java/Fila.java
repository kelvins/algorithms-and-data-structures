
/*
 * Utiliza a classe NoPilha, porque os atributos são os mesmos
 */

public class Fila {

	public static void main(String [] args){
		NoPilha Fila = new NoPilha(6);
		
		insereFila(Fila, 8);
		insereFila(Fila, 0);
		insereFila(Fila, 1);
		insereFila(Fila, 5);
		insereFila(Fila, 7);
		
		mostraFila(Fila);

		removeFila(Fila);
		mostraFila(Fila);
		
		removeFila(Fila);
		mostraFila(Fila);
		
		removeFila(Fila);
		mostraFila(Fila);
	}
	
	public static void insereFila(NoPilha fila, int chave){
		while(fila.getProx() != null){
			fila = fila.getProx();
		}
		NoPilha novo = new NoPilha(chave);
		fila.setProx(novo);
	}
	
	public static void mostraFila(NoPilha fila){
		System.out.print("\nFila : ");
		while(fila != null){
			System.out.print("[ " + fila.getChave() + " ] ");
			fila = fila.getProx();
		}
	}
	
	public static void removeFila(NoPilha fila){
		fila.setChave(fila.getProx().getChave());
		fila.setProx(fila.getProx().getProx());
	}
}