function buscaLinear(vetor, valorBuscado, inicio, fim){
    let posicao = -1;

    if(inicio > fim){
        return posicao;
    }

    for(let i = inicio; i < fim; i++){
        if(vetor[i] == valorBuscado){
            posicao = i;
        }
    }
    return posicao;
}

var vetor = [54,42,11,33,24,99,77,80];
console.log(buscaLinear(vetor, 11, 0, vetor.length));
