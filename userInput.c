#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#include "userInput.h"


/***asks and stores how many human players will play in current round***/
void numberOfPlayers(){
    //ask the user to input how many players they want to play
    printf("How many human players? ");
    scanf("%d", &numPlayers);
    
    //make sure numPlayers does not exceed MAX_PLAYERS
    if (numPlayers > MAX_PLAYERS){
        printf("Error: the number of players entered exceed the maximum number of players allowed\n");
        exit(0);
    }
    
    //make sure the value entered is a real number
    if (numPlayers == 0){
        printf("Error: the number of players entered is not a valid number\n");
        exit(0);
    }
    
    //give all the players their starting amount of money
    for (int i = 0; i < numPlayers; i++){
        players[i].currentM = INITIAL_MONEY;
    }
    printf("Every player currently has $%d\n", players[0].currentM);
}

/***takes in and stores all human players bets***/
void betTaker(){
    for (int i = 0; i < numPlayers; i++){
        //ask user to input their bet
        printf("Player %d, please enter your bet (minimum bet is $%d): ", i+1, MIN_BET);
        scanf("%d", &players[i].bet);
        
        while (validBet(players[i].bet, i) != 0){
            validBet(players[i].bet, i);
        }

        printf("Player %d bet $%d\n", i+1, players[i].bet);
        
    }
}

int validBet(int b, int p){
    //if bet is greater than their currentM ask for new bet
    if (b > players[p].currentM){
        printf("Your bet exceeds the amount of money you currently have. You currently have $%d. Please enter a new bet: ", players[p].currentM);
        scanf("%d", &players[p].bet);
        printf("Bet was: %d\n", players[p].bet);
        getchar();
        return 1;
    }
    
    //if bet is less than min_bet ask for new bet
    if (b < MIN_BET){
        printf("Your bet is less than the minimum bet. Please enter a new bet: ");
        scanf("%d", &players[p].bet);
        printf("Bet was: %d\n", players[p].bet);
        getchar();
        return 1;
    }
    return 0;
}
