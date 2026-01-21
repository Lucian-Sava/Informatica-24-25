/*
    inizializziare - riempimento con valori pari- stampa
    creazione di una liberia personale
*/
#include <stdio.h>
#include "liberia.c"
#define DIM 10

int main()
{
    int vettore[DIM]=0{0};

    richiediValori(vettore, DIM);
    stampaVett(vettore, DIM, '-');
}