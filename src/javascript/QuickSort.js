function quickSort(unsortedArray, start, end){
	let numPositions = end - start;

	if(numPositions > 1){
		let pivotPosition = partition(unsortedArray, start, end);
		quickSort(unsortedArray, start, pivotPosition);
		quickSort(unsortedArray, pivotPosition + 1, end);
	}

	return unsortedArray;
}

function partition(array, start, end){
	let pivot = array[end - 1];
	let foundSmaller = 0;

	for (var i = start; i < end - 1; i++) {
		if(array[i] <= pivot){
			[array[i], array[foundSmaller]] = [array[foundSmaller], array[i]];
			foundSmaller++;
		}
	}

	[array[end - 1], array[foundSmaller]] = [array[foundSmaller], array[end - 1]];
	return foundSmaller;
}

var unsortedArray = [54,42,11,33,24,99,77,80];

let sortedArrayViaQuickSort = quickSort(unsortedArray, 0, unsortedArray.length);

console.log(sortedArrayViaQuickSort);
