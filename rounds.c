#include <stdio.h>
#include"main.h"
#include"rounds.h"

/*
int playAgain: Asks the users if they would like to play again. Returns 1 if they answer yes, returns 0 if they answer no.
*/ 
int playAgain() {
    getchar();
    printf("Do you want to play again? (Answer y or n)\n");
    
    char c;
  int x = 0;
  scanf("%c", &c);
  //look for correct input
  while(x == 0) {
    if(c != 'y' && c != 'n') {
      printf("I am sorry but your input was not correct. Would you like to play again (Answer y or n) \n");
      scanf("%c", &c);
    } else {
      x = 1;
    }
  }
  //return yes or no
  if(c == 'y') {
    return 1;
  } else  {
    return 0;
  }
}
/*
void displayFinalScore(): This function prints out the amount of money that each player has won or lost throughout the game. It also displays how many rounds were played. It returns nothing.
*/
void displayFinalScore() {
  printf("Here are the final statistics for your game:\n");
  int finalScore; //keep track of final score
  for(int i = 0; i < numPlayers; i++) {
    //loop through players and display their final score
    finalScore = players[i].currentM;
    printf("Player %d's final score is: %d\n", i+1, finalScore);
  }
  printf("You played %d rounds during this game\n", numRounds);
}
/*
Void reset(): This function takes in nothing and clears the players' and the computer's hands.
*/
void reset() {
  int i, j;
  //loop through players and clear their hands
  for(j = 0; j < MAX_PLAYERS; j++) {
    for(i = 0; i < MAX_CARDS; i++) {
      players[j].hand[i][0] = 0;
      players[j].hand[i][1] = 0;
      players[j].bet = 0;
      players[j].numCards = 0;
    }
  }
  //clear computers hand and clear array of already dealt cards
  for(i = 0; i < MAX_CARDS; i++) {
    handComp[i][0] = 0;
    handComp[i][1] = 0;
    dealt[i][0] = 0;
    dealt[i][1] = 0;
  }
  //reset number of computer cards
  compCards = 0;
}
  
