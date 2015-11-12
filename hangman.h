#define WORDLIST_FILENAME "words.txt"

/**
 * Function detects, whether player guessed the secret word
 * Based on the letters player used for guessing, this function detects,
 * if it is possible to construct (and guess) the secret word from this set.
 * If it is possible, function returns 1. If not, returns 0.
 * @param secret the secret word lowercase
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @return 1, if word is guess; 0 otherwise.
 */
int isWordGuessed(const char secret[], const char lettersGuessed[]);


/**
 * Function returns string representing the guessed word
 * This string contains visible letters, which were guessed successfuly
 * by player at their correct positions. If there are still some hidden
 * letters, the character '_' will be used for their representation.
 * @param secret the secret word lowercase
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @param guessedWord the constructed string as result of this function (output parameter)
 */
void getGuessedWord(const char secret[], const char lettersGuessed[], char guessedWord[]);


/**
 * Returns all letters, which were not used for guessing
 * Function returns set of lowercase letters sorted in alphabetical order. This
 * set will contain all letters from the alphabet, but it ommits those, which
 * were already guessed.
 * @param lettersGuessed the lowercase letters player already used in his guessing
 * @param availableLetters set of lowercase not yet used letters
 */
void getAvailableLetters(const char lettersGuessed[], char availableLetters[]);


/**
 * Starts interactive hangman game
 *
 * @param secret the secret word lowercase
 */
void hangman(const char secret[]);


/**
 * Returns the random word
 * Function opens the file with all the words and reads randomly one of them
 * into the buffer pointed by secret. Word consists of lowercase letters.
 * If there is some error with reading the file, 1 is returned.
 * Don't forget to initialize the random numbers in your main() function will srand() call!
 * Otherwise (everything is ok), 0 is returned.
 * @param secret buffer, where random word will be read
 * @return status code
 */
int getWord(char secret[]);
