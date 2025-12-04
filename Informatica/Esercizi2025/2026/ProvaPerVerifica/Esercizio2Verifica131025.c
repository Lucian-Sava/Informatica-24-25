/*
Scrivi un programma in linguaggio C che chieda all’utente di inserire una stinga di caratteri , 
utilizzando un array dinamico per memorizzarla. Il programma deve poi analizzare la stringa per determinare quale vocale, tra a, e, i, o, u 
(senza distinzione tra maiuscole e minuscole), compare con maggiore frequenza.
 Infine, dovrà stampare a schermo insieme al numero delle sue occorrenze.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size;
    char *str;
    int count[5] = {0};                 /* a, e, i, o, u*/
    int MaxContatore = 0;               //Memorizza il contatore massimo trovato.
    char VocalePiufrequente = '\0';     //Memorizza la vocale più frequente trovata.

    printf("Inserisci la dimensione massima della stringa: ");
    scanf("%d", &size);

    if(size <= 0)     //Controllo dimensione valida.
    {
        printf("Dimensione non valida.\n");
        return 1;
    }

    str = malloc((size + 1) * sizeof(char));               /* +1 per '\0' *///Alloca la memoria dinamicamente per la stringa.
    if(str == NULL)                                        //Controllo allocazione riuscita o non riuscuta.
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    /* Pulizia del buffer in input */
    int Vc = getchar();                                    //"getchar" legge il primo carattere rimasto nel buffer dopo la lettura di size.
    if(Vc != '\n' && Vc != EOF)                            /* EOF serve a pulire il buffer d'input */
    {
        while(Vc != '\n' && Vc != EOF) Vc = getchar();     //Il "While" fa scorre il buffer fino a trovare il '\n' o EOF.
    }

    printf("Inserisci la stringa: ");

    /* legge al massimo 'size' caratteri */
    if(fgets(str, size + 1, stdin) == NULL)                //fgets legge al massimo "size" caratteri, lasciando spazio per il '\0'.
    {
        printf("Errore nella lettura della stringa\n");
        free(str);
        return 1;
    }

    /* rimuozione del '\n' finale se presente */
    size_t len = strlen(str);                                   //Calcola la lunghezza della stringa. //"strlen" calcola la lunghezza della stringa senza contare il carattere di terminazione '\0'.
    if(len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';    /*Se fgets ha letto anche il \n, lo rimuove.*/

    /* conta le vocali */
    for(size_t i = 0; str[i] != '\0'; i++)                      //Scorre tutta la stringa fino al carattere di terminazione '\0'.
    {
        char c = str[i];                                        // Scorre ogni carattere della stringa.

        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';             // Converte il carattere in minuscolo se è maiuscolo.

        switch(c)                                               // Incrementa il contatore corrispondente alla vocale trovata.            
        {
            case 'a': count[0]++; break;
            case 'e': count[1]++; break;
            case 'i': count[2]++; break;
            case 'o': count[3]++; break;
            case 'u': count[4]++; break;
            default: break;
        }
        if(count[0] > MaxContatore)                             //Dopo ogni incremento, controlla se quella vocale ha superato il MaxContatore
        { 
            MaxContatore = count[0]; VocalePiufrequente = 'a'; 
        }
        if(count[1] > MaxContatore) 
        { 
            MaxContatore = count[1]; VocalePiufrequente = 'e'; 
        }
        if(count[2] > MaxContatore)
        { 
            MaxContatore = count[2]; VocalePiufrequente = 'i'; 
        }
        if(count[3] > MaxContatore)
        { 
            MaxContatore = count[3]; VocalePiufrequente = 'o'; 
        }
        if(count[4] > MaxContatore)
        { 
            MaxContatore = count[4]; VocalePiufrequente = 'u'; 
        }
    }
    if(MaxContatore > 0)                                         //Stampa la vocale più frequente oppure un messaggio se non ci sono vocali.
    {
        printf("La vocale che compare con maggiore frequenza e' '%c' con %d occorrenze.\n", VocalePiufrequente, MaxContatore);
    }
    else
    {
        printf("Nessuna vocale trovata nella stringa.\n");
    }
    free(str);                                                      //Importantissimo: libera la memoria allocata dinamicamente.  
    return 0;                                                       //Termina il programma con successo.
}