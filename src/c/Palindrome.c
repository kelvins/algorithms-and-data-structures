#include <stdio.h>
#include <string.h>

#define MAX_SIZE_WORD 100

void calc_reverse(char *input, char *output) {
  size_t len_input = strlen(input);

  char *last_char = input + len_input - 1;

  for (int i=0; i < len_input; i++) {
    output[i] = *(last_char - i);
  }
  output[len_input] = '\0';
}

int main() {
  char input[MAX_SIZE_WORD];
  char reverse[MAX_SIZE_WORD];

  printf("Digite uma palavra: ");

  fgets(input, MAX_SIZE_WORD, stdin);
  //remove New Line from the end
  input[strlen(input) - 1] = '\0';

  calc_reverse(input, reverse);

  printf("Sua palavra invertida: %s\n", reverse);

  if (!strcmp(input, reverse))
    puts("Sua palavra eh um palindromo!");
  else
    puts("Sua palavra NAO eh um palindromo!");

  return 0;
}


// In english 

// #define MAX_SIZE_WORD 100

// // Function to reverse the input string
// void calc_reverse(char *input, char *output) {
//     size_t len_input = strlen(input); // Get the length of the input string

//     char *last_char = input + len_input - 1; // Point to the last character of the input

//     // Reverse the input string
//     for (int i = 0; i < len_input; i++) {
//         output[i] = *(last_char - i); // Copy characters in reverse order
//     }
//     output[len_input] = '\0'; // Null-terminate the output string
// }

// int main() {
//     char input[MAX_SIZE_WORD]; // Array to hold the input word
//     char reverse[MAX_SIZE_WORD]; // Array to hold the reversed word

//     printf("Enter a word: "); // Prompt the user for input

//     fgets(input, MAX_SIZE_WORD, stdin); // Read a line of input
//     // Remove newline character from the end
//     input[strlen(input) - 1] = '\0';

//     calc_reverse(input, reverse); // Call the function to reverse the word

//     printf("Your reversed word: %s\n", reverse); // Print the reversed word

//     // Check if the input word is a palindrome
//     if (!strcmp(input, reverse))
//         puts("Your word is a palindrome!"); // If it is a palindrome
//     else
//         puts("Your word is NOT a palindrome!"); // If it is not

//     return 0;
// }
