/*
* Listas - Lista linear não ordenada
* Danilo Moura - 2020
*
* Implementação da lista sequencial cujos elementos não estão ordenados
*
* link Go PlayGround: https://play.golang.org/p/3uFOquVlTD8
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
 
// Realiza busca sequencial na lista, percorrendo item por item
func buscaSequencial(lista *Lista, valor int) int {
	i := 0
	for i < lista.numeroElementos {
		if valor == lista.arranjoRegistros[i].valor {
			return i
		} else {
			i++
		}
	}
	return -1
}
 
// Realiza busca sentinela na lista, percorrendo item por item
func buscaSentinela(lista *Lista, valor int) int {
	i := 0
	lista.arranjoRegistros[lista.numeroElementos].valor = valor

	for valor != lista.arranjoRegistros[i].valor {
		i++
	}

	if i == lista.numeroElementos {
		return -1
	} else {
		return i
	}
}
 
// Insere elementos na lista, em uma posição específica, e move todos os outros elementos para a direita
func insereElemento(lista *Lista, registro Registro, posicao int) bool {
	if (lista.numeroElementos == maxSize) || posicao < 0 || posicao > lista.numeroElementos {
		return false
	}

	for j := lista.numeroElementos; j > posicao; j-- {
		lista.arranjoRegistros[j] = lista.arranjoRegistros[j-1]
	}

	lista.arranjoRegistros[posicao] = registro
	lista.numeroElementos++

	return true
}
 
// Exclui um elemento da lista
func excluirElemento(lista *Lista, valor int) bool {
	posicao := buscaSequencial(lista, valor)

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
	insereElemento(&lista, Registro{valor: 20}, 0)
	insereElemento(&lista, Registro{valor: 10}, 0)
	insereElemento(&lista, Registro{valor: 70}, 0)
	insereElemento(&lista, Registro{valor: 30}, 0)
	insereElemento(&lista, Registro{valor: 60}, 0)
	insereElemento(&lista, Registro{valor: 90}, 0)
	insereElemento(&lista, Registro{valor: 80}, 0)
	insereElemento(&lista, Registro{valor: 15}, 0)
	insereElemento(&lista, Registro{valor: 1}, 0)

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
	fmt.Printf("Posição do número 15: %v \n\n", buscaSequencial(&lista, 15))

	fmt.Println("Buscando posição do valor 100:")
	fmt.Printf("Posição do número 100: %v \n\n", buscaSequencial(&lista, 100))
}
