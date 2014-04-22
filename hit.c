#include <stdio.h>
#include"hit.h"
#include"main.h"
#include "dealing.h"

int printed;

/*
int hitDecide(): this function askes the user if they want to hit or not. Returns a 1 if they answer with a y, returns a 0 if they answer with a n.
*/
int hitDecide() {
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
  int total = 0;
  total = totalValue(); //calculate the total value of the hand
  //dealer hits soft 17
  if(levels == 0) {
    while(total <= 17) { //keep hitting until hand is greater than or equal to 17
    dealCard(100, compCards);
    compCards++;
    total = totalValue();
    }
    //dealer hits hard 17
  } else if(levels == 1) {
    while(total < 17) {
      dealCard(100, compCards);
      compCards++;
      total = totalValue();
    }
  }
}
/* 
int cardValue(char c): this function takes in the letter representation of a card and returns its numerical value.
*/
int cardValue(char c) {
  int value;
  //find integer value
  if('2' <= c <= '9') {
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
int totalValue() {
    char c;
    int total, numAce = 0;
    //loop through cards and calculates their values
    for(int i = 0; i < compCards; i++) {
      c = handComp[i][0];
      if (c == 'a') {
          numAce++;
      }
      total += cardValue(c);
      while (total > 21 && numAce > 0) {
          total -= 10; //adjusts computer's total if they bust but can count an ace as 1 instead of 11
      }
    }
    return total;
}
