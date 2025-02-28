 
#include <stdio.h>
#include <string.h>

 
#define N 5
 
/* Ορισμός δομής customer - Ερώτημα 1 */
struct customer
{           
int aa_customer;    /* Α_Α πελάτη*/
float income;      /* Εισόδημα */
float loan_amount; /* Ζητούμενο ποσό δανείου */
float dti;         /* Ποσοστό DTI */
int job_years;     /* Χρόνια στο επάγγελμα */
int red_loan;     /* Ιστορικό κόκκινου δανείου (NAI/OXI)*/
int rating;        /* Βαθμολογία πιστοληπτικής ικανότητας */
};
 
/* Ορισμός δομής loan - Ερώτημα 1 */
struct loan
{                   
int aa_loan;        /* Α_Α δανείου */
int aa_customer;    /* Α_Α πελάτη*/
float loan_amount;  /* Ζητούμενο ποσό δανείου */
};
 
//Δήλωση πίνακα εγγραφών για πελάτες -Ερώτημα 2
// Δήλωση πίνακα εγγραφών για εγκεκριμένα δάνεια - Ερώτημα 2
//Δήλωση απαραίτητων για το πρόγραμμα μεταβλητών 
struct customer customers_list[N];
struct loan loan_list[N];

/* Δήλωση του στόχου συνολικού ποσού δανείων */
float total_bank_loan_amount; /* Συνολικό διαθέσιμο ποσό δανισμού απο την τράπεζα*/
int total_loans = 0; /* Συνολικά δάνεια που έδωσε η τράπεζα*/
float total_customer_loan_amount = 0; /* Συνολικό ποσό που ζητήσαν οι πελ΄άτες και εγκρήθηκε απο την τράπεζα */

int rating_threshold = 650;  /* μεταβλητή για το όριο πιστοληπτικής ικανότητας */

/* συνάρτηση έγκρισης δανείου - Ερώτημα 5 */
void approve_loan() 
{

    for(int i = 0; i < N; i++)
    {
        if (customers_list[i].income < 30000)
        {
            continue;
        }
        if(customers_list[i].dti > 40)
        {
            continue;
        }
        if(customers_list[i].rating < rating_threshold)
        {
            continue;
        } 
        if(customers_list[i].red_loan == 1)
        {
            continue;
        }
        else
        {
            loan_list[total_loans].aa_loan = total_loans + 1;
            loan_list[total_loans].aa_customer = customers_list[i].aa_customer;
            loan_list[total_loans].loan_amount = customers_list[i].loan_amount;
            total_customer_loan_amount += loan_list[total_loans].loan_amount;
            total_loans++;

        }
    }
}

/* συνάρτηση για την εμφάνιση των στοιχείων πελατών, των εγκεκριμένων δανείων, του συνολικού αριθμού των εγκεκριμένων δανείων και του συνολικού ποσού αυτών - Ερώτημα 7*/
void display()
{
    printf("Πίνακας πελατών\n");
    for(int i = 0; i < N; i++)
    {
        printf("id=%d, εισόδημα=%.0f, ζητούμενο ποσό δανείου=%.0f, DTI= %.0f, χρόνια στο επάγγελμα=%d, κόκκινο δάνειο=%d, πιστοληπτική ικανότητα=%d\n",
            customers_list[i].aa_customer,
            customers_list[i].income,
            customers_list[i].loan_amount,
            customers_list[i].dti,
            customers_list[i].job_years,
            customers_list[i].red_loan,
            customers_list[i].rating);
    }
    printf("--------------------------------------------------\n");
    printf("Πίνακας εγκεκριμένων δανείων\n");
    for(int i = 0; i < N; i++)
    {
        if(loan_list[i].aa_loan != 0)
        {
            printf("id=%d, πελάτης=%d, ποσό δανείου=%.0f\n",
                loan_list[i].aa_loan,
                loan_list[i].aa_customer,
                loan_list[i].loan_amount
            );
        }
    }
    printf("--------------------------------------------------\n");
    printf("Συνολικός αριθμός εγκερκιμένων δανείων: %d\n", total_loans);
    printf("Συνολικός ποσό εγκεκριμένων δανείων: %.6f\n", total_customer_loan_amount);
    printf("--------------------------------------------------\n");

}
    
/*συνάρτηση ελέγχου επίτευξης του στόχου δανεισμού και αναπροσαρμογή - Ερώτημα 7*/
void evaluate_loans() 
{
    do
    {
        /* Μηδενίζουμε τον πίνακα με τα εγκεκριμένα δάνεια και τους μετρητές */
        total_loans = 0;
        total_customer_loan_amount = 0;
        for(int i = 0; i < N; i++)
        {
            loan_list[i].aa_loan = 0;
            loan_list[i].aa_customer = 0;
            loan_list[i].loan_amount = 0;
        }

        /* Καλούμε την approved_loan() για έλεγχο με το rating_threshold */
        approve_loan();

        /* Εαν το συνολικό ποσσό εγκεκριμέν ων δανείων είναι μικρότερο απο τον στόχο αλλα ΚΑΙ το όριο ειναι ακόμη >=550, μειώνουμε το όριο κατά 10 μονάδες */
        if (total_customer_loan_amount < total_bank_loan_amount && rating_threshold > 550)
            rating_threshold -= 10;
        else
            break;
    }while (total_customer_loan_amount < total_bank_loan_amount && rating_threshold >= 550);
}
 
