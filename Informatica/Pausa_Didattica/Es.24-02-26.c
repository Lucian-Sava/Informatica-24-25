/*    Dichiarare un array di libri di dimensione massima N
    Consentire l'inserimento dei dati di un libro.
    Aggiornare correttamente il numero di copie disponibili.
    Registare il prestito di un libro:
        -inserendo la data di un prestito e la data di restituzione
        -decrementando il numero di copie disponibili
        -impedendo il prestito se non ci sono copie disponibili
    Visualizzare l'elenco completo dei libri con tutte le informazioni
    Visualizzare solo i libri attualmente in prestito(copie disponibili<copie totali)
    Cercare un libro tramite ISBN
    Stampare solo i libri con prestito scaduto
    Vincoli: accedere ai campi delle date tramite struct annidata
*/

// CORREZIONE DELLA VERIFICA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data
{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct Libro
{
    char titolo[20];
    char autore[20];
    int isbn;
    int copie_totali;
    int copie_disponibili;
    data data_prestito;
    data data_restituzione;
}Libro;


int main()
{
    Libro* biblioteca = NULL;
    int n = 0, scelta;
    char c;

    do{
        printf("-----MANU-----");
        printf("1. Inserisci nuovo libro\n");
        printf("2. Visualizza tutti i libri\n");
        printf("3. Registra prestito\n");
        printf("4. Cerca libro per ISBN\n");
        printf("5. Visualizza libri in prestito\n");
        printf("6. Stampare il libro con il prestito scaduto\n");
        printf("0. Esci\n");
        while((c = getchar()) != '\n') {}
    }while(scelta!=0);

    
}