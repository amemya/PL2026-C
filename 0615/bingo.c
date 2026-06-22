#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main() {
  int card[SIZE][SIZE];

  // 乱数のシードを初期化
  srand((unsigned int)time(NULL));

  // 各列の数字を生成
  // B列: 1〜15, I列: 16〜30, N列: 31〜45, G列: 46〜60, O列: 61〜75
  for (int col = 0; col < SIZE; col++) {
    int min = col * 15 + 1;
    int max = col * 15 + 15;

    for (int row = 0; row < SIZE; row++) {
      int num;
      int is_duplicate;

      // すでに同じ列にある数字と被らないように乱数を生成
      do {
        is_duplicate = 0;
        num = min + rand() % (max - min + 1);

        for (int k = 0; k < row; k++) {
          if (card[k][col] == num) {
            is_duplicate = 1;
            break;
          }
        }
      } while (is_duplicate);

      card[row][col] = num;
    }
  }

  // ビンゴカードの表示
  printf("ビンゴカード:\n");
  printf("  B  I  N  G  O\n");
  printf("----------------\n");
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
      // 真ん中（N列の3行目）はフリースペース（FREE）とする
      if (row == 2 && col == 2) {
        printf(" **"); // フリースペースを ** で表現
      } else {
        printf(" %2d", card[row][col]);
      }
    }
    printf("\n");
  }

  return 0;
}
