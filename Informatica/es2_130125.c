/*scrivi un programma che esegue il calcolo del fattoriale di un numero num inserito*/
#include <stdio.h>
int main()
{
    int num, fatoriale=1;

    printf("inserisci un numero: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++)
    {
        fatoriale *= i;
    }

    printf("il calcolo fattoriale di %d e %d", num, fatoriale);

    return 0;
}