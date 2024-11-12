/*Esercizio3
DATA UNA COPPIA DI NUMERI INTERI COSTRUIRE UN MENÙ TALE CHE 
PREVEDA:
1) LA SOMMA IN VALORE ASSOLUTO;
2) LA DIFFERENZA TRA IL MAGGIORE E IL MINORE;
3) GENERATO UN VALORE K(INTERO) DETERMINARE CHI DEI VALORI SI 
AVVICINA DI PIÙ;
4) DETERMINARE SE UNO È MULTIPLO DELL’ALTRO*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int numero1;
    int numero2;
    int k;
    int scelta;
    int somma;

    printf("Inserisci il primo valore: ", numero1);
    scanf("%d", &numero1);
    printf("Inserisci il secondo valore: ", numero2);
    scanf("%d", &numero2);

    printf("Scegli l'opzione che vuoi:\n 1) La Somma in valore ASSOLUTO \n 2) La Differenza tra il MAGGIORE e il MINORE \n 3)GENERATO UN VALORE K(INTERO) DETERMINARE CHI DEI VALORI SI 
            AVVICINA DI PIÙ \n 4) DETERMINARE SE UNO È MULTIPLO DELL’ALTRO \n Quale scegli? : ", scelta);
    scanf("%d", &scelta);

    switch (scelta)
    {
        case 1:
            somma = abs(numero1) + abs(numero2)
            break;
        case 2:
            if(numero1 >= numero2)
            {
                printf("Il Numero %d e maggiore e il numero %d e Minore", numero1, numero2);
            }
            else
            {
                printf("Il numero %d e maggiore e il numro %d e Minore", numero2, numero1)
            }
            break;
        case 3:
            rand(time(NULL));
            k= rand()%10+5;
            printf("Il numero che si avvicina di più e %d ", k);
            break;
        case 4:
            if(numero1 !=0 && numero1 % numero2)
                printf("%d è multiplo di %d\n", numero1, numero2);
            else if(numero2 !=0 && numero2 % numero1)
                printf("%d è multiplo di %d\n", numero2, numero2);
            break;
    }

    return 0;
}