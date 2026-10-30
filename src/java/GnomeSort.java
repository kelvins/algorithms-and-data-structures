import java.util.Arrays;

public class GnomeSort {
  public static void main(String[] args) {
    int array[] = {10, -10, -9, 9, 8, -8, 7, -7, 6, -6, 5, -5, 4, -4, 3, -3, 2, -2, 1, -1, 0};
    System.out.println("Array before sorting: " + Arrays.toString(array));

    gnomeSort(array);
    System.out.println("Array after sorting with Gnome Sort: " + Arrays.toString(array));
  }

  static void gnomeSort(int[] array) {
    int i = 0;
    while (i < array.length) {
      if (i == 0 || array[i] >= array[i - 1]) {
        i++;

      } else {
        int helper = array[i];
        array[i] = array[i - 1];
        array[i - 1] = helper;

        i--;
      }
    }
  }
}
