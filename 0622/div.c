#include <stdio.h>

int div(int x, int y) {
  int m = x;
  int z = 0;

  if (y == 0) {
    return 0;
  } else {
    while (m >= y) {
      m = m - y;
      z++;
    }
    return (z);
  }
}

int main(void) {
  int x, y;
  printf("自然数 x, y > ");
  scanf("%d %d", &x, &y);

  printf("%d / %d = %d\n", x, y, div(x, y));

  return (0);
}