#include <iostream>
#include <vector>

using namespace std;

int separa(vector<int> &vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int indice = inicio;

    for (int i = inicio; i < fim; i++)
    {
        if (vetor[i] < pivo)
        {
            int temp = vetor[i];
            vetor[i] = vetor[indice];
            vetor[indice] = temp;
            indice++;
        }
    }

    if (pivo <= vetor[indice])
    {
        vetor[fim] = vetor[indice];
        vetor[indice] = pivo;
    }

    return indice;
}

void quickSort(vector<int> &vetor, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivo = separa(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

void quickSort(vector<int> &vetor)
{
    quickSort(vetor, 0, vetor.size()-1);
}

void mostraVetor(vector<int> vetor)
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
    mostraVetor(vetor);
    quickSort(vetor);
    mostraVetor(vetor);
}
