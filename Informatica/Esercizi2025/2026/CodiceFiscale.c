/*
    Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale 
    (senza il carattere di controllo finale) chiedendo all’utente di inserire nome, cognome, data di nascita nel formato GG/MM/AAAA, sesso (M o F).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void calcolo_del_codice_fiscale(char *nome, char *cognome, int giorno, int mese, int anno, char sesso, char *ComunediNascita, char *CodiceFiscale)
{
    int i, count = 0;

    // Cognome: Prime tre consonanti, se meno di tre lettere, aggiunge vovali, se ancora meno di tre, aggiunge X
    // toupper --->  per rendere maiuscole le lettere
    // strchr ---> per cercare un carattere in una stringa
    // isalpha ---> per controllare se è una lettera
    for(i = 0; cognome[i] != '\0' && count < 3; i++)                    // Prime tre consonanti
    {
        if(isalpha(cognome[i]) && !strchr("AEIOUaeiuo", cognome[i]))    // controlla se è consonante
        {
            CodiceFiscale[count++] = toupper(cognome[i]);               // Aggiunge le consonanti
        }
    }
    for(i = 0; cognome[i] != '\0' && count < 3; i++)                    // Aggiunge vocali se necessario
    {
        if(isalpha(cognome[i]) && strchr("AEIOUaeiuo", cognome[i]))     // controlla se è vocale
        {
            CodiceFiscale[count++] = toupper(cognome[i]);               // Aggiunge le vocali
        }
    }
    while(count < 3)
    {
        CodiceFiscale[count++] = 'X';                                   // Aggiunge X se necessario
    }

    // Nome: prime tre consonanti, se nome meno di tree consonanti, aggiunge vocali, se ancora meno aggiunge X

    count = 3; //Ripete da 3 per il nome

    for(i = 0; nome[i] != '\0' && count < 6; i++)                    // Prime tre consonanti
    {
        if(isalpha(nome[i]) && !strchr("AEIOUaeiuo", nome[i]))    // controlla se è consonante
        {
            CodiceFiscale[count++] = toupper(nome[i]);               // Aggiunge le consonanti
        }
    }
    for(i = 0; nome[i] != '\0' && count < 6; i++)                    // Aggiunge vocali se necessario
    {
        if(isalpha(nome[i]) && strchr("AEIOUaeiuo", nome[i]))     // controlla se è vocale
        {
            CodiceFiscale[count++] = toupper(nome[i]);               // Aggiunge le vocali
        }
    }
    while(count < 6)
    {
        CodiceFiscale[count++] = 'X';                                   // Aggiunge X se necessario
    }

    //Data di nascita e sesso
    CodiceFiscale[6] = (anno /10) % 10 + '0';                     // penultima cifra dell'anno
    CodiceFiscale[7] = anno % 10 +'0';                             // ultima cifra dell'anno
    const char mesiCodice[] = "ABCDEHLMPRST";                        // Codici dei mesi
    CodiceFiscale[8] = mesiCodice[mese - 1];                       // codice del mese

    //Giorno e sesso

    if(sesso == 'F' || sesso =='f')
    {
        giorno += 40; //aggiunge 40 se è fermina
    }

    CodiceFiscale[9] = (giorno / 10) % 10 + '0';                    // decina del giorno
    CodiceFiscale[10] = (giorno % 10) + '0';                     // unità del giorno   ù
    CodiceFiscale[11] = 'G';
    CodiceFiscale[12] = '1';
    CodiceFiscale[13] = '8';
    CodiceFiscale[14] = '6';
    CodiceFiscale[15] = '\0'; // Terminatore di stringa

}

int main()
{
    char nome[50], cognome[50]; 
    int giorno, mese, anno;
    char codiceFiscale[16] = "";
    char sesso;
    char ComunediNascita[50];

    // Input dei dati chiesti dall'utente

    do{
        printf("Inserisci il sesso (M/F): ");
        scanf(" %c", &sesso);

    }while(sesso != 'M' && sesso != 'F' && sesso != 'm' && sesso != 'f');

    printf("Inserisci il nome: ");
    scanf("%49s", nome);

    printf("Inserisci il cognome: ");
    scanf("%49s", cognome);

    printf("Inserisci la data di nascita (GG MM AAAA): ");
    scanf("%d %d %d", &giorno, &mese, &anno);

    // Calcolo del codice fiscale
    calcolo_del_codice_fiscale(nome, cognome, giorno, mese, anno, sesso, ComunediNascita, codiceFiscale);

    // Visualizzazione del codice fiscale
    printf("Il codice fiscale e': %s\n", codiceFiscale);

    return 0;
}