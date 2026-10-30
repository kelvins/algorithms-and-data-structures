public class TestMergeSort {
  public static void main(String[] args) {
    int[] testArray = {10, 8, 6, 4, 2, 0, 1, 3, 5, 7, 9};
    MergeSort order = new MergeSort();
    order.sort(testArray, 0, testArray.length - 1);
    for (int i = 0; i < testArray.length; i++) {
      System.out.print(testArray[i] + " ");
    }
  }
}
