#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"

/**
 * Returns all letters, which were not used for guessing
 * Function returns set of lowercase letters sorted in alphabetical order. This
 * set will contain all letters from the alphabet, but it ommits those, which
 * were already guessed.
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @param availableLetters set of lowercase not yet used letters
 */
void getAvailableLetters(const char lettersGuessed[], char availableLetters[]){ 
	const char alph[] = "abcdefhijklmnopqrstuvwxyz";
	int p_aval=0;
	int tmp=0;
	for (int i=0; i<strlen(alph); i++){
		tmp = 0;
		for (int j=0; j<strlen(lettersGuessed); j++) {
			if (alph[i] == lettersGuessed[j]) {
				tmp = 1;
			}
		}
		if (tmp != 1) {
			availableLetters[p_aval] = alph[i];
			p_aval++;
		}
	}
	for (int i=p_aval; i<30; i++) {
		availableLetters[p_aval] = '\0';
	}
}

int main() {
    char result[30];
    getAvailableLetters("arpstxgoieyu", result);
    // result = "bcdfhjklmnqvwz"
    printf("result = \"%s\"\n", result);
    printf("Is result OK:[%s;%s]=%d\n", result, "arpstxgoieyu", strcmp(result,"arpstxgoieyu"));
	return 0;
}
