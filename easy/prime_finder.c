// This program finds and prints all prime numbers within a given range [min, max]. 
// The user is prompted to enter the minimum and maximum values for the range, 
// and the program checks each number within the range to see if it is prime.
#include <stdio.h>
#include <stdbool.h>

// Function prototype for checking if a number is prime
bool prime(int n);

int main(void)
{
    int min; // Variable to store the minimum number for the range

    // Prompt the user for the minimum value of the range, ensuring it's greater than or equal to 1
    do
    {
        printf("Give the Min number: ");
        scanf("%d", &min);
    }
    while (min < 1); // Loop if the entered minimum is less than 1

    int max; // Variable to store the maximum number for the range

    // Prompt the user for the maximum value of the range, ensuring it's greater than `min`
    do
    {
        printf("Give the Max number: ");
        scanf("%d", &max);
    }
    while (min >= max); // Loop if the maximum is less than or equal to the minimum

    // Iterate through the numbers in the range [min, max]
    for (int i = min; i <= max; i++)
    {
        // Check if the number is prime
        if (prime(i))
        {
            printf("%d\n", i); // Print the prime number
        }
    }

    return 0; // Indicate successful program termination
}

// Function to determine if a number is prime
bool prime(int n)
{
    // Numbers less than 2 are not prime
    if (n < 2)
    {
        return false;
    }

    // Check divisibility from 2 to n - 1
    for (int i = 2; i <= n - 1; i++)
    {
        // If `n` is divisible by `i`, it is not prime
        if (n % i == 0)
        {
            return false;
        }
    }

    // If no divisors are found, the number is prime
    return true;
}
