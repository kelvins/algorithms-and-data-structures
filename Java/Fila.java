
/*
 * Utiliza a classe NoPilha, porque os atributos são os mesmos
 */

public class Fila {

	public static void main(String [] args){
		NoPilha Fila = new NoPilha(6);
		
		Fila = insereFila(Fila, 8);
		Fila = insereFila(Fila, 0);
		Fila = insereFila(Fila, 1);
		Fila = insereFila(Fila, 5);
		Fila = insereFila(Fila, 7);
		
		mostraFila(Fila);

		removeFila(Fila);
		mostraFila(Fila);
		
		removeFila(Fila);
		mostraFila(Fila);
		
		removeFila(Fila);
		mostraFila(Fila);
	}
	
	public static NoPilha insereFila(NoPilha fila, int chave){
		NoPilha novo = new NoPilha(chave);
		novo.setProx(fila);
		return novo;
	}
	
	public static void mostraFila(NoPilha fila){
		System.out.print("\nFila : ");
		while(fila != null){
			System.out.print("[ " + fila.getChave() + " ] ");
			fila = fila.getProx();
		}
	}
	
	public static void removeFila(NoPilha fila){
		NoPilha anterior = fila;
		while(fila.getProx() != null){
			anterior = fila;
			fila = fila.getProx();
		}
		anterior.setProx(null);
	}
}