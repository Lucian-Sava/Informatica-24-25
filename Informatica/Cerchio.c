/*Dato il raggio calcolare la circonferenza e l'area del cerchio*/

#include <stdio.h>
long calcolatore(int _C, long _A);
int main()
{
    int r;
    long co;
    long a;

    do{
        printf("Inserisci il dato del raggio: ");
        scanf("%d", &r);
    }while(r<=0);

    co=calcolatore(r, a);
    printf("L'area della circonferenza e %ld ed il calcolo della circonferenza e %ld", r, a);


}

long calcolatore(int _C, long _A)
{
    int C;
    int A;
    int r;

    C=2*3,14*r;
    A=3,14*r*r;

    return C;
    return A;
}