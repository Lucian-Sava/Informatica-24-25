/*INSERIRE UNA SERIE DI VALORI FIN QUANDO LA LORO SOMMA NON SUPERA 200,
  CALCOLARE LA MEDIA E IL NUMERO DI VALORI INSERITI*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    float valore1;
    float valore2;
    float media;

    srand(time(NULL));
    valore1= rand()%100+2;
    printf("Il primo valore e: %.2f ", valore1);
    printf("Inserisci il secondo valore. ");
    scanf("%f", &valore2);

    media = (valore1+valore2)/2;
    printf("La media è: %.2f ", media);

    if(media <= 200)
    {
      printf("La media %.2f non ha superato il valore 200", media);
    }
    else
    {
      printf("La media %.2f ha superato il valore 200", media);
    }

}