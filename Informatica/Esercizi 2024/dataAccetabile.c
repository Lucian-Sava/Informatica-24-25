/* data una data in formato gg mm aaaa
verificare se la data e accetabile*/
#include <stdio.h>
int main()
{
    int giorno=0;
    int mese=0;
    int anno=0;
    int bisestile=0;
    printf("Inserisci il giorno: ");
    scanf("%d", &giorno);
    printf("Inserisci il mese: ");
    scanf("%d", &mese);
    printf("Inserisci l'anno: ");
    scanf("%d", &anno);

    //controllo della data
    //un'anno è bisestile quando se è multiplo di 4 ma non 100 oppure di 400

    //if((anno % 4 == 0 && anno % 100 != 0) || anno % 400 == 0)
    if(anno%100==0)
    {
        if (anno%400==0)
        {
            printf("l'anno è bisestile è ");
            bisestile = 1;

        }
    }
    else
    {
        if (anno%4==0)
        {
            printf("L'anno è bisestile è ");
            bisestile = 1;
        }
    }
    //controllo del mese
    if (mese>=1 && mese<=12)
    {
        if (mese == 2)
        {
            if(giorno>=1 && giorno <=28+bisestile)
            {
                printf("la data e accettabile");
            }
            else 
            {
                printf("La data non è accettabile");
            }
        }
        else
        {
            if( mese == 11 || mese == 4 || mese == 6 || mese == 9)
            {
                if (giorno >=1 && giorno <= 30)
                {
                    printf("la data e accettabile");
                }
                else
                {
                    printf("\nLa data non è accettabile");
                }
            }
            else
            {
                if (giorno >=1 && giorno <= 31)
                {
                    printf("\nla data e accettabile");
                }
                else
                {
                    printf("\nLa data non è accettabile");
                }
            }
        }
    }
    return 0;
}