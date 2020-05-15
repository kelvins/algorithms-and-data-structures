/*
* Grafos - Algoritmo de Dijkstra em C
* Kelvin Salton do Prado - 2015
* Complexidade: Teta(n^2)
*
* 1 para todos - Arestas de pesos não negativo - Algoritmo guloso
* Encontra o caminho mais curto de um vértice (inicio) a outro (destino)
*
* Grafo com 5 vértices e 6 arestas
*
*              6
*   (0)-----------------(1)
*    |                   |
* 10 |                   | 2
*    |         1         |
*   (2)-----------------(3)
*    \                  /
*   3 \                / 8
*      \              /
*       -----(4)-----
*
*  Matriz de Distância
*    0   1   2   3   4
* 0  0   6  10   -   -
* 1  6   0   -   2   -
* 2 10   -   0   1   3
* 3  -   2   1   0   8
* 4  -   -   3   8   0
*
*  Para valores infinitos será considerado o valor: 4294967295
* O objetivo é sair do ponto inicial (0) e chegar ao destino (4) pelo caminho mais curto
* Resposta: (0)->(1)->(3)->(2)->(4) = 12
*
*/

#include <stdio.h>

#define nroVertices 5 // Define uma constante 5 que é a quantidade de vértices do grafo

// Algoritmo de Dijkstra recebe como parâmetro a matriz de distância e o número de vértices
void Dijkstra(unsigned long int matriz[nroVertices][nroVertices], int n){
    bool visitados[n]; // Variável que guarda true para os vértices visitados

    // O valor 'i' do for abaixo não é utilizado, pois o for serve apenas para percorrer todo o número de colunas da matriz
    for(int i = 1; i < n; i++){ // Começa em 1 pois não precisa comparar o vértice com ele mesmo

        int min = -1; // Variável que guarda a posição do menor valor, inicia em -1 pois é uma posição inválida
        unsigned long int MinValor = 4294967295; // Variável que guarda o menor valor encontrado, inicia com 'infinito', assim, sempre na primeira passada o valor será menor que esta variável

        // For que percorre todas as linhas na coluna [0]
        for(int j = 1; j < n; j++){
            // Se o vertice ainda não foi visitado e o valor for menor que o 'MinValor'
            if( !visitados[j] && matriz[j][0] < MinValor ){
                   min = j; // Guarda a posição do menor
                   MinValor = matriz[j][0]; // Guarda o menor valor
            }
          }

          visitados[min] = true; // Marca o valor a posição do minimo como visitado

        // For de 1 até n
          for(int j = 1; j < n; j++){
               // Se o valor da coluna [0] + o valor da coluna que está passando for menor que o valor da linha que está passando e coluna [0]
               // Atualiza a primeira coluna da matriz, que será utilizado para as próximas iterações
               if( (matriz[min][0] + matriz[min][j]) < matriz[j][0] ){
                matriz[j][0] = matriz[min][0] + matriz[min][j];
               }
          }
    }
}

int main(){

    unsigned long int Matriz[nroVertices][nroVertices] = {{          0,          6,         10, 4294967295, 4294967295 },
                                                          {          6,          0, 4294967295,          2, 4294967295 },
                                                          {         10, 4294967295,          0,          1,          3 },
                                                          { 4294967295,          2,          1,          0,          8 },
                                                          { 4294967295, 4294967295,          3,          8,          0 }};

    Dijkstra(Matriz, nroVertices);

    printf("Total caminho mais curto do vertice 0 ao 4: %lu\n", Matriz[4][0]); // Caminho total mais curto

    // Da print na matriz com os valores atualizados
    printf("Matriz:\n");
    for (int i = 0; i < nroVertices; ++i){
        for (int e = 0; e < nroVertices; ++e){
            if( Matriz[i][e] < 10 )
                printf(" %lu ", Matriz[i][e]);
            else
                printf("%lu ", Matriz[i][e]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
