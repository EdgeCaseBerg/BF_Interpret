#include "BFState.h"

//Include guard (Stdlib)
#ifndef __stdlib_H_INCLUDED__ 
	#define __stdlib_H_INCLUDED__
	#include <stdlib.h>
#endif

//Include guard (Stdio)
#ifndef __stdio_H_INCLUDED__
	#define __stdio_H_INCLUDED__
	#include <stdio.h>
#endif

//Include guard (String)
#ifndef __string_H_INCLUDED__
	#define __string_H_INCLUDED__
	//Needed for memset
	#include <string.h>
#endif


//This file defines how BrainFuck actually handles each incoming command.

/* May modify the state of BFState according to the command
   Returns 1 if a jump command is found ( '[' or ']') so that the control
   process can handle a search for the matching one
   Returns 2 if a comment or a noncommand is found
   Returns 0 for anything else.
*/
int handleStateChange(BFState * interp,char command){
	switch(command){
		case '>':
			incrementDataPointer(interp);
			break;
		case '<':
			decrementDataPointer(interp);
			break;
		case '+':
			incrementCurrentByte(interp);
			break;
		case '-':
			decrementCurrentByte(interp);
			break;
		case '.':
			outputByte(interp);
			break;
		case ',':
			inputByte(interp);
			break;
		case '[':
		case ']':
			return 1;
		default:
			return 2;
	}
	return 0;
}

//Takes the instructions and current instructionPointer value, begins the search and
//returns the index of the brace, if none is found returns -1
int findRightBrace(char * commands, int instructionPointer){
	for(; instructionPointer <  (int)strlen(commands); instructionPointer++){
		if(commands[instructionPointer]==']'){
			return instructionPointer;
		}
	}
	return -1;
}

int findLeftBrace(char * commands, int instructionPointer){
	for(; instructionPointer > -1; instructionPointer--){
		if(commands[instructionPointer]=='['){
			return instructionPointer;
		}
	}
	return -1;
}

//Uses and modify's the state of the interp according to the commands given
void translateBF(BFState * interp, char * commands){
 	int iP = 0; //Instruction pointer

 	for(;iP > -1 && iP < (int)strlen(commands); iP++){
 		if( commands[iP] == '[' ){
 			//if the byte at the data pointer is zero, then instead of moving 
 			//the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
 			if(interp->tape[interp->dataPointer] == 0){
 				//Find the matching ], if we don't find it before we run out of commands print an error and run away
 				iP = findRightBrace(commands,iP);
 				if(iP < 0){
 					//No matching brace run away:
 					puts("No Matching Brace for handled [. Please check your program") ;
 					//Subtract because iP++ will push us back from -1 to 0 and the instruction loop will continue.	
 					iP--;
 				}
 				//We'll automatically be pointing at the command after the ] when we loop around the for
 			}
 		}else if( commands[iP]==']'){
 			//if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward 
 			//to the next command, jump it back to the command after the matching [ command.
 			if(interp->tape[interp->dataPointer] != 0){
	 			iP = findLeftBrace(commands,iP);
	 			if(iP < 0){
	 				puts("No Matching Brace for handled ]. Please check your program");
	 				//Subtract because iP++ will push us back from -1 to 0 and the instruction loop will continue.
	 				iP--;
	 			}
	 		}

 		}else{
 			handleStateChange(interp,commands[iP]);
 		}
	}
}

//Read in from the user and when they hit enter, if there is no mismatches in braces
//accept the input and output the BF results. If there is a mismatch, let them know
//and don't accept the input.
void interpreter(BFState * interp){
	puts("Welcome to the BrainFuck Interpreter.\n You can find the full 8 commands of the language on wikipedia.\nPress q to exit.\n\n");
	
	char quitChar = 'q';
	//ASCII enter = 13
	//int accept = 13;
	//Accepting 2000 characters seems like plenty
	int size = 2000;
	char * buffer = (char *) malloc(size);
	char incomingChar = ' ';
	int curChar;
	int braceCheck = 0;
	while(incomingChar != quitChar){
		curChar=0;
		printf("\n>");
		scanf("%c",&incomingChar);
		while(incomingChar  != '\n' && incomingChar != quitChar){
			buffer[curChar] = incomingChar;
			if(incomingChar == '['){
				braceCheck++;
			}else if(incomingChar == ']'){
				braceCheck--;
			}
			curChar++;
			if(curChar > size-1){
				//We ran out of room...
				puts("Command too long! Please break your statements up or use a file");
				incomingChar = quitChar;
				continue;
			}
			scanf("%c",&incomingChar);
		}
		//Do we have any loose braces?
		if(braceCheck == 0){
			translateBF(interp,buffer);
			
		}else{
			puts("Please close your braces, your BF statement has not been executed.");
		}
		//Clear the buffer.l
		memset(buffer,0,size);
	}

}


