/* Scrivi un programma che legge in input il valore di due lati di un quadrilatero, individua se si tratta di un quadrato o di un rettangolo e ne calcola il perimetro e l’area.*/
#include <stdio.h>
int main()
{
    float lato1, lato2;
    printf("Inserisci il valore del primo lato: ");
    scanf("%f", &lato1);
    printf("Inserisci il secondo valore del lato: ");
    scanf("%f", &lato2);

    // Verificare se è un quadrato o un rettangolo
    if (lato1 == lato2)
    {
        printf("Si tratta di un quadrato.\n");
    }
    else
    {
        printf("Si tratta di un rettangolo.\n");
    }
    
    //calcolo del perimetro e dell'area
    float perimetro = 2 * (lato1+lato2);
    float area = lato1 * lato2;

    printf("Perimetro: %.2f\n", perimetro);
    printf("Area: %.2f\n", area);
    return 0;

}