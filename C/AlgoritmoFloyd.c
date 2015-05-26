/*
*	Algoritmo de Floyd-Warshall em C
*	Kelvin Salton do Prado - 2015
*	Encontra o caminho de todos para todos os vértices
*/
#include <stdio.h>

void FloydWarshall(unsigned long int matriz[4][4], int n){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++){
			for(int z = 0; z < n; z++){
				if( matriz[y][z] > (matriz[y][x] + matriz[x][z]) )
					matriz[y][z] = matriz[y][x] + matriz[x][z];
			}	
		}	
	}
}

int main(){

	unsigned long int Matriz[4][4];
	Matriz[0][0] = 0;
	Matriz[0][1] = 10;
	Matriz[0][2] = 4294967295;
	Matriz[0][3] = 4294967295;
	Matriz[1][0] = 10;
	Matriz[1][1] = 0;
	Matriz[1][2] = 20;
	Matriz[1][3] = 3;
	Matriz[2][0] = 4294967295;
	Matriz[2][1] = 20;
	Matriz[2][2] = 0;
	Matriz[2][3] = 7;
	Matriz[3][0] = 4294967295;
	Matriz[3][1] = 3;
	Matriz[3][2] = 7;
	Matriz[3][3] = 0;

	FloydWarshall(Matriz, 4);

	printf("Matriz:\n");
	for (int i = 0; i < 4; ++i){
		for (int e = 0; e < 4; ++e){
			if( Matriz[i][e] < 10 )
				printf(" %lu ", Matriz[i][e]);
			else
				printf("%lu ", Matriz[i][e]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Total caminho mais curto de A a D: %lu\n\n", Matriz[3][0]); // Caminho total mais curto

	return 0;
}