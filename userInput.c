#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#include "userInput.h"

int printed;

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

/***asks and stores at what level the human players want to play at***/
void selectLevel(){
    
    char tempLevel;
    
    //ask user which level they want to play at
    printf("Choose a level. Enter 0 for Easy or 1 for Hard. ");
    scanf(" %c", &tempLevel);
    
    //make sure the value enteres is a 0 or 1
    if (tempLevel == '0'){
        levels = 0;
        printf("You chose to play Easy\n");
    } else if (tempLevel == '1'){
        levels = 1;
        printf("You chose to play Hard\n");
    } else {
        printf("Error: the level entered is not a valid level\n");
        exit(0);
    }
}

/***takes in and stores all human players bets***/
void betTaker(){
    for (int i = 0; i < numPlayers; i++){
        //ask user to input their bet
        printed = 0;
        
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
        if (printed == 0){
            printf("Your bet exceeds the amount of money you currently have. You currently have $%d. Please enter a new bet: ", players[p].currentM);
            printed++;
        } else {
            scanf("%d", &players[p].bet);
        }
        //printf("printed was: %d\n", printed);
        getchar();
        
        return 1;
    }
    
    //if bet is less than min_bet ask for new bet
    if (b < MIN_BET){
        if (printed == 0){
            printf("Your bet is less than the minimum bet. Please enter a new bet: ");
            scanf("%d", &players[p].bet);
            printed++;
        } else {
            scanf("%d", &players[p].bet);
        }
        //printf("printed was: %d\n", printed);
        getchar();
        return 1;
    }
    return 0;
}
