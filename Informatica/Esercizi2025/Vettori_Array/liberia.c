/*
    Sviluppiam la funzione 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "liberia.h" //prototipi delle funzioni
void richiediValori(int vett[], int dim)
{
    int n=0, i=0;
    while(i<dim)
    {
        /*printf("iserisci un valore: ");
        scanf("%d", &n);
        if(n%2==0)
            vett[i]=n;
            i++;*/
        srand(time(NULL));
        vett[i]=rand()%100+1;

    }

}
void caricaVett(int vett[], int dim)
{
    for(int i=0; i<dim; i++)
    {
        printf("inserisci un valore: ");
        scanf("%d", &vett[i]);
    }
}

void stampaVett(int vett[],int DIM, char sep)
{
    for(int i=0; i<DIM; i++)
    {
        printf("%d%c", vett[i], sep);
    }

}

void riempiVettoriCasuale(int vet[], int dim, int minimo, int massimo)
{
    srand(time(NULL));
    for(int i=0; i<dim; i++)
    {
        vet[i]=rand()%(massimo-minimo+1)+minimo;
    }
}
void calcolaMedia(int vet[], int dim)
{
    int somma=0, media=0;
    for(int i=0; i<dim; i++)
    {
        somma+=vet[i];
    }
    media+=somma/dim;
    printf("la media dei valori casuali è: %d", media);
}
void CaricaCasuale(int vett[], int dim, int min, int max){
    srand(time(NULL));
    for(int i=0; i<dim; i++)
    {
        vett[i]=rand()%40+10;
    }
}
void ScambioVettori(int vett[], int vett2[], int dim)
{
    int temp=0;
    for(int i=0; i<dim; i++)
    {
        temp=vett[i];
        vett[i]=vett2[i];
        vett2[i]=temp;
    }
}

void caricaBubble(int vett[], int dim)
{
    int temp=0;

    for(int i=0; i<dim-1; i++)
    {
        for(int j=0; j<dim-1; j++)
        {
            if(vett[j]<vett[j+1]);
            {
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
    }
}

void scambioMinMax(int vett[], int dim)
{
    int min, max, tmp;

    min=vett[0];
    max=vett[0];
    for(int i=1; i<dim; i++)
    {
        //calcolo il valore minimo e la sua posizione all'interno dell'array
        if(vett[i]<min)
        {
            min=vett[i];
            i_min=1;
        }
         //calcolo il valore massimo e la sua posizione all'interno dell'array
        if(vett[i] > max)
        {
           max=vett[i];
           i_max=i;
        }
    }

    //scambio
    vett[i_min]=max;
    vett[i_max]=min;
}