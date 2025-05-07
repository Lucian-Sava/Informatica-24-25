/*DATO UN ARRAY ESEGUIRE LA MEDIA DEI SUOI VALORI*/
#include <stdio.h>
#define SIZE 10

void calcolaMedia(int array[], int size, float *media) {
    int somma = 0;
    for (int i = 0; i < size; i++) {
        somma += array[i];
    }
    *media = (float)somma / size;
}

int main() {
    int array[SIZE];
    float media;

    // Chiedi all'utente di inserire i valori dell'array
    printf("Inserisci %d valori:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    calcolaMedia(array, SIZE, &media);

    printf("La media dei valori dell'array è: %.2f\n", media);

    return 0;
}