#include "IOHelp.h" //Also includes string,io,stdlib
#include "BFState.h"//All the BF compiler stuffs
#include "BFInterp.h"

//Use proper form of main to accept cmdline
int main(int argc, char *argv[]){
	//Look at the command line arguments
	FILE * fp = parseArguments(argc,argv);
	
	BFState thing = createNewBFState(30000);
	if(fp == NULL){
		//No file but are there brainfuck commands being passed to the program?
		if(argc > 1){
			//Yes there are! Do stuff with them!
			int i=1;
			for(; i < argc; i++){
				translateBF(&thing,argv[i]);
			}
		}else{
			//No arguments. Begin interactive interpreter here or do nothing
			//TODO: Make interactive bit (taking input, making sure to grab input if a [ shows up until a ] does. )
		}
	}else{
		//Read the file here and translate it.
		char * commands = readFromFile(fp);
		//Now do it.
		translateBF(&thing,commands);
	}

	//Tests by doing Hellow World.
	//translateBF(&thing,"++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.");

	printf("\nCompiled\n\n");

	//Free memory
	freeBFState(&thing);


	return(0);
}
