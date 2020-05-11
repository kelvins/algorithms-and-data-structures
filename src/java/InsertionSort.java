
public class InsertionSort {
	
	public static void main(String [] args){
		
		int vetor[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

		System.out.println("Insertion Sort:");
		System.out.println("Vetor não ordenado:");
		mostraVetor(vetor);
		
		vetor = insertionSort(vetor);
		
		System.out.println("Vetor ordenado:");
		mostraVetor(vetor);
	}
	
	public static int[] insertionSort(int vetor[]){
		int chave, aux;
		for (int i = 0; i < vetor.length; i++) {
			chave = vetor[i];
			aux = i-1;
			while(aux >= 0 && vetor[aux] > chave){
				vetor[aux+1] = vetor[aux];
				aux -= 1;
			}
			vetor[aux+1] = chave;
		}
		return vetor;
	}
	
	public static void mostraVetor(int vetor[]){
		for (int i = 0; i < vetor.length; i++){
			System.out.print(vetor[i] + ", ");
		}
		System.out.println("");
	}
	
}
