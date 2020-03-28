function quickSort(vetorDesordenado, inicio, fim){
	let quantidadeDePosicoes = fim - inicio;

	if(quantidadeDePosicoes > 1){
		let posicaoDoPivo = particiona(vetorDesordenado, inicio, fim);
		quickSort(vetorDesordenado, inicio, posicaoDoPivo);
		quickSort(vetorDesordenado, posicaoDoPivo + 1, fim);
	}

	return vetorDesordenado;
}

function particiona(vetor, inicio, fim){
	let pivo = vetor[fim - 1];
	let menoresEncontrados = 0;

	for (var i = 0; i < fim - 1; i++) {

		if(vetor[i] <= pivo){
			trocaPosicao(vetor, i, menoresEncontrados);
			menoresEncontrados++;
		}
	}

	trocaPosicao(vetor, fim - 1, menoresEncontrados);
	return menoresEncontrados;
}

function trocaPosicao(vetor, posicaoPrimeiro, posicaoSegundo){
	let primeiroValor = vetor[posicaoPrimeiro];
	let segundoValor = vetor[posicaoSegundo];

	vetor[posicaoPrimeiro] = segundoValor;
	vetor[posicaoSegundo] = primeiroValor;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];

let vetorOrdenadoViaQuickSort = quickSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaQuickSort);
