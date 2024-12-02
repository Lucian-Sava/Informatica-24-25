/*
    LEGGERE UNA SEQUENZA DI NUMERI, VISUALIZARLA E DETERMINARE QUANTI
    NUMERI SONO STATI INSERITI. TERMINA NON APENA ARRIVA UNO 0
*/
#include <stdio.h>
int main()
{
    int numero;
    int cnt=1;
    printf("Iscerisci un valore: ",numero);
    scanf("%d", &numero);
    cnt++;

    while( numero!=0)
    {
        printf("Il valore inserito è; %d\n", numero);
        printf("Iscerisci un valore: ",numero);
        scanf("%d", &numero);
        cnt++;

    }
    printf("Hai inserito %d valori", cnt);
    return 0;
}