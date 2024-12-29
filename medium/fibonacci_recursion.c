#include <stdio.h>

// Function prototype for calculating the nth Fibonacci number using recursion
int fibonacci_recursion(int n);

int main(void)
{
    int n;  // Variable to store the user's input for the nth Fibonacci term

    // Prompt the user until they enter a non-negative number
    do
    {
        printf("Give me the N number of Fibonacci sequence: ");
        scanf("%d", &n);

        // Check if the input is valid (non-negative); prompt again if invalid
    } while (n < 0);

    // Display the nth Fibonacci number using the recursive function
    printf("The Fibonacci sequence for N = %d is: %d\n", n, fibonacci_recursion(n));
    printf("\n"); // Print a newline for better output formatting

    return 0; // Indicate successful program termination
}

int fibonacci_recursion(int n)
{
    if (n == 0)  // Base case: the 0th Fibonacci number is 0
    {
        return 0;
    }

    if (n == 1)  // Base case: the 1st Fibonacci number is 1
    {
        return 1;
    }

    // Recursive case: return the sum of the two preceding Fibonacci numbers
    return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}
