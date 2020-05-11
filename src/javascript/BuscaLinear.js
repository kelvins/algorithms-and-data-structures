function buscaLinear(vetor, valorBuscado){
    for(let i = 0; i < vetor.length; i++){
        if(vetor[i] == valorBuscado){
            return i;
        }
    }
    return -1;
}

var vetor = [54,42,11,33,24,99,77,80];
console.log(buscaLinear(vetor, 11));
