import java.util.Scanner;

public class LinearSearchRecursive {

  public static int linearSearchRecursive(int[] arr, int n, int index, int target) {
    // Base case: If index exceeds array bounds, return -1 indicating target is not found
    if (index >= n) {
      return - 1;
    }

    // If the current element matches the target, return the index
    if (arr[index] == target) {
      return index;
    }

    // Recursive case: move to the next index in the array
    return linearSearchRecursive(arr, n, index + 1, target);
  }

  public static void main(String[] args) {
    int[] arr = {10, 20, 60, 30, 60, 70, 80, 22};

    int n = arr.length;

    int target = 70;

    int result = linearSearchRecursive(arr, n, 0, target);

    if (result >= 0) {
      System.out.println("Target element found at index: " + result);
    } else {
      System.out.println("Target element not found.");
    }
  }
}
