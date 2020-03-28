function burbbleSort(vetorDesordenado, inicio, fim) {
	let trocado;

	do{
		trocado = false;
		for (var i = inicio; i < fim - 1; i++) {
			if(vetorDesordenado[i] > vetorDesordenado[i+1]){
				trocaPosicao(vetorDesordenado, i, i+1);
				trocado = true;
			}
		}
	}while(trocado);

	return vetorDesordenado;
}

function trocaPosicao(vetor, posicaoPrimeiro, posicaoSegundo){
	let primeiroValor = vetor[posicaoPrimeiro];
	let segundoValor = vetor[posicaoSegundo];

	vetor[posicaoPrimeiro] = segundoValor;
	vetor[posicaoSegundo] = primeiroValor;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaBurbbleSort = burbbleSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaBurbbleSort);