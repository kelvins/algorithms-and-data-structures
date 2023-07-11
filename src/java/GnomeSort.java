import java.util.Arrays;

public class GnomeSort {
  public static void main(String[] args) {
    int vetor[] = {10, -10, -9, 9, 8, -8, 7, -7, 6, -6, 5, -5, 4, -4, 3, -3, 2, -2, 1, -1, 0};
    System.out.println("Vetor antes da ordenação:" + Arrays.toString(vetor));

    gnomeSort(vetor);
    System.out.println(
        "Vetor após ordenação com o algoritmo Gnome Sort: " + Arrays.toString(vetor));
  }

  static void gnomeSort(int[] vetor) {
    int i = 0;
    while (i < vetor.length) {
      if (i == 0 || vetor[i] >= vetor[i - 1]) {
        i++;

      } else {
        int auxiliar = vetor[i];
        vetor[i] = vetor[i - 1];
        vetor[i - 1] = auxiliar;

        i--;
      }
    }
  }
}
