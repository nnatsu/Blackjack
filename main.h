#define MAX_PLAYERS 5
#define MAX_CARDS 15
#define INITIAL_MONEY 1000
#define MIN_BET 5
#define NUM_SUITS 4
#define NUM_RANKS 13
char handComp[MAX_CARDS][2];
int numRounds;              //the number of rounds that have been played so far
int numPlayers;             //the number of human players playing
int playing;                //variable to hold whether or not to keep playing the game, 1=yes 0=no
int levels; //the level chosen by the player
char dealt[MAX_CARDS];
struct player {
    int bet;                //the bet for the current round
    int currentM;           //the amount of money the player currently has
    char hand[MAX_CARDS][2]; //the hands the player currently has
  int numCards; //the number of cards that they player has been dealt
};

struct player players[MAX_PLAYERS];     //array of players in game
