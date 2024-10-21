/* Esercizio5
Memorizzare il seme e il punteggio di due carte da poker. Dire quale delle carte vale di più.  Il valore di una carta da poker è dato in primo luogo dal punteggio e in caso di parità di punteggio dal seme.
I punteggi in ordine decrescente sono {k,q,j,9,8,7,6,5,4,3,2,1}, i semi in ordine decrescente sono  {cuori, quadri, fiori, picche} per i semi memorizzare solo la lettera iniziale del seme.
PS: l’ordine dei semi può essere ricordato grazie alla frase “come quando fuori piove” in cui le parole ricordano i nomi dei semi (cuori, quadri, fiori, picche). */

#include <stdio.h>
#include <string.h>

// Funzione per ottenere il valore numerico del punteggio
int valorePunteggio(char punteggio) {
    switch (punteggio) {
        case 'k': return 13;
        case 'q': return 12;
        case 'j': return 11;
        case '9': return 9;
        case '8': return 8;
        case '7': return 7;
        case '6': return 6;
        case '5': return 5;
        case '4': return 4;
        case '3': return 3;
        case '2': return 2;
        case '1': return 1;
        default: return 0;
    }
}

// Funzione per ottenere il valore numerico del seme
int valoreSeme(char seme) {
    switch (seme) {
        case 'c': return 4; // cuori
        case 'q': return 3; // quadri
        case 'f': return 2; // fiori
        case 'p': return 1; // picche
        default: return 0;
    }
}

int main() {
    char punteggio1, seme1;
    char punteggio2, seme2;
    
    // Lettura delle due carte
    printf("Inserisci il punteggio e il seme della prima carta (es. k c): ");
    scanf(" %c %c", &punteggio1, &seme1);
    
    printf("Inserisci il punteggio e il seme della seconda carta (es. q f): ");
    scanf(" %c %c", &punteggio2, &seme2);
    
    // Confronto dei punteggi
    int valore1 = valorePunteggio(punteggio1);
    int valore2 = valorePunteggio(punteggio2);
    
    if (valore1 > valore2) {
        printf("La prima carta vale di più.\n");
    } else if (valore1 < valore2) {
        printf("La seconda carta vale di più.\n");
    } else {
        // Se i punteggi sono uguali, confronto dei semi
        int semeValore1 = valoreSeme(seme1);
        int semeValore2 = valoreSeme(seme2);
        
        if (semeValore1 > semeValore2) {
            printf("Le carte hanno lo stesso punteggio, ma la prima carta vale di più per il seme.\n");
        } else if (semeValore1 < semeValore2) {
            printf("Le carte hanno lo stesso punteggio, ma la seconda carta vale di più per il seme.\n");
        } else {
            printf("Le due carte sono identiche.\n");
        }
    }
    
    return 0;
}