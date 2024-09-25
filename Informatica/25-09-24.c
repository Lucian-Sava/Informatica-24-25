/* Esercizio:
Calcola l'area di un triangolo inserendo la base e l'altezza.*/
#include <stdio.h>
int main()
{
	float base, altezza, area;
	base=0;
	altezza=0;
	printf("Inserire il valore dell base: ",base);
	scanf("%f",&base);
	printf("inserire il valore dell'altezza: ",altezza);
	scanf("%f",&altezza);
	area=(base*altezza)/2;
	printf("l'Area di un triangolo è: %f",area);
	return 0;
}