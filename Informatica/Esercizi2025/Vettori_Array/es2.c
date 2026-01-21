/* Caricato un vettore con valore random
    calcolare la media dei valori
*/
#include <stdio.h>
#include "liberia.c"
//#include "liberia.h"
#define DIM 10

int main()
{
    int vettore[DIM]={0};
    int MAX=100, MIN=1;

    riempiVettoriCasuale(vettore, DIM, MIN, MAX);
    stampaVett(vettore, DIM, '-');
    calcolaMedia(vettore, DIM);
}