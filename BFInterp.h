#ifndef __BFInterp_H__
	#define __BFInterp_H__

#include "BFState.h"


/* May modify the state of BFState according to the command
   Returns 1 if a jump command is found ( '[' or ']') so that the control
   process can handle a search for the matching one
   Returns 2 if a comment or a noncommand is found
   Returns 0 for anything else.
*/
int handleStateChange(BFState * interp,char command);


//Takes the instructions and current instructionPointer value, begins the search and
//returns the index of the brace, if none is found returns -1
int findRightBrace(char * commands, int instructionPointer);

int findLeftBrace(char * commands, int instructionPointer);

//Uses and modify's the state of the interp according to the commands given
void translateBF(BFState * interp, char * commands);


//Read in from the user and when they hit enter, if there is no mismatches in braces
//accept the input and output the BF results. If there is a mismatch, let them know
//and don't accept the input.

void interpreter(BFState * interp);




#endif
