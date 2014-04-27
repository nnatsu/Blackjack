#include <stdio.h>
#include "main.h"

/***Takes in who won from compareFinalHands, given the winnter it tells the player how much money they won or lost***/
int distributeWinnings(int winner, int currentPlayer){
    if (winner == currentPlayer){
        printf("Player %d wins $%d\n", currentPlayer, players[currentPlayer].bet);
        return (players[currentPlayer].bet)*3;
    } else {
        printf("Player %d lost $%d\n", currentPlayer, -players[currentPlayer].bet);
        return -(players[currentPlayer].bet)*2;
    }
}

/***Takes in the amount won or lost by a player and modifies how much money they currently have***/
void keepTrackOfWinnings(int winnings, int currentPlayer){
    players[currentPlayer].currentM = players[currentPlayer].currentM + winnings;
    
    printf("Player %d now has $%d total\n", currentPlayer, players[currentPlayer].currentM);
}
