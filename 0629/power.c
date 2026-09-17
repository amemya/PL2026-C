#include <stdio.h>

/*
累乗を計算する関数
x：整数
y：非負整数
戻り値：x^y（xのy乗）
*/
int power(int x, int y) {
  if (y == 0) {
    return 1;
  }
  return x * power(x, y - 1);
}

int main(void) {
  int x, y;

  // 入力部
  printf("x, y > ");
  scanf("%d %d", &x, &y);

  // 出力部
  printf("%d^%d = %d\n", x, y, power(x, y));

  return (0);
}