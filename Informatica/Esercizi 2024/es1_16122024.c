/*Calcolare lasomma dei primi N numeri naturali
  ES: 5 1+2+3+4+5*/
  #include <stdio.h>
  int main()
  {
    int cnt = 0;
    int Somma = 0;
    int N = 0;
    printf("Inserisci un numero: ");
    scanf("%d", &N);
    for(int i=0; i<=N; i++)
    {
        Somma=Somma+N;
        cnt++;
        if(cnt<N)
        {
            printf("%d + ", cnt);
        }
        else
        {
            printf("%d ", cnt);
        }
    }
    printf("è la somma e %d ", Somma);

    return 0;
  }
