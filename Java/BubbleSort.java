
public class BubbleSort {
	
	public static void main(String [] args){
		
		int vetor[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

		System.out.println("Bubble Sort:");
		System.out.println("Vetor não ordenado:");
		mostraVetor(vetor);

		vetor = bubbleSort(vetor);
		
		System.out.println("Vetor ordenado:");
		mostraVetor(vetor);
	}
	
	public static int[] bubbleSort(int vetor[]){
		int trocas = 0;
		for (int i = 0; i < vetor.length-1; i++) {
			if(vetor[i] > vetor[i+1]){
				int temp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = temp;
				trocas++;
			}
		}
		if(trocas != 0)
			bubbleSort(vetor);
		return vetor;
	}
	
	
	public static int[] bubbleSort2(int vetor[]){
		for (int i = 1; i < vetor.length; i++) {
			int tam = vetor.length;
			for (int j = 0; j < tam-i; j++) {
				if(vetor[j] > vetor[j+1]){
					int temp = vetor[j];
					vetor[j] = vetor[j+1];
					vetor[j+1] = temp;
				}
			}
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
