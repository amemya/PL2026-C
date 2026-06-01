#include <stdio.h>

int main (void) {
  int x, y, z;
  
  while (1) {
    printf("整数２個 > ");
    scanf("%d %d", &x, &y);
    z = x * y;
    printf("%d * %d = %d\n", x, y, z);
    }

  return 0;

}


