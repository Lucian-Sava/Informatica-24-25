/*DATO UN NUMERO N CALCOLARE IL SUO QUADRATO SOMMANDO I PRIMI N NUMERI DISPARI
    ES: N=7 7^2=49

*/
#include <stdio.h>
int main()
{
    int N;
    int somma=1;

    do{
        printf("inserisci un valore: ");
        scanf("%d", &N);
    }while(N<=0);

    while(somma<N*N)
    {
        somma+=2;

    }
    printf("il quadrato di N è: %d ^ %d = %d\n",N, N, somma);

    return 0;
}