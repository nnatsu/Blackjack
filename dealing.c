#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "dealing.h"

int inHand[NUM_SUITS][NUM_RANKS] = {0};
const char rankCode[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
const char suitCode[] = {'C', 'D', 'H', 'S'};

/***deals a specified number of cards***/
void dealHand(){
    int rank, suit;
    
    srand((unsigned) time(NULL));
    
    //give each player two cards
    for (int i = 0; i < numPlayers; i++){
        int numCards = 1;
        
        while (numCards >= 0){
            suit = rand() % NUM_SUITS;      //pick random suit
            rank = rand() % NUM_RANKS;      //pick random rank
            
            //check to make sure the card hasnt already been dealt
            if (inHand[suit][rank] == 0){
                inHand[suit][rank] = 1;
                
                //put the card in the players hand
                players[i].hand[numCards][0] = suitCode[suit];
                players[i].hand[numCards][1] = rankCode[rank];
                
                numCards--;
            }
        }
    }
    
    //deal the computers initial hand
    int numCards = 1;
    while (numCards >= 0){
        suit = rand() % NUM_SUITS;      //pick random suit
        rank = rand() % NUM_RANKS;      //pick random rank
        
        //check to make sure the card hasnt already been dealt
        if (inHand[suit][rank] == 0){
            inHand[suit][rank] = 1;
            
            //put the card in the computers hand
            handComp[numCards][0] = suitCode[suit];
            handComp[numCards][1] = rankCode[rank];
            
            numCards--;
        }
    }
}

/***prints out the cards each player currently has and one of the computers cards***/
void displayHand(){
    
    //display one of the computers cards
    printf("One of the computers cards is: %c%c\n", handComp[0][0], handComp[0][1]);
    
    //for each player, display their hand
    for (int i = 0; i < numPlayers; i++){
        printf("Player %d's current hand: ", i+1);
        for (int j = 0; j < MAX_CARDS; j++){
            printf("%c%c ", players[i].hand[j][0], players[i].hand[j][1]);
        }
        printf("\n");
    }
}
