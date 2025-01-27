// This program determines whether a given year is a leap year and allows the user 
// to add a specified number of days to a given date. It adjusts for leap years 
// when performing date calculations.

#include <stdio.h>
#include <stdbool.h>

// Function to determine if a given year is a leap year
bool is_leap_year(int year);

// Function to add a given number of days to a date, adjusting for months and leap years
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add);

int main() {
    int year; // Variable to store the input year

    // Prompt the user to enter a year within the valid range (1800-10000)
    do {
        printf("Give me a year between 1800 and 10000: ");
        scanf("%d", &year);
    } while (year < 1800 || year > 10000);

    // Check if the entered year is a leap year and display the result
    if (is_leap_year(year)) {
        printf("\n It's a leap year!\n");
    } else {
        printf("\n It's not a leap year!\n");
    }

    int mm, dd, yy, days_left_to_add; // Variables to store the date and days to add

    // Prompt the user to enter a valid date and the number of days to add
    printf("\n Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date. For example for  28 - Febuary - 2020 and to add 2days on the callendar, the input should be: \"28 2 2020 2\": ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);

    // Call the function to add the specified number of days to the date
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);

    // Display the new calculated date
    printf("\n The new date is: %d - %d - %d \n", mm, dd, yy);

    return 0; // Indicate successful program termination
}

// Function to determine if a given year is a leap year
bool is_leap_year(int year) {
    // A leap year is divisible by 4 but not by 100, unless also divisible by 400
    if ((year % 4) == 0) {
        if ((year % 100) != 0 || (year % 400) == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// Function to add a specified number of days to a date, adjusting for months and leap years
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    // Array to store the number of days in each month (index 0 is unused for clarity)
    int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Loop until all days have been added
    while (days_left_to_add > 0) {
        // Adjust February for leap years
        if (*mm == 2 && is_leap_year(*yy)) {
            days_in_month[2] = 29;
        } else {
            days_in_month[2] = 28;
        }

        // Calculate the number of days left in the current month
        int days_left_in_month = days_in_month[*mm] - *dd;

        // If more days need to be added than the remaining days in the month
        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= (days_left_in_month + 1); // Move to the next month
            *dd = 1; // Reset the day to the first of the next month

            // If the current month is December, move to January of the next year
            if (*mm == 12) {
                *mm = 1;
                (*yy)++; // Increment the year
            } else {
                (*mm)++; // Move to the next month
            }
        } else {
            // If the remaining days fit within the current month, simply add them
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}
