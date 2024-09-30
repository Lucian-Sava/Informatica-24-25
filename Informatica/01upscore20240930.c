/* dati due numeri A e B verificare se A è il quadrato di B*/
#include <stdio.h>
int main()
{
    float A, B, quadrato;
    A=0;
    B=0;
    quadrato=0;
    printf("Inserisci il valore di A: ");
    scanf("%f",&A);
    printf("Inserisci il valore di B: ");
    scanf("%f",&B);
    quadrato=B*B;
    printf("Il doppio è: %f", quadrato);
    if(A==quadrato)
    {
        printf("Il valore di A: %f corisponde al quadato %f", A,B);
    }
    else
    {
        printf("Il valore di A: %f non corisponde al quadato %f", A,B");
    } 
    return 0;
}