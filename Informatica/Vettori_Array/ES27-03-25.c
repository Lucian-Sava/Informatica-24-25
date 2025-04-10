/*crea due vetorori e farli eseguire uno scambio dei due valori*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libArray.h"
#include "libArray.c"
#define DIM 25
int main()
{
    int temp=0, vett[DIM], vett2[DIM];

    srand(time(NULL));
    riempiVettoreOrdinatoCasuale(vett, DIM, 0, 100);
    riempiVettoreOrdinatoCasuale(vett2, DIM, 10, 1000);

    printf("Vett1: ");
    stampaVettore(vett, DIM, ' ');
    printf("\nVett2: ");
    stampaVettore(vett2, DIM, ' ');
    
    for(int i=0; i<DIM; i++)
    {
        temp=vett[i];
        vett[i]=vett2[i];
        vett2[i]=temp;
    }

    printf("\nVett1: ");
    stampaVettore(vett, DIM, ' ');
    printf("\nVett2: ");
    stampaVettore(vett2, DIM, ' ');
}