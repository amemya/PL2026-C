#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

// qsort用の比較関数（昇順ソート用）
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int scores[MAX_STUDENTS];
    int freq[11] = {0}; // 階級: 0-9, 10-19, ..., 90-99, 100
    int count = 0;
    int sum = 0;

    printf("点数を入力してください（0〜100）。\n");
    printf("負の数（-1など）を入力すると入力を終了し、結果を表示します。\n\n");

    // 点数の手入力ループ
    while (count < MAX_STUDENTS) {
        int score;
        printf("%d人目の点数: ", count + 1);
        
        // 入力値の取得
        if (scanf("%d", &score) != 1) {
            // 数値以外が入力された場合の読み飛ばし
            while (getchar() != '\n');
            printf("エラー：正しい数値を入力してください。\n");
            continue;
        }

        // 負の数が入力されたらループを終了
        if (score < 0) {
            break;
        }

        // 範囲外の数値のチェック
        if (score > 100) {
            printf("エラー：0から100までの点数を入力してください。\n");
            continue;
        }

        // データの保存
        scores[count] = score;
        sum += score;
        
        // ヒストグラム用の度数カウント
        int index = score / 10;
        freq[index]++;
        
        count++;
    }

    if (count == 0) {
        printf("データが入力されていません。\n");
        return 0;
    }

    // --- 平均点の計算 ---
    double average = (double)sum / count;

    // --- 中央値の計算 ---
    // まず配列を昇順にソートする
    qsort(scores, count, sizeof(int), compare);
    
    double median;
    if (count % 2 == 0) {
        // データ数が偶数の場合、中央の2つの値の平均
        median = (scores[count / 2 - 1] + scores[count / 2]) / 2.0;
    } else {
        // データ数が奇数の場合、ちょうど中央の値
        median = scores[count / 2];
    }

    // --- 結果の出力 ---
    printf("\n==================================\n");
    printf("【基本統計量】\n");
    printf("受験者数: %d人\n", count);
    printf("平均点  : %.1f点\n", average);
    printf("中央値  : %.1f点\n", median);
    printf("==================================\n\n");

    printf("【成績の度数分布（ヒストグラム）】\n");
    for (int i = 0; i <= 10; i++) {
        if (i == 10) {
            printf("  100: ");
        } else {
            printf("%2d-%2d: ", i * 10, i * 10 + 9);
        }

        // 度数の数だけ '*' を出力
        for (int j = 0; j < freq[i]; j++) {
            printf("*");
        }
        printf(" (%d人)\n", freq[i]);
    }

    return 0;
}
