#include <stdio.h>
#include <string.h>

int main(void)
{
    int words = 0;

    char input[256];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    FILE *file = fopen("file_io_word_count.txt", "w");
    if (file == NULL)
    {
        return 1;
    }

    fprintf(file, "%s", input);
    fclose(file);

    FILE *open = fopen("file_io_word_count.txt", "r");
    char c;
    while(fread(&c, sizeof(char), 1, open))
    {
        if(c == ' ')
        {
            words++;
        }
    }
    printf("The amount of words in the document is: %d\n", words+1);
    fclose(open);
}
