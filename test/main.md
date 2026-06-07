# (1)実数を入力し，全体10桁，小数5桁まで表示する
```c
double x;
printf("実数 x > ");

scanf(" [空欄a]", [空欄b]);

printf("x = [空欄c] \n", x);
```

# (2)数列0,1,2,0,1,2,0,1,2,0 (項数10,周期3の循環数列)を表示する
## 1.forループ版
```c
int i;
for ([空欄d];[空欄e];[空欄f]) {
  printf("%d\n", i % 3);
}
```

## 2.前判定whileループ版
```c
int i;
[空欄g];
while ([空欄h]) {
  printf("%d\n", i % 3);
  [空欄i];
}
```

## 3.中判定whileループ版
```c
int i;
[空欄j];
while (1) {
  printf("%d\n", i % 3);
  if ([空欄k])
    [空欄l];
  [空欄m];
}
```
## 4.do-whileループ版

```c
int i;
[空欄n];

do {
  printf("%d\n", i % 3);
  [空欄o];
} while ([空欄p]);
```

## 5.if-goto版

```c
int i;
[空欄q];
LOOP : printf("%d\n", i % 3);
[空欄r];
if (i < 10)
  goto LOOP;
```

## 空欄の回答:
- a: %lf
- b: &x
- c: %10.5f
- d: i = 0
- e: i < 10
- f: i++
- g: i = 0
- h: i < 10
- i: i++
- j: i = 0
- k: i == 9
- l: break
- m: i++
- n: i = 0
- o: i++
- p: i < 10
- q: i = 0
- r: i++

# 次の結果の数値を書け

- a: 25/10
- b: 25.0/10.0
- c: (double) (25/10)
- d: (double) 25/10
- e: 15/10 +1.0

## 解答
- a: 2 (整数/整数=整数(切り捨て))
- b: 2.5 (実数/実数=実数)
- c: 2.5 (double型のため)
- d: 2.5 (double25 /10, 実数/整数=実数)
- e: 2.0 (整数/整数 +実数 = 実数)

# 次のプログラムの実行結果を書け

```c
#include <stdio.h>

int main (void) {
  int r = 4; 
  int x, y;
  
  for (y = 0; y <= r; y++) {
    for (x = 0; x <= r; x++){
      if (x*x + y*y > r*r) break;
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
```
## 解答
```
#####
####
###
##
#
```

# 次のプログラムの実行結果を書け
```c 
#include <stdio.h>

int main (void) {
  int x = 20; 
  int b;

  while (x > 0) {
    b = x%2;
    x = x/2;
    printf("%d\n", b);
  }
  return 0;
}
```

## 解答

```
0
0
1
0
1

```

# 次の仕様，実行例に従うプログラムのコードを書け(写真が荒かったので読み取れたところから推測)

## 要求仕様
- 整数xを入力すると桁数nを算出，表示
- 以上の動作を反復
- 負の値を入力した場合に終了，継続を確認

実行例
```shell
$ ./keta
桁数を求めるよ
非負整数 x > 5
1桁
非負整数 x > 234
3桁
非負整数 x > -1
ゼロ以外で終了 > 0
非負整数 x > 99999
5桁
...
非負整数 x > -1
ゼロ以外で終了 > 1
終了

$
```

```c
#include <stdio.h>

main (    ){
  int x; //入力整数
  int n; //桁数
  int e; // 10, 100, 1000
  printf("桁数を求めるよ\n")

MAIN:
  while (    ){
    printf (    );
    scanf (    );
    if (    );
    n = 1;
    e = 10;
    while (    ) {
      e;
      n;
    }
    printf (    ,    );
    }
  }
}
```

## 解答
```c
#include <stdio.h>
int main(void) {
  int x;
  int n;
  int e;
  printf("桁数を求めるよ\n");
MAIN:
  while (1) {
    printf("非負整数 x > ");
    scanf("%d", &x);
    if (x < 0) break;           // 負なら while を抜ける
    n = 1;
    e = 10;
    while (x >= e) {
      e = e * 10;
      n = n++ ;
    }
    printf("%d桁\n", n);
  }
  printf("ゼロ以外で終了 > ");
  scanf("%d", &x);
  if (x == 0) goto MAIN;
  printf("終了\n");
  return 0;
}
