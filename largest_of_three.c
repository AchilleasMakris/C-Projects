// This program determines which of three integers entered by the user is the largest. 
// The user provides three integers, and the program compares them using conditional statements. 
// If no single number is larger (e.g., if the numbers are equal), it informs the user accordingly.
#include <stdio.h>

int main(void)
{
    int x, y, z; // Variables to store the three input numbers

    // Prompt the user to input three integers
    printf("Give me 3 numbers: \n");
    scanf("%d %d %d", &x, &y, &z);

    // Determine which number is the largest
    if (x > y && x > z) // Check if `x` is greater than both `y` and `z`
    {
        printf("%d is bigger than %d and %d\n", x, y, z); // Output the result for `x`
    }
    else if (y > x && y > z) // Check if `y` is greater than both `x` and `z`
    {
        printf("%d is bigger than %d and %d\n", y, x, z); // Output the result for `y`
    }
    else if (z > x && z > y) // Check if `z` is greater than both `x` and `y`
    {
        printf("%d is bigger than %d and %d\n", z, x, y); // Output the result for `z`
    }
    else // Handle the case where the numbers are equal or no single number is larger
    {
        printf("The numbers are equal\n"); // Inform the user that the numbers are equal
    }

    return 0; // Indicate successful program termination
}
