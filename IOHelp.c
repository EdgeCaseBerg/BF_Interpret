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


//Opens a file whose name is passed through cmdline arguments if it exists
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

//Essentially load a string into a char array while checking the validatity of the 
//string itself. (braces closed)
char * readFromFile(FILE * fp){
	int temp;
	//Allocating 30,000 which is the standard brainfuck tape size.
	int size = 30000;
	char * building = (char *) malloc(size);
	int braceCheck = 0;
	int s =0;
	while((temp = fgetc(fp)) != EOF){
		if(s > size-1){
			//If s is 29,999 then we need to make more room for the null character and such.
			//So double the size of the array and copy the old contents over.
			char * tempArray = (char *)malloc(size*2);
			int t;
			for(t=0; t < size; t++){
				tempArray[t] = building[t];
			}
			size = size*2;
			building = tempArray;
		}
		if(temp == '['){
			braceCheck++;
		}else if(temp == ']'){
			braceCheck--;
		}
		building[s] = (char)temp;
		s++;
	}
	if(braceCheck!=0){
		//Brace Check failed...
		puts("Error in file, missing a closing or opening brace.");
		return "";
	}
	//End it with a null character
	if(s < size-1){
		building[s] = '\0';	
	}else{
		//Seriously? One off.
		char * tempArray = (char *)malloc(size + 1);
		//Reuse s
		s=0;
		for(; s < size+1; s++){
			tempArray[s] = building[s];
		}
		tempArray[size-1] = '\0';
		building = tempArray;
	}

	
	return building;
}

