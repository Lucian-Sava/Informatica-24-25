/*
Scrivi un programma in linguaggio C che chieda all’utente di inserire una stinga di caratteri , 
utilizzando un array dinamico per memorizzarla. Il programma deve poi analizzare la stringa per determinare quale vocale, tra a, e, i, o, u 
(senza distinzione tra maiuscole e minuscole), compare con maggiore frequenza.
 Infine, dovrà stampare a schermo insieme al numero delle sue occorrenze.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int size;
    char *str;
    int count[5] = {0}; /* a, e, i, o, u */
    int MaxContatore = 0;
    char VocalePiufrequente = '\0';

    printf("Inserisci la dimensione massima della stringa: ");
    if (scanf("%d", &size) != 1) {
        printf("Input non valido.\n");
        return 1;
    }

    if (size <= 0) {
        printf("Dimensione non valida.\n");
        return 1;
    }

    str = malloc((size + 1) * sizeof(char)); /* +1 per '\0' */
    if (str == NULL) {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    /* Pulisci il buffer di input */
    int ch = getchar();
    if (ch != '\n' && ch != EOF) 
    {
        while (ch != '\n' && ch != EOF) ch = getchar();
    }

    printf("Inserisci la stringa: ");
    /* legge al massimo 'size' caratteri */
    if (fgets(str, size + 1, stdin) == NULL) 
    {
        printf("Errore nella lettura della stringa\n");
        free(str);
        return 1;
    }
    /* rimuovi '\n' finale se presente */
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';

    /* conta le vocali (case-insensitive) */
    for (size_t i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        switch (c) {
            case 'a': count[0]++; if (count[0] > MaxContatore) { MaxContatore = count[0]; VocalePiufrequente = 'a'; } break;
            case 'e': count[1]++; if (count[1] > MaxContatore) { MaxContatore = count[1]; VocalePiufrequente = 'e'; } break;
            case 'i': count[2]++; if (count[2] > MaxContatore) { MaxContatore = count[2]; VocalePiufrequente = 'i'; } break;
            case 'o': count[3]++; if (count[3] > MaxContatore) { MaxContatore = count[3]; VocalePiufrequente = 'o'; } break;
            case 'u': count[4]++; if (count[4] > MaxContatore) { MaxContatore = count[4]; VocalePiufrequente = 'u'; } break;
            default: break;
        }
    }

    if (MaxContatore > 0) {
        printf("La vocale che compare con maggiore frequenza e' '%c' con %d occorrenze.\n", VocalePiufrequente, MaxContatore);
    } else {
        printf("Non sono state trovate vocali nella stringa.\n");
    }

    free(str);
    return 0;
}