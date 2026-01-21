/* datti N numeri , sommarli 4 a 4 TErmina non appena si introduce uno 0*/
#include <stdio.h>
int main()
{
    int num1, num2, num3, num4;
    int somma = 0;
    int cnt=0;

    while(cnt<=0)
    {
        do{
            printf("Inserisci un valore: ");
            scanf("%d", &num1);
            cnt++;
        }while(num1!=0);
        do{
            printf("Inserisci un valore: ");
            scanf("%d", &num2);
            cnt++;
        }while(num2!=0);
        do{
            printf("Inserisci un valore: ");
            scanf("%d", &num3);
            cnt++;
        }while(num3!=0);
        do{
            printf("Inserisci un valore: ");
            scanf("%d", &num4);
            cnt++;
        }while(num4!=0);

        somma = num1 + num2 + num3 +num4;
    }
return 0;




}