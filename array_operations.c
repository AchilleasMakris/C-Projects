#include <stdio.h>

int main(void)
{
    int n, x;
    int min = 1000; // Initialize min with a high value for comparison
    int max = 0;    // Initialize max with a low value for comparison

    // Prompt the user to enter the total number of elements in the array
    printf("Give me the total numbers of the array: ");
    scanf("%d", &n);

    // Dynamically declare an array based on the user input size
    int array[n];

    // Iterate through the array to populate its values and find the min and max
    for (int i = 1; i <= n; i++)
    {
        // Prompt the user to input a value for each array element
        printf("Give me the number for the %d location: ", i);
        scanf("%d", &x);

        // Assign the user-provided value to the array
        // Note: The loop starts from 1, so indexing here is off by 1 (arrays in C are 0-indexed).
        array[i] = x;

        // Update min if the current value is smaller
        if (x < min)
        {
            min = x;
        }

        // Update max if the current value is larger
        if (x > max)
        {
            max = x;
        }
    }

    // Output the minimum and maximum values found in the array
    printf("The min number of the array is %d and the max number of the array is %d.\n", min, max);

    return 0; // Indicate successful program termination
}
