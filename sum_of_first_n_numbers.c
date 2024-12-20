#include <stdio.h>

int main(void)
{
    int n; // Variable to store the input number
    int sum = 0; // Variable to accumulate the sum of integers from 1 to n

    // Prompt the user for an integer input
    printf("Give me the number N: ");
    scanf("%d", &n);

    // Calculate the sum of integers from 1 to n
    for (int i = 1; i <= n; i++) // Iterate through numbers from 1 to n
    {
        sum += i; // Add the current number `i` to the sum
    }

    // Output the calculated sum
    printf("The sum is: %d\n", sum);

    return 0; // Indicate successful program termination
}
