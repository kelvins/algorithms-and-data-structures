/*
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class ShellSort {

    /**
     * Aplica a ordenação ShellSort no vetor
     * @param vetor Vetor que será ordenado
     */
    public int[] sort(int[] vetor) {
        int i, j, h = 1, temp;

        do {
            h = 3 * h + 1;
        } while (h < vetor.length);

        do {
            h /= 3;

            for (i = h; i < vetor.length; i++) {
                temp = vetor[i];
                j = i - h;
                while (j >= 0 && temp < vetor[j]) {
                    vetor[j + h] = vetor[j];
                    j -= h;
                }
                vetor[j + h] = temp;
            }
        } while (h > 1);
        return vetor;
    }
}
