#include <stdio.h>

int main(void)
{
    int x, n; // Variables to store the multiplication result (`x`) and the input number (`n`)

    // Prompt the user for an integer to generate its multiplication table
    printf("Give me an integer you want the multiplication table for: ");
    scanf("%d", &n);

    // Generate and display the multiplication table for the given number
    for (int i = 1; i <= 10; i++) // Loop from 1 to 10 to cover the standard multiplication table range
    {
        x = i * n; // Calculate the product of `n` and the current iteration value `i`

        // Display the current step of the multiplication table
        printf("%d x %d = %d\n", i, n, x);
    }

    return 0; // Indicate successful program termination
}
