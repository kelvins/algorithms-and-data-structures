function combSort(vetorDesordenado, inicio, fim){
    let distancia = fim;
    let trocado;

    do{
        trocado = false;
        distancia = parseInt(distancia/1.24733095);

        for(let i = inicio; i < fim-distancia; i++){
            if(vetorDesordenado[i] > vetorDesordenado[i+distancia]){
                [vetorDesordenado[i], vetorDesordenado[i+distancia]] = [vetorDesordenado[i+distancia], vetorDesordenado[i]];
                trocado = true;
            }
        }
    }while(distancia > 1 || trocado);

    return vetorDesordenado;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaCombSort = combSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaCombSort);
