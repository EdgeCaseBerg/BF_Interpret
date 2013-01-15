#include "IOHelp.h" //Also includes string,io,stdlib
#include "BFState.h"//All the BF compiler stuffs

//Use proper form of main to accept cmdline
int main(int argc, char *argv[]){
	//Look at the command line arguments
	FILE * fp = parseArguments(argc,argv);
	
	

	if(fp == NULL){
		//No file but are there brainfuck commands being passed to the program?
		if(argc > 1){
			//Yes there are! Do stuff with them!
		}else{
			//No arguments. Begin interactive interpreter here or do nothing
		}
	}

	struct BFState thing;

	printf("%s\n",(char*)thing.tape );

	printf("\nCompiled\n\n");
	
	return(0);
}