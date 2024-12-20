#include <stdio.h>

// Reverses the digits of a given integer.
// Assumes the input integer is non-negative.
int reverse(int n);

int main(void)
{
    int n;

    // Prompt the user for input
    printf("Give me an Integer: ");
    scanf("%d", &n);

    int x = reverse(n);
    // Reverse the input integer and display the result
    printf("The reversed integer is: %d\n", x);
    if(n == x)
    {
        printf("This integer is Palindrome because the reversed number is the same as original. \n");
    }
    else
    {
        printf("This integer is not Palindrome because the reversed number is not the same as original. \n");
    }
    return 0;
}

int reverse(int n)
{
    int rev_num = 0; // Stores the reversed number

    // Process each digit until all digits are reversed
    while (n > 0)
    {
        // Add the last digit of n to the reversed number
        // Multiplying rev_num by 10 shifts its digits to the left, making space for the new digit.
        rev_num = rev_num * 10 + n % 10;

        // Remove the last digit from the input number
        // Integer division ensures that the original number decreases in size with each iteration.
        n = n / 10;
    }

    return rev_num;
}
