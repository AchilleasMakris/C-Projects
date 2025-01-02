// This program validates the rows of a 9x9 Sudoku board to check for duplicate numbers.
// A duplicate in a row violates Sudoku rules, where each row must contain unique numbers from 1 to 9.
// Empty cells are represented by 0 and are not checked for duplicates. The program also checks if
// any number is out of the valid range (1-9). It outputs whether duplicates were found or not.

#include <stdio.h>

int main(void)
{
    // Initialize a 9x9 Sudoku board with preset values (0 represents empty cells)
    int array[9][9] = {
        {5, 0, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int flag = 0; // Variable to indicate whether a duplicate is found in any row

    // Loop through each row of the Sudoku board
    for (int i = 0; i < 9; i++)
    {
        // If a duplicate is found, stop checking further rows
        if (flag == 1)
        {
            break;
        }

        // Loop through each cell in the current row
        for (int j = 0; j < 9; j++)
        {
            // If a duplicate is found, stop checking further cells in this row
            if (flag == 1)
            {
                break;
            }

            // Compare the current cell with all other cells in the same row
            for (int k = 0; k < 9; k++)
            {
                // Check for duplicates in the row:
                // 1. Ignore the current cell itself (`j != k`)
                // 2. Ignore empty cells (value 0)
                if (j != k && array[i][j] == array[i][k] && array[i][j] != 0)
                {
                    flag = 1; // Set flag to indicate a duplicate was found
                    break;
                }

                // Check if the number in the cell is out of bounds (valid range is 1-9)
                if (array[i][j] > 9 || array[i][j] < 0)
                {
                    printf("Out of bounds number.\n"); // Print error message for invalid input
                    break;
                }
            }
        }
    }

    // Output the result based on the flag value
    if (flag == 0)
    {
        printf("Duplicate not found\n"); // No duplicates found in any row
    }
    else if (flag == 1)
    {
        printf("Duplicate found\n"); // A duplicate was found in one of the rows
    }

    return 0; // Indicate successful program termination
}
