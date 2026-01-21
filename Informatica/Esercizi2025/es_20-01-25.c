/*dati un numero a più cifre stampare le singole cifre*/
#include <stdio.h>
int main()
{
    int N, N1, cnt=0;
    int CS1=0, CS2=0, CS3=0;

    do{
        printf("Inserisci un numero: ");
        scanf("%d", &N);
    }while(N<0);


    for(int i=0; i<N; i++)
    {
        printf("Inserisci un'altro valore: ");
        scanf("%d", &N1);
        
        if(N1>=10)
        {
            CS1= N1 / 10;
            CS2= N1 % 10;
            printf("la cifra singola di %d e %d %d\n", N1, CS1, CS2);
        }
        
        if(N1>=100)
        {
            CS1= N1 / 100;
            CS2= N1 % 10 %10;
            CS3= N1 % 10;
            printf("la cifra singola di %d e %d & %d & %d", N1, CS1, CS2, CS3);
        }


        
    }

    

    return 0;
}