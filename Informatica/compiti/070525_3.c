/*DATO UN ARRAY CALCOLARE LA SOMMA DI TUTTI I VALORI POSITIVI E DI TUTTI I VALORI NEGATIVI*/
#include <stdio.h>
#define SIZE 10
void calcolaSomma(int array[], int size, int *sommaPositiva, int *sommaNegativa) {
    *sommaPositiva = 0;
    *sommaNegativa = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            *sommaPositiva += array[i];
        } else if (array[i] < 0) {
            *sommaNegativa += array[i];
        }
    }
}
int main() {
    int array[SIZE];
    int sommaPositiva, sommaNegativa;

    // Chiedi all'utente di inserire i valori dell'array
    printf("Inserisci %d valori:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    calcolaSomma(array, SIZE, &sommaPositiva, &sommaNegativa);

    printf("La somma dei valori positivi è: %d\n", sommaPositiva);
    printf("La somma dei valori negativi è: %d\n", sommaNegativa);

    return 0;
}