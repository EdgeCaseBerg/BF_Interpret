//Include guards for standard librarys
#ifndef  __stdio_H_INCLUDED__
	#define  __stdio_H_INCLUDED__
	#include <stdio.h>
#endif

#ifndef __stdlib_H_INCLUDED__ 
	#define __stdlib_H_INCLUDED__
	#include <stdlib.h>
#endif

#ifndef __string_H_INCLUDED__
	#define __string_H_INCLUDED__
	#include <string.h>
#endif

#ifndef __IOHELP_H_INCLUDED__
	#define __IOHELP_H_INCLUDED__

//Opens a file whose name is passed through cmdline arguments if it exists
FILE * parseArguments(int argc, char * argv[]);

//Essentially load a string into a char array while checking the validatity of the 
//string itself. (braces closed)
char * readFromFile(FILE * fp);


#endif