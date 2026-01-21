/* Data una stringa scriverla all'inverso */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* stringa;

void InvertiStringa(stringa frase)
{
    int temp;
    for(int i=0; i < frase; i++)
    {
        temp = frase;
        frase = stringa[i];
        stringa[i] = temp;
    }
}

int main()
{
    char buffer[100];
    stringa frase;
    
    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin);
    frase = (stringa)malloc(100 * sizeof(char));
    if(frase == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    InvertiStringa(frase);

    free(frase);
    return 0;
}