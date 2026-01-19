/*
classe di studenti:
Cognome, Nome, Classe, Matricola
Per ogni studente dotato di matricola abbiamo le informazioni
riguardando gli esami e il livello raggiunto

1) Ricercare lo tudente con più certificazioni
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char Cognome[20];
    char Nome[20];
    char Classe[3];
    int Matricola; // le matricolle vanno da 1000 a 9999
}Studente;

typedef struct 
{
    int Matricola;
    struct studente
    {
        char corso[20];
        int livello; //compreso tra 1 a 3
    }esame;
}certificazione;

void ricerca_studente_con_piu_certificazioni(Studente studenti[], certificazione ide[], int n_studenti, int n_certificazioni)
{
    int max_certificazioni = 0;
    int studente_max;
    for(int i=0; i<n_studenti; i++)
    {
        int count = 0;
        for(int j=0; j<n_certificazioni; j++)  //scorro le certficazioni
        {
            if(studenti[i].Matricola == ide[j].Matricola) //confronto le certificazioni con la matricola dello studente
            {
                count++;
            }
        }
        if(count > max_certificazioni) //se lo studente corrente ha più certificazioni del massimo aggiornalo
        {
            max_certificazioni = count;
            studente_max = i;
        }
    }
    printf("Lo studente con più certificazioni è %s %s con %d certificazioni.\n", studenti[studente_max].Nome, studenti[studente_max].Cognome, max_certificazioni);
}

int main()
{
    int n_studenti,n_certificazioni;
    int scelta;

    printf("Inserisci la tua scelta:\n1. Inserimento studenti\n2. Inserimento certificazioni\n3. Ricerca studente con più certificazioni\n");
    scanf("%d", &scelta);
    switch(scelta)
    {
        case 1:
        {
            printf("Inserisci il numero di studenti: ");
            scanf("%d", &n_studenti);
            Studente studenti[n_studenti];
            for(int i=0; i<n_studenti; i++)
            {
                printf("Inserisci Cognome: ");
                scanf("%s", studenti[i].Cognome);
                printf("Inserisci Nome: ");
                scanf("%s", studenti[i].Nome);
                printf("Inserisci Classe: ");
                scanf("%s", studenti[i].Classe);
                printf("Inserisci Matricola: ");
                scanf("%d", &studenti[i].Matricola);
            }
            break;
        }
        case 2:
        {
            printf("Inserisci il numero di studenti: ");
            scanf("%d", &n_studenti);
            Studente studenti[n_studenti];
            for(int i=0; i<n_studenti; i++)
            {
                printf("Inserisci Cognome: ");
                scanf("%s", studenti[i].Cognome);
                printf("Inserisci Nome: ");
                scanf("%s", studenti[i].Nome);
                printf("Inserisci Classe: ");
                scanf("%s", studenti[i].Classe);
                printf("Inserisci Matricola: ");
                scanf("%d", &studenti[i].Matricola);
            }
            printf("Inserisci il numero di certificazioni: ");
            scanf("%d", &n_certificazioni);
            certificazione std[n_certificazioni];
            for(int i=0; i<n_certificazioni; i++)
            {
                do
                {
                    printf("Inserisci Matricola dello studente per la certificazione: ");
                    scanf("%d", &std[i].Matricola);
                } while(std[i].Matricola < 1000 || std[i].Matricola > 9999);
                printf("Inserisci Corso: ");
                scanf("%20c", std[i].esame.corso);
                printf("Inserisci Livello: ");
                scanf("%d", &std[i].esame.livello);
            }      
            break;
        }
        case 3:
        {
            ricerca_studente_con_piu_certificazioni(studenti, ide, n_studenti, n_certificazioni);
            break;
        }
    }
    return 0;
}