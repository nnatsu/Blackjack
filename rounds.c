
#include<main.h>
#include<rounds.h>

/*
int playAgain: Asks the users if they would like to play again. Returns 1 if they answer yes, returns 0 if they answer no.
*/ 
int playAgain() {
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
    printf("y\n");
    return 1;
  } else  {
    printf("n\n");
    return 0;
  }
}
