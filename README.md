Blackjack - CS246 Final Project by Angela Mastrianni & Grace Baelen-King
------------------------------------------------------------------------

Compilation Instructions:
-------------------------


Game Play Instructions:
-----------------------
	Blackjack is a traditional casino card game in which each player plays against the dealer. All players attempt to get a hand with a value closest to 21 without going over (if a player goes over 21 it is called a “bust”). A player wins if their hand is closer to 21 than the dealers hand. A player looses if they bust or the dealers hand is closer to 21 than theirs. Each player plays against the dealer.
	In this version of Blackjack when the program starts the players are asked to indicate how many human players will be playing against the computer dealer. The maximum number of players is 5 (this can be changed by changing the MAX_PLAYERS macro defined in main.h). If the value entered is above 5 or is a non-numerical answer the program will print an error and quit.
	The user is then asked to select what level they would like to play at. 0 or easy or 1 for hard. If any value other than 0 or 1 is entered the program will print an error and quit.
	The next step is for each human player to enter their bet. Every player starts with $1000 (this can be changed by changing the INITIAL_MONEY macro defined in main.h). The minimum bet is $5 (can be changed by chaining the MIN_BET macro defined in main.h). Starting from player 1 each player is asked to enter their bet. If the bet the player enters is more than the amount of money they currently have, or if it is less than the minimum bet allowed an error is printed. The player is prompted to enter a new bet. If the new bet is also invalid the program waits for a valid bet to be entered, only one error message is printed. 
	After all the bets are taken the initial hand is dealt. Each player gets 2 initial cards, as does the dealer. The players hands are printed on the screen along with one of the dealers cards. Starting from player 1 each player is asked if they would like to hit by indicating y (yes) or n (no). If any value other than y or n is entered an error message is printed and the player is asked to reenter their answer. If the new response is also invalid the program waits for a valid answer to be entered, only one error message is printed. Each player is allowed to hit as many times as they would like (as long as the amount of cards in their hand does not exceed MAX_CARDS). Players are allowed to keep hitting even if the sum of their cards has already exceeded 21. Aces can count as high (10 points) or low (1 point) depending on which is more beneficial to the player. This change is automatically calculated, if the ace changes from either 1 to 10 or 10 to 1 a message is printed to inform the player of the change.
	After all players have finished hitting each players hand is evaluated and compared to the dealers hand. Either the player or the dealer wins. The payout is 3:2. Each players hand is evaluated in comparison to the dealers. 
	Once the players are informed of their wins or loses they are asked if they would like to play another round. If yes then another round of blackjack is started. If no a summary of the players game play is displayed.

File Manifest:
--------------
main.h
main.c
userInput.h
userInput.c
dealing.h
dealing.c
hit.h
hit.c
evaluate.h
evaluate.c
rounds.h
rounds.c
winnings.h
winnings.h
README

Contact Information:
--------------------
Angela Mastrianni
amastriann@brynmawr.edu

Grace Baelen-King
ebaelenkin@brynmawr.edu
