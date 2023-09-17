/*
TwoSum Algorithm in C
Ricardo Ferreira Carvalheira - 2023
https://github.com/ricardocarva

	Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
	
	You may assume that each input would have exactly one solution, and you may not use the same element twice.
	
	You can return the answer in any order.
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
   
    for(int i=0;i<numsSize-1;i++)
    {
        for( int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                
                int* x = (int*) malloc(2*sizeof(int));
                x[0]=i;
                x[1]=j;
                return x;

            }    
        }
    }
    return NULL;

}

int main() {
    int nums[] = {2, 11, 7, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    printf("The target number is %d.", target);
    printf("The list has the following items: ");
    
    for(int i=0; i< numsSize; i++)
    {
    	printf("%d ", nums[i]);
    }
    
    printf("\n");
    
    int* result = twoSum(nums, numsSize, target);
    
    if (result != NULL) {
    	printf("The two numbers that add up to %d are: %d and %d\n", target, nums[result[0]], nums[result[1]]);
        printf("Indices of the two numbers that add up to %d are: %d and %d\n", target, result[0], result[1]);
        free(result); // Don't forget to free the allocated memory
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
