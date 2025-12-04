/* Data una stringa iniziale e il fattore di cifratura creare la stringa cifrata */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Cifrattura(char *string, int k)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = string[i];

        // Lettere maiuscole
        if (c >= 'A' && c <= 'Z') {
            string[i] = 'A' + (c - 'A' + k) % 26;
        }
        // Lettere minuscole
        else if (c >= 'a' && c <= 'z') {
            string[i] = 'a' + (c - 'a' + k) % 26;
        }
        // Altri caratteri restano invariati
    }


    printf("La cifrattura è: %s\n", string);
}

#include <stdio.h>
#include <string.h>

void Decifrattura(char *stringa, int k)
{
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        char c = stringa[i];

        // Lettere maiuscole
        if (c >= 'A' && c <= 'Z') {
            stringa[i] = 'A' + (c - 'A' - k + 26) % 26;
        }
        // Lettere minuscole
        else if (c >= 'a' && c <= 'z') {
            stringa[i] = 'a' + (c - 'a' - k + 26) % 26;
        }
        // Altri caratteri restano invariati
    }

    printf("La decifrattura è: %s\n", stringa);
}

int main()
{
    char string[100];
    int cifratura;
    int scelta=0;

    printf("Inserisci la stringa iniziale: ");
    scanf("%s", string);

    printf("Inserisci la quantità di cifratura (intero): ");
    scanf("%d", &cifratura);

    Cifrattura(string, cifratura);


    printf("La vuoi decifrare? si--> 1 no ---> 2: ");
    scanf("%d", &scelta);
    

    if(scelta == 1)
    {
        Decifrattura(string, cifratura);
    }
    else if(scelta == 2)
    {
        return 0;
    }
}
