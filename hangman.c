#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "hangman.h"


int getWord(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

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

int isGuessGood( const char secret[], const char guess) {
	int tmp = 0;
	for (int i=0; i<strlen(secret); i++) {
		if (secret[i] == guess) tmp = 1;
	}
	return tmp;
}

void hangman(const char secret[]) {
	char lettersGuessed[30];
	char availableLetters[30];
	char guessedWord[30];
	char guess[30];
	int tryes = 8, p_guess = 0;
	int eend = 0;
	
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %ld letters long.\n", strlen(secret));
	printf("-------------------------------------------------\n");
	while (isWordGuessed( secret, lettersGuessed) != 1) {
		printf("You have %d guesses left.\n", tryes);
		getAvailableLetters( lettersGuessed, availableLetters);
		printf("Available letters: %s\n", availableLetters);
		printf("Please guess a letter: ");
		scanf(" %s", guess);
		if (strlen(guess) > 1) {
			if (strcmp( guess, secret) == 0) {
				for (int i=0; i<strlen(guess); i++) {
					lettersGuessed[p_guess++] = guess[i];
				}
				lettersGuessed[p_guess] = '\0';
				printf("Congratulations, you won!\n");
				eend = 1;
			}
			else {
				printf("Sorry, bad guess. The word was %s.\n", secret);
				eend = 1; 	
			}	
			tryes = 0;
		}
		else {
			lettersGuessed[p_guess++] = guess[0]; lettersGuessed[p_guess] = '\0';
			if (isGuessGood( secret, guess[0])) {
				printf("Good guess:");
			}
			else {
				printf("Oops! That letter is not in my word:");
				tryes--;
			}
			getGuessedWord( secret, lettersGuessed, guessedWord);
			printf("%s\n", guessedWord);
			printf("------------------------------------------------\n");
		}
		if (tryes <= 0) break;
	}
	if (eend != 1){
		if (tryes > 0) {
			printf("Congratulations, you won!\n");
		}
		else {
			printf("Sorry, you ran out of guesses. The word was undeserved.\n");
		}
	}
}
