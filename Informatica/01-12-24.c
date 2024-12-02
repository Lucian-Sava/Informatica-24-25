/*Scrivi un programma che effettua il prodotto tra due numeri utilizzando il metodo delle somme successive dopo aver controllato l’input e accettato solo valori maggiori di 0 */
#include <stdio.h>
int main()
{
    int num1, num2;
    int risultato = 0;

    printf("Inserisci il primo valore: ");
    scanf("%d", &num1);
    printf("Inserisci il seconfo valore: ");
    scanf("%d", &num2);

    if(num1 > 0 && num2 > 0)
    {
        for(int i =0; i < num2; i++)
        {
            risultato += num1;
        }
        printf("Il risultato di %d e %d è: %d\n ", num1, num2, risultato);
    }
    else
    {
        printf("Entrambi i numeri devono essere maggiori di 0!\n");
    }
    return 0;
}