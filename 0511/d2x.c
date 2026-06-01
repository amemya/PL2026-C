#include <stdio.h>

int main (void) {
  int x;
  
  while (1) {
      printf ("Enter a decimal number >");
      scanf("%d", &x);
      printf ("%x\n", x);
  }
  return 0;
}