//κύριο πρόγραμμα
int main()
{
    /* εισαγωγή δεδομένων από το πληκτρολόγιο - Ερώτημα 2 και Ερώτημα 3 */
    /* Εισαγωγή του στόχου του συνολικού ποσού δανείων */
    printf("Δώσε τον στόχο του συνολικού ποσού δανείων (€): ");
    scanf("%f", &total_bank_loan_amount);

    for(int i = 0; i < N; i++)
    {
        /*  Για κάθε πελάτη  */
        printf("\nΕισαγωγή στοιχείων για τον πελάτη %d:\n", i+1);
        customers_list[i].aa_customer= i+1;

         // Εισαγωγή εισοδήματος
         printf("Εισάγετε το εισόδημα του πελάτη: ");
         scanf("%f", &customers_list[i].income);

         // Εισαγωγή ζητούμενου ποσού δανείου
         printf("Εισάγετε το ζητούμενο ποσό δανείου: ");
         scanf("%f", &customers_list[i].loan_amount);

         // Εισαγωγή ποσοστού DTI
        printf("Εισάγετε το ποσοστό DTI (π.χ. 35 για 35%%): ");
        scanf("%f", &customers_list[i].dti);

        do 
        {
        /* Εισαγωγή των χρόνων στο επάγγελμα με αμυντικό προγραμματισμό για αριθμό μεγαλύτερο ή ίσο του μηδενός */
        printf("Εισάγετε τα χρόνια στο επάγγελμα: ");
        scanf("%d", &customers_list[i].job_years);
        if (customers_list[i].job_years < 0)
        {
            printf("Λανθασμένη εισαγωγή. Δώστε έναν αριθμό ≥ 0.\n");
        }
        } while (customers_list[i].job_years < 0);

        /*Εισαγωγή για το αν ο πελάτης έχει κόκκινο δάνειο με αμυντικό προγραμματισμό για είσοδο 0 ή 1*/
        do
        {
            printf("Έχει κόκκινο δανείο; (0 για ΟΧΙ, 1 για ΝΑΙ): ");
            scanf("%d", &customers_list[i].red_loan);
            if(customers_list[i].red_loan != 0 && customers_list[i].red_loan != 1)
            {
                printf("Λάθος εισαγωγή, παρακαλώ δώστε 0 ή 1 \n");
            }
        } while (customers_list[i].red_loan != 0 && customers_list[i].red_loan != 1);
    }
       
    // Υπολογισμός της πιστοληπτικής ικανότητας - Ερώτημα 4
    // εκχώρηση αρχικής τιμής της πιστοληπτικής ικανότητας
    for(int i = 0; i < N; i++)
    {
        int pistoliptiki_ikanotita = 300;
        /* έλεγχος εισοδήματος και αύξηση της τιμής της πιστοληπτικής ικανότητας με βάση τα δεδομένα*/
        if(customers_list[i].income > 50000)
        {
            pistoliptiki_ikanotita += 100;
        }
        /* έλεγχος του DTI και αύξηση της τιμής της πιστοληπτικής ικανότητας με βάση τα δεδομένα*/
        if(customers_list[i].dti < 30)
        {
            pistoliptiki_ikanotita += 150;
        }
        /* έλεγχος των ετών στο επάγγελμα και αύξηση της τιμής της πιστοληπτικής ικανότητας με βάση τα δεδομένα*/
        if(customers_list[i].job_years > 5)
        {
            pistoliptiki_ikanotita += 100;
        }
        /* έλεγχος ύπαρξης κόκκινου δανείου και μείωση της τιμής της πιστοληπτικής ικανότητας με βάση τα δεδομένα*/
        if(customers_list[i].red_loan == 1)
        {
            pistoliptiki_ikanotita -= 200;
        }

        customers_list[i].rating = pistoliptiki_ikanotita;

        /* Τέλος επανάληψης για κάθε πελάτη */
    }
    
 

approve_loan();  // κλήση υποπρογράμματος για αξιολόγηση κριτηρίων για δάνειο
display(); // κλήση υποπρογράμματος για εμφάνιση στοιχείων στην οθόνη
evaluate_loans(); // κάλεσμα υποπρογράμματος για έλεγχος στόχου δανεισμού και επαναπροσδιορισμός

printf("\nΕγκεκριμένα δάνεια μετά την προσαρμογή\n");
display(); // κλήση υποπρογράμματος για εμφάνιση στοιχείων στην οθόνη
// Εμφάνιση του τελικού κατώτατου ορίου πιστοληπτικής ικανότητας.
printf("Τελικό κατώτατο όριο πιστοληπτικής ικανότητας: %d\n", rating_threshold);
    return 0;
}