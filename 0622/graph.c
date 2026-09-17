#include <math.h>
#include <stdio.h>

/* グラフの１点を描く関数 */
void plot(int y) {
  if (y < 0) {
    y = 0; /* マイナスになる場合は0に丸める */
  }
  for (int i = 0; i < y; i++) {
    printf(" ");
  }
  printf("*\n");
}

int main(void) {
  double A, k, w;
  int offset = 40; /* グラフの中心位置 */

  printf("減衰振動関数: y = A * exp(-k * x) * sin(w * x)\n");
  printf("パラメータを入力してください。\n");
  printf("初期振幅 A (例: 35.0): ");
  scanf("%lf", &A);
  printf("減衰率 k (例: 0.06): ");
  scanf("%lf", &k);
  printf("周波数 w (例: 0.4): ");
  scanf("%lf", &w);
  printf("\n");

  printf("Function: y = %g * exp(-%g * x) * sin(%g * x)\n", A, k, w);
  printf("--------------------------------------------------\n");

  /* xを0から60まで動かしながらグラフを描画 */
  for (int x = 0; x <= 60; x++) {
    /* 数学関数を用いて関数の値を計算 */
    double val = A * exp(-k * x) * sin(w * x);

    /* 整数に変換し、オフセットを加えて表示位置(y)を決定 */
    int y = (int)val + offset;

    /* プロット関数を呼び出し */
    plot(y);
  }

  return 0;
}
