#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pig2_system.h"




// サイコロの目
int me;
// サイコロを振り続けるか
char retry;
// retryに入力された文字を数値に変換
int convert;



// サイコロの目が1かどうかを判断する
int judge(int me)
{
    int r;

    // サイコロの目が1の時0を返す
    if (me == 1)
    {
        r = 0;
    }
    // サイコロの目が1以外のとき1を返す
    else
        r = 1;

    return (r);
}

// ポイントが30に達したかどうかを判断する
int pointJudge(struct Hito *h, struct Hito *i)
{
    int x = 0;
    //30点で同点のとき3を返す
    if (h->point == 30 && i->point == 30)
        x = 3;
    // プレイヤー1のポイントが30に達したら1を返す
    else if (h->point == 30)
        x = 1;
    // プレイヤー2のポイントが30に達したら2を返す
    else if (i->point == 30)
        x = 2;
    // どちらのプレイヤーも30ポイントに達していないとき0を返す
    else
        x = 0;

    return (x);
}

// サイコロ
int dice(void)
{
    // 乱数の仕組みの初期化
    srand((unsigned)time(NULL));

    // 乱数を6で割った余りに1を足して1から6の値をランダムに代入
    me = (rand() % 6) + 1;

    return (me);
}

// 1,2以外が入力されたときの対処
void miss(void)
{
    // 1,2以外が入力されたとき
    puts("1か2を入力してください。");
}

// ゲームの動作
void player_turn(struct Hito *h)
{
    // プレイヤーのポイントが30に達するまで繰り返す
    while (h->point < 30)
    {
        printf("%sの番です\n", h->name);
        printf("サイコロを振りますか？【はい…1／いいえ…2】：");
        scanf(" %c", &retry);
        // 文字を数値に変換する
        convert = retry - '0';
        if (convert == 1)
        {
            printf("サイコロの目は%dでした\n", dice());
            // サイコロの目が1のとき
            if (judge(me) == 0)
            {
                // このターンで得たポイントを引く
                h->point = (h->point) - (h->count);
                // ポイント表示
                printf("現在のポイントは%dです。\n", h->point);
                // このターンでサイコロを振った数を初期化
                h->count = 0;
                break;
            }
            // サイコロの目が1以外のとき合計ポイントとこのターンのポイントに1を足す
            h->point++;
            h->count++;
            printf("現在のポイントは%dです。\n", h->point);
        }
        // サイコロを振らない選択をした場合
        else if (convert == 2)
        {
            // ポイント表示
            printf("現在のポイントは%dです。\n", h->point);
            // このターンでサイコロを振った数を初期化
            h->count = 0;
            break;
        }
        // それ以外の入力のとき
        else if (convert != 1 && convert != 2)
        {
            miss();
        }
    }
}

//30ポイント以上のときの動作
void player_turn30(struct Hito *h)
{
    h->count = 0;
    //３０ポイント以上のとき
    while ((h->point)>=30)
    {
        printf("%sの番です\n", h->name);
        printf("サイコロを振りますか？【はい…1／いいえ…2】：");
        scanf(" %c", &retry);
        // 文字を数値に変換する
        convert = retry - '0';
        if (convert == 1)
        {
            printf("サイコロの目は%dでした\n", dice());
            // サイコロの目が1のとき
            if (judge(me) == 0)
            {
                // このターンで得たポイントを引く
                h->point = (h->point) - (h->count);
                // ポイント表示
                printf("現在のポイントは%dです。\n", h->point);
                // このターンでサイコロを振った数を初期化
                h->count = 0;
                break;
            }
            h->point++;
            h->count++;
            printf("現在のポイントは%dです。\n", h->point);
        }
        // サイコロを振らない選択をした場合
        else if (convert == 2)
        {
            // ポイント表示
            printf("現在のポイントは%dです。\n", h->point);
            // このターンでサイコロを振った数を初期化
            h->count = 0;
            break;
        }
        // それ以外の入力のとき
        else if (convert != 1 && convert != 2)
        {
            miss();
        }
    }
}

// 30点で同点のとき
void samePoint(struct Hito *h, struct Hito *i)
{
    // ポイントに差がつくまでゲーム継続
    while ((h->point) == (i->point))
    {
        player_turn30(h);
        player_turn30(i);
    }
    // プレイヤー1のポイントのほうが大きいとき
    if ((h->point) > (i->point))
        printf("%sの勝利です。\n", h->name);
    // プレイヤー2のポイントのほうが大きいとき
    else if ((h->point) < (i->point))
        printf("%sの勝利です。\n", i->name);
}

// ゲームの進行
void game(struct Hito *h, struct Hito *i)
{
    // どちらかのプレイヤーのポイントが30に達するまで繰り返す
    while (pointJudge(h, i) == 0)
    {
        player_turn(h);
        player_turn(i);
    }
    // プレイヤー1が先に30ポイントに達したとき
    if (pointJudge(h, i) == 1)
        printf("%sの勝利です。\n", h->name);

    // プレイヤー2が先に30ポイントに達したとき
    else if (pointJudge(h, i) == 2)
        printf("%sの勝利です。\n", i->name);
    // 30ポイントで同点になったとき
    else if (pointJudge(h, i) == 3)
    {
        samePoint(h, i);
    }
}