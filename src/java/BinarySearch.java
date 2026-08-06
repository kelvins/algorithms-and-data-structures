public class BinarySearch {

  public int position;

  BinarySearch(int[] array, int target) {
    this.position = binarySearch(target, array);
  }

  public int getResult() {
    return this.position;
  }

  public int binarySearch(int target, int[] array) {
    int start = 0;
    int end = array.length - 1;

    while (start <= end) {
      int middle = start + (end - start) / 2;
      if (array[middle] == target) return middle;
      if (array[middle] < target) start = middle + 1;
      else end = middle - 1;
    }
    return -1;
  }
}
