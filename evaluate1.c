#include <stdio.h>
#include "evaluate.h"
#include "main.h"
#include "winnings.h"
#include "hit.h"

int evaluate(int j) {
  int computerVal = totalValue(100);
  int playerVal = totalValue(j);
  printf("The total of the computer's final hand is %d and the total of the player's final hand is %d\n", computerVal, playerVal);
  if (computerVal > 21 && playerVal > 21) {
    return 2;
  } else if (computerVal > playerVal) {
    return 0;
  } else if (playerVal > computerVal) {
    return 1;
  } else {
    return 2;
  }
}
