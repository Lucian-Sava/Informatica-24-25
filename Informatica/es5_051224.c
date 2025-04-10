/*Calcolare il quozziente fra due numeri Applicando il metodo delle sottrazioni successive*/
#include <stdio.h>
int main()
{
    int num1;
    int num2;
    int q;
    int cnt = 0;

    do{
        printf("inserisci un primo numero: ");
        scanf("%d", &num1);
    }while(num1<=0);

    do{
        printf("inserisci un primo numero: ");
        scanf("%d", &num2);
    }while(num2<=0);

    if(num1>num2)
    {
        q=num1;
        while(q>=num2)
        {
            q = q - num2;
            cnt++;
        }
    }
    else if(num1<num2)
    {
        q=num2;
        while(q>=num1)
        {
            q = q - num1;
            cnt++;
        }
    }
    printf("Il risulato delle sottrazioni e: %d\n", cnt);
    printf("il quozziente e: %d\n", q);

    return 0;
}