function combSort(unsortedArray, start, end) {
    let gap = end;
    let swapped;

    do {
        swapped = false;
        gap = parseInt(gap / 1.24733095);

        for (let i = start; i < end - gap; i++) {
            if (unsortedArray[i] > unsortedArray[i + gap]) {
                [unsortedArray[i], unsortedArray[i + gap]] = [unsortedArray[i + gap], unsortedArray[i]];
                swapped = true;
            }
        }
    } while (gap > 1 || swapped);

    return unsortedArray;
}

var unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
let sortedArrayViaCombSort = combSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaCombSort);