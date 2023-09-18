#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &vector)
{
    for (uint32_t index = 0; index < vector.size()-1; index++)
    {
        uint32_t min = index;
        
        for (uint32_t tempIndex = index+1; tempIndex < vector.size(); ++tempIndex)
        {
            if( vector[tempIndex] < vector[min] )
            {
                min = tempIndex;
            }
        }
        
        if( min != index )
        {
            int temp = vector[index];
            vector[index] = vector[min];
            vector[min] = temp;
        }
    }
}

void showVector(vector<int> vector)
{
    for (uint32_t i = 0; i < vector.size(); ++i)
    {
        cout << vector[i] << ", ";
    }
    cout << "\n";
}

int main()
{
    vector<int> vector;
    for (uint32_t i = 0; i < 10; ++i)
    {
        vector.push_back(rand() % 100);
    }
    showVector(vector);
    selectionSort(vector);
    showVector(vector);
}