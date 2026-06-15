#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int r; // 弾倉内の実弾の位置が入るよ
         // 位置がゼロの時に撃つと発射・終了
  int x; // 入力

  printf("ロシアンルーレットを始めるよー\n");
  r = rand() % 6; // 実弾の初期位置をランダムに決定

  while (1) {
    printf("弾倉を回す？\n");
    printf("1以上：回して撃つ，0：そのまま撃つ，-1以下：パス > ");
    scanf("%d", &x);

    if (x <= -1)
      continue; // パス
    if (x >= 1)
      r = rand() % 6; // 弾倉を回す（位置を再設定）
    printf("カチッ...\n");
    if (r == 0)
      break; // 発射・終了

    printf("セーフ\n");
    r--; // 弾倉を１段階だけ回す
  }
  printf("バーン...\n");
  printf("終了\n");

  return (0);
}