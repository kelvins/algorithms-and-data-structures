public class InsertionSort {

  public static void main(String[] args) {

    int[] array = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

    System.out.println("Insertion Sort:");
    System.out.println("Unsorted array:");
    printArray(array);

    array = insertionSort(array);

    System.out.println("Sorted array:");
    printArray(array);
  }

  public static int[] insertionSort(int[] array) {
    int key, aux;
    for (int i = 0; i < array.length; i++) {
      key = array[i];
      aux = i - 1;
      while (aux >= 0 && array[aux] > key) {
        array[aux + 1] = array[aux];
        aux -= 1;
      }
      array[aux + 1] = key;
    }
    return array;
  }

  public static void printArray(int[] array) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + ", ");
    }
    System.out.println("");
  }
}
