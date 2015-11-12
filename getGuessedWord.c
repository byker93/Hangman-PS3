#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"


/**
 * Function returns string representing the guessed word
 * This string contains visible letters, which were guessed successfuly
 * by player at their correct positions. If there are still some hidden
 * letters, the character '_' will be used for their representation.
 * @param secret the secret word lowercase
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @param guessedWord the constructed string as result of this function (output parameter)
 */

void getGuessedWord(const char secret[], const char lettersGuessed[], char guessedWord[]) {
	int tmp=0;
	for (int i=0; i<(strlen(secret)); i++) {
		tmp = 0;
		for (int j=0; j<(strlen(lettersGuessed)); j++) {
			if (secret[i] == lettersGuessed[j]) {
				tmp = 1;
			}
		}
		if (tmp == 1) {
			guessedWord[i] = secret[i];
		}
		else {
			guessedWord[i] = '_';
		}
		guessedWord[i+1] = '\0';
	}
}

int main() {
	char result[30];
    getGuessedWord("container", "arpstxgoieyu", result);
    // result = "_o_tai_er"
    printf("result = \"%s\"\n", result);
	return 0;
}
