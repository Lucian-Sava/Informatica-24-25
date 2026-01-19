/*
    Creazione di spotify con queste funzioni da uttilizzare:
    - Titolo
    - Artista
    - Durata
    - ID univoco
    - Puntatore alla canzone successiva

    Implementare le seguenti funzionalità:
    void stampa_canzone(Canzone *c)
    Stampa a video tutti i campi della canzone.

    void set_canzone(Canzone *c)
    Chiede all’utente i dati della canzone (tranne l’ID, che viene generato dal programma).

    Lista* crea_lista()
    Crea e inizializza una lista lineare vuota di canzoni.

    void stampa_lista(Lista *l)
    Stampa tutti gli elementi della lista delle canzoni disponibili.

    void inserisci_canzone_lista(Lista *l)
    Crea una nuova canzone tramite set_canzone() e la inserisce in testa alla lista.

    void ricerca_canzone_artista(Lista *l, char* artista)
    Cerca e stampa tutte le canzoni dell’artista indicato.

    void libera_memoria(Lista* l)
    Libera correttamente la memoria di tutte le canzoni nella lista.

    void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist)
    Chiede all’utente un ID.
    Se esiste una canzone con quell’ID nella lista delle canzoni disponibili, la aggiunge in fondo alla playlist circolare.

    void stampa_playlist(Lista* playlist)
    Stampa tutti gli elementi della playlist, facendo attenzione alla natura circolare della lista.

    void cancella_canzone_playlist(Lista *playlist)
    Chiede un ID all’utente e, se presente nella playlist, lo rimuove correttamente dalla lista circolare.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- Definizione struct necessarie ---- */
typedef struct Canzone {
    int id;
    char titolo[50];
    char artista[50];
    int durata;
    struct Canzone* next;
} Canzone;

typedef struct Lista {
    Canzone* testa;
    int lunghezza;
} Lista;

/* ---- Variabile globale per gestire l'id univoco delle canzoni ---- */
int id_univoco = 0;

/* ---- Funzioni lista di canzoni disponibili ---- */
void stampa_canzone(Canzone *c);
void set_canzone(Canzone *c);
Lista* crea_lista();
void stampa_lista(Lista *l);
void inserisci_canzone_lista(Lista *l);
void ricerca_canzone_artista(Lista *l, char* artista);
void libera_memoria(Lista* l);

/* ---- Funzioni playlist (lista circolare) ---- */
void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist);
void stampa_playlist(Lista* playlist);
void cancella_canzone_playlist(Lista *playlist);

/* ---- MAIN ---- */

