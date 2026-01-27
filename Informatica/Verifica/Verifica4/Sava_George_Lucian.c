#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char titolo[20];
    char autore[20];
    int isbn;

    struct {
        int copie_attuale;
        int copie_totali;
        int copie_disponibili;
    } copie;

    struct {
        int data_prestitoG;
        int data_prestitoM;
        int data_prestitoA;
        int data_restituzioneG;
        int data_restituzioneM;
        int data_restituzioneA;
    } data;

} libri;

void Inserimento_libri(libri **vettore, int *lunghezza)
{
    int i = *lunghezza;

    libri *tmp = realloc(*vettore, (*lunghezza + 1) * sizeof(libri));  // Riassegna la memoria per un libro in più, perché sto per aggiungerne uno
    if (tmp == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return;
    }
    *vettore = tmp;  // Aggiorna il puntatore al vettore

    printf("Inserisci il titolo del libro: ");
    scanf("%s", (*vettore)[i].titolo);

    printf("Inserisci l'autore del libro: ");
    scanf("%s", (*vettore)[i].autore);

    printf("Inserisci il codice ISBN del libro: ");
    scanf("%d", &(*vettore)[i].isbn);

    printf("Quante copie ha il libro? ");
    scanf("%d", &(*vettore)[i].copie.copie_attuale);

    (*vettore)[i].copie.copie_totali = (*vettore)[i].copie.copie_attuale;           // Inizializzare le copie_totali
    (*vettore)[i].copie.copie_disponibili = (*vettore)[i].copie.copie_attuale;      // Inizializzare le copie_disponibili

    (*lunghezza)++;  // Incrementa la lunghezza del vettore
}

void registro_prestito(libri **vettore, int *lunghezza)
{
    char libro[20];
    int trovato = -1;       // Indice del libro trovato, -1 perchè non l'ho ancora trovato

    printf("Che libro vuoi dare in prestito? ");
    scanf("%s", libro);

    for (int j = 0; j < *lunghezza; j++)  //vado a scorrere il vettore dei libri per vedere se il libro inserito è presente
    {
        if (strcmp(libro, (*vettore)[j].titolo) == 0)  // Confronta i titoli, se sono uguali ritorna 0
        {
            trovato = j; //se lo trovo mi salvo l'indice su vettore trovato
            break;
        }
    }

    if (trovato == -1)// Se il libro non è stato trovato
    {
        printf("Libro non trovato.\n");
        return;
    }

    if ((*vettore)[trovato].copie.copie_disponibili <= 0)  // Controlla se ci sono copie disponibili
    {
        printf("Non ci sono copie disponibili.\n");
        return;
    }

    printf("Inserisci data prestito (G M A): ");
    scanf("%d %d %d",
          &(*vettore)[trovato].data.data_prestitoG,
          &(*vettore)[trovato].data.data_prestitoM,
          &(*vettore)[trovato].data.data_prestitoA);

    printf("Inserisci data restituzione (G M A): ");
    scanf("%d %d %d",
          &(*vettore)[trovato].data.data_restituzioneG,
          &(*vettore)[trovato].data.data_restituzioneM,
          &(*vettore)[trovato].data.data_restituzioneA);

    (*vettore)[trovato].copie.copie_disponibili--; // Decrementa il numero di copie disponibili

    printf("Prestito registrato. Copie rimaste: %d\n",
           (*vettore)[trovato].copie.copie_disponibili);
}

void elenco_completo(libri **vettore, int *lunghezza)
{
    printf("\n=== ELENCO COMPLETO LIBRI ===\n");

    for (int i = 0; i < *lunghezza; i++)   // Scorro il vettore dei libri
    {
        printf("\nLibro %d:\n", i + 1); // Stampo le informazioni del libro, i+1 indica il numero del libro
        printf("Titolo: %s\n", (*vettore)[i].titolo);
        printf("Autore: %s\n", (*vettore)[i].autore);
        printf("ISBN: %d\n", (*vettore)[i].isbn);
        printf("Copie disponibili: %d\n", (*vettore)[i].copie.copie_disponibili);
    }
}

