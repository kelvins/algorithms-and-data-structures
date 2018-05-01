/*
 *
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class BogoSort {

    /**
     * @param vetor
     */
    public int[] sort(int[] vetor) {
        // Verifica se o vetor está ordenado
        while (!isSorted(vetor)) {
            // Embaralha o vetor pra tentar ordenar aleatoriamente
            shuffle(vetor);
        }
        return vetor;
    }

    /**
     * Verifica se o vetor está ordenado
     *
     * @param vetor
     * @return
     */
    private static boolean isSorted(int[] vetor) {
        for (int i = 0; i < (vetor.length - 1); ++i) {
            if (vetor[i] > vetor[i + 1]) {
                return false;
            }
        }

        return true;
    }

    /**
     * Embaralha o vetor pra tentar ordenar aleatoriamente
     *
     * @param vetor Vetor a ser ordenado
     */
    private static void shuffle(int[] vetor) {
        for (int x = 0; x < vetor.length; ++x) {
            int index1 = (int) (Math.random() * vetor.length),
                    index2 = (int) (Math.random() * vetor.length);
            int a = vetor[index1];
            vetor[index1] = vetor[index2];
            vetor[index2] = a;
        }
    }
}
