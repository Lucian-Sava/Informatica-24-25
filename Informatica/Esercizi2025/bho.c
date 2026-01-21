#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("Seleziona il tuo cazzo di sesso (M/F): ");
    char sesso;
    scanf(" %c", &sesso);

    printf("Hai selezionato: %c\n", sesso);
}