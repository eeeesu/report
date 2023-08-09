#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

int main(void){
    assert(judge(1) == 0);
    assert(judge(4) == 1);

    return (0);
}