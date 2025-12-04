/*Eliminare gli spazzi da una stringa*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* stringa;

void compatta(char* buffer, int len)
{
    if(len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
        len--;
    }
}

void elimina_spazi(stringa E)
{
    int j = 0;
    for(int i = 0; E[i] != '\0'; i++)
    {
        if(E[i] != ' ')
        {
            E[j++] = E[i];
        }
    }
    E[j] = '\0'; // terminatore di stringa
}

int main()
{
    char buffer[300];

    stringa Frase;

    printf("Inserisci una frase: ");
    fgets(buffer, sizeof(buffer), stdin); //leggo la frase
    int len = strlen(buffer);             //calcolo la lunghezza della frase
    compatta(buffer, len);

    Frase = (stringa)malloc((len + 1) * sizeof(char)); //alloco la memoria per la frase
    if(Frase == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    /* Copio il buffer in Frase e poi rimuovo gli spazi */
    strcpy(Frase, buffer);   //destinazione, sorgente
    elimina_spazi(Frase);   //elimino gli spazi
    printf("Frase senza spazi: '%s'\n", Frase);
    free(Frase);
    return 0;
}