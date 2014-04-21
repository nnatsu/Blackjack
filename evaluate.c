#include <stdio.h>
#include "evaluate.h"
#include "main.h"
#include "winnings.h"

#define MAX_CARDS 15
#define BUST 0
#define SAFE 1
#define LOSE 0
#define WIN 1
#define DRAW 2

/* Inits a bunch of things */
void init_stat() {
    head = malloc(sizeof(Stat));
    tail = malloc(sizeof(Stat));
    head->next = tail;
    tail->prev = head;
}

/* Evaluates hand */
void card_evaluator(player *p) {
    int i, score = 0;
    for (i = 0; i < 15; i++) {              //Calculate final score
        score += p->hand[i];
    }
    if (score >= 21) {                      //Status is BUST, does not record score
        p->status = BUST;
        printf("Player %d: Bust\n", p->id);
    } else {                                //Status is SAFE, records score
        p->score = score;
        p->status = SAFE;
        printf("Player %d: %d points\n", p->score);
    }
}

/* Compares player's hand with the dealers and distribute
   winnings accordingly */
void compare_final_hands(player *p, player *d) {
    if (d->status == BUST) {                //Dealer is bust
        printf("Dealer busts. Returning bet to player%d.\n", p->id);
        p->currentM += p->bet;
        add_game_stat(DRAW, p);
    } else if (p->status == BUST) {         //Player is bust
        printf("Player%d busts. Loses bet.\n", p->id);
        add_game_stat(LOSE, p);
    } else {                                //Neither bust
        if (p->score > d->score) {          //Player wins
            printf("Player%d wins hand.\n", p->id);
            p->currentM += p->bet * 2;
            add_game_stat(WIN, p);
        } else if (p->score < d->score) {   //Dealer wins
            printf("Player%d loses hand.\n", p->id);
            add_game_stat(LOSE, p);
        } else {                            //Draw
            printf("Equal hand. Returning bet to player%d.\n", p->id);
            p->currentM += p->bet;
            add_game_stat(DRAW, p);
        }
    }
    
    keep_track_of_winnings(p);              //Prints money status
}