void elenco_prestito(libri **vettore, int *lunghezza)
{
    printf("\n=== LIBRI ATTUALMENTE IN PRESTITO ===\n");

    for (int i = 0; i < *lunghezza; i++)  // Scorro il vettore dei libri
    {
        if ((*vettore)[i].copie.copie_disponibili < (*vettore)[i].copie.copie_totali)  // Controllo se ci sono copie in prestito
        {
            printf("\nLibro: %s\n", (*vettore)[i].titolo);
            printf("Prestato il: %d/%d/%d\n",
                   (*vettore)[i].data.data_prestitoG,
                   (*vettore)[i].data.data_prestitoM,
                   (*vettore)[i].data.data_prestitoA);
        }
    }
}

void cerca_libroISBN(libri **vettore, int *lunghezza)
{
    int cerca;
    int trovato = -1;// Indice del libro trovato, -1 perchè non l'ho ancora trovato

    printf("Inserisci ISBN da cercare: ");
    scanf("%d", &cerca);

    for (int j = 0; j < *lunghezza; j++)        //vado a scorrere il vettore dei libri per vedere se l'ISBN inserito è presente
    {
        if (cerca == (*vettore)[j].isbn)        //confronto l'ISBN cercato con quello presente nel vettore
        {
            trovato = j;                        //se lo trovo salvo l'indice
            break;
        }
    }

    if (trovato == -1)
    {
        printf("Libro non trovato.\n");
        return;
    }

    printf("\nLibro trovato:\n");
    printf("Titolo: %s\n", (*vettore)[trovato].titolo);//la varuabile trovato contiene l'indice del libro trovato
    printf("Autore: %s\n", (*vettore)[trovato].autore);
    printf("Copie disponibili: %d\n", (*vettore)[trovato].copie.copie_disponibili);
}

void stampa_prestito_scaduto(libri **vettore, int *lunghezza)
{
    printf("\n=== PRESTITI SCADUTI ===\n");

    for (int i = 0; i < *lunghezza; i++)                       //scorro il vettore dei libri
    {
        if ((*vettore)[i].data.data_restituzioneG != 0)         //controllo se la data di restituzione è stata impostata (diversa da 0)
        {
            printf("\nLibro: %s\n", (*vettore)[i].titolo);
            printf("Restituzione prevista: %d/%d/%d\n",
                   (*vettore)[i].data.data_restituzioneG,
                   (*vettore)[i].data.data_restituzioneM,
                   (*vettore)[i].data.data_restituzioneA);
        }
    }
}

int main()
{
    libri *vettore = NULL;
    int scelta;
    int lunghezza = 0;

    do {
        printf("\n==== MENU ====\n");
        printf("1. Inserimento dei libri\n");
        printf("2. Registrare il prestito di un libro\n");
        printf("3. Visualizzare l'elenco completo dei libri\n");
        printf("4. Visualizzare i libri attualmente in prestito\n");
        printf("5. Cerca libro per ISBN\n");
        printf("6. Stampa dei libri con prestito scaduto\n");
        printf("7. Esci dal programma\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta)
        {
            case 1:
                Inserimento_libri(&vettore, &lunghezza);
                break;
            case 2:
                registro_prestito(&vettore, &lunghezza);
                break;
            case 3:
                elenco_completo(&vettore, &lunghezza);
                break;
            case 4:
                elenco_prestito(&vettore, &lunghezza);
                break;
            case 5:
                cerca_libroISBN(&vettore, &lunghezza);
                break;
            case 6:
                stampa_prestito_scaduto(&vettore, &lunghezza);
                break;
            case 7:
                printf("Uscita...\n");
                free(vettore);
                break;
            default:
                printf("Scelta non valida.\n");
        }

    } while (scelta != 7);

    return 0;
}