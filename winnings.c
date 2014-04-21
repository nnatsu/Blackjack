#include <stdio.h>
#include "winners.h"
#include "evaluate.h"

#define LOSE 0
#define WIN 1
#define DRAW 2

extern Stat head;
extern Stat tail;

/* Implemented in evaluate.c */
void distribute_winnings() {
    
}

/* Adds current game's stat to player for history tracking */
void add_game_stat(int stat, player *p) {
    Stat *new = malloc(sizeof(Stat));
    new->stat = stat;
    new->bet = p->bet;
    p->bet = 0;
    
    new->prev = tail->prev;
    new->next = tail;
    tail->prev->next = new;
    tail->prev = new;
}

/* Prints the current player's money */
void keep_track_of_winnings(player *p) {
    printf("Player%d currently has: %d", p->id, p->currentM);
}

/* Prints the current player's every game stat */
void print_game_stat(player *p) {
    printf("Player%d's game stat:\n", p->id);
    Stat *cur = head->next;
    while (cur->next != NULL) {
        char c;
        switch (cur->stat) {
            case LOSE:
                printf("L, %d\n", cur->bet);
                break;
            case WIN:
                printf("W, %d\n", cur->bet);
                break;
            case DRAW:
                printf("D, 0\n", cur->bet);
                break;
            default:
                break;
        }
        cur = cur->next;
    }
}