#include"hit.h"
#include"main.h"

/*
int hitDecide(): this function askes the user if they want to hit or not. Returns a 1 if they answer with a y, returns a 0 if they answer with a n.
*/
int hitDecide() {
  printf("Do you want a hit(another card)? (Answer y or n)\n");
  char c;
  int x = 0;
  //take in input
  scanf("%c", &c);
  //wait for acceptable input
  while(x == 0) {
    if(c != 'y' && c != 'n') {
      printf("I am sorry but your input was not correct. Please try again:\n");
      scanf("%c", &c);
    } else {
      x = 1;
    }
  }
  //return correct number
  if(c == 'y') {
    printf("y\n");
    return 1;
  } else  {
    printf("n\n");
    return 0;
  }
}

