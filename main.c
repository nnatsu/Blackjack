#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "main.h"
#include "userInput.h"
#include "dealing.h"
#include "hit.h"
#include "rounds.h"
#include "evaluate.h"
#include "winnings.h"

int main(){
    //CONNIE init stuff used in evaluate.h
    init_stat();
    //ask for number of players
    numberOfPlayers();
    //ask players to choose a level
    selectLevel();
    //take each players bet
    betTaker();
    //deal all players their  intial hand
    dealHand();
    //display each players hand
    displayHand();
    //loop through each player
    for (int i = 0; i <numPlayers; i++){
        printf("Player %d:\n", i+1);
        int hit = hitDecide();
        while (hit == 1) {
            dealCard(i, 0);
            displayHand();
            hit = hitDecide();
        }
    }
    return 0;
}

#endif
