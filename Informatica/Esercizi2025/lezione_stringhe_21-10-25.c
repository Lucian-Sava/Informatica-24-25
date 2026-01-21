/*
    DATA UNA STRINGA CONTARE IL NUMERO DELLE VOCALI
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* stringa;

void compatta(char* buffer, int len)
{
    if(len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
        len--;
    }
}

int conta_vocali(stringa Frase)
{
    int cnt = 0;
    for(int i = 0; Frase[i] != '\0'; i++)
    {
        char c = tolower(Frase[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            cnt++;
        }

    }
    return cnt;

}


int main()
{
    char buffer[200];
    
    stringa Frase;

    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin);

    int len = strlen(buffer);
    compatta(buffer, len);

    Frase = (stringa)malloc((len + 1) * sizeof(char));
    if(Frase == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    strcpy(Frase, buffer);   //destinazione, sorgente

    //controllo di quanti vocali ci sono

    printf("Il numero delle vocali e': %d\n", conta_vocali(Frase));

    free(Frase);
    return 0;
}