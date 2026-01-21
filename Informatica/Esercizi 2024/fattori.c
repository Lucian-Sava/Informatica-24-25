/*
Dato un valore stamapare i suoi fattori
ES: 28 = 2*2*7  2, 2, 7
ES: 36 = 2*13   2, 13 
*/
#include <stdio.h>
void stampafattori(n);
int main()
{
    int n;

    do{
        printf("Inserisci un valore: ");
        scanf("%d", &n);
    }while(n<=0);

    stampafattori(n);
}

void stampafattori(n)
{
    printf("I fattori di %d sono: ", n);

    for (int i = 2; i <= n; i++) {
        while (n % i == 0) 
        {
            printf("[%d]", i);
            n /= i;
        }
    }
    printf("\n");
}