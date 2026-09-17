#include <stdio.h>

int main(void) {
  int x, y, z; // x / y = z
  int m;       // 剰余 m = x % y

  printf("自然数 x, y > ");
  scanf("%d %d", &x, &y);

  z = 0; // 商を初期化
  m = x; // 剰余を初期化（x をコピーしておく）
  // 反復回数は未知（割り算の結果）だし，ゼロかもしれないので while文
  while (m >= y) { // 引き算が非負である限り反復
    m = m - y;     // x から y を引く（実際には m から引く）
    z++;           // 引き算の回数をカウント
  }

  printf("%d / %d = %d ... %d", x, y, z, m); // 計算結果を表示

  return (0);
}
