/*
 *
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class BogoSort {

  /**
   * @param vector
   */
  public int[] sort(int[] vector) {
    // Checking if the vector is ordered
    while (!isSorted(vector)) {
      // Shuffle the vector to try to sort it randomly
      shuffle(vector);
    }
    return vector;
  }

  /**
   * Checking again if the vector is ordered
   *
   * @param vector
   * @return
   */
  private static boolean isSorted(int[] vector) {
    for (int i = 0; i < (vector.length - 1); ++i) {
      if (vector[i] > vector[i + 1]) {
        return false;
      }
    }

    return true;
  }

  /**
   * Shuffle the vector to try to sort it randomly
   *
   * @param vector Vector is to be sorted
   */
  private static void shuffle(int[] vector) {
    for (int x = 0; x < vector.length; ++x) {
      int index1 = (int) (Math.random() * vector.length),
          index2 = (int) (Math.random() * vector.length);
      int a = vector[index1];
      vector[index1] = vector[index2];
      vector[index2] = a;
    }
  }
}
/*
 *
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class BogoSort {

  /**
   * @param vector
   */
  public int[] sort(int[] vector) {
    // Verify if the vector is ordered
    while (!isSorted(vector)) {
      // Shuffle the vector to try to sort it randomly
      shuffle(vector);
    }
    return vector;
  }

  /**
   * Verify if the vector (named vector) is sorted 
   *
   * @param vector
   * @return
   */
  private static boolean isSorted(int[] vector) {
    for (int i = 0; i < (vector.length - 1); ++i) {
      if (vector[i] > vector[i + 1]) {
        return false;
      }
    }

    return true;
  }

  /**
   * Shuffle the vector to try to sort it randomly
   *
   * @param vector Vector is to be sorted
   */
  private static void shuffle(int[] vector) {
    for (int x = 0; x < vector.length; ++x) {
      int index1 = (int) (Math.random() * vector.length),
          index2 = (int) (Math.random() * vector.length);
      int a = vector[index1];
      vector[index1] = vector[index2];
      vector[index2] = a;
    }
  }
}
