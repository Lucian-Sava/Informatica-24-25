#include <stdio.h>

int main() {
    char stringa_originale[150];
    char sottostringa[20]; // Dimensione sufficiente per la sottostringa
    int indice_inizio = 1;
    int lunghezza = 20;

    printf("Inserisciuna frase: ");
    scanf("%s", stringa_originale);
    printf("Inserisci la sottostringa: ");
    scanf("%s", sottostringa);

    // Copia i caratteri
    for (int i = 0; i < lunghezza; i++) {
        sottostringa[i] = stringa_originale[indice_inizio + i];
    }
    
    // Aggiungi il carattere nullo per terminare la sottostringa
    sottostringa[lunghezza] = '\0';

    printf("\nLa sottostringa è: %s\n", sottostringa);

    return 0;
}