public class SelectionSort {

  public static void main(String[] args) {

    int array[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

    System.out.println("Selection Sort:");
    System.out.println("Unsorted array:");
    printArray(array);

    array = selectionSort(array, 0);

    System.out.println("Sorted array:");
    printArray(array);
  }

  public static int[] selectionSort(int array[], int index) {
    if (index >= array.length - 1) return array;

    int minimumIndex = index;

    for (int i = index + 1; i < array.length; i++)
      if (array[i] < array[minimumIndex]) minimumIndex = i;

    int temp = array[index];
    array[index] = array[minimumIndex];
    array[minimumIndex] = temp;

    selectionSort(array, index + 1);

    return array;
  }

  public static void printArray(int array[]) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + ", ");
    }
    System.out.println("");
  }
}
