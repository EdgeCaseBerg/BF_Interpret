#ifndef __BFInterp_H__
	#define __BFInterp_H__

#include "BFState.h"



//The point of this file is to provide the main control loop in interacting with user input or
//a file that has been read in. 

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
int findRightBrace(char * commands, unsigned int instructionPointer){

	for(; instructionPointer <  strlen(commands);instructionPointer++){
		if(commands[instructionPointer]==']'){
			return instructionPointer;
		}
	}
	return -1;
}

//Uses and modify's the state of the interp according to the commands given
void translateBF(BFState * interp, char * commands){
 	unsigned int iP = 0; //Instruction pointer

 	for(;iP < strlen(commands);iP++){
 		//if the byte at the data pointer is zero, then instead of moving 
 		//the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
 		if( commands[iP] == '[' ){
 			if(interp->tape[interp->dataPointer] == 0){
 				//Find the matching ], if we don't find it before we run out of commands print an error and run away
 				printf("\n\n%i ",findRightBrace(commands,iP));
 			}else{
 				iP++;
 			}
 		//if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward 
 		//to the next command, jump it back to the command after the matching [ command.
 		}else if( commands[iP]==']'){

 		}else{
 			//handleStateChange(interp,commands[iP]);
 			iP++;
 		}
	}
	
}


#endif
