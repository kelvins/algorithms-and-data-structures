#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &vetor)
{
    for (uint32_t indice = 0; indice < vetor.size()-1; indice++)
    {
        uint32_t min = indice;
        
        for (uint32_t tempIndice = indice+1; tempIndice < vetor.size(); ++tempIndice)
        {
            if( vetor[tempIndice] < vetor[min] )
            {
                min = tempIndice;
            }
        }
        
        if( min != indice )
        {
            int temp = vetor[indice];
            vetor[indice] = vetor[min];
            vetor[min] = temp;
        }
    }
}

void showVector(vector<int> vetor)
{
    for (uint32_t i = 0; i < vetor.size(); ++i)
    {
        cout << vetor[i] << ", ";
    }
    cout << "\n";
}

int main()
{
    vector<int> vetor;
    for (uint32_t i = 0; i < 10; ++i)
    {
        vetor.push_back(rand() % 100);
    }
    showVector(vetor);
    selectionSort(vetor);
    showVector(vetor);
}