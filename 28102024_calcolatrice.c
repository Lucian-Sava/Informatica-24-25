/* Creare una sorta di menù( vedi esempio) tramite dei printf per la scelta dell'operazione da compiere tra due valori generati casualmente( eseguendo lì dove c'è bisogno gli opportuni controlli). Comunicare il risultato dell'operazione o la scelta dell'utente di non fare niente e uscire dal programma:ES: "Seleziona l'operazione da eseguire: 
        0.  TERMINA
        1.  SOMMA
        2.  DIFFERENZA
        3.  MOLTIPLICAZIONE
        4.  DIVISIONE  "*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    float n1, n2;
    int scelta;

    printf("------SCEGLI DAL MENU' L'OPERAZIONE DA FARE ---------");
    printf("\n 0. TERMINA");
    printf("\n 1. SOMMA");
    printf("\n 2. DIFFERENZA");
    printf("\n 3.MOLTIPLICAZIONE");
    printf("\n 4.DIVISIONE");

    printf("\n Inserisci l'operazione da compiere: ");
    scanf("%d", &scelta);
    
    srand( time(NULL));
    n1 = rand()%50+1;
    n2 = rand()%50+1;

    switch (scelta)
    {
        case 0:
            printf("\n Il programma terminato");
            break;
        case 1:
            printf("\n La somma vale: %.2f", n1+n2);
            break;
        case 2:
            printf("\n La differenza vale: %.2f", n1-n2);
            break;
        case 3:
            printf("\n La moltiplicazione vale: %.2f", n1*n2);
            break;
        case 4: 
            printf("\n La divisione vale: %.2f", n1/n2);
            break;
        defeult:
            printf("\n Hai inserito una scelta non valida");
            break;
    }
    return 0;
}