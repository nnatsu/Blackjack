//Makefile

main: main.o hit.o evaluate.o rounds.o winnings.o dealing.o userInput.o
			gcc -o main main.o hit.o evaluate.o rounds.o winnings.o dealing.o userInput.o
			
main.o: main.c main.h evaluate.h hit.h rounds.h winnings.h dealing.h userInput.h
			gcc -c justify.c
			
hit.o: hit.c hit.h main.h dealing.h
			gcc -c hit.c
			
evaluate.o: evaluate.c evaluate.h winnings.h main.h
			gcc -c evaluate.c
			
rounds.o: rounds.c rounds.h main.h
			gcc -c rounds.c
			
winnings.o: winnings.c winnings.h evaluate.h
			gcc -c winnings.c
			
dealing.o: dealings.c dealings.h main.h
			gcc -c dealings.c
			
userInput.o: userInput.c userInput.h main.h
			gcc -c userInput.c
