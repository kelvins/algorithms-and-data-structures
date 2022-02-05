#include <iostream>
#include <vector>

using namespace std;

int busca_sequencial(vector<int> &nums, int target) {

    for (size_t i = 0; i < nums.size(); i++) {
        
        if(nums[i] == target)
            return i;
    }
    
    return -1;
}

int main() {

    vector<int> nums = {1, 2, 3, 4, 5, 27, -1, 12, 999};
    int target;
    
    cout << "Digite o numero que deseja buscar no vetor: ";
    cin >> target;
    cout << "\n";

    int pos = busca_sequencial(nums, target);

    if(pos > -1) {
        cout << "Numero encontrado no vetor na posicao: " << pos << endl;
    }
    else {
        cout << "Numero nao encontrado no vetor." << endl;
    }

    return 0;
}