/*Esercizio:
 Scrivere il doppio di un numero fornito da tastiera*/
#include <stdio.h>
int main()
{	//dischiarare le variaili//
	int N, doppio;
	//inizializiamo le variabili//
	N=0;
	doppio=0;
	printf("Inserisci il primo valore: ");
	scanf("%d",&N);
	//calcolare il doppio del numero// 
	doppio = N*2;
	printf("Il valore doppio è: %d",doppio);
	return 0;
}