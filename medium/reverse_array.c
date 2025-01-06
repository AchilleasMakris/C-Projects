#include <stdio.h>

// Function prototype for swapping (reversing) elements of an array
void swap(int n[], int size);

int main(void)
{
    // Initialize an array with 5 elements
    int n[] = {1, 2, 3, 4, 5};

    // Print the original array before reversal
    printf("Original Array: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d", n[i]);
    }
    printf("\n");

    // Call the function to reverse the array
    swap(n, 5);

    // Print the reversed array
    printf("Reversed Array: ");
    for (int j = 0; j < 5; j++)
    {
        printf("%d", n[j]);
    }
    printf("\n");

    return 0; // Indicate successful program termination
}

// This function reverses the elements of an array in place.
// Parameters:
// - n[]: The array to reverse
// - size: The number of elements in the array
void swap(int n[], int size)
{
    int start = 0;           // Index pointing to the beginning of the array
    int end = size - 1;      // Index pointing to the end of the array
    int temp;                // Temporary variable for swapping

    // Iterate through half of the array to swap elements
    for (int i = 0; i < size / 2; i++)
    {
        // Swap the elements at the 'start' and 'end' positions
        temp = n[start];
        n[start] = n[end];
        n[end] = temp;

        // Move the 'start' index forward and the 'end' index backward
        start++;
        end--;
    }
}
