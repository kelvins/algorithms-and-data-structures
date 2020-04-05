function shellSort(vetorDesordenado, inicio, fim){
    let distancia = 1;

    while(distancia < fim){
        distancia = (distancia*3) + 1;
    }

    distancia = parseInt(distancia/3);

    let j;
    while(distancia>0){
        for(let i = distancia; i< fim; i+=1){
            j = i;
            while(j>= distancia && vetorDesordenado[j - distancia] > vetorDesordenado[j]){
                [vetorDesordenado[j - distancia], vetorDesordenado[j]] = [vetorDesordenado[j], vetorDesordenado[j - distancia]];
            }
        }
        distancia = distancia/2;

    }

    return vetorDesordenado;
}

var vetorDesordenado  = [54,42,11,33,24,99,77,80];
let vetorOrdenadoViaShellSort = shellSort(vetorDesordenado, 0, vetorDesordenado.length);

console.log(vetorOrdenadoViaShellSort);