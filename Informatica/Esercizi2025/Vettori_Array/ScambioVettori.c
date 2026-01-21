/*
    DATI DUE VATTORI CARICATI CASUALMENTE
    ESEGUIRE UNO SCAMBIO DI VALORI
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liberia.h"
#include "liberia.c"
#define DIM 4

int main()
{
    srand(time(NULL));
    int vett[DIM]={0};
    int vett2[DIM]={0};

    CaricaCasuale(vett, DIM, 10,50);
    stampaVett(vett,DIM, '-' );
    CaricaCasuale(vett2, DIM, 10,50);
    printf("\n")
    ScambioVettori(vett ,vett2, DIM);
    stampaVett(vett,DIM; '-' );
    printf("\n");
    stampaVett(vett2, DIM, '-');

}