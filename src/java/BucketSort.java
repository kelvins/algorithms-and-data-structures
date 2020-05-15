/*
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class BucketSort{

    /**
     * @param vetor Vetor que será ordenado
    /**
     * Aplica a ordenação BucketSorte no vetor
     */
    public int[] sort(int[] vetor) {

        final int[] code = hash(vetor);

        List<Integer>[] buckets = new List[code[1]];
        for (int i = 0; i < code[1]; i++) {
          buckets[i] = new ArrayList<Integer>();
        }

        for (int i : vetor) {
          buckets[hash(i, code)].add(i);
        }

        for (List bucket : buckets) {
          Collections.sort(bucket);
        }
        int ndx = 0;
       
        for (int b = 0; b < buckets.length; b++) {
          for (int v : buckets[b]) {
            vetor[ndx++] = v;
          }
        }
        return vetor;
    }
    
    private int[] hash(int[] input) {
        int m = input[0];
            for (int i = 1; i < input.length; i++) {
              if (m < input[i]) {
                m = input[i];
              }
            }
        return new int[]{m, (int) Math.sqrt(input.length)};
    }
    
    private int hash(int i, int[] code) {
        return (int) ((double) i / code[0] * (code[1] - 1));
    }
}
