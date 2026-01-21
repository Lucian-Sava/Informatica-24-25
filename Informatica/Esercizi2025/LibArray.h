/**
 * Scambia due variabili intere
 * @param int* variabile 1 passata per riferimento
 * @param int* variabile 2 passata per riferimento
 */
void scambia(int *var1, int *var2);
/**
 * funzione che stampa gli elementi di un vettore.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param char separatore tra un elemento e un altro 
 */
void stampaVettore(int vettore[], int dim, char sep);
/**
 * funzione che riempie un vettore con valori scelti dall'utente.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 */
void riempiVettore(int vettore[], int dim);
/**
 * funzione riempie un vettore con numeri casuali compresi tra un minimo e un massimo.
 * @param int [] vettore di interi 
 * @param int dimensione del vettore 
 * @param int minimo valore minimo dei numeri casuali
 * @param int massimo valore dei numeri casuali
 */
void riempiVettoreCasuale(int vettore[], int dim, int minimo, int massimo);
/**
 * questa funzione restituisce il numero di volte in cui compare la variabile valore all'interno del vettore
 * @param int[]vettore in ingresso
 * @param int dimensione del vettore
 * @param int valore da ricercare
 * @return int numero di occorrenze
 */
int contaOccorrenze(int vettore[], int dim, int valore);

/**
 * questa funzione restituisce la posizione del primo elemento nell'array che ha valore uguale alla variabile valore, se non trova l'elemento restituisce -1
 * @param int* vettore in ingresso
 * @param int dimensione del vettore
 * @param int valore da ricercare
 * @return int posizione del primo elemento uguale a valore o -1 se non trovato
 */
int ricercaSequenziale(int *vettore, int dim, int valore);


/**
 * questa funzione restituisce la posizione del primo elemento in un array ORDINATO in ordine crescente che ha valore uguale alla variabile valore, se non trova l'elemento restituisce -1
 * @param int[]vettore in ingresso
 * @param int dimensione del vettore
 * @param int indice dell'elemento da cui parte la ricerca
 * @param int indice dell'elemento a cui arriva la ricerca
 * @param int valore da ricercare
 * @return int posizione del primo elemento uguale a valore o -1 se non trovato
 */
int ricercaBinaria(int array[], int dim, int estInf, int estSup, int valore);

/**
 * Funzione che riempie un vettore di dimensione dim con numeri casuali in ordine crescente
 */
void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo);

/**
 * funzione che ordina un vettore
 * @param int[]vettore in ingresso
 * @param int dimensione del vettore
 */

void bubbleSort(int vett[], int dim);

/**
 * funzione che ordina un vettore
 * @param int[]vettore in ingresso
 * @param int dimensione del vettore
 */

 void selectionSort(int vett[], int dim);

/**
 * funzione ricorsiva che ordina un vettore 
 * @param int[]vettore in ingresso
 * @param int dimensione totale del vettore (serve per stampare il vettore ad ogni ricorsione)
 * @param int indice dell'elemento iniziale del vettore da ordinare
 * @param int indice dell'elemento finale del vettore da ordinare
 */

 void quickSort(int v[], int dim, int inizio, int fine);