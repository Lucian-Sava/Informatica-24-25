/* Esercizio1
Il programma letti tre numeri, determini se possono essere considerati in progressione aritmetica; una progressione aritmetica è una serie di numeri in cui la differenza tra due numeri successivi è costante. */
#include <stdio.h>
int main()
{   //dichiarazione delle variabili
    int Num1, Num2, Num3;

    //lettura dei numeri
    printf("Inserisci il primo numero: ");
    scanf("%d", &Num1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &Num2);
    printf("Inserisci il terzo numero: ");
    scanf("%d", &Num3);

    //Calcolo della differenza
    int diff1 = Num2 - Num1;
    int diff2 = Num3 - Num2;

    // Verifica se le differenze sono uguali
    if (diff1 == diff2) 
    {
        printf("I numeri sono in progressione aritmetica.\n");
    } 
    else 
    {
        printf("I numeri non sono in progressione aritmetica.\n");
    }
    
    return 0;
}