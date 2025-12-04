/* 
    Verificare se una stringa è palindroma 
    Es: anna è palindroma
    Es: ciao non è palindroma
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char* String;

int lunghezza(String s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return i-1; //escludo il carattere di nuova linea
}


int Palindroma(String s, int dim)
{
    int flag = 0, i, j;

    for(i = 0, j = dim - 1; i < dim / 2; i++, j--) //correggere
    {
        if(s[i] != s[j])
        {
            flag = 1;
        }
    }
    return flag;
    
}

typedef char* String;

int main()
{
    int dim = 0, palindroma = 0;

    String s = (String)malloc(50 * sizeof(char));
    if(s == NULL)
    {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }

    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    printf("La stringa inserita è: %s\n", s);
    dim = lunghezza(s);
    printf("La lunghezza della stringa è: %d\n", dim);

    palindroma = Palindroma(s, dim);

    if(palindroma == 1)
    {
        printf("La stringa non è palindroma\n");
    }
    else
    {
        printf("La stringa è palindroma\n");
    }
}