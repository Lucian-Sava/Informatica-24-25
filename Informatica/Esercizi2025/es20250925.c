/*
SCRIVERE UN PROGRAMMA IN C CHE:
1. ALLOCHI DINAMICAMENTE UN ARRAY INIZIALE DI N NUMERI
2. INSERISCI DEI VALORI
3. STAMPA ARRAY
4. CALCOLI LA SOMMA DEGI ELEMENTI MULTIPLI DI 3
5. CREIAMO UN NUOVO ARRAY CONTENENTE SOLO VALORI DISPARI
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, *array_dispari;
    int n, i, somma = 0, cont_dispari = 0;
    int scelta;

    do
    {   printf("------MENU------\n");
        printf("1. Allocazione dell'array\n");
        printf("2. Inserimento dei valori\n");
        printf("3. Stampa dell'array\n");
        printf("4. calcolo della somma multipla di 3\n");
        printf("5. Array contenente valori dispari\n");
        printf("6. Uscita\n");
        printf("Scegli la tua opzione: ");
        scanf("%d", &scelta);
        printf("\n");


        switch (scelta)
        {
            case 1:
            {
                printf("Inserisci un numero per la dimensione dell'array: ");
                scanf("%d", &n);
                array = (int *)malloc(n * sizeof(int));
                if(array == NULL)
                {
                    printf("Errore di allocazione della memoria\n");
                    return 1;
                }

                break;
            }
            
            case 2:
            {
                printf("Inserisci %d numeri:\n", n);
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &array[i]);
                }

                break;
            }

            case 3:
            {
                if( array == NULL)
                {
                    printf("L'array non e' stato ancora allocato.\n");
                    break;
                }

                printf("l'array inserito e':\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");

                break;
            }

            case 4:
            {
                if(array == NULL)
                {
                    printf("L'array non e' stato ancora allocato.\n");
                    break;
                }
                somma = 0;

                for(i = 0; i < n; i++)
                {
                    if(array[i] % 3 == 0)
                       somma += array[i];
                }
                printf("La somma dei numeri multipli di 3 e': --> %d\n", somma);
                break;
            }

            case 5:
            {
                //conatatore di numeri dispari
                for(i = 0; i < n; i++)
                {
                    if(array[i] % 2 != 0)
                        cont_dispari++;
                }

                //allocazione dei nuovi array
                array_dispari = (int *)malloc(cont_dispari * sizeof(int));
                if(array_dispari == NULL)
                {
                    printf("Errore di allocazione della memoria\n");
                    free(array);
                    return 1;
                }

                //inserimento dei valori dispari
                int j = 0;
                for(i = 0; i < n; i++)
                {
                    if(array[i] % 2 != 0)
                    {
                        array_dispari[j] = array[i];
                    }
                }

                //stampa dei nuovi array
                printf("L'array con i valori dispari e': --> ");
                for(i = 0; i < cont_dispari; i++)
                {
                    printf("%d ", array_dispari[i]);
                }
                printf("\n");

                //liberazione della memoria
                free(array);
                free(array_dispari);

                return 0;
                break;
            }

            case 6:
            {
                printf("Chiusura del programma.\n");
                return 0;
                break;
            }
        }
        printf("\n");
    }while(scelta != 6);
}