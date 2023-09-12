#include "genpass.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct flag flags;
int handle_constraint(char* constraint){
	int j = 0, k = 0;
	sscanf(constraint, "%d", &j);
	if(j <= 0)
		return -1;
	while(j > 0){
		k = j % 10;
		switch(k){
			case LOWER: flags.is_lower = 1; break;
			case UPPER: flags.is_upper = 1; break;
			case NUMBER: flags.is_number = 1; break;
			case SYMBOL: flags.is_symbol = 1; break;
			default: return -1;
		}
		j = j / 10;
	}
	return 0;
}

long int handle_len(char* len){
	errno = 0;
	long int len_int = strtol(len, NULL, 10);
	if(errno == ERANGE || len_int <= 0)
		return -1;
	return len_int;
}
