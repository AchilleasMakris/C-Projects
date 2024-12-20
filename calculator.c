#include <stdio.h>

int main(void)
{
    int n1, n2;                 // Variables to store input numbers
    int sum, sub, multiply, divide; // Variables to store operation results
    char operator;              // Variable to store the chosen operator

    // Prompt user for the first number
    printf("Give me the first number: ");
    scanf("%d", &n1);

    // Prompt user for the second number
    printf("Give me the second number: ");
    scanf("%d", &n2);

    // Prompt user for the operator (+, -, *, /)
    printf("Give me the operator (+ or - or * or /): ");
    scanf(" %c", &operator); // Space before %c ensures no leftover input is read

    // Perform the operation based on the user-specified operator
    if (operator == '+')
    {
        sum = n1 + n2; // Calculate the sum
        printf("Sum of %d and %d is: %d\n", n1, n2, sum);
    }
    else if (operator == '-')
    {
        sub = n1 - n2; // Calculate the difference
        printf("Subtraction of %d and %d is: %d\n", n1, n2, sub);
    }
    else if (operator == '*')
    {
        multiply = n1 * n2; // Calculate the product
        printf("Multiplication of %d and %d is: %d\n", n1, n2, multiply);
    }
    else if (operator == '/')
    {
        // Check for division by zero
        if (n2 == 0)
        {
            printf("Error: Division by zero is undefined.\n");
            return 1; // Exit with error code
        }
        divide = n1 / n2; // Perform the division
        printf("Division of %d by %d is: %d\n", n1, n2, divide);
    }
    else
    {
        // Handle invalid operators
        printf("Error: Invalid operator '%c'.\n", operator);
        return 1; // Exit with error code
    }

    return 0; // Exit successfully
}
