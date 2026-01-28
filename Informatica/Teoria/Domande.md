# 1. Integrazioni sulle STRUCT
Perché usare una struct? Serve per raggruppare variabili di tipo diverso che si riferiscono allo stesso oggetto reale (es. un contatto o un'auto).

L'alternativa (perché è un problema?): L'alternativa sarebbe usare array separati (es. un array per i nomi, uno per i prezzi). Il problema è che è difficile mantenere i dati sincronizzati: se ordini l'array dei nomi, i prezzi non si spostano da soli e i dati si "mischiano".

Dichiarazione statica vs dinamica:
    Statica: “Auto concessionaria[100];” (Dimensione fissa all'inizio).
    Dinamica: Si usa la “malloc” per allocare memoria solo quando serve (come nelle liste).
# 2. Integrazioni sulle LISTE
Come "Liberare" la memoria
Quando hai finito di usare una lista, devi liberare la memoria di ogni singolo nodo, altrimenti causi un "memory leak".
```c
void liberaLista(Lista testa) 
{
    Nodo *temp;
    while (testa != NULL) 
    {
        temp = testa;	//Salvo il nodo corrente
        testa = testa→next;	//Avanzo al nodo successivo
        free(temp); // Libera il nodo corrente
    }
}
```
Inserimento in CODA
È più complesso della testa perché deve scorrere tutta la lista.
```c
Lista inserisciCoda(Lista testa, int valore) 
{
    Nodo *nuovo = (Nodo*) malloc(sizeof(Nodo));
    nuovo->dato = valore; //Assegno il valore 
    nuovo->next = NULL; 
    if (testa == NULL) return nuovo; // Se la lista è vuota, il nuovo è la testa
    
    Nodo *temp = testa;
    while (temp->next != NULL) 
    {
        temp = temp->next; // Vai fino all'ultimo
   	}
    temp->next = nuovo; // L'ultimo ora punta al nuovo
    return testa;
}
```
La Lista Circolare
     Cos'è? È una lista dove l'ultimo nodo, invece di puntare a NULL, punta di nuovo al primo nodo (Testa).
     Vantaggio: Puoi girare all'infinito nella lista senza fermarti mai.

# 7. Cancellazione di un Nodo
Per eliminare un nodo, devi sempre usare la funzione free(), altrimenti la memoria rimane occupata inutilmente.

A. Cancellazione in TESTA
È l'operazione più semplice: sposti la testa sul secondo nodo e liberi il primo.
```c
Lista eliminaTesta(Lista testa) 
{
    if (testa == NULL) return NULL; // Lista già vuota
    Nodo *daEliminare = testa;   // Memorizzo il nodo da cancellare
    testa = testa->next;         // Sposto la testa al nodo successivo
    free(daEliminare);           // Libero la memoria del vecchio primo nodo
    return testa;
}
```

B. Cancellazione in CODA (Domanda 16)
Per eliminare l'ultimo nodo, devi fermarti al penultimo.
```c
Lista eliminaCoda(Lista testa) 
{
    if (testa == NULL) return NULL; //Non c’è niente da eliminare, quindi ritorna NULL 
    if (testa->next == NULL) // C'è solo un nodo
    { 
        free(testa);
        return NULL;
    }
    
    Nodo *temp = testa; // dichiaro la mia variabile temp e lo punto all’inizio della lista
    // Scorro fino al penultimo nodo
    while (temp->next->next != NULL) 
    {
        temp = temp→next;  //avanzo di un nodo alla volta nella lista 
    }
    
    free(temp->next);    // Libero l'ultimo nodo
    temp->next = NULL;   // Il penultimo diventa l'ultimo
    return testa;
}
```

# 8. Focus Nodi Circolari
Definizione: In una lista circolare, l'ultimo nodo non punta a NULL, ma punta alla testa.

Cancellazione in testa su lista circolare: È difficile perché se elimini la testa, devi anche aggiornare l'ultimo nodo della lista affinché punti alla nuova testa. Se non lo fai, il cerchio si rompe.

Inserimento in fondo: Devi scorrere la lista finché non trovi il nodo che punta alla testa, e far puntare quel nodo al nuovo elemento (che a sua volta punterà alla testa).

# 9. Cose "Necessarie"
1. "Cosa succede se...": Se perdi il puntatore alla testa, perdi l'intera lista. La memoria resta occupata (leak) ma non è più raggiungibile.

2. Variabili Formali: Quando definisci una lista, i parametri che passi alle funzioni (es: Lista testa) sono variabili formali. Se vuoi modificare la lista originale nel main, devi restituire la nuova testa con return o usare i puntatori a puntatore.

3. Memoria Dinamica vs Statica:
    Statica: Array di struct (dimensione decisa alla compilazione).
    Dinamica: Lista (dimensione decisa durante l'esecuzione con malloc).

Domanda tosta: Perché è conveniente una lista rispetto a una struct/array? 
Ris.) Perché la lista permette di aggiungere o togliere elementi senza conoscere prima il numero totale e senza dover spostare tutti gli altri dati in memoria, risparmiando tempo computazionale.	