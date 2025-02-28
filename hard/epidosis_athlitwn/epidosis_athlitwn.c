#include <stdio.h>

#define NUM_OF_ATHLETES 8
#define NUM_OF_JUMPS 6

/* Ορισμός πινάκων */
int ArithmAthl[NUM_OF_ATHLETES];                      /* Αριθμός Αθλητών*/
float Epidoseis[NUM_OF_ATHLETES][NUM_OF_JUMPS] = {0}; /* Επιδόσεις Αθλητών */
float maxEpid[NUM_OF_ATHLETES];                       /* Μέγιστη Επίδοση Αθλητή*/

/* Ορισμός συναρτήσεων */
void input_data_A();/* Είσοδος ΑΑ Αθλητών και Επιδόσεων 1-2-3 */
void input_data_B();/* Είσοδος Επιδόσεων 4-5-6 */
void find_max();    /* Υπολογισμός Καλύτερης Επίδοσης για κάθε Αθλητή */
void sort_data();   /* Ταξινομηση (φθίνουσα) Αποτελεσμάτων */
void print_data();  /* Εκτύπωση Συνολικών Αποτελεσμάτων */

int main()
{
	// system("chcp 1253>nul");
    input_data_A();     
    find_max();
    sort_data(); 
    print_data(); 
    input_data_B(); 
    find_max();
    sort_data(); 
    print_data();  
    return 0; 
}

/* Είσοδος ΑΑ Αθλητών και Επιδόσεων 1-2-3 */
void input_data_A()
{
    int aa_count = 1;
    for(int i = 0; i < NUM_OF_ATHLETES; i++)
    {
        do
        {
            printf("Αριθμός %dου αθλητή (100 - 999): ", aa_count);
            scanf("%d", &ArithmAthl[i]);

            if(ArithmAthl[i] < 100 || ArithmAthl[i] > 999)
            {
                printf("Λάθος τιμή!\n");
            }
            else
            {
                aa_count++;
                break;
            }
        }while(1);
    }
  
    for(int i = 0; i < NUM_OF_JUMPS - 3; i++)
    {
        printf("\n%dη Προσπάθεια\n", i + 1);
        for(int j = 0; j < NUM_OF_ATHLETES; j++)
        {
            do
            {
                printf("Αθλητής %d (1-12 ή -1 για άκυρη): ", ArithmAthl[j]);
                scanf("%f", &Epidoseis[j][i]);

                if((Epidoseis[j][i] < 1 && Epidoseis[j][i] != -1) || Epidoseis[j][i] > 12)
                {
                    printf("Μη έγκυρη επίδοση! Δοκιμάστε ξανά.\n");
                }
                else
                {
                    break;
                }
            }while(1);
        }
    }
}

/* Είσοδος Επιδόσεων 4-5-6 */
void input_data_B()
{
    // Μόνο για τους 4 πρώτους αθλητές
    // 4η, 5η, 6η προσπάθεια (index 3, 4, 5)
    for (int j = 3; j < 6; j++)
    {
        printf("\n%dη Προσπάθεια\n", j + 1);

        // Ξεκινάει από τον 4ο (index 3) και φτάνει στον 1ο (index 0)
        for (int i = 3; i >= 0; i--)
        {
            do
            {
                printf("Αθλητής %d (1-12 ή -1 για άκυρη): ", ArithmAthl[i]);
                scanf("%f", &Epidoseis[i][j]);

                if ((Epidoseis[i][j] < 1 && Epidoseis[i][j] != -1) || Epidoseis[i][j] > 12)
                {
                    printf("Μη έγκυρη επίδοση! Δοκιμάστε ξανά.\n");
                }
                else
                {
                    break;
                }
            } while (1);
        }
    }
}


/* Υπολογισμός Καλύτερης Επίδοσης για κάθε Αθλητή */
void find_max()
{
    for(int i = 0; i < NUM_OF_ATHLETES; i++)
    {
        float max = -1;

        for(int j = 0; j < NUM_OF_JUMPS; j++)
        {
            if(Epidoseis[i][j] > max)
            {
                max = Epidoseis[i][j];
            }
        }
        maxEpid[i] = max;
    }
}

/* Ταξινομηση (φθίνουσα) Αποτελεσμάτων */
void sort_data()
{
    for(int i = 0; i < NUM_OF_ATHLETES - 1; i++)
    {
        int maxIndex = i;  // Υποθέτουμε ότι το i έχει τη μέγιστη τιμή

        for(int j = i + 1; j < NUM_OF_ATHLETES; j++)
        {
            if(maxEpid[maxIndex] < maxEpid[j])  // Αν βρούμε μεγαλύτερη τιμή, ενημερώνουμε το maxIndex
            {
                maxIndex = j;
            }
        }

        // Ανταλλαγή μέγιστης επίδοσης
        float temp = maxEpid[i];
        maxEpid[i] = maxEpid[maxIndex];
        maxEpid[maxIndex] = temp;

        // Ανταλλαγή αριθμού αθλητή (ώστε να ταιριάζει με τις επιδόσεις)
        int tempAA = ArithmAthl[i];
        ArithmAthl[i] = ArithmAthl[maxIndex];
        ArithmAthl[maxIndex] = tempAA;

        // Ανταλλαγή επιδόσεων του αθλητή (όλες οι προσπάθειες)
        for(int k = 0; k < NUM_OF_JUMPS; k++)
        {
            float tempEpi = Epidoseis[i][k];
            Epidoseis[i][k] = Epidoseis[maxIndex][k];
            Epidoseis[maxIndex][k] = tempEpi;
        }
    }
}

void print_data()
{
    printf("\n- ΔΙΕΘΝΕΣ MEETING ΣΤΙΒΟΥ - ΑΛΜΑ ΕΙΣ ΜΗΚΟΣ - ΤΕΛΙΚΑ ΑΠΟΤΕΛΕΣΜΑΤΑ -\n");
    // Header
    printf("  Α_Α   |    1   |    2   |    3   |    4   |    5   |    6   |   max  |\n");

    for (int i = 0; i < NUM_OF_ATHLETES; i++)
    {
        // Print athlete number in a 3-wide field, plus two spaces => total 6 chars before '|'
        printf("  %-4d  |", ArithmAthl[i]);

        for (int j = 0; j < NUM_OF_JUMPS; j++)
        {
            if (Epidoseis[i][j] == -1)        // Foul attempt
                printf("    X   |");          // 7 characters ("   X   ") then '|'
            else if (Epidoseis[i][j] == 0)    // No attempt entered yet
                printf("        |");          // 7 spaces then '|'
            else                              // Valid attempt
                printf(" %6.2f |", Epidoseis[i][j]); 
        }

        // Print max performance, also right-aligned in 6 chars + 1 space => total 7
        printf(" %6.2f |\n", maxEpid[i]);
    }
}
