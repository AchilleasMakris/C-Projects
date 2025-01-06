#include <stdio.h>

int main(void)
{
    int rows = 5;  // Number of rows in Pascal's Triangle
    int array[5][5] = {0};  // Initialize a 2D array with all elements set to 0

    // Generate Pascal's Triangle
    for (int i = 0; i < rows; i++)
    {
        array[i][0] = 1; // First element of each row is always 1
        for (int j = 1; j < i; j++)  // Fill intermediate elements in the row
        {
            array[i][j] = array[i-1][j-1] + array[i-1][j];  // Sum of two elements above
        }
        array[i][i] = 1; // Last element of each row is always 1
    }

    // Print Pascal's Triangle as a centered pyramid
    printf("Pascal's Triangle:\n");

    for (int i = 0; i < rows; i++)
    {
        // Print leading spaces for centering the current row
        for (int space = 0; space < rows - i - 1; space++)
        {
            printf(" ");  // Two spaces per level for better alignment
        }

        // Print the numbers in the current row
        for (int j = 0; j <= i; j++)
        {
            printf("%2d", array[i][j]);  // Print each number with uniform spacing
        }
        printf("\n");  // Move to the next row
    }

    return 0;
}
