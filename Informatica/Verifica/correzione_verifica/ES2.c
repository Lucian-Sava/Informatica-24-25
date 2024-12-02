/* ESercizio
    dato un numero stampare tutto i suoi divisori*/

    #include <stdio.h>
    int main()
    {
        int numero, divisore;

        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        divisore=2;

        if(numero%divisore==0)
        {
            printf("Il numero %d e divisibile per %d", numero, divisore);
        }
        else
        {
            printf("Il numeor %d non e divisore di %d", numero, divisore);
        }
        return 0;
    }