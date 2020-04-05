//Diogo L.C. Felipe
//diogomem@outlook.com

/*
	O Selection Sort, ou algoritomo de ordenação por seleção ordena uma serie de dados
	da seguinte maneira:
		1. Acha o menor valor no vetor a partir da posição 'i';
		2. Troca esse valor com o valor que está na posição 'i';
		3. Soma 1 na posição de inicio (i = i + 1);
		4. Repete o algorítimo até a penultima posição do verto. 
*/

function selectionSort(vetorDesordenado, inicio, fim) {

	for (let i = inicio; i < fim - 1; i++) {
		let menorPosicao = buscaPosicaoMenor(vetorDesordenado, i, fim);
		[vetorDesordenado[menorPosicao], vetorDesordenado[i]] = [vetorDesordenado[i], vetorDesordenado[menorPosicao]];
	}

	return vetorDesordenado;
}

function buscaPosicaoMenor(vetorDesordenado, inicio, termino){
	let posicaoMenor = inicio;
	let menor = vetorDesordenado[inicio]

	for (let i = inicio; i < termino; i++) {
		if(vetorDesordenado[i] < menor){
			menor = vetorDesordenado[i];
			posicaoMenor = i;
		}
	}
	return posicaoMenor;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaSelectionSort = selectionSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaSelectionSort);