#include <stdio.h>

int sign(int x) { return (x > 0) - (x < 0); }

int main(void) {
  int a;
  printf("整数>");
  scanf("%d", &a);

  printf("%+d\n", sign(a));

  return 0;
}