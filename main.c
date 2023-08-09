#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pig2_system.h"



int main(void)
{
    struct Hito player1;
    struct Hito player2;

    // 読み込んだテキストを格納
    char ch;
    // ファイルポインタ
    FILE *fp;
    // ファイルオープン
    fp = fopen("setsumei.txt", "r");
    // ファイルが正しく読み込まれているかどうか確認
    if (fp == NULL)
    {
        printf("\aファイルをオープンできません。\n");
    }
    else
    {
        // ファイルの読み込みと出力
        while ((ch = fgetc(fp)) != EOF)
        {
            putchar(ch);
        }
        // ファイルクローズ
        fclose(fp);
    }

    // 名前の入力
    printf("player1の名前:");
    scanf("%s", player1.name);
    printf("player2の名前:");
    scanf("%s", player2.name);

    puts("それではゲームを始めます");
    printf("先攻は%sです\n", player1.name);

    // 各プレイヤーのポイントとカウントの初期化
    player1.point = 0;
    player1.count = 0;
    player2.point = 0;
    player2.count = 0;

    // ゲームスタート
    game(&player1, &player2);

    return (0);
}