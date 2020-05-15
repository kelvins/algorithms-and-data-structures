/*
 * @author Marcelo Wischniowski <marcelowisc at gmail.com>
 */
public class HeapSort  {

    /**
     * @param vetor Vetor que será ordenado
     * Aplica a ordenação HeapSorte no vetor
     */
    public int[] sort(int[] vetor) {

        for (int i =  vetor.length/ 2 - 1; i >= 0; i--){
            heapify(vetor, vetor.length, i);
        }
       
        for (int i = vetor.length - 1; i>=0; i--)
        {
            
            int temp = vetor[0];
            vetor[0] = vetor[i];
            vetor[i] = temp;
            
            heapify(vetor, i, 0);
        }
        return vetor;
    }
        void heapify(int arr[], int arrayLength, int rootElementIndex)
    {
        
        int leftIndex = 2*rootElementIndex + 1;  
        int rightIndex = 2*rootElementIndex + 2;  
        
        int largest = rootElementIndex;
       
        if (leftIndex < arrayLength && arr[leftIndex] > arr[largest])
            largest = leftIndex;
        
        if (rightIndex < arrayLength && arr[rightIndex] > arr[largest])
            largest = rightIndex;
        
        if (largest != rootElementIndex){
           
            int swap = arr[rootElementIndex];
            arr[rootElementIndex] = arr[largest];
            arr[largest] = swap;
            
            heapify(arr, arrayLength, largest);
        }
    }
}
