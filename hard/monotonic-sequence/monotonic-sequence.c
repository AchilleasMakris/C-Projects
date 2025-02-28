#include <stdio.h>

int main(void) {
    int pinakas[10]; // Στατικός πίνακας με μέγιστο μέγεθος 10
    int n, i;        // Αρχικοποίηση μεταβλητών
    int flag_timwn_pinaka; // Flag για αμυντικό προγραμματισμό

    // i)
    do {
        printf("Πόσα στοιχεία θέλετε να εισάγετε (μέγιστο 10); ");
        scanf("%d", &n);

        if (n >= 3 && n <= 10) {
            do {
                flag_timwn_pinaka = 0; // Μηδενίζουμε το flag στην αρχή του loop

                for (i = 0; i < n; i++) {
                    printf("Εισάγετε τιμή για το στοιχείο %d: ", i + 1);
                    scanf("%d", &pinakas[i]);

                    if (i > 0 && pinakas[i] == pinakas[i - 1]) { // i > 0 για να δώσει ο χρήστης το πρώτο στοιχείο και μετά να το συγκρίνουμε με το προηγούμενο του.
                        printf("Δόθηκαν δύο ίδια συνεχόμενα στοιχεία - παρακαλώ επαναλάβετε την είσοδο από την αρχή.\n");
                        flag_timwn_pinaka = 1; // Θέτουμε το flag σε 1 για να ξανά ξεκινήσει το do-while απο την αρχή
                        break; // Σπάμε το for loop 
                    }
                }
            } while (flag_timwn_pinaka == 1); // Επαναλαμβάνουμε οσο το flag είναι 1
        } else {
            printf("Ο αριθμός των στοιχείων πρέπει να είναι από 3 έως 10.\n");
        }

    } while (n < 3 || n > 10); // Επαναλαμβάνουμε αν το n είναι εκτός ορίων

    // Εμφάνιση των τιμών του πίνακα
    printf("Τα στοιχεία που διαβάστηκαν είναι τα εξής: \n");
    for (i = 0; i < n; i++) {
        printf("Το στοιχείο %d είναι ίσο με %d\n", i + 1, pinakas[i]);
    }

    // ii, iii)
    int k = 0; // Αριθμός αλλαγών μονοτονίας
    int megisti_monotonia = 1; 
    int elaxisti_monotonia = 100;
    int megethos = 1;
    int monotonia_prin = 0;

    // Εύρεση αρχικής μονοτονίας
    if (pinakas[1] > pinakas[0])
        monotonia_prin = 1;
    else if (pinakas[1] < pinakas[0])
        monotonia_prin = -1;

    // Υπολογισμός αλλαγών μονοτονίας
    for (i = 1; i < n; i++) {
        if ((pinakas[i] > pinakas[i - 1] && monotonia_prin != 1) || 
            (pinakas[i] < pinakas[i - 1] && monotonia_prin != -1)) {
            
            k++; // Υπολογισμός αλλαγών μονοτονίας

            if (megethos > megisti_monotonia) {
                megisti_monotonia = megethos;
            }
            if (megethos < elaxisti_monotonia) {
                elaxisti_monotonia = megethos;
            }

            megethos = 1; // Επαναφορά μέτρησης
            if (pinakas[i] > pinakas[i - 1]) {
                monotonia_prin = 1;
            } else {
                monotonia_prin = -1;
                }
        } else {
            megethos++;
        }
    }

    // Υπολογισμός για το τελευταίο τμήμα
    if (megethos > megisti_monotonia) {
        megisti_monotonia = megethos;
    }
    if (megethos < elaxisti_monotonia) {
        elaxisti_monotonia = megethos;
    }

    printf("Αλλαγές μονοτονίας: %d\n", k);
    printf("Μέγιστο μήκος μονοτονικής υποακολουθίας: %d\n", megisti_monotonia);
    printf("Ελάχιστο μήκος μονοτονικής υποακολουθίας: %d\n", elaxisti_monotonia);

    return 0;
}
