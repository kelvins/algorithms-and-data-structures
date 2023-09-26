//Diogo L.C. Felipe
//diogomem@outlook.com

/*
   Insertion Sort is a sorting algorithm that works as follows:
   1. It iterates through the array from the second position onward.
   2. Compares the current value with the previous one:
      - If it's smaller, it swaps the two values and continues comparing with the previous one.
      - If it's larger, it proceeds to analyze the next unsorted element in the array.
*/

function insertionSort(unsortedArray, start, end) {
    for (var i = start + 1; i < end; i++) {
        let currentPosition = i;

        while (currentPosition > 0 && unsortedArray[currentPosition] < unsortedArray[currentPosition - 1]) {
            swapPositions(unsortedArray, currentPosition, currentPosition - 1);
            currentPosition--;
        }
    }
    return unsortedArray;
}

function swapPositions(array, firstPosition, secondPosition) {
    let firstValue = array[firstPosition];
    let secondValue = array[secondPosition];

    array[firstPosition] = secondValue;
    array[secondPosition] = firstValue;
}

var unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
let sortedArrayViaInsertionSort = insertionSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaInsertionSort);