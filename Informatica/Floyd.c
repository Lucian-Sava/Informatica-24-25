/*
SVILUPPARE UN PROGRAMMA IN C CHE SVILUPPI
IL TRIANGOLO DI FLOYD
N=5
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
#include <stdio.h>
void incremento(int *_inc);
int main()
{
    int num=0;

    do{
        printf("Inserisci un valore: ");
        scanf("%d", &num);
    }while(num<0);

    incremento(&num);
    printf("L'incremento e di %d ", num);
}

void incremento(int *_inc)
{
    int R;

    for(int i=1; i<=*_inc; i++)
    {
        for(int j=1; j<i; j++)
        {
            printf("%d", R++);
        }
        printf("\n");
    }
}