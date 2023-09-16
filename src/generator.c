#include "genpass.h"
#include <stdlib.h>
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
	int len_of_set = (int) strlen(set);
	for(int i = 0; i < len; i++){
		*(str + i) = genchar(set, len_of_set);
	}
	*(str + len) = '\0';
	return 0;
}
