/*
* Grafos - Algoritmo de Dijkstra em JavaScript
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

const nVertices = 5; // Define uma constante 5 que é a quantidade de vértices do grafo

// Algoritmo de Dijkstra recebe como parâmetro a matriz de distância e o número de vértices
function Dijkstra(matrix, n) {
    let visitados = new Array(n); // Variável que guarda true para os vértices visitados

    // O valor 'i' do for abaixo não é utilizado, pois o for serve apenas para percorrer todo o número de colunas da matriz
    for (let i = 1; i < n; i++) { // Começa em 1 pois não precisa comparar o vértice com ele mesmo
        let min, minValue;

        // For que percorre todas as linhas na coluna [0]
        for (let j = 1; j < n; j++) {
            // Se o vertice ainda não foi visitado e o valor for menor que o 'MinValor'
            if (!visitados[j] && (!minValue || matrix[j][0] < minValue)) {
                min = j; // Guarda a posição do menor
                minValue = matrix[j][0]; // Guarda o menor valor
            }
        }

        visitados[min] = true; // Marca o valor a posição do minimo como visitado

        // For de 1 até n
        for (let j = 1; j < n; j++) {
            // Se o valor da coluna [0] + o valor da coluna que está passando for menor que o valor da linha que está passando e coluna [0]
            // Atualiza a primeira coluna da matriz, que será utilizado para as próximas iterações

            if (matrix[min][0] + matrix[min][j] < matrix[j][0]) {
                matrix[j][0] = matrix[min][0] + matrix[min][j];
            }
        }
    }
}

function main() {
    let matrix = [];
    let ignore = 4294967295; 
    matrix.push([0, 6, 10, ignore, ignore]);
    matrix.push([6, 0, ignore, 2, ignore]);
    matrix.push([10, ignore, 0, 1, 3]);
    matrix.push([ignore, 2, 1, 0, 8]);
    matrix.push([ignore, ignore, 3, 8, 0]);
    console.table(matrix)

    Dijkstra(matrix, nVertices);

    console.log("Total caminho mais curto do vertice 0 ao 4: ", matrix[4][0]); // Caminho total mais curto

    // Da print na matriz com os valores atualizados
    console.log("Matriz:");
    console.table(matrix);
}

main();