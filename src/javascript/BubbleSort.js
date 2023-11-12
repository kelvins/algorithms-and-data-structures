function bubbleSort(unsortedArray, start, end) {
    let swapped;

    do {
        swapped = false;
        for (var i = start; i < end - 1; i++) {
            if (unsortedArray[i] > unsortedArray[i + 1]) {
                [unsortedArray[i], unsortedArray[i + 1]] = [unsortedArray[i + 1], unsortedArray[i]];
                swapped = true;
            }
        }
    } while (swapped);

    return unsortedArray;
}

var unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
let sortedArrayViaBubbleSort = bubbleSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaBubbleSort);