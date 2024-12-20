// This program calculates the factorial of a non-negative integer provided by the user. 
// It uses a recursive function to compute the factorial. The user is prompted to enter a 
// non-negative integer, and the program ensures this through a `do-while` loop. The result 
// is displayed after calculating the factorial.

#include <stdio.h>

// Function prototype for calculating the factorial of a number
int factorial(int n);

int main(void)
{
    int n; // Variable to store the input number

    // Prompt the user for a positive integer value for `n`
    // Use a `do-while` loop to ensure the input is non-negative
    do
    {
        printf("Give me a number: ");
        scanf("%d", &n);
    } while (n < 0);

    // Print the factorial of the given number
    // The recursive `factorial` function handles the calculation
    printf("The factorial of %d is %d\n", n, factorial(n));

    return 0; // Indicate successful program termination
}

// Recursive function to calculate the factorial of a number
int factorial(int n)
{
    // Base case: If `n` equals 1, return 1 as the factorial
    if (n == 1)
    {
        return 1;
    }

    // Recursive case: Multiply `n` by the factorial of `n - 1`
    return n * factorial(n - 1);
}
