// This program calculates the Least Common Multiple (LCM) of two integers provided by the user. 
// It uses a brute-force approach to find the smallest number that is divisible by both integers. 
// The larger of the two numbers is used as the starting point for efficiency.
#include <stdio.h>

int main(void)
{
    int x, y, temp = 0;

    // Prompt the user to input the first number (x)
    printf("Give me the x: ");
    scanf("%d", &x);

    // Prompt the user to input the second number (y)
    printf("Give me the y: ");
    scanf("%d", &y);

    // Set 'temp' to the larger of the two numbers (x or y)
    // This ensures that we start checking from the larger number
    if (x > y)
    {
        temp = x;
    }
    else if (x < y)
    {
        temp = y;
    }

    // Start a do-while loop to find the Least Common Multiple (LCM)
    do
    {
        // Check if 'temp' is divisible by both 'x' and 'y'
        if (temp % x == 0 && temp % y == 0)
        {
            // If 'temp' is divisible by both 'x' and 'y', it is the LCM
            printf("The Least Common Multiple of %d and %d is %d\n", x, y, temp);
            break; // Exit the loop once the LCM is found
        }

        temp++; // Increment 'temp' and check again
    } while (1); // Continue the loop indefinitely until the LCM is found

    return 0; // Exit the program successfully
}
