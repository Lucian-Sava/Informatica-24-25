#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct      //definizione della struct "Dati" con due campi: "nome" (array di caratteri) ed "eta" (intero)
{
    char nome[30];
    int eta;
}Dati;

void InserimentoDati(Dati **vettore, int *lunghezza)  //funzione per l'inserimento dei dati nel vettore dinamico di struct
{

    int i = *lunghezza; //uso una variabile locale "i" per tenere traccia dell'indice corrente di inserimento
                        //inizializzata con il valore di lunghezza passato per riferimento dalla funzione main

    Dati *tmp = realloc(*vettore, (*lunghezza + 1) * sizeof(Dati)); //riallocazione della memoria per il vettore, aumentando la sua dimensione di 1,
                                                                    //utilizzando "realloc" per mantenere i dati già presenti nel vettore.
                                                                    //uso la variabile temporanea "tmp" per memorizzare il nuovo indirizzo restituito da "realloc"

    if (tmp == NULL) //controllo se la riallocazione è andata a buon fine
    {
        printf("Errore di allocazione della memoria\n");
        return;
    }

    *vettore = tmp; //aggiorno il puntatore del vettore con il nuovo indirizzo restituito dalla realloc

    printf("Dammi il nome...\n");
    scanf("%s",(*vettore[i]).nome);    //inserimento del nome nel campo "nome" della struct all'indice "i", 
                                        //che corrisponde alla nuova posizione disponibile nel vettore.
                                    
    printf("Dammi l'età...\n");
    scanf("%d",&(*vettore)[i].eta);   //stessa cosa come e scritto sopra, ma per il campo "eta"


    
    (*lunghezza)++; //incremento la lunghezza del vettore di 1, poichè ho aggiunto un nuovo elemento.
}

void CancellazioneDato(Dati **vettore, int *lunghezza)      //funzione per la cancellazione di un dato dal vettore dinamico di una struct
{
    if(*lunghezza==0) //controllo se il vettore è vuoto
    {
        printf("Vettore vuoto, non c'è niente da cancellare\n");
        return;
    }

    char nome_cancella[30]; //variabile per memorizzare il nome dell'elemento da cancellare

    printf("Dammi il nome...\n");  //chiedo all'utente il nome dell'elemento da cancellare
    scanf("%s",nome_cancella);      //inserimento del nome da cancellare nella variabile "nome_cancella"
    printf("Cancellazione in corso...\n");

    int trovato = -1; //variabile per tenere traccia dell'indice dell'elemento da cancellare, inizializzata a -1 , che indica che l'elemento non è stato trovato

    for(int j=0; j<*lunghezza; j++) //Va scorrere tutto il vettore per cercare l'elemento da cancellare
    {
        if(strcmp(nome_cancella, (*vettore)[j].nome)==0) //Fa un confronto tra le stringhe per verificare se il nome da cancellare è uguale al nome presente nel vettore.
        {
            trovato = j; //se trova il nome, assegna l'indice alla variabile "trovato"
            break; //esce dal ciclo una volta trovato l'elemento da cancellare
        }
    }

    if(trovato == -1) //Chiedo se l'elemnto da cancellare non e' stato trovato
    {
        printf("Elemento non trovato, impossibile cancellare\n");
        return;
    }

    printf("%s, %d in posizione %d cancellato\n", (*vettore)[trovato].nome, (*vettore)[trovato].eta, trovato+1); //stampa l'elemento che sta per essere cancellato, ed "trovato+1" significa dove si trova l'elemento.

    //sposo a sinistra gli elementi successivi a quello da cancellare per sovrascriverlo
    if(trovato < *lunghezza -1) //controllo se l'elemento da cancellare non è l'ultimo elemento del vettore
    {
        memmove(&(*vettore)[trovato], &(*vettore)[trovato + 1], (*lunghezza - trovato - 1) * sizeof(Dati)); 
        //uso "memmove" per spostare gli elementi successivi a sinistra
        //&(*vettore)[trovato], &(*vettore)[trovato + 1] --> sono gli indirizzi di partenza e destinazione
        //(*lunghezza - trovato - 1) * sizeof(Dati) --> è la dimensione dei dati da spostare (lo sposta di una posizione a sinistra)
    }

    (*lunghezza)--; //decremento la lunghezza del vettore di 1, poichè ho rimosso un elemento.

    if(*lunghezza == 0)
    {
        free(*vettore); //se il vettore è vuoto, libero la memoria allocata
        *vettore = NULL; //imposto il puntatore del vettore a NULL per evitare dangling pointer: che sarebbe un puntatore che punta a una zona di memoria non più valida.
    }
    else  //se il vettore non è vuoto, rialloco la memoria per ridurre la dimensione del vettore
    {
        Dati *tmp = realloc(*vettore, (*lunghezza) * sizeof(Dati)); //riallocazione della memoria per il vettore, riducendo la sua dimensione di 1
                                                                    //utilizzando "realloc" per mantenere i dati rimanenti nel vettore.
        if(tmp)  //controllo se la riallocazione è andata a buon fine
        {
            *vettore = tmp; //aggiorno il puntatore del vettore con il nuovo indirizzo restituito dalla realloc
        }
    }

    printf("Cancellazione completata, La nuova lunghezza e' :%d\n", *lunghezza); //stampa la nuova lunghezza del vettore dopo la cancellazione
}

