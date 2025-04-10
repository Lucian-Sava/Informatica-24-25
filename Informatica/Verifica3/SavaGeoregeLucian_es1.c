/*CALCOLARE QUANTI E QUALI NUMERI PRIMI SONO PRESENTI IN UN AMPIO
INTERVALLO DI VALORI.
DEFINIZIONE DI NUMERO PRIMO: UN NUMERO SI DICE PRIMO SE È DIVISIBILE SOLO
PER 1 E PER SE STESSO.*/
#include <stdio.h>
int main()
{
    int Np, cnt=0, cal=0;

    do{
        printf("Inserisci un numero: ");
        scanf("%d", &Np);
    }while(Np % 1);

    for(int i=1; i<=Np; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cal = Np + Np;
            cnt++;
        }
        printf("I numeri primi sono : %d\n", cnt);
    }
    printf("i numeri presenti in un ampio intervallo di valori e %d", cal);

    return 0;
}