public class SelectionSort {

  public static void main(String[] args) {

    int array[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

    System.out.println("Selection Sort:");
    System.out.println("Array not sorted:");
    mostraVetor(array);

    array = selectionSort(array, 0);

    System.out.println("Array sorted:");
    mostraVetor(array);
  }

  public static int[] selectionSort(int array[], int index) {
    if (index >= array.length - 1) return array;

    int minIndice = index;

    for (int i = index + 1; i < array.length; i++) if (array[i] < array[minIndice]) minIndice = i;

    int temp = array[index];
    array[index] = array[minIndice];
    array[minIndice] = temp;

    selectionSort(array, index + 1);

    return array;
  }

  public static void mostraVetor(int array[]) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + ", ");
    }
    System.out.println("");
  }
}