void RicercaDato(Dati **vettore, int lunghezza)  //funzione per la ricerca di un dato nel vettore dinamico di struct
{
    int opzione, eta_ricerca, j;
    char nome_ricerca[30];

    do{
                    
        printf("Ricerca...\n");
        printf("1. Nome\n");
        printf("2. Età\n");
        printf("3. Esci\n");
        printf("Scelta: ");
        scanf("%d",&opzione);
                
        if (opzione==1)  //Ha la funzione di cercare un dato in base al nome
        {
            printf("Dammi il nome...\n");
            scanf("%s",nome_ricerca);   //Inserimento del dato da ricercare in una nuova variabile

            for(j=0; j<lunghezza; j++) //scorrere tutto il vettore per cercare il dato da ricercare
            {
                if(strcmp(nome_ricerca,(*vettore)[j].nome)==0) //confronto le due stringhe di nome con un "strcmp" per verificare se il dato è presente o uguale
                {
                    printf("%s, %d in posizione %d\n", (*vettore)[j].nome, (*vettore)[j].eta, j+1); //stampa il dato trovato con la sua posizione
                }
            }
        }
                
        if (opzione==2) //Ha la funzione di cercare un dato in base all'età
        {
            printf("Dammi l'età...\n");
            scanf("%d",&eta_ricerca);   //Inserimento del dato da ricercare in una nuova variabile

            for(j=0; j<lunghezza; j++)  //scorrere tutto il vettore per cercare il dato da ricercare
            {
                if(eta_ricerca==(*vettore)[j].eta) //confronto le due stringhe di eta con un "strcmp" per verificare se il dato è presente o uguale
                {
                    printf("%s, %d in posizione %d\n", (*vettore)[j].nome, (*vettore)[j].eta, j+1); //stampa il dato trovato con la sua posizione
                }
                else if(eta_ricerca != (*vettore)[j].eta) //fa un controllo se non trova nessun dato con l'età specificata
                {
                    printf("Nessun dato trovato con l'età %d\n", eta_ricerca); //stampa un messaggio se non trova nessun dato con l'età specificata
                }
            }

        }
    }while (opzione!=3);
}

void VisualizzaDati(Dati **vettore, int lunghezza)    //Ha la funzione di visualizzare tutti i dati presenti nel vettore dinamico di struct
{
    printf("Visualizza...\n");
    printf("Inizio -> ");
                
                
    for(int j=0; j<lunghezza; j++) //scorrere tutto il vettore per stampare tutti i dati presenti nel vettore
    {
        printf("[%d, %s, %d] -> ", j+1, (*vettore)[j].nome, (*vettore)[j].eta );  //stampa i dati presenti nel vettore con il loro indice, j+1 e per indicare la posizione in cui si trova l'elemento
    }
    printf("Fine");
    printf("\n");
    printf("lunghezza vettore: %d\n", lunghezza); //stampa la lunghezza attuale del vettore
}

int main()
{
    int scelta;
    Dati *vettore = NULL; //puntatore al vettore dinamico di struct, inizializzato a NULL
    int lunghezza=0, i=0, j;

    do{
        printf("=====MENU=====\n");
        printf("Scegli un'opzione:\n");
        printf("1. Insermento dei dati\n");
        printf("2. Cancellazione di un dato\n");
        printf("3. Ricerca di un dato\n");
        printf("4. Visualizzazione dei dati\n");
        printf("5. Uscita\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta)
        {
            //io scrivo (&vettore) perchè la funzione che va a modificare il puntatore corrente del vettore, quindi passo 
            //l'indirizzo di esso e con "&" che lo ottengo dall'operatore di indirizzo.
            case 1:
                InserimentoDati(&vettore, &lunghezza);  //Funzione che implemento per l'inserimento dei dati
                break;
            case 2:
                CancellazioneDato(&vettore, &lunghezza); //funzione che implemnto per cancelllare il dato
                break;
            case 3:
                RicercaDato(&vettore, lunghezza); //funzione che implemento per la ricerca del dato
                break;
            case 4:
                VisualizzaDati(&vettore, lunghezza); //Funzione che implemento per visualizzare i dati
                break;
            case 5:
                printf("Uscita in corso...\n");
                free(vettore); //libero la memoria allocata dinamicamente per il vettore
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;    
        }

    }while(scelta!=5);
    return 0;
}
    