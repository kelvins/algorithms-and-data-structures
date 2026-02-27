public class SentinelLinearSearch {
  public static void main(String[] args) {
    int[] arr = {10, 20, 60, 30, 60, 70, 80, 22};
    System.out.println(LinearSentinel(arr, 70));
    System.out.println(LinearSentinel(arr, 45));
  }

  public static int LinearSentinel(int[] arr, int key) {

    int n = arr.length;

    // Storing last element.
    int last = arr[n - 1];

    // Adding key at end index + 1
    arr[n - 1] = key;

    int i = 0;
    for (i = 0; i < n; i++) {
      if (arr[i] == key) break;
    }

    // Restoring the last element
    arr[n - 1] = last;

    // Returning index when found.
    if ((i < n - 1) || arr[n - 1] == key) {
      return i;
    }

    // Returning -1 if not found
    else return - 1;
  }

}
