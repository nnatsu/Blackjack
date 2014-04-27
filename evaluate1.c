#include <stdio.h>
#include "evaluate1.h"
#include "main.h"
#include "winnings1.h"
#include "hit.h"

int evaluate(int j) {

  int computerVal = totalValue(100);
  int playerVal = totalValue(j);
  printf("The total of the computer's final hand is %d and the total of the player %d's final hand is %d\n", computerVal, j+1, playerVal);
  if (computerVal > 21 && playerVal > 21) {
    return 2;
  } else if (playerVal > 21){
      return 0;
  }else if (computerVal > playerVal) {
    return 0;
  } else if (playerVal > computerVal) {
    return 1;
  } else {
    return 2;
  }
}
