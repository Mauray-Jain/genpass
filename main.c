#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "src/genpass.h"

int main(void){
	long int len = 0;
	char action;
	char constraint[6]; // 6 bcoz 4 constraints \n and \0
	char len_str[20];
	char* set = malloc(100 * sizeof(char));
	char* generated_prev = NULL;
	char* generated_str = malloc(sizeof(char)); // some initial size
	if(generated_str == NULL){
		perror("Can't allocate memory");
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	printf("Hallo! Welcome to genpass:\n");

	while(1){
		do {
			printf("Enter the length of string you want to generate: ");
			read(len_str, sizeof len_str);
			len = handle_len(len_str);
			if(len <= 0)
				printf("Invalid Values\n");
		} while(len <= 0);

		generated_str = realloc(generated_prev = generated_str, (unsigned) len * sizeof(char) + 1); // +1 for \0
		if(generated_str == NULL){
			free(generated_prev); // If realloc failed original needs to be freed
			generated_prev = NULL;
			free(set);
			set = NULL;
			perror("Realloc failed");
			exit(EXIT_FAILURE);
		}
		clear();

		printf("Enter the numbers to include the following in the string generated (only numbers any order, don't repeat):\n");
		printf("%d: Lower\n", LOWER);
		printf("%d: Upper\n", UPPER);
		printf("%d: Number\n", NUMBER);
		printf("%d: Symbol\n", SYMBOL);

		int i = 0;
		do {
			printf("Enter: ");
			read(constraint, sizeof constraint);
			i = handle_constraint(constraint);
			if(i < 0){
				printf("Invalid option\n");
			}
		} while(i != 0);
		memset(set, 0, 100);
		genset(set);

		do {
			clear();
			genstr(generated_str, len, set);
			printf("Generated string: %s\n", generated_str);
			printf("What you wanna do next?\n");
			printf("s: start again\n");
			printf("r: recreate\n");
			printf("Any other key to exit ...");
			scanf("%c", &action); getchar();
		} while(action == 'r');

		flags.is_lower = 0;
		flags.is_upper = 0;
		flags.is_number = 0;
		flags.is_symbol = 0;

		if(action != 'r' && action != 's'){
			break;
		}
		clear();
	}
	printf("Thanks\n");
	free(generated_str);
	free(set);
	set = NULL;
	generated_str = NULL;
	return 0;
}
