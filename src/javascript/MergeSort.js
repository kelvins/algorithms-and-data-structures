function mergeSort(unsortedArray, start, end) {
    let numberOfPositions = end - start;

    if (numberOfPositions > 1) {
        let middle = Math.floor((start + end) / 2);

        mergeSort(unsortedArray, start, middle);
        mergeSort(unsortedArray, middle, end);
        mergeTwoSortedArrays(unsortedArray, start, middle, end);
    }

    return unsortedArray;
}

function mergeTwoSortedArrays(sortedArray, start, middle, end) {
    let mergedArray = [];

    let mergedArrayPosition = 0;
    let firstArrayPosition = start;
    let secondArrayPosition = middle;

    while (firstArrayPosition < middle && secondArrayPosition < end) {
        let firstArrayValue = sortedArray[firstArrayPosition];
        let secondArrayValue = sortedArray[secondArrayPosition];

        if (firstArrayValue < secondArrayValue) {
            mergedArray[mergedArrayPosition] = firstArrayValue;
            firstArrayPosition++;
        } else {
            mergedArray[mergedArrayPosition] = secondArrayValue;
            secondArrayPosition++;
        }
        mergedArrayPosition++;
    }

    while (firstArrayPosition < middle) {
        mergedArray[mergedArrayPosition++] = sortedArray[firstArrayPosition++];
    }

    while (secondArrayPosition < end) {
        mergedArray[mergedArrayPosition++] = sortedArray[secondArrayPosition++];
    }

    for (let i = 0; i < mergedArrayPosition; i++) {
        sortedArray[start + i] = mergedArray[i];
    }
}

let unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
let sortedArrayViaMergeSort = mergeSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaMergeSort);