/* Scrivere un programma che letto due orari in ore, minuti e secondi restituisce quale orario viene prima */
#include <stdio.h>
int main()
{
    int ore1, minuti1, secondi1, ore2, minuti2, secondi2, dataminore, datamaggiore;
    printf("Inserisci le Ore: ");
    scanf("%d", &ore1);
    printf("Inserisci le minuti1: ");
    scanf("%d", &minuti1);
    printf("Inserisci le secondi1: ");
    scanf("%d", &secondi1);
    printf("Inserisci le Ore: ");
    scanf("%d", &ore2);
    printf("Inserisci le minuti1: ");
    scanf("%d", &minuti2);
    printf("Inserisci le secondi1: ");
    scanf("%d", &secondi2);
    
if(ore1<24 || minuti1<60 || secondi1<60 && ore1<0 || minuti1<0 || secondi1<0)
    {
        printf("la dati sono accettabili\n");
    }
    else
    {
        printf("Le date non sono accettabili\n");
    }

    if(ore1 + minuti1 + secondi1 > ore2 + minuti2 + secondi2)
    {
        printf("La prima data e Maggiore della seconda data");
    }
    else
    {
        printf("La Seconda Data e Maggiore della prima data");
    }

    if(ore1 + minuti1 + secondi1 == ore2 + minuti2 + secondi2)
    {
        printf("Le date sono Uguali");
    }
    if (ore1 + minuti1 + secondi1 > ore2 + minuti2 + secondi2)
        dataminore = ore2 + minuti2 + secondi2;
        datamaggiore = ore1 + minuti1 + secondi1;
        {
            printf("La Data con l'orario che viene prima è %d %d %d \n", ore2, minuti2, secondi2);
        }
    if (ore1 + minuti1 + secondi1 < ore2 + minuti2 + secondi2)
        datamaggiore = ore1 + minuti1 + secondi1;
        dataminore = ore2 + minuti2 + secondi2;
        {
            printf(" la Data con l'orario che viene prima è %d %d %d \n", ore1, minuti1, secondi1);
        }

    return 0;


    



}
