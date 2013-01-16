#include "IOHelp.h" //Also includes string,io,stdlib
#include "BFState.h"//All the BF compiler stuffs

//Use proper form of main to accept cmdline
int main(int argc, char *argv[]){
	//Look at the command line arguments
	FILE * fp = parseArguments(argc,argv);
	
	struct BFState thing;
	thing.currentSize = 30000;
	thing.tape = malloc(thing.currentSize);
	thing.dataPointer = 0;

	if(fp == NULL){
		//No file but are there brainfuck commands being passed to the program?
		if(argc > 1){
			//Yes there are! Do stuff with them!
		}else{
			//No arguments. Begin interactive interpreter here or do nothing
		}
	}

	//Tests
	incrementDataPointer(&thing);
	incrementCurrentByte(&thing);
	decrementDataPointer(&thing);
	decrementDataPointer(&thing);
	int i;
	for(i=0; i <53; i++){
		incrementCurrentByte(&thing);	
	}
	

	outputByte(&thing);
	printf("%c\n",thing.tape[thing.dataPointer]);
	printf("%i\n",thing.dataPointer );
	printf("%i\n",thing.currentSize );

	printf("\nCompiled\n\n");

	//Free memory
	freeBFState(&thing);


	return(0);
}