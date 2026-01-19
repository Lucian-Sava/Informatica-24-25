/*
    Legistare le informazione di alcuni libri :
    1) Titolo
    2) Autore
    3) Anno di pubblicazione
    Usiamo l'Array libri
    4) pubblicare i libri (stampa)
    5) rimuovere un libro
    6) cercare un libro in base al titolo
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char titolo[20];
    char autore[20];
    int anno;
    
}Libro;

void stampaLibri(Libro *libri, int nLibri)
{
    printf("\n---Libri inseriti sono: ---\n");
    for(int i=0; i<nLibri; i++)
    {
        printf("titolo: %s\n", libri[i].titolo);
        printf("autore: %s\n", libri[i].autore);
        printf("anno di pubblicazione : %d\n\n", libri[i].anno);

    }
}

void EliminaLibro(Libro *libri, int *nLibri, char titolo[])
{
    int trova=0;
    for(int i=0; i<*nLibri; i++)
    {
        if(strcmp(libri[i].titolo, titolo)==0)
        {
            trova=1;
            for(int j=i; j<*nLibri-1; j++)
            {
                libri[j]=libri[j+1];
            }
            (*nLibri)--;
            printf("Libro eliminato con successo\n");
            break;
        }
    }
}

void cercaLibro(Libro *libri, int nLibri, char titolo[])
{
    for(int i=0; i<nLibri; i++)
    {
        if(strcmp(libri[i].titolo, titolo)==0)
        {
            printf("Libro trovato:\n");
            printf("titolo: %s\n", libri[i].titolo);
            printf("autore: %s\n", libri[i].autore);
            printf("anno di pubblicazione : %d\n\n", libri[i].anno);
            return;
        }
    }
}

void InserisciLibro(Libro *libri, int nLibri)
{
    for(int i=0; i<nLibri; i++)
    {
        printf("Inserisci il titolo del libro %d: ", i+1);
        scanf("%s", libri[i].titolo);
        printf("Inserisci l'autore delò libro %d: ", i+1);
        scanf("%s", libri[i].autore);
        printf("Inserisci l'anno dipubblicazione del libro %d: ", i+1);
        scanf("%d", &libri[i].anno);
    }
}

int main()
{
    int nLibri;
    Libro *libri;
    int scelta;
    char titolo[20];

    do{
        printf("Inserisci il numero di libri (max10): ");
        scanf("%d", &nLibri);
    }while(nLibri<0 || nLibri>10);

    libri = (Libro*)malloc(nLibri * sizeof(Libro));

    if(libri == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    printf("Sceli la opzione che desideri fare:");
    printf("\n1) Inserisci un libro");
    printf("\n2) Elimina un libro");
    printf("\n3) Stampa i libri");
    printf("\n4) Cerca un libro");
    printf("\n5) Esci dal programma");

    if(scelta == 1)
    {
        InserisciLibro(libri, nLibri);
    }
    else if(scelta == 2)
    {
        printf("Inserisci il titolo del libro da eliminare: ");
        scanf("%s", titolo);
        EliminaLibro(libri, &nLibri, titolo);
    }
    else if(scelta == 3)
    {
        stampaLibri(libri, nLibri);
    }
    else if(scelta == 4)
    {
        printf("Inserisci il titolo del libro da cercare: ");
        scanf("%s", titolo);
        cercaLibro(libri, nLibri, titolo);
    }
    else if(scelta == 5)
    {
        printf("Esci dal programma\n");
        return 0;
    }
    else
    {
        printf("Scelta non valida!\n");
    }
    free(libri);
    return 0;
}