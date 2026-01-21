/*
    creare una struct Squadra contenente le seguentiinformazioni:
    - nome della squadra 
    - colore della maglia
    - punteggio
    - nome,cognome,titoli allenatore
    caricato un massimo di 10 squadre stampare quelle con punteggio superiore a 100
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
    char nome[20];
    char coloreMaglia[20];
    int punteggio;
    struct allenatore
    {
        char nome[20];
        char cognome[20];
        int titoli;
    }mister;
}Squadra;

void stampa(Squadra *teams, int nSquadre)
{
    printf("\n-----Squadre con punteggio superiore a 100-----\n");
    for(int i=0; i<10; i++)
    {
        if(teams[i].punteggio > 100)
        {
            printf("Nome: %s\n", teams[i].nome);
            printf("Colore Maglia: %s\n", teams[i].coloreMaglia);
            printf("Punteggio: %d\n\n", teams[i].punteggio);
            printf("Allenatore: %s\n\n", teams[i].mister.nome);
            printf("Cognome Allenatore: %s\n\n", teams[i].mister.cognome);
            printf("Numero Titoli Allenatore: %d\n\n", teams[i].mister.titoli);
        }
        else
        {
            printf("La squadra %s non ha un punteggio superiore a 100.\n\n", teams[i].nome);
        }
    }
}

int main()
{
    Squadra *teams;
    int nSquadre;
    
    do{
        printf("Inserisci il numero delle squadre (max 10): ");
        scanf("%d", &nSquadre);

    }while(nSquadre<0 || nSquadre>10);

    teams = (Squadra*)malloc(nSquadre * sizeof(Squadra));
    if(teams == NULL)
    {
        printf("Errore di allocazione memoria\n");
        return 1;
    }
    for(int i=0; i<nSquadre; i++)
    {
        printf("Inserisci il nome della squadra %d: ", i+1);
        scanf("%s", teams[i].nome);
        fflush(stdin);
        printf("Inserisci il colore della maglia della squadra %d: ", i+1);
        scanf("%s", teams[i].coloreMaglia);
        fflush(stdin);
        printf("Inserisci il punteggio della squadra %d: ", i+1);
        scanf("%d", &teams[i].punteggio);
        fflush(stdin);
        printf("Inserisci il nome dell'alenatore della squadra %d: ", i+1);
        scanf("%s", teams[i].mister.nome);
        fflush(stdin);
        printf("Inserisci il cognome dell'allenatore della squadra %d: ", i+1);
        scanf("%s", teams[i].mister.cognome);
        fflush(stdin);
        printf("Inserisci il numero di titoli dell'allenatore della squadra %d: ", i+1);
        scanf("%d", &teams[i].mister.titoli);
        fflush(stdin);
    }

    stampa(teams, nSquadre);
}
