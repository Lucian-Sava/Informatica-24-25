#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* next;
}Nodo;

typedef Nodo* Lista; // Definizione del tipo Lista come puntatore a Nodo   ( Nodo --> struct Nodo )

/*Lista inserisciCoda(Lista testa, int valore)
{
    Nodo *nuovo = (Nodo*) malloc(sizeof(Nodo)); // Creo il nodo
    nuovo->dato = valore; //Assegno il valore 
    nuovo->next = NULL; // Il nuovo nodo sarà l'ultimo, quindi punta a NULL
    if (testa == NULL) return nuovo; // Se la lista è vuota, il nuovo è la testa, che si trova all'inizio, si usa perchè la lista è vuota
    
    Nodo *temp = testa;  //uso un puntatore temporaneo, che si trova all'inizio della lista e va fino alla fine
    while (temp->next != NULL) {// Scorro fino alla fine della lista
        temp = temp->next; // Vai fino all'ultimo
    }
    temp->next = nuovo; // L'ultimo ora punta al nuovo
    return testa; // Ritorno la testa della lista, che si trova adesso all'inizio
}
*/
/*//metodo di cancellazione A
Lista eliminaTesta(Lista testa) {
    if (testa == NULL) return NULL; // Lista già vuota
    
    Nodo *daEliminare = testa;   // Memorizzo il nodo da cancellare
    testa = testa->next;         // Sposto la testa al nodo successivo
    free(daEliminare);           // Libero la memoria del vecchio primo nodo
    return testa;
}
*/

//metodo di cancellazione B

Lista eliminaCoda(Lista testa) {
    if (testa == NULL) return NULL; // Lista vuota
    if (testa->next == NULL) {      // Un solo nodo
        free(testa);                // Libero la memoria
        return NULL;                // La lista ora è vuota
    }

    Nodo *temp = testa;             // Puntatore temporaneo

    // Mi fermo al penultimo nodo
    while (temp->next->next != NULL) {// Scorro fino al penultimo nodo
        temp = temp->next;      // Vai al nodo successivo
    }

    free(temp->next);   // libero l'ultimo nodo
    temp->next = NULL;  // il penultimo diventa l'ultimo

    return testa;       // Ritorno la testa della lista
}



Lista inserisciTesta(Lista testa, int valore) 
{
    Nodo *nuovo = (Nodo*)malloc(sizeof(Nodo));  // Creo il nodo
    nuovo->dato = valore;                       // Assegno il valore
    nuovo->next = testa;                        // Il nuovo nodo punta alla vecchia testa
    return nuovo;                               // La nuova testa è il nuovo nodo
}

void stampaLista(Lista testa) 
{
   	Nodo *temp = testa; // Uso un puntatore temporaneo
    while (temp != NULL) // Scorro la lista
    {
        printf("%d -> ", temp->dato); // Stampo il dato
        temp = temp->next; // Mi sposto al nodo successivo
    }
  	printf("NULL\n"); // Indico la fine della lista
}

int main() {
    Lista testa = NULL; // Lista inizialmente vuota

    //RICORDA: di inserire gli elementi in TESTA uno alla volta, non "LISTA", perchè la funzione restituisce la nuova testa della lista
    
    testa = inserisciTesta(testa, 10);  // Inserisco elementi in testa
    testa = inserisciTesta(testa, 20);  // Inserisco un altro elemento2 in testa
    testa = inserisciTesta(testa, 30);  // Inserisco un altro elemento3 in testa
    
    printf("Contenuto della lista:\n");
    stampaLista(testa);

   /*printf("Inserimento in coda:\n");
   testa = inserisciCoda(testa, 40); // Inserisco elemento in coda
   stampaLista(testa);
    */
   /*printf("Eliminazione della testa:\n");
   testa = eliminaTesta(testa); // Elimino la testa
   stampaLista(testa);
    */
    printf("Eliminazione della coda:\n");
    testa = eliminaCoda(testa); // Elimino la coda
    stampaLista(testa);
    
    return 0;
}