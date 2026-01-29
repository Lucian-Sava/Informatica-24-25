#include <stdio.h>
#include <string.h>

typedef struct { // Definizione della struct Auto
    char marca[30];
    char modello[30];
    float prezzo;
} Auto;

int main() {
    Auto concessionaria[100]; // Array di struct, la struct Auto la definisco concettualmente come una "nuova variabile", che e la concessionaria
    int n, i;
    int Maprezzo;
    int Posizione;
    int trovato = 0;

    // 1. Quante auto inserire?
    printf("Quante auto vuoi inserire? ");
    scanf("%d", &n);

    // 2. Ciclo di Caricamento
    for(i = 0; i < n; i++) 
    {
        printf("\n--- Auto n.%d ---\n", i+1); // i+1 perche l'utente conta da 1
        printf("Marca: ");
        scanf("%s", concessionaria[i].marca); // Niente &        
        printf("Modello: ");
        scanf("%s", concessionaria[i].modello); // Niente &        
        printf("Prezzo: ");
        scanf("%f", &concessionaria[i].prezzo); // Qui serve la &
    }

        //printf("Il cliente Dice il massimo di prezzo che vuoi spendere: ");
        //scanf("%d", &Maprezzo);
    // 3. Esempio di elaborazione: Stampa auto costose (> 10000)
    printf("\n--- AUTO COSTOSE ---\n");
    for(i = 0; i < n; i++) 
   {    
        /*
            METODO 1 : uso il confronto diretto

                // Accesso ai campi con il punto
                if(concessionaria[i].prezzo > 10000) 
                {
                    printf("Auto: %s %s - Euro: %.2f\n", 
                    concessionaria[i].marca, 
                    concessionaria[i].modello, 
                    concessionaria[i].prezzo);
                }
        */

        /*
            METODO 2 : uso il confronto di stringhe
                if(strcmp(concessionaria[i].marca, "Citroen") == 0)
                {
                    printf("Ho trovato una Citroen: %s\n", concessionaria[i].marca);
                    printf("Il modello è: %s\n", concessionaria[i].modello);
                }
        */
        /*
            METODO 3 : uso il confronto di stringhe con minore o amggiore del prezzo
                if(concessionaria[i].prezzo <= Maprezzo) 
                {
                    Maprezzo = concessionaria[i].prezzo; // Aggiorno il valore del prezzo minore
                    Posizione = i; // Aggiorno la posizione dell'auto piu economica
                    printf("L'auto affidabile è: %s %s - Euro: €%.2f\n", 
                    concessionaria[Posizione].marca, 
                    concessionaria[Posizione].modello, 
                    concessionaria[Posizione].prezzo);
                }
        */

        /* 
            METODO 4 : uso flag (trovato)
                    if(strcmp(concessionaria[i].marca, "Fiat") == 0)
                    {
                        printf("Ho trovato una fiat: %s\n", concessionaria[i].modello);
                        trovato = 1;
                    }
                    else if(trovato == 0)
                    {
                        printf("Non ho trovato una fiat in magazzino\n");
                    }
        */
   }return 0;
}