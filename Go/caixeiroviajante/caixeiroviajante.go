/*
 * O Problema do Caixeiro Viajante (PCV) eh um problema que tenta determinar a
 * menor rota para percorrer uma serie de cidades (visitando uma unica vez cada
 * uma delas), retornando a cidade de origem.
 *
 * Utilizando uma matriz de distancia para representar um grafo nao direcionado.
 *
 * Supondo que temos o seguinte grafo:
 *
 *               6
 *      -------------------
 *     |    3         1    |
 *   (000)-----(001)-----(002)
 *     | \     / | \     / |
 *     |  \  6/  |  \2  /  |
 *     |   \ /   |   \ /   |
 *    2|    /   8|    /    |5
 *     |   / \   |   / \   |
 *     |  /  3\  |  /4  \  |
 *     | /     \ | /     \ |
 *   (003)-----(004)-----(005)
 *     |    6         4    |
 *      -------------------
 *               1
 *
 *      Matriz de Distancia
 *       0  1  2  3  4  5
 *    0  0  3  6  2  3  -
 *    1  3  0  1  6  8  2
 *    2  6  1  0  -  4  5
 *    3  2  6  -  0  6  1
 *    4  3  8  4  6  0  4
 *    5  -  2  5  1  4  0
 *
 * Melhor solucao:
 * 0 - 3 - 5 - 1 - 2 - 4 - 0: 13
 */

package caixeiroviajante

import "fmt"

const vertices = 6
const infinito = 99999999

var matrizDistancia [][]int

var tempSolucao   []int  // Solucao temporaria
var melhorSolucao []int  // Melhor solucao
var visitados     []bool // Vertices visitados

var valorMelhorSolucao int
var valorSolucaoAtual  int

func caixeiroViajanteAux(x int) {

  // Significa que ja nao eh mais a melhor solucao podemos parar por aqui
  if valorSolucaoAtual > valorMelhorSolucao {
    return
  }

  // Significa que o vetor da solucao temporaria esta completo
  if x == vertices {
    distancia := matrizDistancia[tempSolucao[x-1]][tempSolucao[0]]

    // Significa que encontrou uma solucao melhor
    if distancia < infinito && (valorSolucaoAtual + distancia) < valorMelhorSolucao {

      // Temos uma solucao melhor
      valorMelhorSolucao = valorSolucaoAtual + distancia

      // Copia todo o vetor para a melhor solucao
      for i := 0; i < vertices; i++ {
        melhorSolucao[i] = tempSolucao[i]
      }
    }
    return
  }

  // Ultimo vertice que se encontra na solucao temporaria
  ultimo := tempSolucao[x-1]

  // Percorre todas as colunas da matriz de distancia na linha do ultimo vertice
  for i := 0; i < vertices; i++ {

    // Se a posicao ainda nao foi visitada e o valor da matriz eh menor que infinito
    if visitados[i] == false && matrizDistancia[ultimo][i] < infinito {
      // Marque a posicao como visitada
      visitados[i] = true
      // Carrega o vertice atual na solucao temporaria
      tempSolucao[x] = i
      // Incrementa o total do caminho percorrido com base na posicao da matriz
      valorSolucaoAtual = valorSolucaoAtual + matrizDistancia[ultimo][i]
      // Chama recursivamente para o proximo vertice
      caixeiroViajanteAux(x+1)
      // Se ainda nao terminou decrementa o valor da variabel que guarta o total do caminho
      valorSolucaoAtual = valorSolucaoAtual - matrizDistancia[ultimo][i]
      // Define como nao visitada para poder ser acessada por outro vertice
      visitados[i] = false
    }
  }
}

func caixeiroViajante(posicaoInicial int) {
  // Verifica se a posicao eh valida
  if posicaoInicial < vertices {
    visitados[posicaoInicial] = true // Marca o primeiro vertice como visitado
    tempSolucao[0] = posicaoInicial  // Coloca a posicao inicial na primeira posicao da solucao temporaria
    caixeiroViajanteAux(1)           // Chama o metodo auxiliar do caixeiro viajante
  } else {
    fmt.Println("Vertice inicial invalid")
  }
}

// Inicia os vetores e valores padrao
func inicia() {

  valorMelhorSolucao = infinito
  valorSolucaoAtual  = 0

  for i := 0; i < vertices; i++ {
    visitados     = append(visitados,  false)
    tempSolucao   = append(tempSolucao,   -1)
    melhorSolucao = append(melhorSolucao, -1)
  }

  // Cria a matriz de distancia
  linha0 := []int{       0, 3,        6,        2, 3, infinito}
  linha1 := []int{       3, 0,        1,        6, 8,        2}
  linha2 := []int{       6, 1,        0, infinito, 4,        5}
  linha3 := []int{       2, 6, infinito,        0, 6,        1}
  linha4 := []int{       3, 8,        4,        6, 0,        4}
  linha5 := []int{infinito, 2,        5,        1, 4,        0}

  matrizDistancia = append(matrizDistancia, linha0)
  matrizDistancia = append(matrizDistancia, linha1)
  matrizDistancia = append(matrizDistancia, linha2)
  matrizDistancia = append(matrizDistancia, linha3)
  matrizDistancia = append(matrizDistancia, linha4)
  matrizDistancia = append(matrizDistancia, linha5)
}

// Funcao que roda o exemplo do caixeiro viajante
func Run() {
  inicia()
  caixeiroViajante(0)

  fmt.Println("\nCaixeiro Viajante")
  fmt.Println("Caminho minimo:", valorMelhorSolucao)
  for i := 0; i < vertices; i++ {
    fmt.Print(melhorSolucao[i], ", ")
  }
  fmt.Print(melhorSolucao[0])
  fmt.Println("\n")
}
