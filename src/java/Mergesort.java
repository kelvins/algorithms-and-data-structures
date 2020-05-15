
class MergeSort 
{ 
    void merge(int vetor[], int inicio, int meio, int fim) 
    { 
        int n1 = meio- inicio+ 1; 
        int n2 = fim -meio;
        int Inicial[] = new int [n1]; 
        int Final[] = new int [n2];
        for (int i=0; i<n1; ++i) 
        	Inicial[i] = vetor[inicio + i]; 
        for (int j=0; j<n2; ++j) 
            Final[j] = vetor[meio + 1+ j];
        int i = 0, j = 0;
        int k = inicio; 
        while (i < n1 && j < n2) 
        { 
            if (Inicial[i] <= Final[j]) 
            { 
                vetor[k] = Inicial[i]; 
                i++; 
            } 
            else
            { 
                vetor[k] = Final[j]; 
                j++; 
            } 
            k++; 
        } 
        while (i < n1) 
        { 
            vetor[k] = Inicial[i]; 
            i++; 
            k++; 
        } 
        while (j < n2) 
        { 
            vetor[k] = Final[j]; 
            j++; 
            k++; 
        } 
    } 
    void sort(int vetor[], int inicio, int fim) 
    { 
        if (inicio < fim) 
        {
            int meio= (inicio+fim)/2; 
            sort(vetor, inicio, meio); 
            sort(vetor , meio+1, fim); 
            merge(vetor, inicio, meio, fim); 
        } 
    }
}