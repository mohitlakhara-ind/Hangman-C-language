#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Struct to hold a word and its hint
struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};

// Function to display the current state of the word
void displayWord(const char word[], const bool guessedLetters[]);

// Function to draw the hangman
void drawHangman(int tries);

// Function to display credits
void displayCredits();

// driver code
int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Array of words with hints
    struct WordWithHint wordList[] = {
        { "github", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
        { "airplane", "A flying vehicle" },
        { "python", "A popular programming language" },
        { "jupiter", "The largest planet in our solar system" },
        { "waterfall", "A flowing water feature" },
        { "umbrella", "Used to protect from rain" },
        { "mountain", "A large natural elevation of the earth" }
    };

    int wordCount = sizeof(wordList) / sizeof(wordList[0]);

    // Select a random word from the list
    int wordIndex = rand() % wordCount;

    const char* secretWord = wordList[wordIndex].word;
    const char* hint = wordList[wordIndex].hint;

    int wordLength = strlen(secretWord);
    char guessedWord[MAX_WORD_LENGTH] = { 0 };

    // Initialize guessedWord with underscores
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0'; // Null-terminate the string
    
    bool guessedLetters[26] = { false };

    printf("***************************************\n");
    printf("*          Welcome to Hangman!        *\n");
    printf("***************************************\n");
    printf("Hint: %s\n", hint);

    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("\n");
        printf("Tries Left: %d\n", MAX_TRIES - tries);
        displayWord(secretWord, guessedLetters);
        drawHangman(tries);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (!isalpha(guess)) {
            printf("Invalid input. Please enter a letter.\n");
            continue;
        }

        if (guessedLetters[guess - 'a']) {
            printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        guessedLetters[guess - 'a'] = true;

        bool found = false;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                found = true;
                guessedWord[i] = guess;
            }
        }

        if (found) {
            printf("Good guess!\n");
        } else {
            printf("Sorry, the letter '%c' is not in the word.\n", guess);
            tries++;
        }

        if (strcmp(secretWord, guessedWord) == 0) {
            printf("\n***************************************\n");
            printf("  Congratulations! You've guessed the word: %s\n", secretWord);
            printf("***************************************\n");
            break;
        }
    }

    if (tries >= MAX_TRIES) {
        printf("\n***************************************\n");
        printf("  Sorry, you've run out of tries. The word was: %s\n", secretWord);
        printf("***************************************\n");
    }

    displayCredits();
    return 0;
}

void displayWord(const char word[], const bool guessedLetters[])
{
    printf("Word: ");
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessedLetters[word[i] - 'a']) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawHangman(int tries)
{
    const char* hangmanParts[] = {
        "  _________",
        " |       |",
        " |       O",
        " |      /|\\",
        " |      / \\",
        " |"
    };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
    if (tries == MAX_TRIES) {
        printf("Game over!\n");
    }
}

void displayCredits()
{
    printf("\n***************************************\n");
    printf("*             Game Credits            *\n");
    printf("***************************************\n");
    printf("* Developed by: Mohit Lakhara          *\n");
    printf("* GitHub: https://github.com/mohitlakhara-ind *\n");
    printf("* Thank you for playing Hangman!       *\n");
    printf("***************************************\n");
}
