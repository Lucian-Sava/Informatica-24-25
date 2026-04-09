/*
Registrare leinformazioni di alcuni libri
con titolo, autore, anno e prezzo.
Determinare il ibro più costoso e il più vecchio.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Libro
{
    char titolo[40];
    char autore[20];
    int anno;
    float prezzo;
};
typedef char* Stringa;
void compatta(Stringa buffer, int lunghezza)
{
    if(lunghezza >0 && buffer[lunghezza-1] == '\n')
    {
        buffer[lunghezza-1] = '\0';
        lunghezza--;
        //sostituisco il carattere di nuova linea con il terminatore di stringa
    }
}

int main()
{
    struct Libro *libri;
    int n=3;
    int datato, i_datato;
    int i_costoso;
    float costo;
    int lun;
    char libro[40];

    //allochiamo i primi3 elementi
    libri =(struct Libro*)malloc(n * sizeof(struct Libro));
    if(libri==NULL)
    {
        printf("Errore allocazione memoria\n");
        return 1;
    }

    //inserimento dati
    strcpy(libri[0].titolo, "L'amore mio noin muore");
    strcpy(libri[0].autore, "Roberto Saviano");
    libri[0].anno=2025;
    libri[0].prezzo=19.50;

    strcpy(libri[1].titolo, "Maledetti di Dio");
    strcpy(libri[1].autore, "Sven assel");
    libri[1].anno=1953;
    libri[1].prezzo=13;

    strcpy(libri[2].titolo, "Il diritto di contare");
    strcpy(libri[2].autore, "Margot Lee Shetterly");
    libri[2].anno=2016;
    libri[2].prezzo=25.99;

    //visualizzazione dati
    printf("===Lista Libri===\n");
    for(int i=0; i<n; i++)
    {
        printf("Libro %d:\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n", libri[i].prezzo);
        printf("\n");
    }
    n+=1; //aumentiamo il numero di libri

    libri=(struct Libro*)realloc(libri, n *sizeof(struct Libro));
    if(libri == NULL)
    {
        printf("Errore allocazione memoria\n");
        return 1;
    }

    //inserimento del dato del nuovo libro
    strcpy(libri[3].titolo, "Il codice da Vinci");
    strcpy(libri[3].autore, "Dan Brown");
    libri[3].anno=2003;
    libri[3].prezzo=9.99;

    //visualizzazione dati
    printf("===Lista Libri===\n");
    for(int i=0; i<n; i++)
    {
        printf("Libro %d:\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n", libri[i].prezzo);
        printf("\n");
    }


    //calcoliamo i llibro più datato
    datato=libri[0].anno;
    i_datato=0;
    for(int i=1; i<n; i++)
    {
        if(libri[i].anno < datato)
        {
            datato = libri[i].anno;
            i_datato = i;
        }
    }

    printf("Il libro più datato è : %s di %s, anno %d\n", libri[i_datato].titolo, libri[i_datato].autore, libri[i_datato].anno);
    
    //calcoliamo il libro più costoso

    costo = libri[0].prezzo;
    i_costoso=0;
    for(int i=1; i<n; i++)
    {
        if(libri[i].prezzo > costo) // prezzo più grande
        {
            costo = libri[i].prezzo;
            i_costoso = i;
        }
    }

    printf("Il libro più costoso è : %s di %s, prezzo %.2f\n€", libri[i_costoso].titolo, libri[i_costoso].autore, libri[i_costoso].prezzo);

    //elimina un libro
    printf("Inserisci il titolo del libro da eliminare: ");
    fgets(libro, 50, stdin);
    lun = strlen(libro);
    compatta(libro, lun);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(libri[i].titolo, libro)))
        {
            for(int j=i; j<n-1; j++)
            {
                strcpy(libri[j].titolo, libri[j+1].titolo);
                strcpy(libri[j].autore, libri[j+1].autore);
                libri[j].anno = libri[j+1].anno;
                libri[j].prezzo = libri[j+1].prezzo;
            }
            n-=1;
        }
    }

    //reallochiamo il nuovo array
    libri = (struct Libro*)realloc(libri, n * sizeof(struct Libro));
    if(libri == NULL)
    {
        printf("Errore allocazione memoria\n");
        return 1;
    }

    //visualizzazione dati
    printf("===Lista Libri===\n");
    for(int i=0; i<n; i++)
    {
        printf("Libro %d:\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n", libri[i].prezzo);
        printf("\n");
    }
    free(libri);
    return 0;
}