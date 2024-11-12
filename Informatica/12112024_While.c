/*acrivi un programma che chieda all'utente un numero che sia necessariamente maggiore di 3 e che indica quanti valori della sequenza di fibonacci mostrare.
  Per esempio se l'utente inserisci 6 dovranno essere mostrati 1 1 2 3 5 8. Vedi p.160*/
  #include <stdio.h>
  int main()
  {
    int Num, Conta, fibA, fibB, fibC;

    printf("Inserisci un Numro: ");
    scanf("%d", &Num);

    fibA = 1;
    fibB = 1;
    printf(" %d", fibA);
    printf(" %d", fibB);

    Conta = 3;


    while(Conta < Num)
    {
        fibC = fibA + fibB;
        printf(" %d", fibC);
        Conta++;
        fibA = fibB;
        fibB = fibC;
    }
    printf("Il valore Conta e Maggiore Uguale del valore Num");
    return 0;

  }