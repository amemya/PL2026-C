#include <stdio.h>

int main(void) {
  int i;
  i = 0;

  do {
    printf("%d", i % 3);
    i++;
  } while (i < 10);
  return 0;
}