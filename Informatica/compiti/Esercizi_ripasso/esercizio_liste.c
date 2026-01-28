#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dato;
    struct Nodo* next;
}Nodo;

typedef Nodo* Lista;

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
    
    testa = inserisciTesta(testa, 10);  // Inserisco elementi in testa
    testa = inserisciTesta(testa, 20);  // Inserisco un altro elemento2 in testa
    testa = inserisciTesta(testa, 30);  // Inserisco un altro elemento3 in testa
    
    printf("Contenuto della lista:\n");
    stampaLista(testa);
    
    return 0;
}