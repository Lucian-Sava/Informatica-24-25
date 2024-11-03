/*Gioco della Morra cinese: supponendo sasso=1, carta=2, forbice=3, chiedere all’utente la sua scelta e far generare al computer la sua. Stabilire il vincitore. N.B.:per chi non conoscesse il gioco: sasso vince forbice, sasso perde carta, carta perde forbice.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void determinareVincitore(int utente, int computer) {
    switch(utente) {
        case 1: // Sasso
            switch(computer) {
                case 1: printf("Pareggio! Entrambi avete scelto Sasso.\n"); break;
                case 2: printf("Hai perso! Carta batte Sasso.\n"); break;
                case 3: printf("Hai vinto! Sasso batte Forbice.\n"); break;
            }
            break;
        case 2: // Carta
            switch(computer) {
                case 1: printf("Hai vinto! Carta batte Sasso.\n"); break;
                case 2: printf("Pareggio! Entrambi avete scelto Carta.\n"); break;
                case 3: printf("Hai perso! Forbice batte Carta.\n"); break;
            }
            break;
        case 3: // Forbice
            switch(computer) {
                case 1: printf("Hai perso! Sasso batte Forbice.\n"); break;
                case 2: printf("Hai vinto! Forbice batte Carta.\n"); break;
                case 3: printf("Pareggio! Entrambi avete scelto Forbice.\n"); break;
            }
            break;
        default: 
            printf("Scelta non valida.\n");
            break;
    }
}

int main() {
    int sceltaUtente, sceltaComputer;

    srand(time(NULL)); // Inizializza il generatore di numeri casuali

    printf("Scegli:\n1. Sasso\n2. Carta\n3. Forbice\nScelta: ");
    scanf("%d", &sceltaUtente);

    sceltaComputer = (rand() % 3) + 1; // Genera una scelta casuale per il computer (1-3)

    printf("Il computer ha scelto: %d\n", sceltaComputer);
    determinareVincitore(sceltaUtente, sceltaComputer);

    return 0;
}
