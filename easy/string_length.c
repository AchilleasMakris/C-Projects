// This program calculates the length of a string entered by the user without using the `strlen` function.
// It dynamically allocates memory for the string and manually counts its characters until it reaches the null terminator.
#include <stdio.h>
#include <stdlib.h>

// This program calculates the length of a string entered by the user without using the `strlen`
// function. It dynamically allocates memory for the string and manually counts its characters.

int main(void)
{
    int count = 0; // Variable to store the length of the string

    // Dynamically allocate memory for the input string (maximum 100 characters)
    char *string = malloc(100 * sizeof(char));

    // Prompt the user for input
    printf("Write a string: ");
    fgets(string, 100, stdin); // Read up to 99 characters (reserving space for null terminator)

    // Loop through the string to count characters until the null terminator ('\0') is reached
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }

    // Output the calculated string length
    // Note: This includes the newline character added by `fgets` if the input doesn't exceed 99
    // characters.
    printf("The string length without strlen is: %d\n", count);

    // Free the allocated memory to prevent memory leaks
    free(string);

    return 0; // Exit successfully
}
