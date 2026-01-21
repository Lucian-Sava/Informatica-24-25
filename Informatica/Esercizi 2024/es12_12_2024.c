/*dati N numeri in input (con n chiesto all'utente strettamente maggiore di 5 ), calcolare la somma dei numeri negativi e dei numeri positivi*/
#include <stdio.h>
int main()
{
    int N = 0;
    int N1 = 0;
    int sommaN = 0;
    int sommaP = 0;
    
    while(N<=5)
    {
        printf("Inserisci un valore: \n");
        scanf("%d", &N);
    }

    for(int i=0; i < N; i++)
    {
        printf("insersci un valore: ");
        scanf("%d", &N1);

        if(N>=0)
        {
            sommaP = sommaP + N1;
        }
        else if(N<0)
        {
            sommaN = sommaN + N1;
        }
    }
    printf("I risultato positvo e: %d\n", sommaP);
    printf("Il risultato negativo e: %d\n", sommaN);
    return 0;
}