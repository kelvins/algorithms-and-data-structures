// Implementation of sentinel search using JavaScript.

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
    array = [32, 45, 31, 87, 32, 12, 76, 32, 16, 47, 54, 90];
    wantedValue = 54;

    foundIndex = sentinelSearch(array, wantedValue);

    if (foundIndex >= 0) {
        console.log(`Value found at index "${foundIndex}".`)
    } else {
        console.log("Value not found.")
    }
}

main();

