#include <stdio.h>

int main(void)
{
    // Declare variables to store the two numbers and a temporary variable for swapping
    int x, y, temp;

    // Prompt the user to input the first number
    printf("Give me the x: ");
    scanf("%d", &x);

    // Prompt the user to input the second number
    printf("Give me the y: ");
    scanf("%d", &y);

    // Check if one of the numbers is 0 and the other is positive
    if (y == 0 && x > 0)
    {
        // If y is 0, the GCD is x
        printf("The Greatest Common Divisor is %d\n", x);
    }
    else if (x == 0 && y > 0)
    {
        // If x is 0, the GCD is y
        printf("The Greatest Common Divisor is %d\n", y);
    }
    else
    {
        // Use the Euclidean algorithm to find the GCD of x and y
        do
        {
            // Store the value of x in temp before swapping
            temp = x;
            x = y; // Set x to y
            y = temp % x; // Set y to the remainder of temp divided by x
        } while (y > 0); // Continue looping until the remainder is 0
    }

    // Print the calculated GCD
    printf("The Greatest Common Divisor is %d\n", x);

}
