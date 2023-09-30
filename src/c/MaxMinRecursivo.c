/*
*	
*/

#include <stdio.h>

#define TAM 10

void MaxMin(int vetor[], int min, int max, int indice){
	if( vetor[indice] < min )
		min = vetor[indice];
	if( vetor[indice] > max )
		max = vetor[indice];
	if( indice < TAM-1 )
		MaxMin(vetor, min, max, indice+1);
	else
		printf("Min: %d \nMax: %d\n\n", min, max);
}

int main(){
	int vetor[TAM] = {9,2,1,8,6,3,4,5,0,7};
	MaxMin(vetor, vetor[0], vetor[0], 0);
	return 0;
}