#include<stdio.h>
#define SIZE 100

int BinarySearch(int array[], int size, int searched)
{
	int start, middle, end;
	start = 0;
	end = size - 1;
	middle = end / 2;
	
	while (start < end && array[middle] != searched) 
	{
		if (searched > array[middle]) // new start
			start = middle + 1;
			
		if (searched < array[middle]) // new end
			end = middle - 1;
			
		// new middle
		middle = (start + end) / 2;
	}
	
	if (array[middle] == searched)
		return middle;
	
	return -1;
}

int main()
{
	int searche;
	int arraySize = 10;
    int array[SIZE] = {1, 5, 10, 12, 18, 22, 87, 90, 112, 129};
    
    printf("Please provide the number you want to search for: ");
    scanf("%d", &searche);
    
    int pos =  BinarySearch(array, arraySize, searche);
    
    if (pos != -1)
    	printf("Found in position = %d.\nValue = %d\n", pos, array[pos]);
    else 
    	printf("Not found\n");
    
    return 0;
}
