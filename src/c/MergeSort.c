/*
*	Exemplo de Ordenação utilizando Merge Sort
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

//  In english 

/*
* Example of Sorting using Merge Sort
*
* Divide and Conquer:
*
* Divide: Split the data into small subsequences;
* Conquer: Sort the two halves recursively using merge sort;
* Combine: Merge the two halves into a single sorted set.
*
*/


// #define ARRAY_SIZE 100

// void merge(int array[], int size) {
//     int mid = size / 2;
//     int i = 0, j = mid, k = 0;
//     int temp[size];

//     while (i < mid && j < size) {
//         if (array[i] <= array[j])
//             temp[k] = array[i++];
//         else
//             temp[k] = array[j++];
//         k++;
//     }

//     if (i == mid)
//         while (j < size)
//             temp[k++] = array[j++];
//     else
//         while (i < mid)
//             temp[k++] = array[i++];

//     for (i = 0; i < size; i++)
//         array[i] = temp[i];
// }

// void mergeSort(int array[], int size) {
//     int mid = size / 2;

//     if (size > 1) {
//         mergeSort(array, mid);
//         mergeSort(array + mid, size - mid);
//         merge(array, size);
//     }
// }

// int main() {
//     int array[ARRAY_SIZE];

//     // Fill the array with random values 0-1000
//     srand(time(NULL));
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         array[i] = rand() % 1000;
//         printf("%d, ", array[i]);
//     }

//     printf("\n\n");

//     mergeSort(array, ARRAY_SIZE);

//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         printf("%d, ", array[i]);
//     }

//     return 0;
// }
