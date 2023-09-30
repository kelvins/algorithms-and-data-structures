
/*
   Selection Sort, or the selection sort algorithm, sorts a series of data
   as follows:
      1. Finds the smallest value in the array starting from position 'i';
      2. Swaps this value with the value at position 'i';
      3. Increments the starting position (i = i + 1);
      4. Repeats the algorithm until the penultimate position of the array.
*/

function selectionSort(unsortedArray, start, end) {

	for (let i = start; i < end - 1; i++) {
	   let smallestPosition = findSmallestPosition(unsortedArray, i, end);
	   [unsortedArray[smallestPosition], unsortedArray[i]] = [unsortedArray[i], unsortedArray[smallestPosition]];
	}
 
	return unsortedArray;
 }
 
 function findSmallestPosition(unsortedArray, start, end) {
	let smallestPosition = start;
	let smallest = unsortedArray[start];
 
	for (let i = start; i < end; i++) {
	   if (unsortedArray[i] < smallest) {
		  smallest = unsortedArray[i];
		  smallestPosition = i;
	   }
	}
	return smallestPosition;
 }
 
 var unsortedArray = [54, 42, 11, 33, 24, 99, 77, 80];
 let sortedArrayViaSelectionSort = selectionSort(unsortedArray, 0, unsortedArray.length);
 
 console.log(sortedArrayViaSelectionSort);
 