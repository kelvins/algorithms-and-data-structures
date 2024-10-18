#include<stdio.h>



int exponenciacao(int base, int expoente){

	if(expoente==0) return 1;
	
	return (base * exponenciacao(base, expoente-1));

}



int main(){
	
	printf("%d\n", exponenciacao(5, 3));

	return 0;
}


//  In english 
// Function to calculate exponentiation using recursion
// int exponentiation(int base, int exponent) {
//     // Base case: any number raised to the power of 0 is 1
//     if (exponent == 0) return 1;
    
//     // Recursive case: multiply the base by the result of exponentiation with decreased exponent
//     return (base * exponentiation(base, exponent - 1));
// }

// int main() {
//     // Call the exponentiation function with base 5 and exponent 3, and print the result
//     printf("%d\n", exponentiation(5, 3));

//     return 0; // Exit the program
// }