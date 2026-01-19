#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auto {
    char targa[9];
    char marca[20];
    char modello[20];
    float prezzo_giorno;
    struct Auto* next;
} Auto;

typedef struct Lista {
    Auto* testa;
    int lunghezza;
} Lista;

void strip_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

void set_auto(Auto* nuova_auto){
    printf(" === Inserimento nuova auto ===\n");

    printf("Inserisci targa: ");
    fgets(nuova_auto->targa, sizeof(nuova_auto->targa), stdin);
    strip_newline(nuova_auto->targa);

    printf("Inserisci marca: ");
    fgets(nuova_auto->marca, sizeof(nuova_auto->marca), stdin);
    strip_newline(nuova_auto->marca);

    printf("Inserisci modello: ");
    fgets(nuova_auto->modello, sizeof(nuova_auto->modello), stdin);
    strip_newline(nuova_auto->modello);

    printf("Inserisci prezzo giornaliero: ");
    if (scanf("%f", &nuova_auto->prezzo_giorno) != 1) {
        printf("Prezzo non valido, impostato a 0.0\n");
        nuova_auto->prezzo_giorno = 0.0f;
    }

    // Pulisce il buffer dopo scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int targa_esiste(Lista* lista, const char* targa) {
    Auto* temp = lista->testa;
    while (temp != NULL) {
        if (strcmp(temp->targa, targa) == 0) return 1;
        temp = temp->next;
    }
    return 0;
}

void inserisciAuto(Lista* lista) {
    Auto* nuova = (Auto*)malloc(sizeof(Auto));
    if (nuova == NULL) {
        printf("Errore di allocazione\n");
        exit(1);
    }
    nuova->next = NULL;

    set_auto(nuova);

    if (targa_esiste(lista, nuova->targa)) {
        printf("Errore: Auto con la stessa targa gia' esistente.\n");
        free(nuova);
        return;
    }

    if (lista->testa == NULL) {
        lista->testa = nuova;
    } else {
        Auto* temp = lista->testa;
        while (temp->next != NULL) temp = temp->next;
        temp->next = nuova;
    }
    lista->lunghezza++;
    printf("Auto inserita correttamente.\n");
}

void stampaAuto(Lista* parco_auto){
    Auto* temp = parco_auto->testa;
    int i = 0;
    while (temp != NULL){
        printf("\n=== AUTO %d ===\n", i+1);
        printf("Targa: %s\nMarca: %s\nModello: %s\nPrezzo: %.2f €/giorno\n",
               temp->targa, temp->marca, temp->modello, temp->prezzo_giorno);
        i++;
        temp = temp->next;
    }
    if (i == 0) printf("Nessuna auto presente.\n");
}

void eliminaAuto(Lista* lista) {
    if (lista->testa == NULL) {
        printf("La lista e' vuota. Nessuna auto da eliminare.\n");
        return;
    }

    char targa_da_eliminare[9];
    printf("Inserisci la targa dell'auto da eliminare: ");
    fgets(targa_da_eliminare, sizeof(targa_da_eliminare), stdin);
    strip_newline(targa_da_eliminare);

    Auto* current = lista->testa;
    Auto* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->targa, targa_da_eliminare) == 0) {
            if (previous == NULL) {
                lista->testa = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            lista->lunghezza--;
            printf("Auto con targa %s eliminata con successo.\n", targa_da_eliminare);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Auto con targa %s non trovata.\n", targa_da_eliminare);
}

Lista* crea_lista(){
    Lista *parco_auto = (Lista*)malloc(sizeof(Lista));
    if (parco_auto == NULL) {
        printf("Errore di allocazione lista\n");
        exit(1);
    }
    parco_auto->lunghezza = 0;
    parco_auto->testa = NULL;
    return parco_auto;
}

int main(){
    Lista *parco_auto = crea_lista();
    int scelta;
    int c;
    do {
        printf("\n===== AUTONOLEGGIO 2000 =====\n");
        printf("1. Inserisci nuova auto\n");
        printf("2. Visualizza auto\n");
        printf("3. Elimina auto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        if (scanf("%d", &scelta) != 1) {
            printf("Input non valido.\n");
            while ((c = getchar()) != '\n' && c != EOF) {}
            scelta = -1;
            continue;
        }
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (scelta) {
            case 1:
                inserisciAuto(parco_auto);
                break;
            case 2:
                stampaAuto(parco_auto);
                break;
            case 3:
                eliminaAuto(parco_auto);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 0);

    /* libera memoria residua (opzionale) */
    Auto* cur = parco_auto->testa;
    while (cur) {
        Auto* next = cur->next;
        free(cur);
        cur = next;
    }
    free(parco_auto);

    return 0;
}