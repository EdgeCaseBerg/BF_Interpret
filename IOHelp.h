#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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