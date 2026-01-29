# 1. Che cos'è una Struct?
Una struct (abbreviazione di structure) è un tipo di dato definito dall'utente. A differenza degli array (che contengono dati dello stesso tipo), una struct permette di raggruppare variabili di tipi diversi (es. stringhe, interi, float) sotto un unico nome. Queste variabili interne si chiamano campi o membri.

-)Esempio concettuale: Se devi gestire uno studente, non usare tre array separati (uno per i 	   nomi, uno per i cognomi, uno per i voti), ma crea un tipo Studente che li contenga tutti.

# 2. Definizione della Struct ( typedef)
In C è molto comodo usare typedef per evitare di dover scrivere la parola struct ogni volta che dichiari una variabile.
Esempio:
```c
#include <stdio.h>
#include <string.h>
// Definizione del TIPO
typedef struct 
{
    char nome[30];   // Stringa: array di char
    char cognome[30];
    float media;
    int assenze;
} Studente;  // "Studente" diventa il nome del nuovo tipo
```

# 3. Dichiarazione e Assegnazione
Nel main dichiari le variabili usando il nome definito col typedef.
Esempio:
```c
int main() 
{
    Studente s1; // Variabile singola
    // ASSEGNAZIONE DIRETTA (ATTENZIONE!)
   	// s1.nome = "Mario";  <-- ERRORE GRAVE IN C! Non si può assegnare con =
   	// Si usa strcpy (string copy)
    strcpy(s1.nome, "Mario");
	s1.media = 7.5; // I numeri funzionano normalmente con =
}
```

# 4. Input e Output (scanf e printf)
## Output (Stampa)
Usa i "segnaposto" (formati specifici), quindi :
-) %s per le stringhe
-) %d per interi (int)
-) %f per decimali (float)

Esempio:
```c
    printf("Lo studente %s ha la media del %f\n", s1.nome, s1.media);
```

## Input (Lettura da tastiera)
Attenzione alla & (e commerciale).

-) Per i numeri (int, float) CI VUOLE la &.
-) Per le stringhe (char[]) NON ci vuole la & (perché il nome dell'array è già un indirizzo).

Esempio:
```c
printf("Inserisci nome: ");
scanf("%s", s1.nome);      // Niente & per le stringhe!
printf("Inserisci media: ");
scanf("%f", &s1.media);    // Qui ci vuole la &
```

# 5. Array di Struct (Esercizio Completo)
Esempio classico di : caricamento e stampa di un array di struct
```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char marca[30];
    char modello[30];
    float prezzo;
} Auto;

int main() {
    Auto concessionaria[100]; // Array di struct
    int n, i;

    // 1. Quante auto inserire?
    printf("Quante auto vuoi inserire? ");
    scanf("%d", &n);

    // 2. Ciclo di Caricamento
    for(i = 0; i < n; i++) 
    {
        printf("\n--- Auto n.%d ---\n", i+1);
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
    }
    return 0;
}
```

# 6. Controlli (IF)
Per cercare una stringa (es. stampare tutte le Fiat), si usa strcmp. Se restituisce 0, le stringhe sono uguali. 

Esempio: 
```c
// Esempio: Stampare solo le auto di marca "Fiat"
	if (strcmp(concessionaria[i].marca, "Fiat") == 0) 
	{
    	printf("Trovata una Fiat: %s\n", concessionaria[i].modello);
	}	
```

Delle volte ci sono dei confronti da fare e si uttilizza un [if con Num. macchina< Num.]
ma si possono anche fare un confronto con [Num. Macchina > Num. Concessionaria]

Esempio : 
```c
float maxPrezzo = 0;
int posMax = 0;

for(i = 0; i < n; i++) 
{
    if (concessionaria[i].prezzo > maxPrezzo) 
	{
       	maxPrezzo = concessionaria[i].prezzo;
        posMax = i; // Memorizzo l'indice (la posizione)
    }
}
printf("L'auto più costosa è: %s\n", concessionaria[posMax].modello);
```

## CONSIGLIO (uso flag):

Esempio :
```c
int trovato = 0; // Parto dal presupposto che non c'è
for(i = 0; i < n; i++) 
{
    if (strcmp(concessionaria[i].marca, "Fiat") == 0) 
    {
       	printf("Trovata: %s\n", concessionaria[i].modello);
        trovato = 1; // Trovata!
    }
}
if (trovato == 0) 
{
    printf("Nessuna auto Fiat in magazzino.\n");
}
```