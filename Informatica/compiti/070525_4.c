/*DATO UN ARRAY SOSTITUIRE TUTTI GLI 0 CON IL VALORE MINIMO*/
#include <stdio.h>
#define SIZE 10
void sostituisciZero(int array[], int size) {
    int min = array[0];
    // Trova il valore minimo
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    // Sostituisci gli zeri con il valore minimo
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            array[i] = min;
        }
    }
}
int main() {
    int array[SIZE];
    // Chiedi all'utente di inserire i valori dell'array
    printf("Inserisci %d valori:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    sostituisciZero(array, SIZE);
    // Stampa l'array modificato
    printf("Array dopo la sostituzione degli zeri:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}