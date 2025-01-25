import java.util.Scanner;

public class LinearSearchRecursive {

    public static int linearSearchRecursive(int[] arr, int n, int index, int target) {
        // Base case: If index exceeds array bounds, return -1 indicating target is not found
        if (index >= n) {
            return -1;
        }

        // If the current element matches the target, return the index
        if (arr[index] == target) {
            return index;
        }

        // Recursive case: move to the next index in the array
        return linearSearchRecursive(arr, n, index + 1, target);
    }

    public static void main(String[] args) {
        // Create a scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        int[] arr = new int[n];

        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        System.out.print("Enter the element you need to search for in the array: ");
        int target = scanner.nextInt();

        // Call the recursive linear search function
        int result = linearSearchRecursive(arr, n, 0, target);

        if (result >= 0) {
            System.out.println("Target element found at index: " + result);
        } else {
            System.out.println("Target element not found.");
        }

        // Close the scanner to avoid memory leaks
        scanner.close();
    }
}
