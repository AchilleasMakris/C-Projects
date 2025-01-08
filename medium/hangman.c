// This program is a simple Hangman game where a random word is selected from a file
// containing a list of words. The user attempts to guess the word by entering one letter
// at a time. They have 6 incorrect guesses before the game ends in failure. If the user
// guesses the word correctly, they win the game.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char array[2309][50]; // Array to store up to 2309 words, each up to 49 characters long

    // Open the file containing the words in read mode
    FILE *read = fopen("hangman.txt", "r");
    
    // Read words from the file into the `array`
    int i = 0;
    while (fscanf(read, "%49s", array[i]) != EOF)
    {
        i++; // Increment the index for the next word
    }
    fclose(read); // Close the file after reading

    // Seed the random number generator using the current time
    srand(time(NULL));

    // Pick a random word from the array
    int random_index = rand() % 2309;
    char word[50]; // Variable to store the chosen word
    strcpy(word, array[random_index]); // Copy the randomly selected word to `word`

    // Determine the length of the chosen word
    int length = strlen(word);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (word[i] != '\0') // Ensure not to count the null terminator
        {
            count++;
        }
    }

    // Display the welcome message and the game's instructions
    printf("Welcome to Hangman! Guess the hidden word by entering one letter at a time. ");
    printf("You have 6 chances to guess wrong before the game is over. Good luck!\n");
    printf("Let's play Hangman! The word has been chosen. It has %d letters. Can you guess it?\n", count);

    // Display underscores representing the letters in the chosen word
    for (int i = 0; i < length; i++)
    {
        printf("_ ");
    }
    printf("\n");

    int lives = 6;           // Number of incorrect guesses allowed
    int found[length];       // Array to track guessed letters in the word
    for (int i = 0; i < length; i++)
    {
        found[i] = 0;        // Initialize all letters as not guessed
    }

    char used[26] = {0};     // Array to store the user's guessed letters
    int used_count = 0;      // Counter for the number of unique letters guessed

    // Main game loop
    while (lives > 0)
    {
        printf("You have %d lives left!\n", lives);
        printf("Give me a letter:\n");
        char input;
        scanf(" %c", &input); // Read the user's guessed letter

        int lives_flag = 0;   // Flag to track if the guess is correct
        int already_guessed = 0; // Flag to check if the letter has been guessed before

        // Check if the letter was already guessed
        for (int i = 0; i < used_count; i++)
        {
            if (used[i] == input)
            {
                already_guessed = 1;
                break;
            }
        }

        if (already_guessed)
        {
            // Inform the user if they guessed the same letter again
            printf("You already guessed '%c'! Try a different letter.\n", input);
            continue; // Skip the rest of the loop for this guess
        }

        // Add the guessed letter to the `used` array if it's not already present
        if (used_count < 26)
        {
            used[used_count] = input;
            used_count++;
        }

        // Display all letters guessed so far
        printf("Letters guessed so far:\n");
        for (int i = 0; i < used_count; i++)
        {
            printf("%c ", used[i]);
        }
        printf("\n");

        // Check if the guessed letter is in the word
        for (int i = 0; i < length; i++)
        {
            if (input == word[i])
            {
                found[i] = 1;   // Mark the letter as found
                lives_flag = 1; // Correct guess flag
            }
        }

        if (lives_flag != 1)
        {
            lives--; // Decrement lives if the guess is incorrect
        }

        int flag = 1; // Flag to check if the user has guessed the entire word

        // Display the current state of the word (guessed and unguessed letters)
        for (int i = 0; i < length; i++)
        {
            if (found[i] == 1)
            {
                printf("%c ", word[i]);
            }
            else
            {
                flag = 0; // If any letter is still missing, set flag to 0
                printf("_ ");
            }
        }

        // If the user has guessed the entire word, end the game
        if (flag == 1)
        {
            printf("\nNice! You found the word with %d lives left!\n", lives);
            break;
        }

        printf("\n");

        // Clear any leftover input from the buffer
        while (getchar() != '\n');
    }

    // If the user runs out of lives, display the losing message
    if (lives == 0)
    {
        printf("\nOopsie, you lost! The word was: %s\n", word);
    }

    return 0; // Indicate successful program termination
}
