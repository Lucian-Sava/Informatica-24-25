/* Creare un Array dinamico chiedendo all'utenete la sua dimensione il programma deve prevedere le seguenti funzioni:
1. Crea l'array
2. Inserisce gli elementi nell'array
3. Stampa gli elementi dell'array
4. uscire dal programma
*/
#include <stdio.h>
#include <stdlib.h>
int* creavettore(int _n)
{
    int *_vettore = NULL;
    _vettore = (int *)malloc(_n * sizeof(int));
    if(_vettore == NULL)
    {
        printf("Errore di allocazione!\n");
        return _vettore;
    }
}

int* inseriscielementi(int *_vettore, int _n)
{
    int i;
    for(i = 0; i <_n; i++)
    {
        printf("Inserisci l'elemento: ");
        scanf("%d", &_vettore[i]);
    }
    return _vettore;
}

void stampaelementi(int *_vettore, int _n)
{
    printf("hai inserito i seguenti elementi: \n");
    for(int i = 0; i<_n; i++)
    {
        printf("%d ", _vettore[i]);
    }
}

int main()
{
    int *vettore = NULL ; // puntatore al vettore
    int n;

    do
    {
        printf("Quanti elementi vuoi inserire? ");
        scanf("%d", &n);
    }while(n <= 0);

    vettore = creavettore(n); // crea il vettore
    vettore = inseriscielementi(vettore, n); // inserisce gli elementi
    stampaelementi(vettore, n); // stampa gli elementi
    
    free(vettore); // libera la memoria
    return 0;
}