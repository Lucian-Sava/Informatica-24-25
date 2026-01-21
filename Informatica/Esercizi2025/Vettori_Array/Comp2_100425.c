/*
Dato
un vettore numerico di N posizioni al primo elemento dispari stampare
quanti valori diversi da zero si sono incontrati, il numero dispari
incontrato e la sua posizione nel vettore
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 5

void caricaVettore(int vett[], int dim)
{
    int i=0;
    printf("Inserisci un valore: ");

    for(i=0; i<dim; i++)
    {
        scanf("%d\n", &vett[i]);
    }
}
void StampaVettore(int vett[], int dim)
{
    int i=0;
    printf("il vettore e\' composto da: ");
    for(i=0; i<dim; i++)
    {
        printf("%d\t", vett[i]);
    }
}
void contaPosizione(int vett[], int dim)
{
    int i=0, cnt=0;
    while(vett[i]%2 != 1 && i<dim)
    {
        int cnt=0;
        if(vett[i] != 0)
        {
            cnt++;
        }
        i++;
    }
    if(vett[i]%2 == 1)
    {
        printf("iL VALORE DISPARI E' %d NELLA POSIZIONE %d", vett[i], i+1);
        printf("\n sono stati incontrati %d valori",cnt);
    }
}
int main()
{
    int vett[DIM];

    caricaVettore(vett, DIM);
    StampaVettore(vett, DIM);
    contaPosizione(vett, DIM);

}