#include <stdio.h>

// 全要素を表示する関数
void print(int *p, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");
}

// 全要素を値 v に初期化する関数
void reset(int *p, int n, int v) {
  for (int i = 0; i < n; i++) {
    p[i] = v;
  }
}

// 全要素に対して各符号の個数を調べる関数
int check(int *p, int n, int *np, int *nm) {
  int zero_count = 0;
  *np = 0;
  *nm = 0;

  for (int i = 0; i < n; i++) {
    if (p[i] > 0) {
      (*np)++;
    } else if (p[i] < 0) {
      (*nm)++;
    } else {
      zero_count++;
    }
  }
  return zero_count;
}

// 全要素を入力する関数
void input(int *p, int n) {
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
}

// 全要素を配列 p から配列 q へコピーする関数
void copy(int *p, int *q, int n) {
  for (int i = 0; i < n; i++) {
    q[i] = p[i];
  }
}

#define NUM 5

int main(void) {
  int a[NUM];
  int b[NUM];
  int np, nm, nz;

  print(a, NUM); // ゴミが表示される

  nz = check(a, NUM, &np, &nm); // 符号をカウント
  printf("ゼロ|正|負：%d|%d|%d 個\n", nz, np, nm);

  reset(a, NUM, 7); // a の全要素を 7 にする
  print(a, NUM);    // 7 7 7 ... が表示される

  nz = check(a, NUM, &np, &nm); // 符号をカウント
  printf("ゼロ|正|負：%d|%d|%d 個\n", nz, np, nm);

  input(a, NUM); // てきとーなデータを a にキーボード入力すると...
  print(a, NUM); // そいつらが表示される

  copy(a, b, NUM); // a の全要素を b にコピーする
  print(b, NUM);   // b として，a と同じ内容が表示される

  return (0);
}