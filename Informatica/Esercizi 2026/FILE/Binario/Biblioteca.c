/*
CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO;
TUTTO VIENE GESTITO DA FILE BINARI
typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;

void AggiuntaLibro()
{
    FILE *fp = fopen("ListaL.bin", "ab");
    if(fp == NULL)
    {
        printf("Errore appertura file");
        return;
    }

    Libro l;

    printf("\n==========================================\n");
    printf("\n||   ---> AGGIUNTA/CREAZIONE LIBRO <--- ||\n\n");

    printf("--> Inserisci l'autore del libro:   ");
    scanf("%[^\n]", l.autore);
    getchar();

    printf("--> Inserisci il titolo del libro:  ");
    scanf("%[^\n]", l.titolo);
    getchar();

    printf("--> Inserisci l'ISBN:  ");
    scanf(" %19[^\n]", l.ISBN);
    getchar();

    printf("--> Inserisci l'anno del libro:  ");
    scanf("%d", &l.anno);
    printf("\n==========================================\n");

    fwrite(&l, sizeof(Libro), 1, fp);
    fclose(fp);

    printf("|| !?-CONTATTO AGGIUNTO CON SUCCESSO-?! ||");
}

void StampaLista()
{
    FILE *fp = fopen("ListaL.bin", "rb");
    if(fp == NULL)
    {
        printf("Errore di appertura file");
        return;
    }

    Libro l;

    printf("===========================================\n");
    printf("||          ---> LISTA LIBRI <--         ||\n");
    while(fread(&l, sizeof(Libro), 1, fp) == 1)
    {
        printf("===========================================\n");
        printf("|| --> Titolo_Libro: %s\n", l.titolo);
        printf("|| --> Autore_Libro: %s\n", l.autore);
        printf("|| --> ISBN_Libro: %s\n", l.ISBN);
        printf("|| --> Anno_Libro: %d\n", l.anno);
    }

    fclose(fp);
    printf("===========================================\n");
}

void RicercaLibro()
{
    FILE *fp = fopen("ListaL.bin", "rb");
    Libro l;
    int trovato=0;
    char ID_TIT[30];
    
    printf("====================================\n");
    printf("||     --> TROVA LIBRO <--      ||\n");
    printf("====================================\n");
    printf("--> Inserisci il titolo dle libro: ");
    scanf("%[^\n]", ID_TIT);
    getchar();

    if (fp == NULL) {
        printf("Rubrica vuota!\n");
        return;
    }
    while(fread(&l, sizeof(Libro), 1, fp) == 1 && !trovato){
        if(strcmp(ID_TIT, l.titolo) == 0){
            printf("===========================================\n");
            printf("|| --> Autore_Libro: %s\n", l.autore);
            printf("|| --> ISBN_Libro: %s\n", l.ISBN);
            printf("|| --> Anno_Libro: %d\n", l.anno);
            trovato = 1;
        }
    }
    if(!trovato)
        printf("\nLibro non trovato.");

    fclose(fp);
}

void CancellaLibro()
{
    FILE *fptemp = fopen("TempLB.bin", "wb");
    FILE *fp = fopen("ListaL.bin", "rb");
    char cerca[30];
    Libro l;
    if(fp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }
        if(fptemp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }

    printf("Inserisci il titolo: ");
    scanf(" %[^\n]", cerca);
    getchar();

    while(fread(&l, sizeof(Libro), 1, fp))
    {
        if(strcmp(l.titolo, cerca)==0)
        {
            printf("La persona che stavi cercando e stato trovato... l'elemento sarà eliminato");
        }
        else
        {
            fwrite(&l, sizeof(Libro), 1, fptemp);

        }
    }

    getchar();
    fclose(fp);
    fclose(fptemp);

    fp = fopen("TempLB.bin", "rb");
    fptemp = fopen("ListaL.bin", "wb");

    while(fread(&l, sizeof(Libro), 1, fp))
    {
        fwrite(&l, sizeof(Libro), 1, fptemp);
    }

    fclose(fp);
    fclose(fptemp);
}

void ModificaISBN() {
    FILE *fp = fopen("ListaL.bin", "rb+");
    Libro l;
    char T_ISBN[20], N_ISBN[20];
    int trovato = 0;

    if (fp == NULL) {
        printf("Errore apertura file. Lista vuota o file mancante.\n");
        return;
    }

    printf("Inserisci l'ISBN da modificare: ");
    scanf(" %19s", T_ISBN);
    getchar();

    printf("Inserisci il nuovo ISBN: ");
    scanf(" %19s", N_ISBN);
    getchar();

    while(fread(&l, sizeof(Libro), 1, fp) == 1) 
    {
        if(strcmp(T_ISBN, l.ISBN) == 0) 
        {
            strcpy(l.ISBN, N_ISBN);
            fseek(fp, -sizeof(Libro), SEEK_CUR);
            fwrite(&l, sizeof(Libro), 1, fp);
            trovato = 1;
        }
    }
    if(!trovato) printf("ISBN non trovato.\n");
    fclose(fp);
}

void SeparaLibri()
{
    FILE *fp = fopen("ListaL.bin", "rb");
    FILE *fpN = fopen("NuovoLib.bin", "ab");
    FILE *fpV = fopen("VecchioLib.bin", "ab");

    if(fp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }
    if(fpN == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }
    if(fpV == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }

    Libro l;

    while(fread(&l, sizeof(Libro), 1, fp))
    {
        if(l.anno > 2000)
            fwrite(&l, sizeof(Libro), 1,  fpN);
        else if (l.anno < 2000)
            fwrite(&l, sizeof(Libro), 1,  fpV);
        
    }

   fclose(fpN);
   fclose(fpV);
   fclose(fp);

    fpN = fopen("NuovoLib.bin", "rb");
    fpV = fopen("VecchioLib.bin", "rb");

    printf("\n|| ----- LISTA NUOVI LIBRI ----- ||\n");
    while(fread(&l, sizeof(Libro), 1, fpN))
    {
        printf("===========================================\n");
        printf("|| --> Titolo_Libro: %s\n", l.autore);
        printf("|| --> Autore_Libro: %s\n", l.autore);
        printf("|| --> ISBN_Libro: %s\n", l.ISBN);
        printf("|| --> Anno_Libro: %d\n", l.anno);
    }
    printf("\n|| ----- LISTA VECCHI LIBRI ----- ||\n");
    while(fread(&l, sizeof(Libro), 1, fpV))
    {
        printf("===========================================\n");
        printf("|| --> Titolo_Libro: %s\n", l.autore);
        printf("|| --> Autore_Libro: %s\n", l.autore);
        printf("|| --> ISBN_Libro: %s\n", l.ISBN);
        printf("|| --> Anno_Libro: %d\n", l.anno);
    }

   fclose(fpN);
   fclose(fpV);
}

int main()
{
    int scelta;

    do{
        printf("\n==========================================\n");
        printf("\n||   ---> GESTIONE LIBRERIA <---        ||\n");
        printf("||  1. Aggiunta della lista del libro   ||\n");
        printf("||  2. Visualizza lista libri           ||\n");
        printf("||  3. Ricerca del libro                ||\n");
        printf("||  4. Cancellazione di un Libro        ||\n");
        printf("||  5. Modifica L'isbn                  ||\n");
        printf("||  6. Separa Lista dei libri           ||\n");
        printf("||  0. Esci                             ||\n");
        printf("\n==========================================\n");
        printf("--> Inserisci la tua Scelta : ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta)
        {
            case 1:
            {
                AggiuntaLibro();
                break;
            }
            case 2:
            {
                StampaLista();
                break;
            }
            case 3:
            {
                RicercaLibro();
                break;
            }
            case 4:
            {
                CancellaLibro();
                break;
            }
            case 5:
            {
                ModificaISBN();
                break;
            }
            case 6:
            {
                SeparaLibri();
                break;
            }
            case 0:
            {
                printf("||--> Uscita dal programma...           ||\n");
                break;
            }
            default:
            {
                printf("||--> Scelta non valida!                ||\n");
                break;
            }
        }

    }while(scelta != 0);
}