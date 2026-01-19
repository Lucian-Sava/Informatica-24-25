#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct          //creazione di una struttura "Dati"
{
    char nome[30];
    int eta;
}Dati;

int main() { 
    
   int scelta, lunghezza=0, i=0, j; //inizializzazione di variabili
   Dati *vettore = NULL;    //dichiarazioine del puntatore a struct dinamico impostato a NULL
    
   do
   {     
    printf("--- Menù ---\n");        
    printf("Scegli l'operazione da eseguire:\n");    
    printf("1. Inserisci\n");
    printf("2. Cancella\n");
    printf("3. Ricerca\n");
    printf("4. Visualizza\n"); 
    printf("5. Esci\n");
    printf("Scelta: "); 
    scanf(" %d", &scelta);

    switch (scelta) { 
         case 1: 
                 
                printf("Inserisci...\n");
                vettore = realloc(vettore, (i + 1) * sizeof(Dati)); //Uttizza una funzione realloc che aumenta lo spazio di una struttura dinamica
                                                                    //che permette di non sprecare memoria in anticipo, diversamente da un array statico.
                
                printf("Dammi il nome...\n");
                scanf("%s",vettore[i].nome);    //inserimento al campo del nome che avviene attraveso l'utilizzo dell'operatore "."
                                                //perché l'indice tra parentesi quadrate si occupa già di puntare alla cella corretta; quindi "vettore[i].nome"
                 printf("Dammi l'età...\n");
                scanf("%d",&vettore[i].eta);

                i++;
                lunghezza++;
                
                break; 

        case 2: 
                int k;
                char nome_cancella[30];

                printf("Cancella...\n");
                   
                printf("Dammi il nome...\n");       //la cancellazione viene per nome, tramite un confronto tra stringhe: "strcmp".
                scanf("%s",nome_cancella);

                for(j=0; j<=lunghezza; j++)  //vado a scorrerre tutto il vettore, fino a alla sua lunghezza.
                {
                            if(strcmp(nome_cancella,vettore[j].nome)==0) //individua il dato da eliminare, ed esegue uno spostamento a sinistra di ogni elemento successivo 
                                                                         //a quello rimosso che viene copiato nella posizione precedente, sovrascrivendo di fatto il dato da cancellare
                            {
                                printf("%s, %d trovato in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1); //stampa dove è stato trovato l'elemento da cancellare

                                for (i=j; i<lunghezza-1; i++) //Effetua uno spostamento a sinistra di ogni elemento successivo a quello rimosso
                                {
                                     vettore[k]=vettore[k+1]; //Copia la posizione successiva e va ad sovrascrivere la posizione corrente
                                }
                            }
                    lunghezza--;    //Riduce la lunghezza del vettore di 1
                    vettore = realloc(vettore, lunghezza * sizeof(Dati));  //Ridimensionare il vettore, per toglire lo spazio non più necessario         
                }        
                break; 
        
         case 3: 
                int opzione, eta_ricerca;
                char nome_ricerca[30];

                do{
                    
                    printf("Ricerca...\n");
                    printf("1. Nome\n");
                    printf("2. Età\n");
                    printf("3. Esci\n");
                    printf("Scelta: ");
                    scanf("%d",&opzione);
                
                    if (opzione==1)
                    {
                        printf("Dammi il nome...\n");
                        scanf("%s",nome_ricerca);   //Inserimento del dato da ricercare in una nuova variabile

                        for(j=0; j<lunghezza; j++) //scorrere tutto il vettore per cercare il dato da ricercare
                        {
                            if(strcmp(nome_ricerca,vettore[j].nome)==0) //confronto le due stringhe di nomecon un "strcmp" per verificare se il dato è presente o uguale
                            {
                                printf("%s, %d in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1); //stampa il dato trovato con la sua posizione
                            }
                        }
                    }
                
                    if (opzione==2){
                        printf("Dammi l'età...\n");
                        scanf("%d",&eta_ricerca);   //Inserimento del dato da ricercare in una nuova variabile

                        for(j=0; j<lunghezza; j++)  //scorrere tutto il vettore per cercare il dato da ricercare
                         {
                            if(eta_ricerca==vettore[j].eta) //confronto le due stringhe di eta con un "strcmp" per verificare se il dato è presente o uguale
                            {
                                printf("%s, %d in posizione %d\n", vettore[j].nome, vettore[j].eta, j+1); //stampa il dato trovato con la sua posizione
                            }
                        }
                    }
                }while (opzione!=3);
                
                break;            
    
         case 4:
                
                printf("Visualizza...\n");
                printf("Inizio -> ");
                
                
                for(j=0; j<lunghezza; j++) //scorrere tutto il vettore per stampare tutti i dati presenti nel vettore
                {
                    printf("[%d, %s, %d] -> ", j+1, vettore[j].nome, vettore[j].eta );  //stampa i dati presenti nel vettore con il loro indice
                }
                printf("Fine");
                printf("\n");
                printf("lunghezza vettore: %d\n", lunghezza); //stampa la lunghezza attuale del vettore
                
                break; 
                        
      case 5:
                free(vettore); //funzione per liberare la memoria allocata dinamicamente
                return 0;             
      default: 
                       printf("Errore: Scelta non valida.\n"); 
        }   
   }while(scelta!=5);
   
   
   return 0; 
}
