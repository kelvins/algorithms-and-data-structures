public class BubbleSort {

  public static void main(String[] args) {

    int vector[] = {9, 0, 4, 2, 3, 8, 7, 1, 6, 5};

    System.out.println("Bubble Sort:");
    System.out.println("unordered vector:");
    showvector(vector);

    vector = bubbleSort(vector);

    System.out.println("ordered vector:");
    showvector(vector);
  }

  public static int[] bubbleSort(int vector[]) {
    int exchange = 0;
    for (int i = 0; i < vector.length - 1; i++) {
      if (vector[i] > vector[i + 1]) {
        int temp = vector[i];
        vector[i] = vector[i + 1];
        vector[i + 1] = temp;
        exchange++;
      }
    }
    if (exchange != 0) bubbleSort(vector);
    return vector;
  }

  public static int[] bubbleSort2(int vector[]) {
    for (int i = 1; i < vector.length; i++) {
      int tam = vector.length;
      for (int j = 0; j < tam - i; j++) {
        if (vector[j] > vector[j + 1]) {
          int temp = vector[j];
          vector[j] = vector[j + 1];
          vector[j + 1] = temp;
        }
      }
    }
    return vector;
  }

  public static void showvector(int vector[]) {
    for (int i = 0; i < vector.length; i++) {
      System.out.print(vector[i] + ", ");
    }
    System.out.println("");
  }
}
