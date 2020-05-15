#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> vetor)
{
    for (uint32_t fim = vetor.size()-1; fim > 0; --fim)
    {
        for (uint32_t indice = 0; indice < fim; ++indice)
        {
            if (vetor[indice] > vetor[indice+1])
            {
                int troca = vetor[indice];
                vetor[indice] = vetor[indice+1];
                vetor[indice+1] = troca;
            }
        }
    }
    return vetor;
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
    vetor = bubbleSort(vetor);
    showVector(vetor);
}
