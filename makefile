finalProject: main.o hit.o evaluate1.o winnings1.o dealing.o userInput.o rounds.o
	gcc -o finalProject main.o hit.o evaluate1.o winnings1.o dealing.o userInput.o rounds.o
main.o: main.c main.h evaluate1.h hit.h rounds.h winnings1.h dealing.h userInput.h
	gcc -c main.c
hit.o: hit.c hit.h main.h dealing.h
	gcc -c hit.c
evaluate1.o: evaluate1.c evaluate1.h winnings1.h main.h hit.h
	gcc -c evaluate1.c
winnings1.o: winnings1.c winnings1.h evaluate1.h
	gcc -c winnings1.c
dealing.o: dealing.c dealing.h main.h
	gcc -c dealing.c
userInput.o: userInput.c userInput.h main.h
	gcc -c userInput.c
rounds.o: rounds.c rounds.h main.h
	gcc -c rounds.c
