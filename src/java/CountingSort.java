public class CountingSort {

  int getMax(int[] a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] > max) max = a[i];
    }
    return max;
  }

  void countSort(int[] a, int n) {
    int[] output = new int[n + 1];
    int max = getMax(a, n);
    // int max = 42;
    int[] count = new int[max + 1];

    for (int i = 0; i <= max; ++i) {
      count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      count[a[i]]++;
    }

    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
      output[count[a[i]] - 1] = a[i];
      count[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
      a[i] = output[i];
    }
  }

  /* Function to print the array elements */
  void printArray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) System.out.print(a[i] + " ");
  }

  public static void main(String args[]) {
    int a[] = {11, 30, 24, 7, 31, 16, 39, 41};
    int n = a.length;
    CountingSort c1 = new CountingSort();
    System.out.println("\nBefore sorting array elements are - ");
    c1.printArray(a, n);
    c1.countSort(a, n);
    System.out.println("\nAfter sorting array elements are - ");
    c1.printArray(a, n);
    System.out.println();
  }
}
