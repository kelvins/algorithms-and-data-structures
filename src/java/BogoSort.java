/*
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class BogoSort {

  public static int[] bogoSort(int[] vector) {
    // Check if the vector is ordered
    while (!isSorted(vector)) {
      // Shuffle the vector to try to sort it randomly
      shuffle(vector);
    }
    return vector;
  }

  /** Check if the vector is ordered */
  private static boolean isSorted(int[] vector) {
    for (int i = 0; i < (vector.length - 1); ++i) {
      if (vector[i] > vector[i + 1]) {
        return false;
      }
    }

    return true;
  }

  /** Shuffle the vector to try to sort it randomly */
  private static void shuffle(int[] vector) {
    for (int x = 0; x < vector.length; ++x) {
      int index1 = (int) (Math.random() * vector.length),
          index2 = (int) (Math.random() * vector.length);
      int a = vector[index1];
      vector[index1] = vector[index2];
      vector[index2] = a;
    }
  }

  public static void printVector(int vector[]) {
    for (int i = 0; i < vector.length; i++) {
      System.out.print(vector[i] + ", ");
    }
    System.out.println("");
  }

  public static void main(String[] args) {

    int vector[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

    System.out.println("BogoSort:");
    System.out.println("Unordered vector:");
    printVector(vector);

    vector = bogoSort(vector);

    System.out.println("Sorted vector:");
    printVector(vector);
  }
}
