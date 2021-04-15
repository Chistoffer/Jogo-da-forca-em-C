#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MASK_CHAR '-'

char inputChar(void)
{
    char buffer[2];
    fflush(stdin);
    printf("\nLETRA: ");
    fgets(buffer, 2, stdin);
    return buffer[0];
}

void initMask(char *mask, char *word)
{
    int length = strlen(word);
    memset(mask, MASK_CHAR, length);
    mask[length] = '\0';
}

void printMask(char *mask)
{
    int i;
    int length = strlen(mask);
    for(i = 0; i < length; i++)
        printf("%c ", mask[i]);
}

int main(void)
{
    char c;
    int index;
    int length;
    int count = 0;
    char *ptr;
    char word[MAX_WORD_LENGTH + 1];
    char mask[MAX_WORD_LENGTH + 1];
    strcpy(word, "INCONSTITUCIONAL");
    initMask(mask, word);

    length = strlen(word);
    while(count < length)
    {
        printMask(mask);
        c = inputChar();
        ptr = strchr(word, c);
        while(ptr)
        {
            count++;
            index = ptr - word;
            mask[index] = word[index];
            ptr = strchr(ptr + 1, c);
        }
    }
    printf("\n");
    system("pause");
    return 0;
}
