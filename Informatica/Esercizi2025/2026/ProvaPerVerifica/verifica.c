/*
Si vuole gestire la raccolta dei punteggi di sportivi, 
ottenuta tramite prove selettive, con valori che oscillano 
dallo 0 ad un massimo di 180 punti.
Lo studente deve gestire le seguenti richieste tramite un menù:
 
1. l'aggiornamento periodico dei nuovi punteggi inseriti; 
   l'elenco ne può contenere al massimo 1000;
   (N.B. non è detto che l'elenco contenga effettivamente tutti e 1000);
   
2. visualizzare a schermo i punteggi inseriti;

3. determinare quanti hanno totalizzato un punteggio superiore ai 150 e 
   quanti un punteggio inferiore a 80;

4. 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array[1000];
	int cnt = 0;
	int scelta;
	int i, j;
	do {
		printf("\n-----MENU-----\n");
		printf("1. Inserimento del nuovo punteggio\n");
		printf("2. Visualizzazione dei punteggi\n");
		printf("3. Determina quanti >150 e quanti <80\n");
		printf("4. Eliminazione punteggi >50\n");
		printf("5. Ordina i punteggi\n");
		printf("6. Esci\n");
		printf("Che opzione scegli? ");
		scanf("%d", &scelta);

		if (scelta == 1) {
			if (cnt >= 1000) {
				printf("Raggiunto il massimo di 1000 punteggi.\n");
			} else {
				int p;
				printf("Inserisci il punteggio: ");
				scanf("%d", &p);
				if (p < 0 || p > 180) {
					printf("Punteggio non valido (0-180).\n");
				} else {
					array[cnt++] = p;
				}
			}
		}

		else if (scelta == 2) {
			if (cnt == 0) {
				printf("Nessun punteggio inserito.\n");
			} else {
				printf("Punteggi inseriti:\n");
				for (i = 0; i < cnt; i++) {
					printf("%d ", array[i]);
				}
				printf("\n");
			}
		}

		else if (scelta == 3) {
			int sopra150 = 0, sotto80 = 0;
			for (i = 0; i < cnt; i++) {
				if (array[i] > 150) sopra150++;
				if (array[i] < 80) sotto80++;
			}
			printf("Punteggi >150: %d\n", sopra150);
			printf("Punteggi <80: %d\n", sotto80);
		}

		else if (scelta == 4) {
			int eliminati = 0;
			for (i = 0; i < cnt; ) {
				if (array[i] > 50) {
					// Elimina spostando a sinistra
					for (j = i; j < cnt - 1; j++) {
						array[j] = array[j+1];
					}
					cnt--;
					eliminati++;
				} else {
					i++;
				}
			}
			printf("Eliminati %d punteggi >50.\n", eliminati);
		}

		else if (scelta == 5) {
			// Bubble sort
			for (i = 0; i < cnt - 1; i++) {
				for (j = 0; j < cnt - i - 1; j++) {
					if (array[j] > array[j+1]) {
						int tmp = array[j];
						array[j] = array[j+1];
						array[j+1] = tmp;
					}
				}
			}
			printf("Punteggi ordinati:\n");
			for (i = 0; i < cnt; i++) {
				printf("%d ", array[i]);
			}
			printf("\n");
		}

		else if (scelta == 6) {
			printf("Chiusura del programma.\n");
		}

		else {
			printf("Scelta non valida.\n");
		}

	} while (scelta != 6);
	return 0;
}