//Required to have return type of FILE

#ifndef __IOHELP_H_INCLUDED__
	#define __IOHELP_H_INCLUDED__
	#include <stdio.h>
//Opens a file whose name is passed through cmdline arguments if it exists
FILE * parseArguments(int argc, char * argv[]);

//Essentially load a string into a char array while checking the validatity of the 
//string itself. (braces closed)
char * readFromFile(FILE * fp);


#endif
