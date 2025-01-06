#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(void)
{
    char array[2309][50];

    FILE *read = fopen("hangman.txt", "r");
    
    int i = 0;
    while (fscanf(read, "%49s", array[i]) != EOF)
    {
        i++;
    }
    fclose(read);

    // pick a random number of the array
    srand(time(NULL));
    int random_index = rand() % 2309;
    
    char word[50];
    strcpy(word, array[random_index]);

    int length = strlen(word);
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(word[i] != '\0')
        {
            count++;
        }
    }


    printf("Welcome to Hangman! Guess the hidden word by entering one letter at a time. You have 6 chances to guess wrong before the game is over. Good luck!");
    printf("Let's play Hangman! The word has been chosen. It has %d letters. Can you guess it? \n", count);


    for(int i = 0; i < length; i++)
    {
        printf("_ ");
    }
    printf("\n");

    int lives = 6;
    int found[length];
    for(int i = 0; i < length; i++)
    {
        found[i] = 0;
    }

    while(lives > 0)
    {
        printf("You have %d lives left! \n", lives);
        printf("Give me a letter: \n");
        char input;
        scanf("%c", &input);

        int lives_flag = 0;

        for(int i = 0; i < length; i++)
        {
            if(input == word[i])
            {
                found[i] = 1;
                lives_flag = 1;
            }

        }

        if(lives_flag != 1)
        {
            lives--;
        }

        int flag = 1;

        for(int i = 0; i < length; i++)
        {
            if(found[i] == 1)
            {
                printf("%c ", word[i]);
            }
            else
            {
                flag = 0;
                printf("_ ");
            }
        }
        

        if(flag == 1)
        {
            printf("\nNice! You found the word in %d lives left!\n", lives);
            break;
        }

        printf("\n");

        while(getchar() != '\n');
    }
    if(lives == 0)
    {
        printf("\nOopsie, you lost! The word was: %s\n", word);
    }
}