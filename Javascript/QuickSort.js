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
			[vetorDesordenado[i], vetorDesordenado[menoresEncontrados]] = [vetorDesordenado[menoresEncontrados], vetorDesordenado[i]];
			menoresEncontrados++;
		}
	}

	[vetorDesordenado[fim - 1], vetorDesordenado[menoresEncontrados]] = [vetorDesordenado[menoresEncontrados], vetorDesordenado[fim - 1]];
	return menoresEncontrados;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];

let vetorOrdenadoViaQuickSort = quickSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaQuickSort);
