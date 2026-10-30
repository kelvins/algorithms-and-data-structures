public class MinMaxRecursivo {

  public static void main(String[] args) {
    int[] arr = {9, 8, 13, 33, 18, 20, 88, 14, 40, 77};
    MinMax(arr, arr[0], arr[0], 0);
  }

  public static void MinMax(int vect[], int minimum, int maximum, int index) {
    if (vect[index] < minimum) {
      minimum = vect[index];
    }
    if (vect[index] > maximum) {
      maximum = vect[index];
    }
    if (index < vect.length - 1) {
      MinMax(vect, minimum, maximum, index + 1);
    } else {
      System.out.println("Mínimo :" + minimum + "\nMáximo: " + maximum);
    }
  }
}
