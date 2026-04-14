/* Creare una ribrica che gestisca la memorizzazione dei contatti e ne visualizzi l'elenco */

#include <stdio.h>

typedef struct
{
    char nome[30];
    char telefono[15];

}Contatto;

void aggiuntacontatto()
{
    FILE *fp = fopen("rubrica.bin", "ab");
    if(fp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }

    Contatto c;
    printf("Inserisci il nome: ");
    scanf("%[^\n]", c.nome);
    getchar();
    printf("Inserisci il numero di telefono: ");
    scanf("%[^\n]", c.telefono);
    getchar();

    fwrite(&c, sizeof(Contatto), 1, fp);
    fclose(fp);
}

void StampaContatti()
{
    FILE *fp = fopen("rubrica.bin", "rb");
    if(fp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }

    Contatto c;

    printf("\n-------RUBRICA-------\n");
    while(fread(&c, sizeof(Contatto), 1, fp) == 1 )
    {
        printf("Nome: %s, Telefono %s\n", c.nome, c.telefono);
    }
    fclose(fp);
}

int main()
{
    int scelta;

    do{
        printf("------MENU RUBRICA------\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("0. Esci\n");
        printf("Scegli la tua scelta : ");
        scanf("%d", &scelta);
        getchar();
        switch(scelta)
        {
            case 1:
            {
                aggiuntacontatto();
                break;
            }
            case 2:
            {
                StampaContatti();
                break;
            }
            case 0:
            {
                printf("Uscita dal pèrogramma...");
                break;
            }
            default:
            {
                printf("Scelta non valida\n");
                break;
            }
        }
    }while (scelta != 0);

    
}

