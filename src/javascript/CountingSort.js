function countingSort(arr) {
    // Find the maximum element in the array to determine the range
    let max = Math.max(...arr);

    // Create a count array to store the count of each element
    let count = new Array(max + 1).fill(0);

    // Count the occurrences of each element in the input array
    for (let i = 0; i < arr.length; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the actual position of each element
    for (let i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a new output array and store the elements in their sorted order
    let output = new Array(arr.length);
    for (let i = arr.length - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return output;
}

const arr = [4, 2, 2, 8, 3, 3, 1];
const sortedArr = countingSort(arr);
console.log("Original array:", arr);
console.log("Sorted array:", sortedArr);
