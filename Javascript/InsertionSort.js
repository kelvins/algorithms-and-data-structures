//Diogo L.C. Felipe
//diogomem@outlook.com

/*
	O Insertion Sort, ou algoritomo de ordenação por inserção ordena uma serie de dados
	da seguinte maneira:
		1. Varre o vetor da segunda posição em diante;
		2. Compara o valor que está sendo analisado com o valor anterior:
			caso seja menor, troca os dois valores e compara novamente com o anterior.
			caso seja maior, segue a análise para o próximo elemento não analisado do vetor.
*/

function insertionSort(vetorDesordenado, inicio, fim){

		for (var i = inicio + 1; i < fim; i++) {

			let posicaoAnalise = i;
		
			while(posicaoAnalise > 0 && vetorDesordenado[posicaoAnalise] < vetorDesordenado[posicaoAnalise -1]){
				trocaPosicao(vetorDesordenado, posicaoAnalise, posicaoAnalise - 1);
				posicaoAnalise--;
			}
		}
	return vetorDesordenado;
}

function trocaPosicao(vetor, posicaoPrimeiro, posicaoSegundo){
	let primeiroValor = vetor[posicaoPrimeiro];
	let segundoValor = vetor[posicaoSegundo];

	vetor[posicaoPrimeiro] = segundoValor;
	vetor[posicaoSegundo] = primeiroValor;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaInsertionSort = insertionSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaInsertionSort);