#include <stdio.h>

int main (void) {
  int n;
  int sum = 0;

  printf ("non-negative integers >");
  scanf ("%d", &n);

  for (int i = 0; i <= n; i++){
    sum += i;
  }

  printf ("sum Sn = %d\n" ,sum);
  return 0;
}
