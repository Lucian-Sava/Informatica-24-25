/*Supponete
che la parità di scambio tra Euro e Dollaro sia la seguente: 1 € =
1,23 $. Il programma deve chiedere all'utente se intende cambiare:     
- Dollari in Euro;
- Euro in Dollari.
Data
una somma di denaro calcolare il controvalore. */
#include <stdio.h> //introddure la liberira

    void ConvertireDollariinEuro(float Dollari) //void indica che la funziona non restituisce al valore come ConvertireDollariinEuro
    {
        float Euro = Dollari / 1.23; //assegnazione della variabile Euro che uguale a Dollari dividendo per 1.23 = quanto e il dollaro
        printf("%.2f $ = %.2f €\n", Euro, Dollari); //Stampa del risultato di Euro e Del Dollaro 
    }
    void ConvertireEuroindollari(float Euro) //dichiarazione della variabile Euro
    {
        float Dollari = Euro * 1.23; // assegnazione della variabile dollari che uguale a Euro moltiplicato per 1.23 = quanto e il dollaro
        printf("%.2f € = %.2f $\n", Euro, Dollari); //syampa del risultato di Euro e del Dollaro
    }

    int main()
    {
        int Segli; //assegnazione della variabile Scegli
        float Quantita; //assegnazione della varibile Quantità

        printf("Seleziona l'operazione: \n");
        printf("1. Converti Dollari in Euro\n");
        printf("2. Converti Euro in Dollari\n");
        printf("Scelta: ");
        scanf("%d", &Segli);

        switch (Segli)
        {
            case 1:
                printf("Inserisci l'Importo In Dollari: ");
                scanf("%f", &Quantita);
                ConvertireDollariinEuro(Quantita);
                break;
            case 2:
                printf("Inserisci l'Importo In Euro: ");
                scanf("%f", &Quantita);
                ConvertireEuroindollari(Quantita);
                break;
            default:
                printf("Scelta non valida.\n");
                break;
        }

        return 0;
    }



    /*
        (PER RISPARMIARE TEMPO E PER "NON AGGIUNGERE VOID")
    if (scelta == 1) {
        printf("Inserisci l'importo in Dollari: ");
        scanf("%f", &valore);
        conversione = valore / tassoCambio;
        printf("L'importo in Euro è: %.2f\n", conversione);
    } else if (scelta == 2) {
        printf("Inserisci l'importo in Euro: ");
        scanf("%f", &valore);
        conversione = valore * tassoCambio;
        printf("L'importo in Dollari è: %.2f\n", conversione);
    } else {
        printf("Scelta non valida.\n");
    }
 */