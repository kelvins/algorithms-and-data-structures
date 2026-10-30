#include <stdio.h>
#include <string.h>

#define MAX_SIZE_WORD 100

void calc_reverse(char *input, char *output) {
  size_t len_input = strlen(input);

  char *last_char = input + len_input - 1;

  for (int i = 0; i < len_input; i++) {
    output[i] = *(last_char - i);
  }
  output[len_input] = '\0';
}

int main() {
  char input[MAX_SIZE_WORD];
  char reverse[MAX_SIZE_WORD];

  printf("Enter a word: ");

  fgets(input, MAX_SIZE_WORD, stdin);
  // remove New Line from the end
  input[strlen(input) - 1] = '\0';

  calc_reverse(input, reverse);

  printf("Reversed word: %s\n", reverse);

  if (!strcmp(input, reverse))
    puts("Your word is a palindrome!");
  else
    puts("Your word is not a palindrome!");

  return 0;
}
