#include <stdio.h>  // printf(), getchar() に必要
#include <stdlib.h> // rand() に必要
#include <time.h>   // time() に必要

int main(void) {
  int x, y; // サイコロの出目（1〜6）が入るよ
  int z;    // 出目の合計が入るよ
  int bet;  // 客の賭け（0:丁, 1:半）

  srand(time(NULL));

  while (1) {
    printf("丁(偶数)なら0、半(奇数)なら1を入力 (終了は-1) > ");
    if (scanf("%d", &bet) != 1)
      break;

    if (bet == -1) {
      printf("終了\n");
      break;
    }

    // scanfで残った改行を読み飛ばす
    while (getchar() != '\n')
      ;

    x = rand() % 6 + 1; // 1〜6 の乱数
    y = rand() % 6 + 1; // 同上
    z = x + y;

    printf("%d，%d の ", x, y);

    if (z % 2 == 0) {
      printf("丁\n");
      if (bet == 0) {
        printf("勝ち\n");
      } else {
        printf("負け\n");
      }
    } else {
      printf("半\n");
      if (bet == 1) {
        printf("勝ち\n");
      } else {
        printf("負け\n");
      }
    }

    printf("（[Enter]キーを押して次へ）");
    getchar(); // [Enter]キーの入力を待つ
  }
  return (0);
}