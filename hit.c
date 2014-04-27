#include <stdio.h>
#include"hit.h"
#include"main.h"
#include "dealing.h"

int printed;
int numAce = 0;
int totalChange = 0;

/*
int hitDecide(): this function askes the user if they want to hit or not. Returns a 1 if they answer with a y, returns a 0 if they answer with a n.
*/
int hitDecide(int i) {
  int total = totalValue(i);
  printf("Your current total is %d\n", total);
  if(totalChange == 1) {
    printf("We adjusted the point value of your aces to keep you from busting.\n");
    totalChange = 0;
  }
  if(total > 21) {
    printf("Your total is over 21, you have busted and cannot hit anymore\n");
    return 0;
  }
  printf("Do you want a hit(another card)? (Answer y or n)\n");
  char c;
  int x = 0;
  //take in input
  scanf(" %c", &c);
  //wait for acceptable input
  while(x == 0) {
    if(c != 'y' && c != 'n') {
        if (printed == 0){
            printf("I am sorry but your input was not correct. Please try again. The game will wait until you provide correct input.\n");
            printed++;
        } else {
            scanf("%c", &c);
        }
    } else {
      x = 1;
    }
  }
  //return correct number
  if(c == 'y') {
    return 1;
  } else  {
    return 0;
  }
}

/*
void computerHit: This function determines if the computer needs another card. Keeps giving the computer another card until they have the minimum dictated by the rules.
*/
void computerHit() {
  int total = totalValue(100); //calculate the total value of the hand
  //determines when the dealer shoulds hit
    while(total < 17) {
      dealCard(100, 0);
      //compCards++;
      total = totalValue(100);
    }
  //if level is hard, dealer hits on soft 17s
  if(levels == 1 && total == 17 && numAce > 0) {
      dealCard(100, 0);
      //compCards++;
      total = totalValue(100);
  }
}
/* 
int cardValue(char c): this function takes in the letter representation of a card and returns its numerical value.
*/
int cardValue(char c) {
  int value = 0;
  //find integer value
  //if('2' <= c <= '9') {
    if (c == '2' || c == '3' || c == '4' || c == '5'|| c == '6' || c == '7' || c == '8' || c == '9'){
    value = c - 48;
  } else if (c == 't' || c == 'k' || c == 'j' || c == 'q' ){
    value = 10;
  } else {
    value = 11;
  }
  return value;
}
/*
int totalValue() : this finds the total value of the hand and returns it.
*/
int totalValue(int j) {
    char c;
    int total =  0;
    int num = 0;
    numAce = 0;
    if(j == 100) {
      num = compCards;
    } else {
      num = players[j].numCards;
    }
    //loop through cards and calculates their values
    int i;
    for(i = 0; i < num; i++) {
      if (j == 100) {
        c = handComp[i][1];
      } else {
        c = players[j].hand[i][1];
      }
      if (c == 'a') {
          numAce++;
      }
      total += cardValue(c);
      while (total > 21 && numAce > 0) {
          total -= 10; //adjusts total if they bust but can count an ace as 1 instead of 11
          totalChange = 1;
      }
    }
    return total;
}
