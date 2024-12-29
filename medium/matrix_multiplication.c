#include <stdio.h>

// Function prototype for element-wise multiplication of two 2x5 matrices
void multiply(int arr1[2][5], int arr2[2][5]);

int main(void)
{
    // Initialize two 2x5 matrices with predefined values
    int arr1[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}; // First matrix
    int arr2[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}; // Second matrix

    // Call the function to multiply the matrices element-wise
    multiply(arr1, arr2);

    return 0; // Indicate successful program termination
}

// This function performs element-wise multiplication of two 2x5 matrices.
// It calculates the product of corresponding elements from the input matrices
// and prints the results for each operation.
void multiply(int arr1[2][5], int arr2[2][5])
{
    int result[2][5] = {}; // Initialize the result matrix with all elements set to 0

    // Iterate through the rows of the matrices
    for (int i = 0; i < 2; i++)
    {
        // Iterate through the columns of the matrices
        for (int j = 0; j < 5; j++)
        {
            // Perform element-wise multiplication
            result[i][j] = arr1[i][j] * arr2[i][j];

            // Print the operation and result
            printf("Multiplication of %d and %d results in: %d\n", 
                    arr1[i][j], arr2[i][j], result[i][j]);
        }
    }
}
