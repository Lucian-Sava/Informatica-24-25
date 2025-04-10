/*Calcolare il fattoriale di un numero
    ES: 7!= 1*2*3*4*5*6*7 */

#include <stdio.h>
void fattoriale(int _f, long *_n);
int main()
{
    int N=0;
    long n=1;

    do{
        printf("Inserisci un numero: ");
        scanf("%d", &N);
    }while(N<=0);

    fattoriale(N, &n);
    printf("il fattoriale è %d è %ld", N, n);
}

void fattoriale(int _f, long *_n)
{

   for(int i=1; i<=_f; i++)
   {
        *_n*=i;
   }

}