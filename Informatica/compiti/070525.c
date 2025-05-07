/* Dato un array calcolare quanti valori pari e quanti valori dispari */
#include <stdio.h>

void contaPariDispari(int array[], int size, int *pari, int *dispari) {
    *pari = 0;
    *dispari = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*pari)++;
        } else {
            (*dispari)++;
        }
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int pari, dispari;

    contaPariDispari(array, size, &pari, &dispari);

    printf("Valori pari: %d\n", pari);
    printf("Valori dispari: %d\n", dispari);

    return 0;
}