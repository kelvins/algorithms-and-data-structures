public class RadixSort {

  /**
   * @param array array to be sorted; applies Radix Sort to the array
   */
  public int[] sort(int[] array) {
    int length = array.length, i, exp = 1, higher = array[0];
    int[] temp = new int[10];

    for (i = 1; i < length; i++) if (array[i] > higher) higher = array[i];

    while (higher / exp > 0) {
      int[] bucket = new int[10];

      for (i = 0; i < length; i++) bucket[(array[i] / exp) % 10]++;

      for (i = 1; i < 10; i++) bucket[i] += bucket[i - 1];

      for (i = length - 1; i >= 0; i--) temp[--bucket[(array[i] / exp) % 10]] = array[i];

      for (i = 0; i < length; i++) array[i] = temp[i];

      exp = exp * 10;
    }
    return array;
  }
}
