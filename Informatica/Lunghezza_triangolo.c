/* Esercizio2
Il programma legge tre numeri e dice se possono essere le lunghezze dei lati di un triangolo (perché un triangolo possa essere tale la somma di ogni coppia lati deve essere maggiore dell’altro)*/
#include <stdio.h>
int main()
{   //dichiarazione delle variabili
    int lato1, lato2, lato3;

    //lettura dei numeri
    printf("Inserisci i tre numeri dei lati: ");
    scanf("%d %d %d", &lato1, &lato2, &lato3);

     // Verifica se i numeri possono essere i lati di un triangolo
     if(lato1 + lato2 > lato3 && lato1 + lato3 > lato2 && lato2 + lato3 >lato1)
     {
        printf("I numeri possono essere le lunghezze dei lati di un triangolo \n");
     }
     else
     {
        printf("I numeri NON possono essere le lunghezze dei lati di un triangolo \n");
     }
     return 0;

}