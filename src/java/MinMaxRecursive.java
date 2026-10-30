public class MinMaxRecursive {

  public static void main(String[] args) {
    int[] arr = {9, 8, 13, 33, 18, 20, 88, 14, 40, 77};
    minMax(arr, arr[0], arr[0], 0);
  }

  public static void minMax(int vect[], int minimum, int maximum, int index) {
    if (vect[index] < minimum) {
      minimum = vect[index];
    }
    if (vect[index] > maximum) {
      maximum = vect[index];
    }
    if (index < vect.length - 1) {
      minMax(vect, minimum, maximum, index + 1);
    } else {
      System.out.println("Minimum: " + minimum + "\nMaximum: " + maximum);
    }
  }
}
