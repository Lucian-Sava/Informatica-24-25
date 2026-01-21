/*Dati in input 10 numeri interi determinare il valore maggiore e quante volte compare*/
#include <stdio.h>
int main()
{
    int N = 0;
    int Nm = 0;
    int NM = 0;
    int cnt = 0;

    for(int i=0; i!=10; i++)
    {
        printf("Inserisci un Valore: ");
        scanf("%d", &N);
        if(N>NM)
        {

            NM = N;
            Nm = Nm;
            cnt=1;
        }
        else if(N<NM)
        {
            Nm = N;
        }
        else if (N==NM)
        {
            cnt++;
        }
    }
        printf("Il valore maggiore e: %d\n", NM);
        printf("Il valore compare %d\n", cnt++);

    return 0;
}