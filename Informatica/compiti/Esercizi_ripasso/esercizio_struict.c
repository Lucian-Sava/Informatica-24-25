#include <stdio.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modello[30];
    float prezzo;
} Auto;

int main() {
    Auto concessionaria[100]; // Array di struct, la struct Auto la definisco concettualmente come una "nuova variabile", che e la concessionaria
    int n, i;

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
    // 3. Esempio di elaborazione: Stampa auto costose (> 10000)
    printf("\n--- AUTO COSTOSE ---\n");
    for(i = 0; i < n; i++) 
   {
        // Accesso ai campi con il punto
        if(concessionaria[i].prezzo > 10000) 
        {
            printf("Auto: %s %s - Euro: %.2f\n", 
            concessionaria[i].marca, 
            concessionaria[i].modello, 
            concessionaria[i].prezzo);
        }
   }return 0;
}