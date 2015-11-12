#include <stdio.h>
#include "hangman.h"

int main() {
	char secret[30];
	if (getWord( secret) != 0) {
		printf("Error with input file\n");
		return 0;
	}
	hangman( secret);
	return 0;
}
