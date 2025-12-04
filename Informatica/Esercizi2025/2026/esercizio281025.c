/*
    Provare la LIBRERIA string.h
    Per le seguenti operazioni:
    1. Calcolo la lunghezza della stringa
    2. Controllo le stringhe uguali
    3. Copiare una stringa
    4. Cercare un carattere e comunicare la frequenza
    5. Concatenare due stringhe
    6. Ricerca di una stringa nell'altra
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int scelta;
  do{
    printf("---------MENU---------\n");
    printf("1. Calcolo la lunghezza della stringa\n");
    printf("2. Controllo le stringhe uguali\n");
    printf("3. Copiare una stringa\n");
    printf("4. Cercare un carattere e comunicare la frequenza\n");
    printf("5. Concatenare due stringhe\n");
    printf("6. Ricerca di una stringa nell'altra\n");
    printf("7. Esci\n");
    printf("Scegli un'opzione: ");
    scanf("%d", &scelta);

    switch (scelta)
    {
        case 1:
        {
            //calcolo della lunghezza della stringa

            char str1[100];
            printf("Inserisci una stringa: \n");
            scanf("%s", str1);
            printf("La lunghezza della stringa e': %ld\n", strlen(str1));
            break;
        }
        case 2:
        {
            //Controllo delle stringhe se sono uguali

            char str1[100], str2[100];
            printf("Inserisci la seconda stringa: \n");
            scanf("%s", str2);

            if(str1 == str2)
            {
                printf("Le stringhe sono uguali \n");
            }
            else
            {
                printf("Le stringhe non sono uguali\n");
            }
        }
        case 3:
        {
            //Copia di una stringa
            
            char str3[100], str1[100];

            strcpy(str3, str1);
            printf("la stringa copiata e': %s\n", str3);
            break;
        }
        case 4:
        {
            // Cercare il carattere e comunicare la sua frequenza

            char carattere;
            char str1[100];
            int frequenza = 0;

            printf("Inserisci il carattere da cercare: \n");
            scanf("%c", &carattere);

            for(int i = 0; i < strlen(str1); i++)
            {
                if(str1[i] == carattere)
                {
                    frequenza++;
                }
            }

            printf("La frequenza del carattere %c e': %d\n", carattere, frequenza);
            break;
        }
        case 5:
        {
            // Concatenare due stringhe

            char str4[100], str1[100];

            printf("Inserisci la seconda stringa da contatenare: \n");
            scanf("%s", str4);
            strcat(str1, str4);
            printf("La stringa concatenata e': %s\n", str1);
            break;
        }
        case 6:
        {
            // Ricerca di una stringa nell'altra

            char str5[100], str1[100];

            printf("Inserisci la stringa da cercare: \n");
            scanf("%s", str5);

            if(strstr(str1, str5) != NULL)
            {
                printf("La stringa %s e' stata trovata in %s\n", str5, str1);
            }
            else
            {
                printf("La stringa %s non e' stata trovata in %s\n", str5, str1);
            }
            break;
        }
        case 7:
        {
            printf("Uscita dal programma.\n");
            break;
        }
        default:
            printf("Scelta non valida. Riprova.\n");
            break;  
    }
  }while(scelta != 7);
}