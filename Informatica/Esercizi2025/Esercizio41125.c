/*
    Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale 
    (senza il carattere di controllo finale) chiedendo all’utente di inserire nome, cognome, data di nascita nel formato GG/MM/AAAA, sesso (M o F).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//calcolo del codice fiscale

int codiceFiscale()
{
    strcat(codiceFiscale, nome, cognome, giorno, mese, anno, sesso);
    return 0;
}

int nome()

int main()
{
    char nome[50], cognome[50]; 
    int giorno, mese, anno;
    char codiceFiscale[16] = "";
    char sesso;



    // Input dei dati chiesti dall'utente

    do{
        printf("Inserisci il sesso (M/F): ");
        scanf(" %c", &sesso);

    }while(sesso != 'M' && sesso != 'F' && sesso != 'm' && sesso != 'f');

    printf("Inserisci il nome: ");
    scanf("%49s", nome);

    printf("Inserisci il cognome: ");   // Limite di 49 caratteri per evitare overflow
    scanf("%49s", cognome);
    
    printf("Inserisci la data di nascita (GG/MM/AAAA): ");
    scanf("%d/%d/%d", &giorno, &mese, &anno);




    // Calcolo del codice fiscale
    // Cognome: prime tre consonanti, se meno di tre lettere, aggiungere vocali, se ancora meno di tre, aggiungere X

    int i, count = 0;
    
        for(i = 0; cognome[i] != '\0' && count < 3; i++)                    // Prime tre consonanti
        {
            if(isalpha(cognome[i]) && !strchr("AEIOUaeiuo", cognome[i]))    // controlla se è consonante
            {
                codiceFiscale[count++] = toupper(cognome[i]);               // Aggiunge le consonanti
            }
        }

        for(i = 0; cognome[i] != '\0' && count < 3; i++)                    // Aggiunge vocali se necessario
        {
            if(isalpha(cognome[i]) && strchr("AEIOUaeiuo", cognome[i]))     // controlla se è vocale
            {
                codiceFiscale[count++] = toupper(cognome[i]);               // Aggiunge le vocali
            }
        }

        while(count < 3)
        {
            codiceFiscale[count++] = 'X';                                   // Aggiunge X se necessario
        }




    //Nome: prime tre consonanti, se meno di tre lettere, aggiungere vocali, se ancora meno di tre, aggiungere X

    count = 3; //Ripete da 3 per il nome

    int consonantiTrovate = 0;

    for(i = 0; nome[i] != '\0' && count < 3; i++)                    // Prime tre consonanti
    {
        if(isalpha(nome[i]) && !strchr("AEIOUaeiuo", nome[i]))    // controlla se è consonante
        {
            codiceFiscale[count++] = toupper(nome[i]);               // Aggiunge le consonanti
            consonantiTrovate++;
        }
    }

    for(i = 0; nome[i] != '\0' && count < 3; i++)                    // Aggiunge vocali se necessario
    {
        if(isalpha(nome[i]) && strchr("AEIOUaeiuo", nome[i]))     // controlla se è vocale
        {
            codiceFiscale[count++] = toupper(nome[i]);               // Aggiunge le vocali
            consonantiTrovate++;
        }
    }

    while(count < 3)
    {
        codiceFiscale[count++] = 'X';                                   // Aggiunge X se necessario
    }



    // Data di nascita e sesso

    codiceFiscale[6] = (anno / 10) % 10 + '0';                      // penultima cifra dell'anno
    codiceFiscale[7] = anno % 10 +'0';                              // ultima cifra dell'anno
    const char mesiCodice[] = "ABCDEHLMPRST";                        // Codici dei mesi
    codiceFiscale[8] = mesiCodice[mese - 1];                       // codice del mese

    if(sesso == 'M' || sesso == 'm')
    {
        codiceFiscale[9] = (giorno / 10) + '0';                      // decina del giorno
        codiceFiscale[10] = (giorno % 10) + '0';                     // unità del giorno
    }
    else if(sesso == 'F' || sesso == 'f')
    {
        int giornoFemmina = giorno + 40;                             // aggiunge 40 per il sesso femminile
        codiceFiscale[9] = (giornoFemmina / 10) + '0';               // decina del giorno
        codiceFiscale[10] = (giornoFemmina % 10) + '0';              // unità del giorno
    }
    else
    {
        printf("Sesso non valido. Usa M o F.\n");
        return 1;
    }

    codiceFiscale[11] = '\0'; // Terminatore di stringa
    printf("Il codice fiscale calcolato e': %s\n", codiceFiscale);
    return 0;
}
