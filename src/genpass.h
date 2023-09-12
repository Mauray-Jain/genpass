#pragma once

// Flags for constraints
extern struct flag{
	unsigned int is_lower: 1;
	unsigned int is_upper: 1;
	unsigned int is_number: 1;
	unsigned int is_symbol: 1;
} flags;

enum {LOWER = 1, UPPER, NUMBER, SYMBOL};

void clear(void);
void read(char* str, int n);

void genset(char* set);
int genstr(char* str, long int len, char* set);

int handle_constraint(char* constraint);
long int handle_len(char* len);
