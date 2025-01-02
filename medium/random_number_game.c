// This program is a simple Number Guessing Game where the computer randomly selects
// a number between 1 and 100. The user tries to guess the number, and the program
// provides feedback ("too high" or "too low") after each guess. The game ends when 
// the user guesses the correct number, and the program displays the total number of attempts.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;              // Variable to store the user's guess
    int x;              // Randomly generated number to be guessed
    int tries = 0;      // Counter to track the number of attempts

    // Seed the random number generator using the current time
    srand(time(NULL));

    // Generate a random number between 1 and 100
    x = rand() % 100 + 1;

    // Display the welcome message and instructions for the game
    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100. Can you guess it?\n");

    // Loop until the user guesses the correct number
    do
    {
        // Prompt the user to enter their guess
        printf("\nEnter your Guess: ");
        scanf("%d", &n); // Read the user's input and store it in variable `n`

        // Compare the user's guess with the randomly generated number
        if (n > x)
        {
            // If the guess is higher than the target, provide feedback
            printf("Too high! Try again.");
            tries++; // Increment the attempt counter
        }
        else if (n < x)
        {
            // If the guess is lower than the target, provide feedback
            printf("Too low! Try again.");
            tries++; // Increment the attempt counter
        }
        else
        {
            // If the guess is correct, congratulate the user
            tries++; // Increment the attempt counter for the correct guess
            printf("Correct! You guessed it in %d attempts.\n", tries);
        }
    } while (n != x); // Repeat the loop until the user guesses the correct number

    return 0; // Indicate successful program termination
}
