function shellSort(unsortedArray, start, end) {
    let gap = 1;

    while (gap < end) {
        gap = gap * 3 + 1;
    }

    gap = parseInt(gap / 3);

    let j;
    while (gap > 0) {
        for (let i = gap; i < end; i += 1) {
            j = i;
            while (j >= gap && unsortedArray[j - gap] > unsortedArray[j]) {
                [unsortedArray[j - gap], unsortedArray[j]] = [unsortedArray[j], unsortedArray[j - gap]];
            }
        }
        gap = gap / 2;
    }

    return unsortedArray;
}

var unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
let sortedArrayViaShellSort = shellSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaShellSort);