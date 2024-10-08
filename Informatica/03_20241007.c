/* DATO UN NUMRO A PIU' CIFRE ESEGUIRE LA SOMMA DELLE CIFRE E STABILE SE E' DIVISIBILE PER 3*/
#include <stdio.h>
int main()
{
    int Num1=0;
    int cifre=0;
    printf("Inserisci un numero: ");
    scanf("%d", &Num1);
    cifre = Num1 % 10 && Num1 % 100 && Num1 % 1000;
    if(Num1 % 3==0)
    {
        printf("Il numero %d e divisibile per 3", Num1);
    }
    else
    {
        printf("il numero %d non e divisibile per 3", Num1);
    }
    return 0;
}