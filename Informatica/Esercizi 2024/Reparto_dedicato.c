/* Un
grande magazzino ha 4 reparti, rappresentati con i numeri da 1 a 4.
La Direzione decide di applicare sui prodotti di ciascun reparto
sconti con percentuali differenziate:-  reparto
   1 = nessuno sconto -  reparto
   2 = sconto 3%-  reparto
   3 = sconto 2%-  reparto
   4 = sconto 5%
Dati
reparto di appartenenza e prezzo di un prodotto, calcolare e
visualizzare il prezzo scontato*/
#include <stdio.h>

float calcolaSconto(int reparto, float prezzo) {
    float prezzoScontato;

    switch (reparto) {
        case 1:
            prezzoScontato = prezzo; // nessuno sconto
            break;
        case 2:
            prezzoScontato = prezzo * 0.97; // sconto 3%
            break;
        case 3:
            prezzoScontato = prezzo * 0.98; // sconto 2%
            break;
        case 4:
            prezzoScontato = prezzo * 0.95; // sconto 5%
            break;
        default:
            printf("Reparto non valido.\n");
            return -1;
    }

    return prezzoScontato;
}

int main() {
    int reparto;
    float prezzo, prezzoScontato;

    printf("Inserisci il reparto (1-4): ");
    scanf("%d", &reparto);

    printf("Inserisci il prezzo del prodotto: ");
    scanf("%f", &prezzo);

    prezzoScontato = calcolaSconto(reparto, prezzo);

    if (prezzoScontato != -1) {
        printf("Il prezzo scontato è: %.2f\n", prezzoScontato);
    }

    return 0;
}
