./bin/test: ./bin/main.o ./bin/BFState.o ./bin/BFInterp.o ./bin/IOHelp.o
	gcc -o ./bin/test ./bin/main.o ./bin/BFState.o ./bin/BFInterp.o ./bin/IOHelp.o

./bin/main.o: ./main.c
	gcc -o ./bin/main.o -c ./main.c

./bin/BFInterp.o: ./BFInterp.c ./BFInterp.h
	gcc -o ./bin/BFInterp.o -c ./BFInterp.c

./bin/IOHelp.o: ./IOHelp.c ./IOHelp.h
	gcc -o ./bin/IOHelp.o -c ./IOHelp.c

./bin/BFState.o: ./BFState.c ./BFState.h
	gcc -o ./bin/BFState.o -c ./BFState.c

