/*MENU'
	1) CREARE ARRAY
	2) STAMPARE ARRAY
	3) DATO UN ARRAY CALCOLARE QUANTI VALORI PARI E QUANTI VALORI DISPARI; 
    4) DATO UN ARRAY ESEGUIRE LA MEDIA DEI SUOI VALORI;
    5) DATO UN ARRAY CALCOLARE LA SOMMA DI TUTTI I VALORI POSITIVI E DI TUTTI I VALORI NEGATIVI;
    6) DATO UN ARRAY SOSTITUIRE TUTTI GLI 0 CON IL VALORE MINIMO;
    PREMERE 0 PER TERMINARE
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 5

void caricaVettore(int vett[], int dim){
	int i;
    for(i=0; i<dim; i++){
        vett[i] = rand()%101;//carichiamolo con valori da 0 a 100
    }
}

void stampaVettore(int vett[], int dim){
	int i;
    for(i=0; i<dim; i++){
        printf("%d ", vett[i]);
    }
}

void contaPariDispari(int vett[], int dim, int *p, int *d){
	int i;
	for(i=0; i<dim; i++){
        if(vett[i]%2==0)
        	*p= *p + 1;
        else
        	*d= *d + 1;
    }
}

float calcolaMedia(int vett[], int dim){
	float media=0;
	int i;
	
	for(i=0; i<dim; i++){
		media+= vett[i];
	}
	return media;
}

void sommaPosNeg(int vett[], int dim, int *p, int *n){
	int i;
	
	for(i=0; i<dim; i++){
		if (vett[i]<0)
			*p = *p + vett[i];
		else
			*n = *n + vett[i];
	}
}

void sostituisci(int vett[], int dim){
	int i, min;
	//calcoliamo prima il valore minimo
	min=vett[0];
	for(i=1; i<dim; i++){
		if(vett[i]<min)
			min=vett[i];	
	}
	//adesso passiamo a sostituire tutti gli eventuali 0 con il valore minimo
	for(i=0; i<dim; i++){
		if(vett[i] == 0)
			vett[i] = min;		
	}
}

int main(){
	int vett[DIM]={0}, *p=0, *d=0, *n=0, scelta=0, i;
	float media=0;
	srand(time(NULL));
	
	do{
		//costruisco un menu che contenga tutti i punti degli esercizi che vi ho assegnato
		printf("\n--------------- Menu\' -------------- \n");
		printf("Esegui una scelta: \n");
		printf("1) CREARE ARRAY \n");
		printf("2) STAMPARE ARRAY \n");
		printf("3) DATO UN ARRAY CALCOLARE QUANTI VALORI PARI E QUANTI VALORI DISPARI;\n");
		printf("4) DATO UN ARRAY ESEGUIRE LA MEDIA DEI SUOI VALORI;\n");
		printf("5) DATO UN ARRAY CALCOLARE LA SOMMA DI TUTTI I VALORI POSITIVI E DI TUTTI I VALORI NEGATIVI;\n");
		printf("6) DATO UN ARRAY SOSTITUIRE TUTTI GLI 0 CON IL VALORE MINIMO INSERENDO ANCHE I VALORI NEGATIVI;\n");
		printf("PREMERE 0 PER TERMINARE\n");
		scanf("%d", &scelta);
		switch (scelta){
			
			case 1:
				caricaVettore(vett,DIM);
				break;
			
			case 2:
				stampaVettore(vett,DIM);
				break;
			
			case 3:
				p=0; d=0;
				contaPariDispari(vett,DIM,&p,&d);
				printf("\nI valori dispari sono %d mentre i pari sono %d", d, p);
				break;
			
			case 4:
				media = calcolaMedia(vett,DIM)/DIM;
				printf("\nLa media calcolata vale %.2f  ", media);
				break;
			case 5:
				p=0;n=0;
				//carichiamo e stampiamo nuovamente il vettore manualmente inserendo anche valori negativi
				printf("\nInserisci nuovi valori nell'array anche negativi: \n");
				for(i=0; i<DIM; i++){
					scanf("%d",&vett[i]);
				}
				sommaPosNeg(vett,DIM,&p,&n);
				printf("\nLa somma dei positivi vale %d e quelli dei negativi vale %d ", p, n);
				break;
			case 6:
				//creiamo un array inserendo volutamente degli 0
				printf("\nInserisci nuovi valori nell'array almeno uno 0 e anche negativi: \n");
				for(i=0; i<DIM; i++){
					scanf("%d",&vett[i]);
				}
				sostituisci(vett,DIM);
				stampaVettore(vett,DIM);
			 	break;
			default:
				printf("--------- FINE PROGRAMMA ---------- ");
				break;
		}	
		
		
			
			
	}while(scelta!=0);
	
}