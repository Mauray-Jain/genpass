#include "genpass.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clear(void){
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	system("cls");
	#else
	system("clear");
	#endif
}

void read(char* str, int n){
	fgets(str, n, stdin);
	if(!strstr(str, "\n")){
		int ch;
		while((ch = getchar()) != '\n' && ch != EOF);
	}
}
