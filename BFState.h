
//Include guard
#ifndef __stdlib_H_INCLUDED__ 
#define __stdlib_H_INCLUDED__

#include <stdlib.h>

#endif

//Include guard (BF State)
#ifndef __BFSTATE_H_INCLUDED__
#define __BFSTATE_H_INCLUDED__

typedef struct BFState{
	//The Turing Tape in this tarpit that we'll be playing with.
	char * tape;
	int dataPointer;
	int currentSize;

} BFState;

void freeBFState(struct BFState * interp){
	free(interp->tape);
	interp->dataPointer = 0;
	interp->currentSize = 0;
}

struct BFState incrementDataPointer(struct BFState interp){
	//To make sure that we don't index out of bounds we can
	//Elect to either double the size of the tape, or to wrap.
	interp.dataPointer++;
	if(interp.dataPointer >= interp.currentSize){
		//Copy the array into a new one that is larger.
		char  newTape[(interp.currentSize*2)];
		int i;
		for(i=0; i < interp.currentSize; i++){
			newTape[i] = interp.tape[i];
		}
		interp.currentSize = interp.currentSize*2;
		interp.tape = newTape;
	}
	return interp;
}


#endif