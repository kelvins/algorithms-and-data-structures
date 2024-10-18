/*
*	Exemplo de Busca Sentinela em C
*	Objetivo: Encontrar um valor em um vetor sem precisar testar todos os valores dentro do laço
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 10

// Busca sentinela, realiza uma busca sequencial sem precisar testar a chave a cada passo do laço de busca
int buscaSentinela(int vetor[], int chave){
	vetor[TAM_VETOR] = chave; // Coloca o valor buscado (chave) na última posição do vetor
	int aux = 0; // Variável de controle do laço
	while( vetor[aux] != chave ) // Enquanto não encontrar o valor (chave) incrementa 1 em aux
		aux++;
	if( aux == TAM_VETOR ) // Caso o valor de aux seja igual ao tamanho do vetor, significa que foi até o final e não encontrou o valor
		return -1; // Não encontrou
	else // Caso aux seja diferente, significa que encontrou o valor e quebrou o laço, o aux é a posição do valor buscado
		return aux; // Encontrou
}

int main(){

	int vetor[TAM_VETOR+1]; // Declara o vetor com +1 pois é a posição que será utilizada pela sentinela

	// Preenche o vetor com valores aleatórios 0-1000
	srand(time(NULL));
	for(int i = 0; i < TAM_VETOR; i++){
		vetor[i] = rand()%1000;
		printf("%d, ", vetor[i]);
	}

	// Faz a busca, passando como parâmetro o vetor e a chave que deseja buscar
	int res = buscaSentinela(vetor, vetor[TAM_VETOR-2]);
	if( res != -1 )
		printf("\n\nValor %d encontrado na posicao %d.\n\n", vetor[res], res);
	else
		printf("\n\nValor não encontrado no vetor\n\n");

	return 0;
}


// In english

/*
* Sentinel Search Example in C
* Objective: Find a value in an array without needing to test all values within the loop
*/


// #define ARRAY_SIZE 10

// // Sentinel search function that performs a sequential search without testing the key at each iteration
// int sentinelSearch(int array[], int key) {
//     array[ARRAY_SIZE] = key; // Place the searched value (key) at the last position of the array
//     int index = 0; // Control variable for the loop
//     // While the current element is not the key, increment index
//     while (array[index] != key) 
//         index++;
    
//     // If index equals the size of the array, it means the search went to the end without finding the key
//     if (index == ARRAY_SIZE) 
//         return -1; // Not found
//     else // If index is different, it means the value was found
//         return index; // Found
// }

// int main() {
//     int array[ARRAY_SIZE + 1]; // Declare the array with +1 because this position will be used by the sentinel

//     // Fill the array with random values between 0 and 1000
//     srand(time(NULL));
//     for (int i = 0; i < ARRAY_SIZE; i++) {
//         array[i] = rand() % 1000;
//         printf("%d, ", array[i]);
//     }

//     // Perform the search, passing the array and the key to search for
//     int res = sentinelSearch(array, array[ARRAY_SIZE - 2]);
//     if (res != -1)
//         printf("\n\nValue %d found at position %d.\n\n", array[res], res);
//     else
//         printf("\n\nValue not found in the array\n\n");

//     return 0;
// }
