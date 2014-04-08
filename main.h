#define MAX_PLAYERS 5
#define MAX_CARDS 15
char handComp[MAX_CARDS];
int numRounds;              //the number of rounds that have been played so far
int numPlayers;             //the number of human players playing
int playing;                //variable to hold whether or not to keep playing the game, 1=yes 0=no
struct player {
    int bet;                //the bet for the current round
    int currentM;           //the amount of money the player currently has
    char hand[MAX_CARDS];   //the hands the player currently has
};

struct player players[MAX_PLAYERS];     //array of players in game
