/*
*	Exemplo de Ordenação utilizando Merge Sort
*	Kelvin Salton do Prado - 2015
*
*	Dividir para conquistar:
*
*	Dividir: Dividir os dados em subsequências pequenas;
*	Conquistar: Classificar as duas metades recursivamente aplicando o merge sort;
*	Combinar: Juntar as duas metades em um único conjunto já classificado.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 100

void merge(int vetor[], int tamanho) {
  int meio = tamanho / 2;
  int i = 0, j = meio, k = 0;
  int aux[tamanho];

  while( i < meio && j < tamanho ){
    if( vetor[i] <= vetor[j] )
      aux[k] = vetor[i++];
    else
      aux[k] = vetor[j++];
    k++;
  }
 
  if( i == meio )
    while( j < tamanho )
      aux[k++] = vetor[j++];
  else
    while( i < meio )
      aux[k++] = vetor[i++];
 
  for( i = 0; i < tamanho; i++ )
    vetor[i] = aux[i];
}
 
int mergeSort(int vetor[], int tamanho){
	int meio = tamanho / 2;

	if( tamanho > 1 ){
		mergeSort(vetor, meio);
		mergeSort(vetor + meio, tamanho - meio);
		merge(vetor, tamanho);
	}

}

int main(){

	int vetor[TAM_VETOR];
	
	// Preenche o vetor com valores aleatórios 0-1000
	srand(time(NULL));
	for(int i = 0; i < TAM_VETOR; i++){
		vetor[i] = rand()%1000;
		printf("%d, ", vetor[i]);
	}
	
	printf("\n\n");
	
	mergeSort(vetor, TAM_VETOR);

	for(int i = 0; i < TAM_VETOR; i++){
		printf("%d, ", vetor[i]);
	}
	
	return 0;
}