/*GENERATA UNA DATA TRA L’ANNO 2000 E L’ANNO 2024, AD OGGI E SAPENDO CHE GIACOMO HA 20 GIORNI PER CONSEGNARE IL LAVORO ASSEGNATO, COMUNICARE LA DATA DI CONSEGNA.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int anno, mese, giorno, bisestile, consegna;
    srand(time(NULL));
    anno=rand()%24+2000;
    mese=rand()%12;
    giorno=rand()%31;

    if( (anno%4==0 && anno!=100) || anno%400==0)//febbraio 29 giorni
    {
        printf("L'anno e bisestile");
        bisestile=1;
        if(mese==2)
        {
            if(giorno>=1 && giorno<=28+bisestile)
                printf("La data e bisestile");
        }
            if(mese==11 || mese==4 || mese==6 || mese==9)
            {
                if(giorno>=1 && giorno<=30)
                {
                    printf("la data e acettabile\n");
                }
                else
                {
                    printf("La data non accetabile\n");
                }
                    if(giorno>=1 && giorno<31)
                    {
                        printf("la data e accetabile\n");
                    }
                    else
                    {
                        printf("La data non e accetabile\n");
                    }
            }
        consegna = giorno + 20;
        printf("Per il mese di %d la consegna e di %d giorni", mese, consegna);
    }



    



    return 0;
}