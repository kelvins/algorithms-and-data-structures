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
