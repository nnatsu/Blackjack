#ifndef _evaluate_h
#define _evaluate_h

typedef struct struct Stat;

struct Stat{
    int stat;
    int bet;
    Stat *next;
    Stat *prev;
};

Stat *head, *tail;

void init_stat();

void card_evaluator(player *p);

void compare_final_hands(player *p, player *d);

#endif
