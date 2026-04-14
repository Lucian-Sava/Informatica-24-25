/* Creata un astruct prodotto con nome id e prezzo
    scrivere su file binariouna serie di prodotti
    modificare il prezzo di un prodotto dato il suo id
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    float prezzo;
}Prodotto;

void InserisciProdotto(const char *filename)
{
    FILE *fp = fopen(filename, "ab");
    int n;
    if (fp == NULL) 
    {
        printf("Errore apertura file!\n");
        return;
    }

    printf("Quanti prodotti vuoi inserire?\n");
    scanf("%d", &n);

    Prodotto L;

    for(int i = 0; i < n; i++)
    {
        printf("Prodotto: %d\n", i+1);
        printf("ID: ");
        scanf("%d", &L.id);
        getchar();
        printf("NOME: ");
        scanf("%[^\n]", L.nome);
        getchar();
        printf("PREZZO: ");
        scanf("%f", &L.prezzo);
        getchar();

        fwrite(&L, sizeof(Prodotto), 1, fp);
    }
    fclose(fp);
}

void StampaProdotti(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Errore apertura file!\n");
        return;
    }
    Prodotto L;
    printf("-----ELENCO PRODOTTI-----\n");
    while(fread(&L, sizeof(Prodotto),1,fp)==1)
    {
        printf("ID: %d - NOME: %s - Prezzo: %.2f\n", L.id, L.nome, L.prezzo);
    }
}

void CercaProdotto(const char *filename, int _id)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        printf("Errore apertura file!\n");
        return;
    }
    Prodotto L;

    int trovato = 0;
    while(fread(&L, sizeof(Prodotto),1,fp)==1 && !trovato)
    {
        if(L.id==_id)
        {
            trovato = 1;
            printf("\nTrovato!!\n Nome: %s - Prezzo %f", L.nome, L.prezzo);
        }
    }
    if(!trovato)
    {
        printf("\nProdotto non trocvato");
    }
    fclose(fp);
}

void ModificaPrezzo(const char *filename, int _id, int _NuovoPrezzo)
{
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) 
    {
        printf("Errore apertura file!\n");
        return;
    }
    Prodotto L;

    while(fread(&L, sizeof(Prodotto),1,fp)==1)
    {
        if(L.id==_id)
        {
            L.prezzo == _NuovoPrezzo;
            
            fseek(fp, -sizeof(Prodotto), SEEK_CUR); //posizione corrente mi totna indietro di 1
            fwrite(&fp, sizeof(Prodotto), 1, fp);
        }
    }
    fclose(fp);
}

int main()
{
    const char *file = "prodotti.dat";
    int scelta;
    int id;
    float NuovoPrezzo;

    do{
         printf("\n--------Menu Prodotti--------\n");
        printf("1. Aggiungi elenco prodotti\n");
        printf("2. Visualizza elenco prodotti\n");
        printf("3. Modifica prezzo prodotto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta)
        {
        case 1:
        {
            InserisciProdotto(file);
            break;
        }
        case 2:
        {
            StampaProdotti(file);
            break;
        }
        case 3:
        {
            printf("\nInserisci l'ID del prodotto: ");
            scanf("%d", &id);
            getchar();

            CercaProdotto(file, id);

            printf("Inserisci il nuovo prezzo: ");
            scanf("%f", &NuovoPrezzo);
            getchar();

            ModificaPrezzo(file, id, NuovoPrezzo);
            break;
        }
        case 0:
        {
            printf("Uscita dal programma...");
            break;
        }
        default:
        {
            printf("Valore inserito non valido!");
            break;
        }
    }
    }while(scelta =! 0);
}