int main() {
    Lista* lista_canzoni = crea_lista();
    Lista* playlist = crea_lista();

    int scelta;
    char artista[50];

    do {
        printf("\n===== SPOTIFY 0.0.0.1 =====\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Aggiungi canzone alla playlist\n");
        printf("5. Stampa playlist\n");
        printf("6. Cancella canzone dalla playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar(); // pulisci buffer input

        switch (scelta) {
            case 1:
                inserisci_canzone_lista(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                artista[strcspn(artista, "\n")] = 0; // rimuove newline
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);

    libera_memoria(lista_canzoni);
    libera_memoria(playlist);
    return 0;
}

/* =======================================================================================
   Implementazione funzioni
======================================================================================= */

void stampa_canzone(Canzone *c) {
    printf("ID: %d\n", c->id);
    printf("Titolo: %s\n", c->titolo);
    printf("Artista: %s\n", c->artista);
    printf("Durata: %d secondi\n\n", c->durata);
}

void set_canzone(Canzone *c) {
    c->id = ++id_univoco;

    printf("Inserisci il titolo della canzone: ");
    fgets(c->titolo, 50, stdin);
    c->titolo[strcspn(c->titolo, "\n")] = 0;

    printf("Inserisci l'artista della canzone: ");
    fgets(c->artista, 50, stdin);
    c->artista[strcspn(c->artista, "\n")] = 0;

    printf("Inserisci la durata della canzone (in secondi): ");
    scanf("%d", &c->durata);
    getchar();
}

Lista* crea_lista() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if (!l) {
        printf("Errore allocazione memoria.\n");
        exit(1);
    }
    l->testa = NULL;
    l->lunghezza = 0;
    return l;   // CORRETTO
}

void stampa_lista(Lista *l) {
    if (l->testa == NULL) {
        printf("La lista è vuota.\n");
        return;
    }

    Canzone* current = l->testa;
    while (current != NULL) {
        stampa_canzone(current);
        current = current->next;
    }
}

void inserisci_canzone_lista(Lista *l) {
    Canzone* nuova = (Canzone*)malloc(sizeof(Canzone));
    if (!nuova) {
        printf("Errore allocazione memoria.\n");
        return;
    }

    set_canzone(nuova);
    nuova->next = l->testa;
    l->testa = nuova;
    l->lunghezza++;

    printf("Canzone inserita con ID %d.\n", nuova->id);
}

void ricerca_canzone_artista(Lista *l, char* artista) {
    if (l->testa == NULL) {
        printf("La lista è vuota.\n");
        return;
    }

    Canzone* current = l->testa;
    int trovate = 0;

    while (current != NULL) {
        if (strcmp(current->artista, artista) == 0) {
            stampa_canzone(current);
            trovate = 1;
        }
        current = current->next;   // CORRETTO
    }

    if (!trovate)
        printf("Nessuna canzone trovata per l'artista %s.\n", artista);
}

void libera_memoria(Lista* l) {
    Canzone* current = l->testa;
    while (current != NULL) {
        Canzone* temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist) {
    int id_ricerca;
    printf("Inserisci ID della canzone da aggiungere: ");
    scanf("%d", &id_ricerca);
    getchar();

    Canzone* current = lista_canzoni->testa;

    while (current != NULL) {
        if (current->id == id_ricerca) {

            Canzone* nuova = (Canzone*)malloc(sizeof(Canzone));
            if (!nuova) {
                printf("Errore allocazione memoria.\n");
                return;
            }

            *nuova = *current; // copia struttura
            nuova->next = NULL;

            if (playlist->testa == NULL) {
                playlist->testa = nuova;
                nuova->next = nuova;
            } else {
                Canzone* tail = playlist->testa;
                while (tail->next != playlist->testa)
                    tail = tail->next;

                tail->next = nuova;
                nuova->next = playlist->testa;
            }

            playlist->lunghezza++;
            printf("Canzone aggiunta alla playlist.\n");
            return;
        }
        current = current->next;
    }

    printf("ID non trovato.\n");
}

void stampa_playlist(Lista* playlist) {
    if (playlist->testa == NULL) {
        printf("La playlist è vuota.\n");
        return;
    }

    Canzone* current = playlist->testa;
    do {
        stampa_canzone(current);
        current = current->next;
    } while (current != playlist->testa);
}

void cancella_canzone_playlist(Lista *playlist) {
    if (playlist->testa == NULL) {
        printf("Playlist vuota.\n");
        return;
    }

    int id;
    printf("Inserisci ID della canzone da rimuovere: ");
    scanf("%d", &id);
    getchar();

    Canzone* current = playlist->testa;
    Canzone* prev = NULL;

    do {
        if (current->id == id) {

            if (current == playlist->testa) {
                Canzone* tail = playlist->testa;
                while (tail->next != playlist->testa)
                    tail = tail->next;

                if (playlist->lunghezza == 1) {
                    free(current);
                    playlist->testa = NULL;
                } else {
                    tail->next = current->next;
                    playlist->testa = current->next;
                    free(current);
                }
            } else {
                prev->next = current->next;
                free(current);
            }

            playlist->lunghezza--;
            printf("Canzone rimossa.\n");
            return;
        }

        prev = current;
        current = current->next;

    } while (current != playlist->testa);

    printf("ID non trovato nella playlist.\n");
}