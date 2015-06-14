
public class MaxMinArray {

	public static void main(String [] args){
		int vetor[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};
		MaxMinRecursivo(vetor, vetor[0], vetor[0], 0);
		System.out.println("---------");
		MaxMinIterativo(vetor);
	}
	
	public static void MaxMinRecursivo(int vetor[], int max, int min, int indice){
		if(vetor[indice] > max)
			max = vetor[indice];
		if(vetor[indice] < min)
			min = vetor[indice];
		if(indice < vetor.length-1)
			MaxMinRecursivo(vetor, max, min, indice+1);
		else{
			System.out.println("Max : " + max);
			System.out.println("Min : " + min);
		}
	}
	
	public static void MaxMinIterativo(int vetor[]){
		int max = vetor[0], min = vetor[0];
		if( vetor.length > 1){
			for (int i = 0; i < vetor.length; i++) {
				if(vetor[i] > max)
					max = vetor[i];
				else if(vetor[i] < min)
					min = vetor[i];
			}
		}
		System.out.println("Max : " + max);
		System.out.println("Min : " + min);
	}
	
}
