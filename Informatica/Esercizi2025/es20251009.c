/* stringhe con malloc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer; // puntatore alla stringa buffer
    int len;
    
    printf("Inserisci la lunghezza della stringa: ");
    scanf("%d", &len);

    // allloco lo spazio in memoria
    buffer = (char *)malloc((len + 1) * sizeof(char)); // +1 per il terminatore di stringa
    if(buffer == NULL)
    {
        printf("Errore di allocazione memoria\n");
        return 1;
    }

    printf("Inserisci una stringa: ");
         //scanf("%s", buffer); // leggo la stringa
    fgets(buffer, len + 1, stdin); // leggo la stringa
    printf("Hai inserito: %s\n", buffer);

    free(buffer); // libero la memoria allocata
    return 0;
}