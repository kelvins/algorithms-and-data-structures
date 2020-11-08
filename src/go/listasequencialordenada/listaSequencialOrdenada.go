/*
* Listas - Lista linear ordenada
* Danilo Moura - 2020
*
* Implementação da lista sequencial cujos elementos estão ordenados
*
* link Go PlayGround: https://play.golang.org/p/J6Jbi2_FWJk
 */

package main

import "fmt"

var maxSize = 50
 
// Estrura que será guardada em cada posição da lista
type Registro struct {
	valor int
	// Outros campos podem ser adicionados aqui
}
 
// Estrutura que guarda um arranjo de Registro, e o número de elementos no arranjo
type Lista struct {
	arranjoRegistros []Registro
	numeroElementos  int
}
 
// Cria uma nova lista
func criarLista() Lista {
	lista := Lista{
		arranjoRegistros: make([]Registro, maxSize),
		numeroElementos:  0,
	}

	return lista
}
 
// reseta o contador de elementos da lista
func inicializar(lista *Lista) {
	lista.numeroElementos = 0
}
 
// Recupera a quantidade de elementos da lista
func tamanho(lista *Lista) int {
	return lista.numeroElementos
}
 
// Imprime valores dos elementos na lista
func imprimir(lista *Lista) {
	for i := 0; i < lista.numeroElementos; i++ {
		fmt.Printf("%v ", lista.arranjoRegistros[i].valor)
	}
	fmt.Println()
}

// Realiza busca binária na lista
func buscaBinaria(lista *Lista, valor int) int {
	esquerda := 0
	direita := lista.numeroElementos - 1

	for esquerda <= direita {
		meio := ((esquerda + direita) / 2)
		if lista.arranjoRegistros[meio].valor == valor {
			return meio
		} else {
			if lista.arranjoRegistros[meio].valor < valor {
				esquerda = meio + 1
			} else {
				direita = meio - 1
			}
		}
	}

	return -1
}
 
// Insere elementos na lista em ordem crescente, garantindo com a lista esteja sempre ordenada
func insereRegistroOrdenado(lista *Lista, registro Registro) bool {
	if lista.numeroElementos == maxSize {
		return false
	}

	posicao := lista.numeroElementos

	for posicao > 0 && lista.arranjoRegistros[posicao-1].valor > registro.valor {
		lista.arranjoRegistros[posicao] = lista.arranjoRegistros[posicao-1]
		posicao--
	}

	lista.arranjoRegistros[posicao] = registro
	lista.numeroElementos++

	return true
}

// Exclui um elemento da lista
func excluirElemento(lista *Lista, valor int) bool {
	posicao := buscaBinaria(lista, valor)

	if posicao == -1 {
		return false
	}

	for i := posicao; i < lista.numeroElementos-1; i++ {
		lista.arranjoRegistros[i] = lista.arranjoRegistros[i+1]
	}

	lista.numeroElementos--

	return true
}

func main() {
	lista := criarLista()

	inicializar(&lista)

	fmt.Println("Inserindo valores na lista...")
	insereRegistroOrdenado(&lista, Registro{valor: 20})
	insereRegistroOrdenado(&lista, Registro{valor: 10})
	insereRegistroOrdenado(&lista, Registro{valor: 70})
	insereRegistroOrdenado(&lista, Registro{valor: 30})
	insereRegistroOrdenado(&lista, Registro{valor: 60})
	insereRegistroOrdenado(&lista, Registro{valor: 90})
	insereRegistroOrdenado(&lista, Registro{valor: 80})
	insereRegistroOrdenado(&lista, Registro{valor: 15})
	insereRegistroOrdenado(&lista, Registro{valor: 1})

	fmt.Println()
	fmt.Println("Imprimindo lista...")
	imprimir(&lista)
	fmt.Println("Tamanho da lista:", tamanho(&lista))

	fmt.Println()

	fmt.Println("Excluindo elemento 80 da lista...")
	excluirElemento(&lista, 80)

	fmt.Println()
	fmt.Println("Imprimindo lista...")
	imprimir(&lista)
	fmt.Println("Tamanho da lista:", tamanho(&lista))

	fmt.Println()
	fmt.Println("Buscando valores na lista:")
	fmt.Println()

	fmt.Println("Buscando posição do numero 15:")
	fmt.Printf("Posição do número 15: %v \n\n", buscaBinaria(&lista, 15))

	fmt.Println("Buscando posição do valor 100:")
	fmt.Printf("Posição do número 100: %v \n\n", buscaBinaria(&lista, 100))
}
