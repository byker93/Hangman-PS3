#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"
/**
 * 
    printf("%d\n", isWordGuessed("secret", "aeiou"));
    // prints: 0
    printf("%d\n", isWordGuessed("hello", "aeihoul"));
    // prints: 1

*/


/**
 * Function detects, whether player guessed the secret word
 * Based on the letters player used for guessing, this function detects,
 * if it is possible to construct (and guess) the secret word from this set.
 * If it is possible, function returns 1. If not, returns 0.
 * @param secret the secret word lowercase
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @return 1, if word is guess; 0 otherwise.
 */
int isWordGuessed(const char secret[], const char lettersGuessed[]){
	int true=0, tmp=0;
	for (int i=0; i<(strlen(secret)); i++) {
		tmp = 0;
		for (int j=0; j<(strlen(lettersGuessed)); j++) {
			if (secret[i] == lettersGuessed[j]) {
				tmp = 1;
			}
		}
		if (tmp == 1) true++;
	}
	if (true != strlen(secret)) return 0; else return 1;
}

int main() {
	printf("%d\n", isWordGuessed("secret", "aeiou"));
	printf("%d\n", isWordGuessed("hello", "aeihoul"));
	return 0;
}
