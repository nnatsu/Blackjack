#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "dealing.h"

int inHand[NUM_SUITS][NUM_RANKS] = {0};
const char rankCode[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
const char suitCode[] = {'C', 'D', 'H', 'S'};

void dealCard(int p, int numCards){
    int rank, suit;
    srand((unsigned) time(NULL));
    
    //check to see if we are dealing a card to the computer
    if (p == 100){
        while (numCards >= 0){
            suit = rand() % NUM_SUITS;      //pick random suit
            rank = rand() % NUM_RANKS;      //pick random rank

            //check to make sure the card hasnt already been dealt
            if (inHand[suit][rank] == 0){
                inHand[suit][rank] = 1;
        
                int i = 0;
                
                //find an emply space in their hand
                while (handComp[i][0] != 0){
                    i++;
                }
                
                //put the card in the computers hand
                if (handComp[i][0] == 0){
                    handComp[i][0] = suitCode[suit];
                    handComp[i][1] = rankCode[rank];
                }
                numCards--;
            }
        }
    //otherwise we are dealing a card to a player
    } else {
        while (numCards >= 0){
            suit = rand() % NUM_SUITS;      //pick random suit
            rank = rand() % NUM_RANKS;      //pick random rank

            //check to make sure the card hasnt already been dealt
            if (inHand[suit][rank] == 0){
                inHand[suit][rank] = 1;
                
                int i = 0;
                
                //find an emply space in their hand
                while (players[p].hand[i][0] != 0){
                    i++;
                }
        
                //put the card in the players hand
                if(players[p].hand[i][0] == 0){
                    players[p].hand[i][0] = suitCode[suit];
                    players[p].hand[i][1] = rankCode[rank];
                }
                numCards--;
            }
        }
    }
}

/***deals a specified number of cards***/
void dealHand(){
    //give each player two cards
    for (int i = 0; i < numPlayers; i++){
        dealCard(i, 1);
    }
    
    //deal the computers initial hand
    dealCard(100, 1);
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
