/* DATO UN NUMERO A PIU' CIFRE STAMPARE LE CIFRE CHE COMPONGONO IL NUMERO*/
#include <stdio.h>
int main()
{
    int num=0;
    int q, r, s;
    printf("Inserisci un numro: ");
    scanf("%d", &num);
    num = q;
    q= num / 10;
    r = num % 10;
    s = num % 10;
    q= q / 10;
    r = r % 10;
    s = s + r % 10;
    printf("Il risultato0 e:%d ", num);
    return 0;
                      

    
}