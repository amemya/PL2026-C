# include <stdio.h>

int main (void) {
  int total;
  int x;
  int n, i;

  printf ("Number of Data >");
  scanf ("%d", &n);

  total = 0;
  printf("%d non-negative integers >", n);
  for (i = 0; i <n; i++) {
    scanf ("%d", &x);
    total += x;
  }

  printf ("total = %d\n", total);

  return 0;
}


