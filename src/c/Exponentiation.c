#include<stdio.h>



int exponenciacao(int base, int expoente){

	int i;
	int result = base;
	
	for(i=0; i<expoente-1; i++)
		result *= base;

	return result;

}



int main(){
	
	printf("%d\n", exponenciacao(5, 3));

	return 0;
}


// Function to calculate exponentiation (base raised to the power of exponent)
// int exponentiation(int base, int exponent) {
//     int i; // Loop counter
//     int result = base; // Initialize result with the base value
    
//     // Loop to multiply the base 'exponent - 1' times
//     for (i = 0; i < exponent - 1; i++) {
//         result *= base; // Multiply result by base
//     }

//     return result; // Return the calculated exponentiation result
// }

// int main() {
//     // Call the exponentiation function with base 5 and exponent 3, and print the result
//     printf("%d\n", exponentiation(5, 3));

//     return 0; // Exit the program
// }