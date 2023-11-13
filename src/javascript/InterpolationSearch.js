/**
 * @description Interpolation Search
 * @reference https://en.wikipedia.org/wiki/Interpolation_search
 */

/**
 * @param {Array} arr - Array of elements to be searched
 * @param {Array} first - First index of the array
 * @param {Array} last - Last index of the array
 * @param {Number} value - Value to be searched
 * @return {Number} - Index of the searched element or -1 if not found
 * @throws {Error} - If the array is empty
 */
const interpolationSearch = (arr, first, last, value) => {
  let pos;
  if (first <= last && value >= arr[first] && value <= arr[last]) {
    pos = first + Math.floor((last - first) * (value - arr[first]) / (arr[last] - arr[first]));
    if (arr[pos] === value)
      return pos;
    else if (arr[pos] < value)
      return interpolationSearch(arr, pos + 1, last, value);
    else
      return interpolationSearch(arr, first, pos - 1, value);
  }
  return -1;
}

const main = () => {
  // The array needs to be sorted
  const arr = [10, 12, 13, 16, 18, 19, 20, 21,
    22, 23, 24, 33, 35, 42, 47];
  let n = arr.length;

  // Searching for the value 18
  let x = 18
  let index = interpolationSearch(arr, 0, n - 1, x);

  if (index !== -1)
    console.log(`Index of the searched element: ${index}`);
  else
    console.log("Element not found");
}

main();
