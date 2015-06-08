/*
*	Exemplo de Busca Sentinela em C
*	Objetivo: Encontrar um valor em um vetor sem precisar testar todos os valores dentro do laço
*	Kelvin Salton do Prado - 2015
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