#include <stdio.h>

// Αρχικοπο΄ίηση σταθερών για εύκολη αλλαγή Rows/Columns.
#define ROWS 4
#define COLS 5

int main(void)
{

    // ΑΜΥΝΤΙΚΟΣ ΠΡΟΓΡ/ΜΟΣ ΓΙΑ ΘΕΤΙΚΑ ΣΤΟΙΧΕΙΑ ΣΤΟΝ ΠΙΝΑΚΑ
    // ΠΙΝΑΚΑΣ 2 ΔΙΑΣΤΑΣΕΩΝ.
    int n[ROWS][COLS];
    
    for(int i = 0; i < ROWS; i++){            //ROWS
        for(int j = 0; j < COLS; j++){         //COLUMNS 
           do {
               printf("Δώσε στοιχείο του πίνακα (θετικός αριθμός) στη θέση (%d,%d): ", i, j);
               scanf("%d", &n[i][j]);
           } while (n[i][j] <= 0);
        }
    }
    
    
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%6d", n[i][j]);
            printf("   ");
        }
        printf("\n");
    }

    // Αρχικοποίηση μεταβλητών
    int inside_total = 0, outside_total = 0, sum_inside = 0, sum_outside = 0;

    // Έλεγχος για εσωτερικά στοιχεία
    if(ROWS <= 2 || COLS <= 2)
    {
        printf("Ο πίνακας δεν έχει εσωτερικά στοιχεία.\n");
    }
    else
    {
        // Υπολογισμός εσωτερικών στοιχείων 
    for(int i = 1; i < ROWS - 1; i++)
    { 
        for(int j = 1; j < COLS - 1; j++)  
        { 
            sum_inside += n[i][j];
            inside_total++;
        }
    }
    
    // Υπολογισμός εξωτερικών στοιχείων (όλα τα στοιχεία περιμετρικά)
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            { // Στοιχεία στα όρια
                sum_outside += n[i][j];
                outside_total++;
            }
        }
    }

    // Υπολογισμός μέσων όρων
    double avr_inside = 0, avr_outside = 0;

    avr_inside = (double) sum_inside / inside_total;
    avr_outside = (double) sum_outside / outside_total;


    if(avr_inside > avr_outside)
    {
        printf("Ο μέσος όρος των εσωτερικών στοιχείων (%.2f) ειναι μεγαλύτερος του μέσου όρου των εξωτερικών στοιχείων (%.2f): του πίνακα.\n" , avr_inside, avr_outside);
    }
    else
    {
        printf("Ο μέσος όρος των εξωτερικών στοιχείων (%.2f) είναι μεγαλύτερος ή ίσος του μέσου όρου των εσωτερικών στοιχείων (%.2f) του πίνακα.\n",
               avr_outside, avr_inside);
    }

    }

    return 0;
}