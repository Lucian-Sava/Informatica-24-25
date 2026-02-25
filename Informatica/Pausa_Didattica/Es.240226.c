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

Libro* InserisciLibro(Libro* L, int* n)
{
    //n parametro formale della funzione
    L = (Libro*)realloc(L, ((*n)+1)* sizeof(Libro));
    if(L == NULL)
    {
        printf("Errore di allocazione\n");
        exit(1);
    }

    printf("Inserisci il titolo del libro\n");
    fgets(L[*n].titolo, 20, stdin);
    L[*n].titolo[strcspn (L[*n].titolo, "\n")] = '\0';

    printf("Inserisci l'Autore :");
    fgets(L[*n].autore, 20, stdin);
    L[*n].autore[strcspn (L[*n].autore, "\n")] = '\0';

    printf("Inserisci isbn :");
    scanf("%d", &L[*n].isbn);

    printf("Inserisci le copie totali :");
    scanf("%d", &L[*n].copie_totali);

    L[*n].copie_disponibili = L[*n].copie_totali;   //imposto il num. di copie attualmente disponibili di un libro in modo che sia uguale al num. di copie possedute
    L[*n].data_prestito.giorno = 0;
	L[*n].data_prestito.mese = 0;
	L[*n].data_prestito.anno = 0;
	L[*n].data_restituzione.giorno = 0;
	L[*n].data_restituzione.anno = 0;
	L[*n].data_restituzione.mese = 0;
	(*n)++;

    return L;
}

void stampa(Libro *L, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\n----------------------------");
        printf("\nTitolo : %s\n", L[i].titolo);
        printf("\nAutore: %s\n", L[i].autore);
        printf("\nISBN: %d\n", L[i].isbn);
        printf("\nCopie tot disponibili: %d\n", L[i].copie_totali);
        printf("\nCopie disponibili: %d\n", L[i].copie_disponibili);
        printf("\nData prestito: %d %d %d\n", L[i].data_prestito.giorno, L[i].data_prestito.mese, L[i].data_prestito.anno);
        printf("\n restituzione: %d %d %d\n", L[i].data_restituzione.giorno, L[i].data_restituzione.mese, L[i].data_restituzione.anno);
        printf("\n");
    }
}

void registraLibro(Libro* L, int n)
{
    int isbn, trovato = 0;

    printf("Inserisci l'ISBN del libro :");
    scanf("%d", &isbn);

    for(int i = 0; i < n; i++)
    {
        if(isbn == L[i].isbn)
        {
            if(L[i].copie_disponibili != 0)
            {
                trovato = 1;
                L[i].copie_disponibili -= 1;

                printf("\nInserisci il giorno della data prestito: \n");
                scanf("%d", &L[i].data_prestito.giorno);
                printf("\nInserisci il mese della data prestito: \n");
                scanf("%d", &L[i].data_prestito.mese);
                printf("\nInserisci il anno della data prestito: \n");
                scanf("%d", &L[i].data_prestito.anno);
                printf("\nInserisci il giorno della data di restituzione: \n");
                scanf("%d", &L[i].data_restituzione.giorno);
                printf("\nInserisci il mese della data di restituzione: \n");
                scanf("%d", &L[i].data_restituzione.mese);
                printf("\nInserisci il anno della data di restituzione: \n");
                scanf("%d", &L[i].data_restituzione.anno);
            }
            else
            {
                printf("Copie non disponibili\n");
            }

        }
    }
}

void CercaISBN(Libro* L, int n)
{
    int cerca;
    printf("In serisci l'ISBN : \n");
    scanf("%d", &cerca);
    for(int i = 0; i < n; i++)
    {
        if(cerca == L[i].isbn)
        {
            printf("\nTitolo : %s\n", L[i].titolo);
            printf("\nAutore: %s\n", L[i].autore);
            printf("\nISBN: %d\n", L[i].isbn);
        }
    }
}

void visualizzaLibriPrestito(Libro* L, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(L[i].copie_disponibili < L[i].copie_totali)
        {
            printf("il libro in prestito è: %s\n", L[i].titolo);
        }
    }
}

void visualizzaPrestitoScaduto(Libro* L, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(L[i].data_restituzione.giorno || L[i].data_restituzione.mese || L[i].data_restituzione.anno <= L[i].data_prestito.giorno || L[i].data_prestito.mese || L[i].data_prestito.anno)
        {
            printf("Il libro scaduto e l'autalmente questo: \n");
            printf("\nTitolo: %s\n", L[i].titolo);
            printf("\nAutore: %s\n", L[i].autore);
            printf("\nData restituzione:  %d/%d/%d\n", L[i].data_restituzione.giorno,L[i].data_restituzione.mese,L[i].data_restituzione.anno);
        }
        else
        {
            printf("non ci sono libri scaduti\n");
        }
    }
}

int main()
{
    Libro* biblioteca = NULL;
    int n = 0, scelta;
    char c;

    do{
        printf("-----MENU-----\n");
        printf("1. Inserisci nuovo libro\n");
        printf("2. Visualizza tutti i libri\n");
        printf("3. Registra prestito\n");
        printf("4. Cerca libro per ISBN\n");
        printf("5. Visualizza libri in prestito\n");
        printf("6. Stampare il libro con il prestito scaduto\n");
        printf("0. Esci\n");
        printf("Inserisci la tua Scelta Soldato:");
        scanf("%d", &scelta);
        while((c = getchar()) != '\n') {}

        switch(scelta)
        {
            case 0:
            {
                printf("esci dal programma");
                break;
            }
            case 1:
            {
                biblioteca = InserisciLibro(biblioteca, &n);   // quindi n è una Dimensione
                break;
            }
            case 2:
            {
                stampa(biblioteca, n);
                break;
            }
            case 3:
            {
                registraLibro(biblioteca, n);
                break;
            }
            case 4:
            {
                CercaISBN(biblioteca, n);
                break;
            }
            case 5:
            {
                visualizzaLibriPrestito(biblioteca, n);
                break;
            }
            case 6:
            {
                visualizzaPrestitoScaduto(biblioteca, n);
                break;
            }
            default:
            {
                printf("\nScelta non valida!");
            }
        }
    }while(scelta!=0);


}