#include <stdio.h>
#include "main.h"

/***Takes in who won from compareFinalHands, given the winnter it tells the player how much money they won or lost***/
int distributeWinnings(int winner, int currentPlayer){
    if (winner == 1){
        printf("Player %d wins $%d\n", currentPlayer+1, (players[currentPlayer].bet)*3);
        return (players[currentPlayer].bet)*3;
    } else if (winner == 0){
        printf("Player %d lost $%d\n", currentPlayer+1, -(players[currentPlayer].bet)*2);
        return -(players[currentPlayer].bet)*2;
    } else if (winner == 2){
        printf("There was a draw, both the dealer and player %d had the same number of points. Player %d gets to keep their bet of %d\n", currentPlayer+1, currentPlayer+1, players[currentPlayer].bet);
        return 0;
    }
    return 0;
}

/***Takes in the amount won or lost by a player and modifies how much money they currently have***/
void keepTrackOfWinnings(int winnings, int currentPlayer){
    players[currentPlayer].currentM = players[currentPlayer].currentM + winnings;
    
    printf("Player %d now has $%d total\n", currentPlayer+1, players[currentPlayer].currentM);
}
