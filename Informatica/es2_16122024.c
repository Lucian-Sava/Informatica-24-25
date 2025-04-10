/* Stampa iprimi n numeri dispari succesivi al numero A 
   Es:  A=5 e B=8
   7, 9, 11, 13, 15, 17, 19, 21
   A = 4 e N=8
   5, 7, 9, 11, 13, 15, 17, 19
   */
  #include <stdio.h>
  int main()
  {
    int A=0; 
    int N=0; 
    int Somma=0;
    printf("Insrisci il valore di A: ");
    scanf("%d", &A);
    printf("Inserisci il valore di N: ");
    scanf("%d", &N);

    for(int i=0; i<A; i++)
    {
        Somma=A+N;
        if(Somma<
        {
            printf("Il valore si N e dispari: %d\n", N);
        }
        else
        {
            printf("Il valore di A e dispari: %d\n", A);
        }

    }
    printf("La somma è : %d", Somma);
    return 0;
  }