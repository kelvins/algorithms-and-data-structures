#include<stdio.h>



int fatorial(int n){

	if(n==1) return 1;
	
	return (n * fatorial(n-1));

}



int main(){
	
	printf("%d\n", fatorial(5));

	return 0;
}


//  In english

// Function to calculate the factorial of a number n
// int factorial(int n) {
//     // Base case: if n is 1, return 1 (1! = 1)
//     if (n == 1) return 1;

//     // Recursive case: n! = n * (n-1)!
//     return (n * factorial(n - 1));
// }

// int main() {
//     // Call the factorial function with 5 and print the result
//     printf("%d\n", factorial(5));  // Output: 120

//     return 0;  // Exit the program
// }