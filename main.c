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

void playGame(){
    //take each players bet
    betTaker();
    //deal all players their  intial hand
    dealHand();
    //display each players hand
    displayHand();
    //loop through each player
    int i;
    for (i = 0; i < numPlayers; i++){
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
}

int main(){

    numRounds = 1;
    
    //ask for number of players
    numberOfPlayers();
    //ask players to choose a level
    selectLevel();
    //play game
    playGame();

    
    int round = playAgain();
    while (round == 1){
        reset();
        numRounds++;
        playGame();
        round = playAgain();
    }
    
    if (round == 0){
        displayFinalScore();
    }
    return 0;
}
