#include <stdio.h>

int main (void) {
  int x;
  
  while (1) {
      printf ("Enter a hexadecimal number >");
      scanf("%x", &x);
      printf ("%d\n", x);
  }
  return 0;
}

