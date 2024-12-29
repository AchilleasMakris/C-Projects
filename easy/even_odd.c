// This program determines whether a given integer is even or odd. 
// The user is prompted to input a number, and the program checks if the number 
// is divisible by 2 without a remainder. If divisible, the number is even; otherwise, it is odd.

#include <stdio.h>

int main(void)
{
    int x; // Variable to store the user input

    // Prompt the user to input an integer
    printf("Give me a number: ");
    scanf("%d", &x);

    // Check if the number is even or odd
    if (x % 2 == 0) // If the remainder when divided by 2 is 0, it's even
    {
        printf("It's even\n"); // Output indicating the number is even
    }
    else // If the remainder when divided by 2 is not 0, it's odd
    {
        printf("It's odd\n"); // Output indicating the number is odd
    }

    return 0; // Indicate successful program termination
}
