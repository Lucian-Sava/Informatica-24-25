/*Esercizio1
CONTARE IL NUMERO DI CIFRE DI CUI SI COMPONE UN NUMERO DATO E
COMUNICARE QUANTE VOLTE COMPARE LA CIFRA DI VALORE K CHIESTA
ALL’UTENTE.
N.B.: accettare valori che vanno da 0 a 9999
ES: 3 è composto da 1 cifra e supponendo k=5 allora k compare 0 volte, 56 è composto
da 2 cifre e k compare 1 volta*/

#include <stdio.h>
int main()
{
    int numero=0;
    int k=0;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    if(k = numero / 10)
    {
        printf("La prima cifra che compone il numero e %d ", k);
    }
    return 0;
}