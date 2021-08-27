//Implementação de busca com sentinela feita utilizando Javascript.

function sentinelSearch(array, wantedValue) {
    array.push(wantedValue);
    let index = 0;

    while (array[index] != wantedValue) {
        index++;
    }

    if (index == array.length - 1) {
        return -1;
    } else {
        return index;
    }
}

function main() {
    array = [32,45,31,87,32,12,76,32,16,47,54,90];
    wantedValue = 54;

    foundIndex = sentinelSearch(array, wantedValue);

    if (foundIndex >= 0) {
        console.log(`Valor encontrado no índice "${ foundIndex }".`)
    }else {
        console.log("Valor não encontrado.")
    }
}

main();
