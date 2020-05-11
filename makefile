CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fno-builtin -std=c99 -O2 -ftree-vectorize -msse2 -ftree-vectorizer-verbose=1

main: parameters.o test.o input.o engine.o main.o
	$(CC) $(CFLAGS) parameters.o test.o input.o engine.o main.o -o main -lm
	rm *.o
	@echo ""
	@echo "=============================================================================="
	@echo "#                                                                            #"
	@echo "#                               USAGE:                                       #"
	@echo "#   1. Adjust epsilon, gamma and delta or problem size in \"parameters.c\"     #" 
	@echo "#   2. Define custom function and starting vector initializer in \"input.c\"   #"
	@echo "#   3. Remake new configuration.                                             #"
	@echo "#   4. Type \"make run\" to start algorithm with custom configuration or       #"
	@echo "#      \"make test\" to run set of preset test functions.                      #"
	@echo "#   5. Open \"results.txt\" with text editor of Your choice.                   #"
	@echo "#                                                                            #"
	@echo "=============================================================================="
	@echo ""
main.o:
	$(CC) $(CFLAGS) -c main.c -o main.o
engine.o:
	$(CC) $(CFLAGS) -c engine.c -o engine.o
input.o:
	$(CC) $(CFLAGS) -c input.c -o input.o
test.o:
	$(CC) $(CFLAGS) -c test.c -o test.o
parameters.o:
	$(CC) $(CFLAGS) -c parameters.c -o parameters.o
run:
	./main -run > results.txt
test:
	./main -test > results.txt
