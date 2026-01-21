/*
creaiamo n menù di richiese
1) CARICAE UN  array con un solo valor pari
2) stampare l'array
3) ordina l'array tramite la tecnica del bubble sort.
*/
#include <stdio.h>
#include "liberia.c"
#include "liberia.h"
#define DIM 5

int main()
{
    int vett[DIM];

    int scelta=0;
    do{
        printf("Manu'");
        printf("\n1) Carica l'array");
        printf("\n2) Stampare l'array");
        printf("\n3) Ordina l'array tramite la tecnica del Bubble sort");
        printf("\n4) Trovato il valore minimo e il valore massimo all'interno dell'array scambire posizione");
        printf("\nDigita 0 per terminare");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:
            {
                caricaVett(vett, DIM);
                break;
            }
        case 2:
            {
                stampaVett(vett, DIM, '-');
                break;
            }
        case 3:
            {
                caricaBubble(vett, DIM);
                break;
            }
        case 4:
            {
                scambioMinMax(ett, DIM);
                break;
            }
        default:
            break;
        }

    }while(scelta!=0);

    

}