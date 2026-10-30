public class ShellSort {

  /**
   * Apply Shell Sort to the array
   *
   * @param array array to be sorted
   */
  public int[] sort(int[] array) {
    int i, j, h = 1, temp;

    do {
      h = 3 * h + 1;
    } while (h < array.length);

    do {
      h /= 3;

      for (i = h; i < array.length; i++) {
        temp = array[i];
        j = i - h;
        while (j >= 0 && temp < array[j]) {
          array[j + h] = array[j];
          j -= h;
        }
        array[j + h] = temp;
      }
    } while (h > 1);
    return array;
  }
}
