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

//Uses and modify's the state of the interp according to the commands given
// void translateBF(struct BFState * interp, char * commands){
// 	int iP = 0; //Instruction pointer
// 	for(;iP < strlen(commands);iP++){

// 	}

// }


#endif
