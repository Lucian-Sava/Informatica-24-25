/*se un programma che, dati in input n numeri interi e un numero x determini :
- quanti numeri sono maggiori di x;
-quanti numeri sono minori di x;
-quanti numeri sono uguali a x;
*/
#include <stdio.h>
int main()
{
    int n, x;
    int M=0;
    int U=0;
    int m=0;
    int N=0;

    printf("Inserisci un limite: ");
    scanf("%d", &N);


    printf("inserisci un altro numero: ");
    scanf("%d", &x);

    for(int i=1; i<=N; i++)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &n);

            if(x>n)
            {
                M++;
            }
            else if(x=n)
            {
                U++;
            }
            else if(x<n)
            {
                m++;
            }
            printf("%d maggiore \n %d minore \n %d uguale", M, m, U);
    }
    return 0;
}