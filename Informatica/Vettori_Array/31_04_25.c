/* dopo aver caricato un vettore numerico confrontare la somma 
delle componenti di indice pari con la somma 
delle componenti dispari e dire se la somma maggiore 
è divisibile per un assegnato valore k (con k diverso da 0)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liberia.c"
#include "liberia.h"
#define DIM 5
int main()
{
    int vett[DIM];
    int vett2[DIM];
    richiedi