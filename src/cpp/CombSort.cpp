#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

/**
 * Comb Sort Optimization:
 * 1. Pass by reference (&) to avoid copying the entire vector (O(1) extra space).
 * 2. Use std::swap for better readability and potential compiler optimizations.
 * 3. Combined 'gap' and 'swapped' logic into a single while loop condition.
 */
void combSort(std::vector<int>& vect) {
    int n=vect.size();
    int gap=n;
    float shrink=1.3f;
    bool swapped=true;

    while (gap>1||swapped) {
        // Update the gap
        gap=static_cast<int>(gap / shrink);
        if(gap<1) {
            gap=1;
        }

        swapped=false;

        // Compare elements with the current gap
        for (int i=0; i+gap<n; i++) {
            if (vect[i]>vect[i + gap]) {
                std::swap(vect[i], vect[i + gap]);
                swapped=true;
            }
        }
    }
}
// Helper function to print vectors cleanly
void printVector(const std::string& label, const std::vector<int>& vect) {
    std::cout << label << ": ";
    for (size_t i = 0; i < vect.size(); ++i) {
        std::cout<<vect[i]<<(i==vect.size()-1 ?"":", ");
    }
    std::cout << std::endl;
}
int main() {
    // Test Case 1
    std::vector<int> data1 = {3, 15, 4, 3, 2, 4, 14, 7, 10, 3, 20, 8, 4, 9, 5};
    printVector("Initial Vector 1", data1);
    combSort(data1);
    printVector("Sorted Vector 1 ", data1);
    std::cout << std::endl;

    // Test Case 2
    std::vector<int> data2 = {10, 164, 20, 50, 70, 90, 1, 90, 14, 530, 439};
    printVector("Initial Vector 2", data2);
    combSort(data2);
    printVector("Sorted Vector 2 ", data2);
    return 0;
}
