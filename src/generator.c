#include "genpass.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

char genchar(char* set, int len){
	return set[rand() % len];
}

void genset(char* set){
	if(flags.is_lower)
		strcat(set, "abcdefghijklmnopqrstuvwxyz");
	if(flags.is_upper)
		strcat(set, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	if(flags.is_number)
		strcat(set, "0123456789");
	if(flags.is_symbol)
		strcat(set, "`~!@#$%^&*()-_=+[]{}\\|;:'\",.<>/?");
}

int genstr(char* str, long int len, char* set){
	char x;
	int len_of_set = (int) strlen(set);
	for(int i = 0; i < len; i++){
		x = genchar(set, len_of_set);
		*(str + i) = x;
	}
	*(str + len) = '\0';
	return 0;
}
