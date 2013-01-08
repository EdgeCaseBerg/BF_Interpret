#include "IOHelp.h" //Also includes string,io,stdlib

//The Turing Tape in this tarpit that we'll be playing with.
char tape[30000];

//Use proper form of main to accept cmdline
int main(int argc, char *argv[]){
	//Look at the command line arguments
	FILE * fp = parseArguments(argc,argv);
	
	if(fp == NULL){

	}

	printf("\nCompiled\n\n");
	
	getchar();
	return(0);
}