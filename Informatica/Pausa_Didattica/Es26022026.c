/*
    Data la struct prodotto:
    -   nome
    -   codice (int)
    -   quantità
    -   prezzo

    Eseguire
    1. Inserire prodotto
    2. Stampare Elenco prodotti
    3. Cercare un prodotto per codice
    4. Calcolare il valore totale del magazzino
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Prodotto
{
    char nome[20];
    int codice;
    int quantità;
    float prezzo;
}Prodotto;

Prodotto* InserisciProdotto(Prodotto* P, int* n)
{
    P = (Prodotto*)realloc(P, ((*n)+1)* sizeof(Prodotto));
    if(P == NULL)
    {
        printf("Errore di allocazione!");
        exit(1);
    }

    printf("Inserisci il nome del prodotto\n");
    fgets(P[*n].nome, 20, stdin);
    P[*n].nome[strcspn (P[*n].nome, "\n")] = '\0';  //Vado ad aggiungere manualmente il /0

    printf("Inserisci il codice del prodotto: \n");
    scanf("%d", &P[*n].codice);

    printf("Inserisci la quantità del prodotto: \n");
    scanf("%d", &P[*n].quantità);

    printf("Inserisci il prezzo del prodotto: \n");
    scanf("%f", &P[*n].prezzo);

    (*n)++;  //FONDAMENTALE !!! Incrementare "n"

    return P;
}

void StampaProdotto(Prodotto *P, int n) 
{
    printf("\n--- Elenco Prodotti (%d) ---\n", n);

    if(n == 0)
    {
        printf("\nIl magazzino e' vuoto!\n");
        return;
    }
    
    for(int i = 0; i < n; i++) 
    {
        printf("Prodotto  :  %d:\n", i + 1);
        printf("  Nome     : %s\n", P[i].nome);
        printf("  Codice   : %d\n", P[i].codice);
        printf("  Quantita : %d\n", P[i].quantità);
        printf("  Prezzo   : %.2f Euro\n", P[i].prezzo);
        printf("---------------------------\n");
    }
}

void CalcoloTOTmazzino(Prodotto *P, int n)
{
    float TOT = 0;
    for(int i = 0; i < n; i++)
    {
        TOT += (P[i].prezzo * P[i].quantità);
    }
    printf("Il valore TOT del magazzino e : %.2f Euro\n", TOT);
}

void Cercacodice(Prodotto* P, int n)
{
    int cerca;
    printf("In serisci il codice : \n");
    scanf("%d", &cerca);
    for(int i = 0; i < n; i++)
    {
        if(cerca == P[i].codice)
        {
            printf("\nNome Prodotto : %s\n", P[i].nome);
            printf("\nPrezzo: %f\n", P[i].prezzo);
            printf("\nCodice: %d\n", P[i].codice);
            printf("\nQuabtità : %d\n", P[i].quantità);
        }
    }
}

int main()
{
    Prodotto* magazzino = NULL;
    int n = 0;
    int scelta;
    char c;

    do{
        printf("-----MENU-----\n");
        printf("1. Inserisci nuovo prodotto\n");
        printf("2. stampare elenco prodotti\n");
        printf("3. cercare un prodotto per codice\n");
        printf("4. Calcolare il valore totale del magazzino\n");
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
                magazzino = InserisciProdotto(magazzino, &n);
                break;
            }
            case 2:
            {
                StampaProdotto(magazzino, n);
                break;
            }
            case 3:
            {
                Cercacodice(magazzino, n);
            }
            case 4:
            {
                CalcoloTOTmazzino(magazzino, n);
                break;
            }
            default:
            {
                printf("\nScelta non valida!");
            }
        }
    }while(scelta!=0);

}