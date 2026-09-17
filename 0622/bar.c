#include <stdio.h>

/*
棒グラフを描く関数
引数 n：棒の長さ，非負整数
戻り値：なし
*/

void bar(int n) // 戻り値なしの場合，型を void とする
{
  int i; // この関数内で使う変数を移設

  for (i = 0; i < n; i++) { // 共通部分を移設
    printf("*");
  }
  printf("\n");

  //	return;		// 戻り値なしの場合，return 自体を省略してもよい
}

int main(void) // 引数なしも void とする
{
  int a = 10;
  int b = 20;
  int c = 15;

  bar(a); // a の棒グラフ
  bar(b); // b の棒グラフ
  bar(c); // c の棒グラフ

  return (0);
}