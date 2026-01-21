/*RICHIESTI DUE NUMERI DA TASTIERA VERIFICA E COMUNICA SE SONO NUMERI
AMICI/AMICALI.
DEFINIZIONE DI NUMERI AMICALI: DUE NUMERI SI DICONO AMICALI SE LA SOMMA
DEI DIVISORI DEL PRIMO NUMERO È UGUALE AL SECONDO NUMERO E VICEVERSA.*/
#include <stdio.h>
int main()
{
    int N1, N2, somma=0;

    printf("Inserisci un numero: ");
    scanf("%d", &N1);

    printf("Inserisci il secondo numero: ");
    scanf("%d", &N2);

    

    for(int i=1; i<=N1 / 2; i++)
    {
        somma += N1
        for(int j=1; j<=i; j++)
        {
            somma= N1 + N2 %2;
        }
        if(N1 % i)
        {
            
            printf("Sono Amicali\n");
        }
        else
        {
            printf("Non sono Amicali\n");
        }
    }

    printf("La somma dei divisori sono: %d ", somma);



}