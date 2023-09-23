/*
*	Example of Sentinel Search in C
*	Purpose: Find a value in an array without needing to test all values within the loop
*	Kelvin Salton do Prado - 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Sentinel search, performs a sequential search without the need to test the key at each step of the search loop
int sentinelSearch(int array[], int key){
	array[ARRAY_SIZE] = key; // Place the searched value (key) in the last position of the array
	int aux = 0; // Loop control variable
	while( array[aux] != key ) // While the value (key) is not found, increment 1 to aux
		aux++;
	if( aux == ARRAY_SIZE ) // If the value of aux is equal to the size of the array, it means it went to the end and did not find the value
		return -1; // Not found
	else // If aux is different, it means it found the value and broke out of the loop, aux is the position of the searched value
		return aux; // Found
}

int main(){

	int array[ARRAY_SIZE+1]; // Declare the array with +1 because it's the position that will be used by the sentinel
	
	// Fill the array with random values from 0 to 1000
	srand(time(NULL));
	for(int i = 0; i < ARRAY_SIZE; i++){
		array[i] = rand() % 1000;
		printf("%d, ", array[i]);
	}

	// Perform the search, passing the array and the key you want to search for as parameters
	int res = sentinelSearch(array, array[ARRAY_SIZE-2]);
	if( res != -1 )
		printf("\n\nValue %d found at position %d.\n\n", array[res], res);
	else
		printf("\n\nValue not found in the array.\n\n");
	
	return 0;
}
