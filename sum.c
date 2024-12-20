#include <stdio.h>

// Function prototype for summing a series of integers
int int_sum(int n);

int main(void)
{
    int n; // Variable to store the number of integers to be summed

    // Prompt the user for the number of integers they want to sum
    printf("Give me the number of integers you want to sum: ");
    scanf("%d", &n);

    // Call the function to calculate the sum of the integers
    int sum = int_sum(n);

    // Output the calculated sum
    printf("The sum of the integers is: %d\n", sum);

    return 0; // Indicate successful program termination
}

// Function to sum a series of integers
int int_sum(int n)
{
    int sum = 0; // Initialize the sum variable to 0
    int x; // Variable to store each individual integer input by the user

    // Iterate through the range of integers (1 to n)
    for (int i = 1; i <= n; i++)
    {
        // Prompt the user for the current integer
        printf("Give me the %d integer: ", i);
        scanf("%d", &x); // Read the user's input into `x`

        // Add the input value `x` to the running sum
        sum += x;
    }

    // Return the final sum after all integers have been added
    return sum;
}
