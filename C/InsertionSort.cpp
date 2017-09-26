#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vetor) {

    for (uint32_t indice = 1; indice < vetor.size(); indice++)
    {
		int chave = vetor[indice];
		int i = indice - 1;
		
		while (i >= 0 && vetor[i] > chave)
		{
			vetor[i+1] = vetor[i];
			i--;
		}
		
		vetor[i+1] = chave;
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
    insertionSort(vetor);
    showVector(vetor);
}
