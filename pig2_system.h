// 名前の文字数
#define NAME_LEN 64

struct Hito
{
    // 名前
    char name[NAME_LEN];
    // 獲得ポイント
    int point;
    // サイコロを振った数
    int count;
};

int judge(int me);
int pointJudge(struct Hito *h, struct Hito *i);
int dice(void);
void miss(void);
void player_turn(struct Hito *h);
void player_turn30(struct Hito *h);
void samePoint(struct Hito *h, struct Hito *i);
void game(struct Hito *h, struct Hito *i);