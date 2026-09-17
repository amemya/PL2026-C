#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int f[14] = {0}; // 現在の手札にある番号dの枚数
    int s[14] = {0}; // これまでに配付された番号dの枚数
    int hand_count = 0; // 現在の手札の合計枚数

    // 乱数の種を初期化
    srand((unsigned)time(NULL));

    while (1) {
        // 現在の手札を表示
        printf("現在の手札 (%d 枚) :", hand_count);
        if (hand_count == 0) {
            printf(" \n");
        } else {
            for (int i = 1; i <= 13; i++) {
                if (f[i] > 0) {
                    printf(" %d", i);
                }
            }
            printf("\n");
        }

        // 番号をランダムに生成し、配付済みの同番号が4枚以上の場合は再生成
        int d;
        while (1) {
            d = rand() % 13 + 1;
            if (s[d] < 4) {
                break;
            }
        }
        
        printf("番号: %d\n", d);
        s[d]++; // 配付済みの枚数をカウントアップ

        // ペアの判定
        if (f[d] == 1) {
            printf("ペア成立\n");
            f[d] = 0; // ペアになったら手札から除去
            hand_count--;
        } else {
            f[d] = 1; // 手札に追加
            hand_count++;
        }

        // 手札がゼロ枚になったら終了
        if (hand_count == 0) {
            printf("終了\n");
            break;
        }
    }

    return 0;
}
