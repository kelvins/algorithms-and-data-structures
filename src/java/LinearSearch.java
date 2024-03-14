public class LinearSearch {
  public static void main(String[] args) {
    int array[] = {1, 2, 40, 233, 78, 83, 456};
    System.out.println(LinearSearch(array, 40));
    System.out.println(LinearSearch(array, 3));
  }

  public static int LinearSearch(int array[], int value) {
    for (int i = 0; i < array.length; i++) {
      if (array[i] == value) {
        return i;
      }
    }
    return -1;
  }
}
