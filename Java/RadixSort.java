
/*
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class RadixSort {
    
    /**
     * @param vetor Vetor que será ordenado
     * Aplica a ordenação RadixSorte no vetor
     */
	public int[] sort(int[] vetor) {
        int length = vetor.length,
            i,
            exp = 1,
            higher = vetor[0];
            int[] temp = new int[10];


            for (i = 1; i < length; i++)
                if (vetor[i] > higher)
                    higher = vetor[i];
            
            while (higher / exp > 0){
                int[] bucket = new int[10];
     
                for (i = 0; i < length; i++)
                    bucket[(vetor[i] / exp) % 10]++;
                
                for (i = 1; i < 10; i++)
                    bucket[i] += bucket[i - 1];
                
                for (i = length - 1; i >= 0; i--)
                    temp[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
                
                for (i = 0; i < length; i++)
                    vetor[i] = temp[i];
                
                exp = exp * 10;        
            }
            return vetor;
	}               
}
