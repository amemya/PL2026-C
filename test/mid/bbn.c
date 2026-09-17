#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;        // 手札全体の枚数
    int f[14] = {};   // 手札の各番号の枚数
    int s[14] = {};   // 配付済みの各番号の枚数
    int d;            // 番号

    do {
HAND:   // 手札の表示
        printf("現在の手札 (%d 枚) : ", n);
        for ( d = 1 ; d <= 13 ; d++ ) {
            if ( f[d] == 0 ) continue ;
            printf("%d ", d);
        }
        printf( "\n" );

DRAW:   // 手札の追加 (1〜13の乱数)
        d = rand() % 13 + 1 ;
        if ( s[d] >= 4 ) goto DRAW ;
        s[d]++ ;
        printf( "番号: %d\n" , d );
        f[d]++ ;
        n++ ;

PAIR:   // ペアの判定, 手札の除去
        if ( f[d] == 2 ) {
            printf( "ペア成立\n" );
            f[d] = 0 ;
            n -= 2 ;
        }
    } while ( n > 0 );
    printf( "終了\n" );

    return (0);
}
