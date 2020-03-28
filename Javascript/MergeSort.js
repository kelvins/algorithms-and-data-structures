function mergeSort(vetorDesordenado, inicio, fim){
	let quantidadeDePosicoes = fim - inicio;

	if(quantidadeDePosicoes > 1){
		let miolo = (inicio + fim) / 2;

		mergeSort(vetorDesordenado, inicio, miolo);
		mergeSort(vetorDesordenado, miolo, fim);
		intercalaVetorOrdenadoEmDuasPartes(vetorDesordenado, inicio, miolo, fim);
	}

	return vetorDesordenado;
}

function intercalaVetorOrdenadoEmDuasPartes(vetorOrdenadoEmDuasPartes, inicio, miolo, termino){
	let vetorIntercalado = [];

	let posicaoVetorIntercalado = 0;
	let posicaoPrimeiroVetor = inicio;
	let posicaoSegundoVetor = miolo;

	while(posicaoPrimeiroVetor < miolo && posicaoSegundoVetor < termino){
		let valorPrimeiroVetor = vetorOrdenadoEmDuasPartes[posicaoPrimeiroVetor];
		let valorSegundoVetor = vetorOrdenadoEmDuasPartes[posicaoSegundoVetor];

		if(valorPrimeiroVetor < valorSegundoVetor){
			vetorIntercalado[posicaoVetorIntercalado] = valorPrimeiroVetor;
			posicaoPrimeiroVetor++;
		}else{
			vetorIntercalado[posicaoVetorIntercalado] = valorSegundoVetor;
			posicaoSegundoVetor++;
		}	
		posicaoVetorIntercalado++;
	}

	while(posicaoPrimeiroVetor < miolo){
		vetorIntercalado[posicaoVetorIntercalado++] = vetorOrdenadoEmDuasPartes[posicaoPrimeiroVetor++];
	}

	while(posicaoSegundoVetor < termino){
		vetorIntercalado[posicaoVetorIntercalado++] = vetorOrdenadoEmDuasPartes[posicaoSegundoVetor++];
	}

	for (var i = 0; i < posicaoVetorIntercalado; i++) {
		vetorOrdenadoEmDuasPartes[inicio + i] = vetorIntercalado[i];
	}
}

var vetorDesordenado = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaMergeSort = mergeSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaMergeSort);