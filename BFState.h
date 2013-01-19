
//Include guard (Stdlib)
#ifndef __stdlib_H_INCLUDED__ 
	#define __stdlib_H_INCLUDED__
	#include <stdlib.h>

#endif

//Include guard (BF State)
#ifndef __BFSTATE_H_INCLUDED__
	#define __BFSTATE_H_INCLUDED__
	

#ifndef __stdio_H_INCLUDED__
	#define __stdio_H_INCLUDED__
	#include <stdio.h>
#endif

#ifndef __string_H_INCLUDED__
	#define __string_H_INCLUDED__
	//Needed for memset
	#include <string.h>

#endif


typedef struct {
	//The Turing Tape in this tarpit that we'll be playing with.
	char * tape;
	int dataPointer;
	int currentSize;

} BFState;

BFState createNewBFState(int size);

//Free's the memory allocated to the BFState's tape and resets its variables
void freeBFState(BFState * interp);

//Takes a BFState pointer and modifys dataPointer and the size of the tape and currentSize
void incrementDataPointer(BFState * interp);

//Modifies State of the BFState to have dataPointer -1
void decrementDataPointer(BFState * interp );

void incrementCurrentByte(BFState * interp);

void decrementCurrentByte(BFState * interp);

void outputByte(const BFState * interp);

void inputByte(BFState * interp);


//Brackets [] where [ = while(tape[datapointer]!=0){  and  ] = } 
//should be implemented during program execution of reading the file or
//interpretting results.

#endif
