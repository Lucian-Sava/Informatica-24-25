/*
    DAti 10 valori stamparli
*/
#include <stdio.h>
int main()
{
    int num;//10 valori 
    int cnt=0;//variabile contatore inizzializzato a 0

    while(cnt<5)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        cnt++;//cnt+cnt+1;
        printf("\n Il valore inserito è: %d\n", num);

    }
}