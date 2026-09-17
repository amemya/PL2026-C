#include <stdio.h>
#include <string.h>

#define BUFLEN 256 // 文字列バッファのサイズ

#define BUFFMT "%255s" // バッファの入力書式...この方法はイマイチ
/*
        もし，BUFLEN の値を変えたら，BUFFMT の数字も変える必要があります．
        要するに二度手間...
        面倒ってほどの手間ではないけど，間違えてトラブる危険性は高い．
*/

/*
小計（ファイル内の合計）を計算する関数
引数 *file：入力ファイル名
戻り値：小計
*/
int sum(char *file) {
  FILE *fp = NULL;
  int t = 0;
  int x;

  fp = fopen(file, "r");
  if (fp == NULL) {
    perror("オープン失敗");
    return (0);
  }
  while (fscanf(fp, "%d", &x) != EOF) {
    t += x;
  }
  printf("小計：%d\n", t);
  if (fp != NULL)
    fclose(fp);
  return (t);
}

void help() {
  printf("exit\n");
  printf("help\n");
  printf("reset\n");
  printf("save ファイル名\n");
  printf("show\n");
  printf("sum ファイル名\n");
}

int main(void) {
  int total = 0;    // 合計
  char cmd[BUFLEN]; // コマンドの文字列バッファ

  char *fmt = BUFFMT; // 書式文字列...イマイチな方法
  char arg[BUFLEN];
  /*
          char	fmt[16];		// 書式文字列...イケてる方法
          sprintf(fmt, "%%%ds", BUFLEN-1);	// 書式文字列を自動生成する
  */
  /*
          sprintf() は文字配列への書式付き出力ね．stdio.h
          "%%" は，１文字の文字列 "%" を表わすよ．
          "%d" は，数値 BUFLEN-1 の文字列..."255" に置き換わるよ．
          "s" は そのまま "s" だよ．
          結局，fmt の内容は "%255s" になるね．
          バッファサイズ変更の手間は #define BUFLEN の１箇所だけで済むよ．
  */

  while (1) {
    // コマンドの入力
    printf("命令 > ");
    if (scanf(fmt, cmd) == EOF)
      break;

    // コマンドの解釈・実行
    if (strcmp(cmd, "exit") == 0)
      break; // exit コマンド

    else if (strcmp(cmd, "sum") == 0) { // sum コマンド
      scanf(fmt, arg);                  // データファイル名の入力
      total += sum(arg);                // ファイル内の小計を合計

    } else if (strcmp(cmd, "show") == 0) { // show コマンド
      printf("合計：%d\n", total);         // 現在の合計を表示
    }

    else if (strcmp(cmd, "reset") == 0) { // reset コマンド
      total = 0;
    } else if (strcmp(cmd, "save") == 0) { // save コマンド
      FILE *save_fp;
      scanf(fmt, arg); // 保存ファイル名の入力
      save_fp = fopen(arg, "w");
      if (save_fp == NULL) {
        perror("オープン失敗");
      } else {
        fprintf(save_fp, "%d\n", total);
        fclose(save_fp);
      }
    } else if (strcmp(cmd, "help") == 0) { // help コマンド
      help();
    }

    // この辺りに他のコマンドを追加してゆくよ

    else { // コマンドが１個だけならこの else は冗長．break 直後なので．
      printf("エラー：不明なコマンド：%s\n", cmd);
    }
    printf("\n");
  }
  printf("終了．\n\n");
  return (0);
}