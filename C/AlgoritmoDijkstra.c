/*
*	Algoritmo de Dijkstra em C
*	Kelvin Salton do Prado - 2015
*	Encontra o caminho mais curto de um vértice a outro
*/
#include <stdio.h>

void Dijkstra(unsigned long int matriz[4][4], int n){
	bool visitados[n]; // Guarda true para os vértices visitados
	// O valor 'i' do for abaixo não é utilizado, pois o for serve apenas para percorrer todo o número de colunas da matriz 
	for(int i = 1; i < n; i++){ // Começa em 1 pois não precisa comparar o vértice com ele mesmo
		int min = -1;
		unsigned long int MinValor = 4294967295;
		for(int j = 1; j < n; j++){
			// Se o vertice ainda não foi visitado e o valor for menor que o 'MinValor'
			if( !visitados[j] && matriz[j][0] < MinValor ){
				min = j; // Guarda a posição do menor
				MinValor = matriz[j][0]; // Guarda o menor valor
			}
		}
		visitados[min] = true; // Marca o valor a posição do minimo como visitado
		for(int j = 1; j < n; j++){
			// Percorre cada linha testandos os valores
			if( (matriz[min][0] + matriz[min][j]) < matriz[j][0] ){
				matriz[j][0] = matriz[min][0] + matriz[min][j];
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
	Matriz[1][3] = 22;
	Matriz[2][0] = 4294967295;
	Matriz[2][1] = 20;
	Matriz[2][2] = 0;
	Matriz[2][3] = 8;
	Matriz[3][0] = 4294967295;
	Matriz[3][1] = 22;
	Matriz[3][2] = 8;
	Matriz[3][3] = 0;

	Dijkstra(Matriz, 4);

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

	printf("Total caminho mais curto A a D: %lu\n\n", Matriz[3][0]); // Caminho total mais curto

	return 0;
}