#include <stdio.h>

int main(void) {
  int i;
  i = 0;
  while (1) {
    printf("%d", i % 3);
    if (i == 9)
      break;
    i++;
  }
  return 0;
}