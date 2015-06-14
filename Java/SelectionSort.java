
public class SelectionSort {
	
	public static void main(String [] args){
		
		int vetor[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

		System.out.println("Selection Sort:");
		System.out.println("Vetor não ordenado:");
		mostraVetor(vetor);
		
		vetor = selectionSort(vetor, 0);
		
		System.out.println("Vetor ordenado:");
		mostraVetor(vetor);
	}
	
	public static int[] selectionSort(int vetor[], int indice){
		if(indice >= vetor.length-1)
			return vetor;
		
		int minIndice = indice;
		
		for (int i = indice+1; i < vetor.length; i++)
			if(vetor[i] < vetor[minIndice])
				minIndice = i;
		
		int temp = vetor[indice];
		vetor[indice] = vetor[minIndice];
		vetor[minIndice] = temp;
		
		selectionSort(vetor, indice+1);
		
		return vetor;
	}
	
	public static void mostraVetor(int vetor[]){
		for (int i = 0; i < vetor.length; i++){
			System.out.print(vetor[i] + ", ");
		}
		System.out.println("");
	}
}

