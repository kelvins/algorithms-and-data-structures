#include<stdio.h>
#include<stdlib.h>

/*
*	Exemplos de função para retornar o fatorial de um número n
*	função recursiva
*/

int main(){
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    int result = fatorial(num);
    printf("1 => ");
    printf("%d! é : %d\n", num, result);
    return(0);
}

int fatorial(int num){
    if(num <= 1 ){
        return 1;
    }
    printf("%d * ", num);
    return num * fatorial(num - 1);
}




//  In english 
/*
*   Examples of a function to return the factorial of a number n
*   This is a recursive function.
*/

// Function prototype for factorial
// int factorial(int num);

// int main() {
//     int num;  // Variable to store the user input
//     printf("Enter a number: "); // Prompt user for input
//     scanf("%d", &num);  // Read the user input

//     int result = factorial(num);  // Call the factorial function
//     printf("1 => ");
//     printf("%d! is: %d\n", num, result);  // Print the result

//     return 0;  // Exit the program
// }

// // Recursive function to calculate the factorial of a number
// int factorial(int num) {
//     if (num <= 1) {  // Base case: factorial of 0 or 1 is 1
//         return 1;
//     }
//     printf("%d * ", num);  // Print the current number (for demonstration)
//     return num * factorial(num - 1);  // Recursive call
// }