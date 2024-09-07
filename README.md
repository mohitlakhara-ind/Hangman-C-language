This C program implements a classic Hangman game where the user must guess a secret word by inputting letters one by one. The game provides a hint for the word, and the user has up to six incorrect guesses before losing.

Features:
Word List with Hints: A selection of predefined words is provided, each with a corresponding hint to assist the player. Words include topics like animals, food, and programming languages.

Dynamic Word Display: As the user guesses letters, the program reveals the correctly guessed letters and replaces the unguessed ones with underscores (_). Each incorrect guess progresses the drawing of the hangman.

Limited Attempts: Players are allowed up to six incorrect guesses. With each incorrect guess, parts of the hangman drawing appear on the screen, progressing toward a fully drawn hangman when the player loses.

Formatted Output: The game includes a well-structured, user-friendly interface with clear messages for remaining tries, hints, and game outcomes (win or lose). It also provides prompts and feedback on guesses.

Credits Section: After the game ends, a Credits section is displayed, acknowledging the developer and sharing the GitHub link where more projects can be found.

Game Flow:
The game selects a random word from a predefined list.
The user is prompted to guess letters one by one.
If the user correctly guesses the word within six wrong guesses, they win.
If the user fails to guess the word, the game reveals the correct word and displays the hangman.
The game also handles repeated guesses and invalid inputs, ensuring a smooth user experience.







