/*
Scrivi un programma in C che: 
1. Che chiede all'utene quanti numeri interi vuole inserire;
3. Allocca dinamicamente un array di quella dimensione con malloc();
4. Chiede all'uente se vuole aumentare la dimensione dell'array;
    - se si, richiede la nuova dimensione e usa realloc() per ridimensionare l'array;
    - permette quindi di inserire i nuovi valori negli spazi aggiuntivi;
5. Infine, stampa tutti gli elementi dell'array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, nuovo;
    int *array;

    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    if(array == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    printf("Vuoi aumentare la dimensione dell'array?\n");
    printf("1. Si\n");
    printf("2. No\n");
    scanf("%d", &nuovo);
    printf("\n");

    if(nuovo == 1 )
    {
        int nuovo_size;
        printf("Inserisci la nuova dimensione dell'array: ");
        scanf("%d", &nuovo_size);
        array = (int *)realloc(array, nuovo_size +1 * sizeof(int));
        if(array == NULL)
        {
            printf("Errore di allocazione della memoria\n");
            return 1;
        }

        printf("Inserisci %d numeri:\n", nuovo_size);
        for(int i = 0 ; i < nuovo_size; i++)
        {
            scanf("%d", &array[i]);
        }
        printf("L'array inserito e':\n");
        for(int i = 0; i < nuovo_size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\n");
        printf("Inserisci %d numeri:\n", n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }

        printf("L'array inserito e':\n");
        for(int i = 0; i < n; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    free(array);
    return 0;
}