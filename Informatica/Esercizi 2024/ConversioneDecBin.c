/*dato un valore convertirlo in valore decimale a binario*/

#include <stdio.h>
#include <math.h>

long converti(int _n);      /*Parametro formale*/

int main()
{
    int n=0;
    long  conversione=0;
    do{
        printf("Inserisci un valore: ");
        scanf("%d", &n);
    }while(n<=0);

    conversione=converti(n);    /*parametro effetivo*/
    printf("%ld\n", conversione);
}

long converti(int _n)
{
    int quoz=_n, resto=0;
    int cont=0;
    int _conv=0;

    while(quoz!=0)
    {
        resto=quoz%2;
        quoz=quoz/2;
        
        _conv=pow(10, cont);
        cont++;
    }


    return _conv;
}