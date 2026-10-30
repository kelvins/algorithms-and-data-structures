public class HeapSort {

  /**
   * @param array array to be sorted; applies Heap Sort to the array
   */
  public int[] sort(int[] array) {

    for (int i = array.length / 2 - 1; i >= 0; i--) {
      heapify(array, array.length, i);
    }

    for (int i = array.length - 1; i >= 0; i--) {

      int temp = array[0];
      array[0] = array[i];
      array[i] = temp;

      heapify(array, i, 0);
    }
    return array;
  }

  void heapify(int arr[], int arrayLength, int rootElementIndex) {

    int leftIndex = 2 * rootElementIndex + 1;
    int rightIndex = 2 * rootElementIndex + 2;

    int largest = rootElementIndex;

    if (leftIndex < arrayLength && arr[leftIndex] > arr[largest]) largest = leftIndex;

    if (rightIndex < arrayLength && arr[rightIndex] > arr[largest]) largest = rightIndex;

    if (largest != rootElementIndex) {

      int swap = arr[rootElementIndex];
      arr[rootElementIndex] = arr[largest];
      arr[largest] = swap;

      heapify(arr, arrayLength, largest);
    }
  }
}
