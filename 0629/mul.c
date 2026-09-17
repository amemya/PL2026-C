#include <stdio.h>

int mul(int x, int y) {
  if (y == 0) {
    return 0;
  }
  return x + mul(x, y - 1);
}

int main(void) {
  int x, y;
  printf("非負整数 x, y > "); // 問題を入力
  scanf("%d %d", &x, &y);
  printf("%d * %d = %d\n", x, y, mul(x, y)); // 計算結果を表示

  return (0);
}