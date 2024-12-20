#include <stdio.h>

int main(void)
{
    int n;                     // Variable to store the number of Fibonacci terms
    long long int a = 0, b = 1, next; // Variables to hold Fibonacci numbers; use `long long` to handle large values

    // Prompt the user for a non-negative number of Fibonacci terms
    do
    {
        printf("Give me the N number of Fibonacci sequence: ");
        scanf("%d", &n);

        // Validate the input to ensure it is non-negative
    } while (n < 0);

    // Generate and display the Fibonacci sequence up to the N-th term
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", a); // Print the current term of the sequence

        // Calculate the next Fibonacci number
        next = a + b;
        a = b; // Update a to the current term
        b = next; // Update b to the next term
    }

    printf("\n"); // Print a newline after the sequence
    return 0; // Indicate successful program termination
}