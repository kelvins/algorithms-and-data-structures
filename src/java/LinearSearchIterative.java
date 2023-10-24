public class LinearSearchIterative {
  public static void main(String[] args) {
    int array_1[] = {1, 2, 40, 233, 78, 83, 456};
    System.out.println(LinearSearch(array_1, 40));
    System.out.println(LinearSearch(array_1, 3));
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
