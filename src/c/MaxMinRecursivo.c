/*
*	Example of a recursive algorithm.
*	Objective: find the maximum and minimum values in an array using recursion.
*	Kelvin Salton do Prado - 2015
*/

#include <stdio.h>

#define SIZE 10

void MaxMin(int array[], int min, int max, int index){
	if( array[index] < min )
		min = array[index];
	if( array[index] > max )
		max = array[index];
	if( index < SIZE - 1 )
		MaxMin(array, min, max, index + 1);
	else
		printf("Min: %d \nMax: %d\n\n", min, max);
}

int main(){
	int array[SIZE] = {9,2,1,8,6,3,4,5,0,7};
	MaxMin(array, array[0], array[0], 0);
	return 0;
}
