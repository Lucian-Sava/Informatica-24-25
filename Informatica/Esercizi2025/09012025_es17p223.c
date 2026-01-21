/*Numero perfetto, quando la somma dei suoi sommitori esculo se stesso è il numero stesso, Es p.223 n.17
Scrivi un programma che ricerca i primi tre numeri pefetti e li visualizza sullo scherm
Es: n=6 div=1,2,3 somma=1+2+3=6

6 - 28 - 496
*/

#include <stdio.h>
int main()
{
    int n;
    int somma=0;
    int c=0;
    for(int i=1; i<500; i++)
    {
        for(int j=1; j<=i/2; j++)
        {
          if(i%j==0)
            somma+=j;
        

        }
        if(somma==i)
        {
            printf("\nil numero %d è un numero perfetto.", i);
        }
        somma=0;
    }
    return 0;
}