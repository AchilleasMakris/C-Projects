#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int big = 0, second = 0; // Variables to store the largest and second largest values
    int *arr = malloc(sizeof(int) * 5); // Dynamically allocate memory for an array of 5 integers

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit program if memory allocation fails
    }

    // Prompt the user to enter 5 integers
    printf("Give me 5 Integers: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("The integer in slot %d: ", i + 1); // Prompt user for each integer
        scanf("%d", &arr[i]); // Read the integer and store it in the array
    }
    printf("\n");

    // Find the largest number in the array
    for (int i = 0; i < 5; i++)
    {
        if (big < arr[i])
        {
            big = arr[i]; // Update 'big' if a larger value is found
        }
    }

    // Find the second largest number in the array
    for (int j = 0; j < 5; j++)
    {
        if (second < arr[j]) // Check if the current number is greater than 'second'
        {
            if (arr[j] == big)
            {
                continue; // Skip the largest number to find the second largest
            }
            else
            {
                second = arr[j]; // Update 'second' if a larger number (other than 'big') is found
            }
        }
    }

    // Output the second largest number
    printf("The second biggest number on the array is: %d\n", second);

    // Free the dynamically allocated memory
    free(arr);

    return 0; // Indicate successful program termination
}
