#include <stdio.h>

int main(void) {
  int i;
  i = 0;
LOOP:
  printf("%d", i % 3);
  i++;
  if (i < 10)
    goto LOOP;
  return 0;
}