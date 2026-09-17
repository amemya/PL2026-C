#include <stdio.h>
#include <string.h>

#define LEN  64
#define FMT  "%s"

int main(void)
{
    FILE  *fp;
    char    buf[ LEN ];
    int     r;

    while (1) {
        printf("ファイル名 > ");
        r = scanf(FMT, buf);
        if (r == EOF ) break;
        if ( strlen (buf) == 1) break;

        fp = fopen (buf, "w");
        if (fp == NULL) {
            perror("作成失敗");
            continue;
        }
        printf ("%s の作成成功\n", buf);
        fclose (fp) ;
    }
    return 0;
}
