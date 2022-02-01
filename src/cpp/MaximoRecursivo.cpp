#include <iostream>
#include <vector>


int max_recursivo(std::vector<int> nums, int n) {

    if(n == 1)
        return nums[0];
    else{
        int aux = max_recursivo(nums, n-1);
        
        if(aux > nums[n-1]) 
            return aux;
        
        return nums[n-1];
    }    
}

int main() {

    std::vector<int> nums{1, 2, 3, 4, 32, 6, 7, 8, 9, 10};

    std::cout << "nums = {";
    for(auto& i : nums) {

        std::cout << i;
        
        if(&i != &nums.back()) {
            std::cout << ",";
        }
    }
    std::cout << "}" << std::endl;

    std::cout << "Max = " << max_recursivo(nums, nums.size()) << std::endl;

    return 0;
}
