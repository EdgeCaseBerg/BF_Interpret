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

FILE * parseArguments(int argc, char * argv[]){
	if(argc > 1){
		//Look for -f flag for file input
		if(strcmp(argv[1],"-f")==0){
			//Check for a file name:
			if(argc > 2){
				//Check for the file existing.
				FILE * filePointer;
				if((filePointer = fopen(argv[2],"r"))){
					return filePointer;
				}else{
					//File could not be opened
					printf("File could not be opened.\n");
				}
			}else{
				//What are you doing?
				printf("Expected argument of file not found.\n");
			}
		}
	}
	return NULL;
}

#endif