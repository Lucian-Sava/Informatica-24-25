/* stabilire se dati due numeri Ae B controllare se A è minore, uguale, maggiore di B*/
#include <stdio.h>
int main()
{
    int a=0;
    int b=0;
    printf("inserisci il primo valore: ");
    scanf("%d", &a);
    printf("Inserisci il secondo valore: ");
    scanf("%d",&b);
    if (a==b)
    {
        printf("I due valori sono uguali");
    }
    else
    {
        if (a>b)
        {
            printf("a e maggiore di b %d", a,b);
        else
            printf("a è minore di b %d", a,b);
        }
    }
    return 0;
}