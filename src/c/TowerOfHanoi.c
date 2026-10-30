/*
Tower of Hanoi in C
*/

#include <stdio.h>

void hanoi(int peg0, int peg2, int peg1, int disks) {
  if (disks == 1)
    printf("Move de %i para %i\n", peg0, peg2);

  else {
    hanoi(peg0, peg1, peg2, disks - 1);
    hanoi(peg0, peg2, peg1, 1);
    hanoi(peg1, peg2, peg0, disks - 1);
  }
}

int main() {
  hanoi(0, 2, 1, 3);
  return 0;
}
