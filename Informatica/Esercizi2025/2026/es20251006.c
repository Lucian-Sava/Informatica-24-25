/*
Scrvi un programma in C che gestisca un insieme di numeri interi usando un array dinamico.
il programma deve permettere, tramite menù:
1. Aggiungere un numero (espandendo l'array con realloc)
2. visualizzare tutti i numeri
3. cercare un numero specifico
4. Ordinare i numeri in ordine crescente
5. Eliminare un numero scelto
6. uscire dal programma
*/

#include <stdio.h>
#include <stdlib.h>


void aggiunginumero(int **array, int *size);
void visualizzazione(int *array, int size);
void cerca_numeri(int *array, int size);
void ordina_numeri(int *array, int size);
void elimina_numero(int **array, int *size);


void aggiunginumero(int **array, int *size)
{
    int numero;
    printf("Inserisci il numero da aggiungere: ");
    scanf("%d", &numero);

    int *temp = (int *)realloc(*array, (*size + 1) * sizeof(int));
    if(temp == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return;
    }
    *array = temp;
    (*array)[*size] = numero;
    (*size)++;
    printf("Numero aggiunto con successo!\n");
}

void visualizzazione(int *array, int size)
{
    if(size == 0)
    {
        printf("L'array e' vuoto.\n");
        return;
    }
    printf("Numeri nell'array:\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ordina_numeri(int *array, int size)
{
    if(size == 0)
    {
        printf("l'aray e' vuoto.\n");
        return;
    }
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1 ; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1 ];
                array[j + 1] = temp;
            }
        }
    }
    printf("Numeri ordinati con successo!\n");
}

void elimina_numero(int **array, int *size)
{
    if(*size == 0)
    {
        printf("L'array e' vuoto.\n");
        return;
    }
    int numero;
    printf("Inserisci il numero da eliminare: ");
    scanf("%d", &numero);
    int trovato = 0;
    for(int i = 0; i < *size; i++)
    {
        if((*array)[i] == numero)
        {
            trovato = 1;
            for(int j = i; j < *size - 1; j++)
            {
                (*array)[j] = (*array)[j + 1];
            }
            (*size)--;
            int *temp = NULL;
            if(*size > 0)
                temp = (int *)realloc(*array, (*size) * sizeof(int));
            else
                temp = NULL;
            if(temp == NULL && *size > 0)
            {
                printf("Errore di allocazione della memoria\n");
                return;
            }
            *array = temp;
            printf("Numero eliminato con successo!\n");
            break;
        }
    }
    if(!trovato)
        printf("Numero non trovato nell'array.\n");
}
void cerca_numeri(int *array, int size)
{
    if(size == 0)
    {
        printf("L'array e' vuoto.\n");
        return;
    }
    int numero, trovato = 0;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &numero);
    for(int i = 0; i < size; i++)
    {
        if(array[i] == numero)
        {
            printf("Numero trovato in posizione %d.\n", i);
            trovato = 1;
            break;
        }
    }
    if(!trovato)
        printf("Numero non trovato nell'array.\n");
}

int main()
{
    int scelta;
    int *array = NULL;
    int size = 0;

    do{
        printf("MENU'\n");
        printf("1. Aggiungi un numero\n");
        printf("2. visualizza tutti i numeri\n");
        printf("3. cerca un numero specifico\n");
        printf("4. ordina i numeri in modo crescente\n");
        printf("5. Elimina un numero scelto\n");
        printf("6. Esci dal programma\n"),

        printf("Che opzione scegli?\n");
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1:
                aggiunginumero(&array, &size);
                break;
            case 2:
                visualizzazione(array, size);
                break;
            case 3:
                cerca_numeri(array, size);
                break;
            case 4:
                ordina_numeri(array, size);
                break;
            case 5:
                elimina_numero(&array, &size);
                break;
            case 6:
                printf("Uscita dal programma\n");
                free(array);
                break;
        }
    }while(scelta !=6);


}