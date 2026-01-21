/* Scrivi un programma che legge in input il valore di tre lati di un triangolo, individua se si tratta di un triangolo equilatero e ne calcola in tal caso l’area e il perimetro*/
#include <stdio.h>
#include <math.h>
int main()
{   //dichiarazione delle variabili
    float lato1, lato2, lato3;
    printf("Inserisci il valore del primo lato: ");
    scanf("%f", &lato1);
    printf("Inserisci il valore del secondo lato: ");
    scanf("%f", &lato2);
    printf("Inserisci il valore del terzo lato: ");
    scanf("%f", &lato3);

    //Verificare se è o non è un triangolo equilatero
    if (lato1 == lato2)
    {
        if(lato2 == lato3)
        {
            printf("è un tringolo equilatreo.\n");
        }
        //Calcolare il perimetro e l'area
    float perimetro = 3 * lato1;
    float area = (sqrt(3) / 4) * lato1 * lato1;
    printf("Perimetro: %.2f\n", perimetro);
    printf("Area: %.2f\n", area);
    }
    else
    {
        printf("Non è un triangolo Equilatero.\n");
    }
    return 0;
}