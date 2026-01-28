# 1. Cos'è una Lista Concatenata?
A differenza di un array (che ha una dimensione fissa e occupa celle di memoria vicine), una lista è una sequenza di elementi chiamati Nodi, sparsi nella memoria e collegati tra loro tramite dei puntatori.
Ogni Nodo è composto da due parti:
1. Dato: l'informazione che vogliamo salvare (es. un numero intero).
2. Puntatore (Next): l'indirizzo di memoria del nodo successivo.

# 2. Definizione del Nodo (Struct)
Per creare una lista, dobbiamo definire una struct che contenga un puntatore a se stessa (auto-referenziazione).

Esempio:
```c
#include <stdio.h>
#include <stdlib.h> // Necessaria per malloc() e free()

typedef struct nodo{
    int dato;               // Il valore contenuto
    struct nodo *next;      // Puntatore al prossimo nodo
}Nodo;

typedef Nodo* Lista;        // Definiamo 'Lista' come un puntatore a un Nodo
```

# 3. Gestione Dinamica: malloc e NULL
Le liste usano la memoria dinamica.
-) malloc(sizeof(Nodo)): serve per creare un nuovo nodo nello spazio di memoria durante l'esecuzione.
-) NULL: è un valore speciale che indica la fine della lista (l'ultimo nodo punta a NULL).

# 4. Operazioni Principali (Codice da Sapere)
## A. Inserimento in TESTA (il più semplice)
Aggiunge un elemento all'inizio della lista.

Esempio: 
```c
Lista inserisciTesta(Lista testa, int valore) 
{
    Nodo *nuovo = (Nodo*) malloc(sizeof(Nodo)); // Creo il nodo
    nuovo->dato = valore;                       // Assegno il valore
    nuovo->next = testa;                        // Il nuovo nodo punta alla vecchia testa
    return nuovo;                               // La nuova testa è il nuovo nodo
}
```
Cosa fa il codice :
    1. Allocare dinamicamente un nuovo nodo;
    2. Inserisce il valore richiesto;
    3. Fa puntare il nuovo nodo alla testa attuale;
    4. Restituisce il nuovo nodo, che diventa la nuova testa della lista

## B. Visualizzazione (Scansione della lista)
Per leggere la lista si usa un puntatore ausiliario per non perdere la testa della lista.

Esempio: 
```c
void stampaLista(Lista testa) 
{
   	Nodo *temp = testa; // Uso un puntatore temporaneo
    while (temp != NULL) 
    {
        printf("%d -> ", temp->dato);
        temp = temp->next; // Mi sposto al nodo successivo
    }
  	printf("NULL\n");
}
```

Cosa fa il codice : 
    1. Riceve il parametro testa, cioe il puntatore al primo nodo della lista.
    2. Uttilizza un puntatore temp per scorere la lista senza modificare testa.
    3. Va a stampare ogni valore (temp→dato) seguito da una freccia
    4. Quando arriva alla fine (temp == NULL), stampa NULL.

## C. Ricerca di un elemento

Esempio : 
```c
int cerca(Lista testa, int x) 
{
    Nodo *temp = testa;
    while (temp != NULL) 
    {
       	if (temp->dato == x) return 1; // Trovato!
       	temp = temp->next;
  	}
	return 0; // Non trovato
}
```

Cosa fa il codice :
    1. Parte dal primo dopo (testa)
    2. Confronta temp→ dato con x
    3. Se trova la corrispondenza, termina subito restituendo 1
    4. Se arriva alla fine senza trovare nulla, restituisce 0

# 5. Differenze Array vs Liste (Teoria per l'orale/scritto)
| Caratteristica         | Array                                  | Lista Concatenata                                  |
|------------------------|----------------------------------------|----------------------------------------------------|
| Dimensione             | Fissa (Statica)                        | Variabile (Dinamica)                               |
| Memoria                | Contigua (tutti vicini)                | Sparsa                                             |
| Inserimento            | Difficile (bisogna spostare tutto)     | Facile (basta cambiare un puntatore)              |
| Accesso                | Diretto (tramite indice [i])           | Sequenziale (bisogna scorrere dall'inizio)        |

### Mini Esempio
```c
int main() {
    Lista miaLista = NULL; // Lista inizialmente vuota
    
    miaLista = inserisciTesta(miaLista, 10);
    miaLista = inserisciTesta(miaLista, 20);
    miaLista = inserisciTesta(miaLista, 30);
    
    printf("Contenuto della lista:\n");
    stampaLista(miaLista);
    
    return 0;
}
```