/* Dati 3 numeri stampare il più piccolo, il più grande e la loro media aritmetica *///Lucian Sava George //
#include <stdio.h>
int main()
{
    int A, B, C, Min, Max;
    float Med;
    A=0;
    B=0;
    C=0;
    Min=0;
    Max=0;
    Med=0;
    printf("Inserisci il primo valore: ");
    scanf("%d",&A);
    printf("Inserisci il secondo valore: ");
    scanf("%d",&B);
    printf("Inserisci il terzo valore: ");
    scanf("%d",&C);
    Min = A;
    if (B < Min)
    {
        Min = B;
    }
    if (C < Min)
    {
        Min = C;
    }
    Max = A;
    if (B > Max)
    {
        Max = B;
    }
    if (C > Max)
    {
        Max = C;
    }
    Med=(A+B+C)/3.0;
    printf("Il numero più piccolo è %d\n", Min);
    printf("Il numero più grande è %d\n", Max);
    printf("La media aritmetica è %f.2\n", Med);
    return 0;
}