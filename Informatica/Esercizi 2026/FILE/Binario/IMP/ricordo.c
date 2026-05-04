/*
    creazione di un file in cui ci sono tutte le funzioni che abbiamo fatto per i file per momerizzare.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct di una persona

typedef struct{
    char nome[20];
    char cognome[20];
    char genere[10];
    int eta;
}Persona;

void AggiuntaPersona()
{
    FILE *pr = fopen("Persona.bin", "ab");
    if(pr == NULL)
    {
        printf("Errore dell'appertura del file");
        return;
    }

    Persona P;

    printf("--> Inserisci il nome della persona: ");
    scanf("%[^\n]", P.nome);
    getchar();
    printf("--> Inserisci il Cognome della persona: ");
    scanf("%[^\n]", P.cognome);
    getchar();
    printf("--> Inserisci il Genere della persona: ");
    scanf("%[^\n]", P.genere);
    getchar();
    printf("--> Inserisci l'età della persona: ");
    scanf("%d", &P.eta);

    fwrite(&P, sizeof(Persona), 1, pr);
    fclose(pr);

    printf("!?-- CONTATTO AGGIUNTO CON SUCCESSO --?!");
}

void VisualizzazionePersona()
{
    FILE *pr = fopen("Persona.bin", "rb");
    if(pr == NULL)
    {
        printf("Errore della lettura del file");
        return;
    }

    Persona P;

    printf("==============================\n");
    printf("||      LISTA PERSONE       ||\n");
    while(fread(&P, sizeof(Persona), 1, pr) == 1)
    {
        printf("==============================\n");
        printf("--> NOME: %s\n", P.nome);
        printf("--> COGNOME: %s\n", P.cognome);
        printf("--> Sesso: %s\n", P.genere);
        printf("--> Età : %d\n", P.eta);
    }

    fclose(pr);
    printf("==============================\n"); 
}

void RicercaPersona()
{
    FILE *pr = fopen("Persona.bin", "rb");
    if(pr == NULL)
    {
        printf("Errore sulla ricerca della persona");
        return;
    }
    Persona P;

    int TR = 0;
    char ID[20];

    printf("====================================\n");
    printf("||     --> RICERCA PERSONA <--      ||\n");
    printf("====================================\n");
    printf("--> Inserisci il nome della persona: ");
    scanf("%[^\n]", ID);
    getchar();

    while(fread(&P, sizeof(Persona), 1, pr) == 1 && !TR)
    {
        if(strcmp(ID, P.nome) == 0)
        {
            TR = 1;
            printf("==============================\n");
            printf("--> COGNOME: %s\n", P.cognome);
            printf("--> Sesso: %s\n", P.genere);
            printf("--> Età : %d", P.eta);
        }
    }
    if(!TR)
    {
        printf("La persona che stai cercando non c'è");
    }

    fclose(pr);
}

void CancellazionePersona()
{
    FILE *prTEMP = fopen("Cancellazione.bin", "wb");
    FILE *pr = fopen("Persona.bin", "rb");

    Persona P;
    char cerca[20];

    if(pr == NULL || prTEMP == NULL)
    {
        printf("Errore sull'apertura del file o sulla sua creazione");
        return;
    }

    printf("--> Inserisci la persona che vuoi cercare: ");
    scanf("%[^\n]", cerca);
    getchar();

    while(fread(&P, sizeof(Persona), 1, pr))
    {
        if(strcmp(P.nome, cerca) == 0)
        {
            printf("-->La persona che stai cercando e statta trovata\n");
            printf("-->Cencellazione della persona...\n");
            printf("-->Eliminazione complettato\n");
        }
        else
        {
            fwrite(&P, sizeof(Persona), 1, prTEMP);
        }
    }

    fclose(pr);
    fclose(prTEMP);

    pr = fopen("Cancellazione.bin", "rb");
    prTEMP = fopen("Persona.bin", "wb");

    while(fread(&P, sizeof(Persona), 1, pr))
    {
        fwrite(&P, sizeof(Persona), 1, prTEMP);
    }

    fclose(pr);
    fclose(prTEMP);
}

void ModificaEta()
{
    FILE *pr = fopen("Persona.bin", "rb+");
    if(pr == NULL)
    {
        printf("Errore sulla modifica del file");
        return;
    }

    Persona P;
    char cerca[20];
    int N_eta;
    int trovato = 0;

    printf("-->Inserisci il nome della persona per modificare l'eta: ");
    scanf("%[^\n]", cerca);
    getchar();

    printf("-->Inserisci la nuova Età della persona: ");
    scanf("%d", &N_eta);

    while(fread(&P, sizeof(Persona), 1, pr) == 1)
    {
        if(strcmp(cerca, P.nome) == 0)
        {
            trovato = 1;
            P.eta = N_eta;
            fseek(pr, -sizeof(Persona), SEEK_CUR);
            fwrite(&P, sizeof(Persona), 1, pr);
        }
    }
    if(!trovato)
    {
        printf("-->La persona che stai cercando non c'è");
    }
    fclose(pr);

}

void SeparazioneSessi()
{
    FILE *pr = fopen("Persona.bin", "rb");
    FILE *prM = fopen("Maschio.bin", "ab");
    FILE *prF = fopen("Femmina.bin", "ab");

    if(pr == NULL || prM == NULL || prF == NULL)
    {
        printf("Errore sulla creazione del file o sulla lettura dle file");
        return;
    }

    Persona P;

    while(fread(&P, sizeof(Persona), 1, pr))
    {
        if (strcmp(P.genere, "Maschio") == 0)
        {
            fwrite(&P, sizeof(Persona), 1, prM);
        }
                if(strcmp(P.genere, "Femmina") == 0)
        {
            fwrite(&P, sizeof(Persona), 1, prF);
        }
    }

    fclose(pr);
    fclose(prM);
    fclose(prF);

    prM = fopen("Maschio.bin", "rb");
    prF = fopen("Femmina.bin", "rb");

    printf("\n||  ----- LISTA MASCHI -----  ||\n");
    while(fread(&P, sizeof(Persona), 1, prM))
    {
        printf("===========================================\n");
        printf("|| --> NOME: %s\n", P.nome);
        printf("|| --> COGNOME: %s\n", P.cognome);
        printf("|| --> ETA': %d\n", P.eta);  
    }
    printf("\n||  ----- LISTA FEMMINE -----  ||\n");
    while(fread(&P, sizeof(Persona), 1, prF))
    {
        printf("===========================================\n");
        printf("|| --> NOME: %s\n", P.nome);
        printf("|| --> COGNOME: %s\n", P.cognome);
        printf("|| --> ETA': %d\n", P.eta);  
    }

    fclose(prM);
    fclose(prF);
}

int main()
{
    int scelta;
    do{
        printf("\n====================================================\n");
        printf("\n||         ----DATI DI UNA PERSONA----              ||\n");
        printf("\n====================================================\n");
        printf("||      1.Aggiunta di una persona                   ||\n");
        printf("||      2.Visualizzazione delle persone             ||\n");
        printf("||      3.Ricerca della persona tramite il nome     ||\n");
        printf("||      4.Cancellazione di una persona              ||\n");
        printf("||      5.Modifica l'eta della persona              ||\n");
        printf("||      6.Separazione Maschio o Fermina             ||\n");
        printf("||      0.Uscita dal programma                      ||\n");
        printf("\n====================================================\n");

        printf("--> Inserisci la tua scelta : ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta)
        {
            case 1:
            {
                AggiuntaPersona();
                break;
            }
            case 2:
            {
                VisualizzazionePersona();
                break;
            }
            case 3:
            {
                RicercaPersona();
                break;
            }
            case 4:
            {
                CancellazionePersona();
                break;
            }
            case 5:
            {
                ModificaEta();
                break;
            }
            case 6:
            {
                SeparazioneSessi();
                break;
            }
            case 0:
            {
                printf("--> UScita dal programma...");
                break;
            }
            default :
            {
                printf("Errore sull'inserimeto della tua scelta");
                break;
            }
        }
    }while(scelta != 0);
}