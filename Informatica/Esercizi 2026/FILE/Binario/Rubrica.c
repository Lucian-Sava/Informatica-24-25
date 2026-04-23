/* Creare una ribrica che gestisca la memorizzazione dei contatti e ne visualizzi l'elenco 
    Aggiungere o creare il file rubrica
    stampa lista contatti
    elimina un contatto in base al nome
    separa il file rubrica in due file in base al sesso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[30];
    char telefono[15];
    char sesso;

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
    printf("Inserisci il sesso: ");
    scanf("%c", &c.sesso);
    getchar();

    fwrite(&c, sizeof(Contatto), 1, fp);
    fclose(fp);

    printf("Contato aggiunto!\n");
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
        printf("Nome: %s, Telefono %s, Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fp);
    printf("------------------------\n");
}

void EliminazioneContatto()
{
    //Creare un file temporale copiare il file orig., cerco l'elemento, trovo l'elemento lo elimino, e copio il file temp. su file originale.

    FILE *fptemp = fopen("Temp.bin", "wb");
    FILE *fp = fopen("rubrica.bin", "rb");
    char cerca[30];
    Contatto c;
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

    printf("Inserisci il nome: ");
    scanf(" %[^\n]", cerca);
    getchar();

    while(fread(&c, sizeof(Contatto), 1, fp))
    {
        if(strcmp(c.nome, cerca)==0)
        {
            printf("La persona che stavi cercando e stato trovato... l'elemento sarà eliminato");
        }
        else
        {
            fwrite(&c, sizeof(Contatto), 1, fptemp);

        }
    }

    fclose(fp);
    fclose(fptemp);

    fp = fopen("Temp.bin", "rb");
    fptemp = fopen("rubrica.bin", "wb");

    while(fread(&c, sizeof(Contatto), 1, fp))
    {
        fwrite(&c, sizeof(Contatto), 1, fptemp);
    }

    fclose(fp);
    fclose(fptemp);

}

void SeparaSessi()
{
    FILE *fp = fopen("rubrica.bin", "rb");
    FILE *fpM = fopen("Maschio.bin", "ab");
    FILE *fpF = fopen("Femmina.bin", "ab");

    if(fp == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }
    if(fpF == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }
    if(fpM == NULL)
    {
        printf("Errore appertura file\n");
        return;
    }

    Contatto c;

    while(fread(&c, sizeof(Contatto), 1, fp))
    {
        if(c.sesso == 'f' || c.sesso == 'F')
            fwrite(&c, sizeof(Contatto), 1,  fpF);
        else if (c.sesso == 'm' || c.sesso == 'M')
            fwrite(&c, sizeof(Contatto), 1,  fpM);
        
    }

   fclose(fpM);
   fclose(fpF);
   fclose(fp);

    fpM = fopen("Maschio.bin", "rb");
    fpF = fopen("Femmina.bin", "rb");

    printf("\n------Rubrica Femmine-------\n");
    while(fread(&c, sizeof(Contatto), 1, fpF))
    {
        printf("Nome: %s, Telefono %s, Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    printf("\n------Rubrica Maschi-------\n");
    while(fread(&c, sizeof(Contatto), 1, fpM))
    {
        printf("Nome: %s, Telefono %s, Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }

   fclose(fpM);
   fclose(fpF);

}

void eliminazioneRubricaFM()
{
    FILE *fptemp1 = fopen("Temp1.bin", "wb");
    FILE *fptemp2 = fopen("Temp2.bin", "wb");
    FILE *fpM = fopen("Maschio.bin", "rb");
    FILE *fpF = fopen("Femmina.bin", "rb");
    char cerca[30];
    Contatto c;


    int N = 0;

    printf("Quante persone vuoi togliere? :: \n");
    scanf("%d", &N);

    for(int q=0; q < N; q++)
    {
        printf("Inserisci il nome: ");
        scanf(" %[^\n]", cerca);
        getchar();

        while(fread(&c, sizeof(Contatto), 1, fpM) || fread(&c, sizeof(Contatto), 1, fpF))
        {
            if(strcmp(c.nome, cerca)==0)
            {
                printf("La persona che stavi cercando e stato trovato... l'elemento sarà eliminato\n");
            }
            else
            {
                fwrite(&c, sizeof(Contatto), 1, fptemp1);

            }

            if(strcmp(c.nome, cerca)==0)
            {
                printf("La persona che stavi cercando e stato trovato... l'elemento sarà eliminato\n");
            }
            else
            {
                fwrite(&c, sizeof(Contatto), 1, fptemp2);

            }
        }
    }




    fclose(fpM);
    fclose(fpF);
    fclose(fptemp1);
    fclose(fptemp2);

    fpM = fopen("Temp1.bin", "rb");
    fptemp1 = fopen("Maschio.bin", "wb");
    fpF = fopen("Temp2.bin", "rb");
    fptemp2 = fopen("Femmina.bin", "wb");

    /*while(fread(&c, sizeof(Contatto), 1, fpM))
    {
        fwrite(&c, sizeof(Contatto), 1, fptemp1);
    }
    while(fread(&c, sizeof(Contatto), 1, fpF))
    {
        fwrite(&c, sizeof(Contatto), 1, fptemp2);
    }
    */
   
    for(int i=0; i < fread(&c, sizeof(Contatto), 1, fpM); i++)
    {
        fwrite(&c, sizeof(Contatto), 1, fptemp1);
    }
    for(int j=0; j < fread(&c, sizeof(Contatto), 1, fpF); j++)
    {
        fwrite(&c, sizeof(Contatto), 1, fptemp2);
    }

    fclose(fpM);
    fclose(fpF);
    fclose(fptemp1);
    fclose(fptemp2);
}

int main()
{
    int scelta;

    do{
        printf("\n------MENU RUBRICA------\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Eliminazione contatto\n");
        printf("4. Separa contatti in base al sesso\n");
        printf("5. Eliminazione cloni nomi F & M\n");
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
            case 3:
            {
                EliminazioneContatto();
                break;
            }
            case 4:
            {
                SeparaSessi();
                break;
            }
            case 5:
            {
                eliminazioneRubricaFM();
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

