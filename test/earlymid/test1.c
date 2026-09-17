#include <stdio.h>

int i;
int main(void) {
  for (i = 0; i < 10; i++) {
    printf("%d", i % 3);
  }
  return 0;
}