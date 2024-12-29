#include <stdio.h>
#include <string.h>

int main(void)
{
    int words = 0; // Variable to count the number of words in the string
    char *string = "This is a string with seven words."; // Sample string to count words

    // Loop through each character in the string
    for (int i = 0; i < strlen(string); i++)
    {
        // Check for spaces that are followed by another character (indicating a new word)
        if (string[i] == ' ' && string[i + 1] != '\0')
        {
            words++; // Increment the word count when a space is encountered
        }
    }

    // Output the total word count (add 1 to account for the first word)
    printf("The number of words in the string is: %d\n", words + 1);

    return 0; // Indicate successful program termination
}
