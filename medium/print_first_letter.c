// This program takes a string input from the user and extracts the first letter 
// of each word in the string. It uses a `for` loop to iterate through the string 
// and identifies the start of each word by checking for spaces. The extracted 
// letters are printed consecutively to form an acronym or initialism.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000]; // Array to store the user input string, with a maximum size of 1000 characters

    // Prompt the user to input a string
    printf("Give me a string: ");
    fgets(s, 1000, stdin); // Read the string from the user, including spaces, using `fgets`

    int string = strlen(s); // Calculate the length of the input string

    // Loop through each character in the string
    for (int i = 0; i < string; i++)
    {
        // Print the first character of the string
        if (i == 0)
        {
            printf("%c", s[0]);
        }

        // Check for a space and print the character immediately after it
        if (i > 0 && s[i] == ' ')
        {
            printf("%c", s[i + 1]);
        }
    }

    // Print a newline character after displaying the result
    printf("\n");

    return 0; // Indicate successful program termination
}
