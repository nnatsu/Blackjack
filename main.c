#include <stdio.h>
#include "main.h"
#include "userInput.h"
#include "dealing.h"
#include "hit.h"
#include "rounds.h"
#include "evaluate1.h"
#include "winnings1.h"
//#include "evaluate.h"
//#include "winnings.h"

int main(){
    //CONNIE init stuff used in evaluate.h
    //init_stat();
    
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
    int i;
    for  (i = 0; i < numPlayers; i++){
        printf("Player %d:\n", i+1);
        int hit = hitDecide(i);
        while (hit == 1) {
            dealCard(i, 0);
            displayHand();
            hit = hitDecide(i);
        }
    }
    //hit for the computer
    computerHit();
    
    for (i = 0; i < numPlayers; i++){
        int winner = evaluate(i);
        int money = distributeWinnings(winner, i);
        keepTrackOfWinnings(money, i);
    }
    return 0;
}
