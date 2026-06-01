#include <stdio.h>

int main (void) {
  int maximal = -1;
  int minimal = 101;
  int n ;

  do {
    printf ("enter score (Negative numbers to exit) >");  
    scanf("%d", &n);

    if (n >= 0) {
      if (n < minimal) minimal = n;
      if (n > maximal) maximal = n;
    }
  } while (n >= 0);

  if (maximal == -1) {
    printf ("No scores entered \n");
  } else {
      printf ("minimal = %d \n", minimal);
      printf ("maximal = %d \n", maximal);
  }

  return 0;

}




