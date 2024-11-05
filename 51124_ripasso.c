/*Scrivi un programma in C che permetta di inserire 1 voto di uno studente.
Poi genera casualmente un secondo voto compreso tra 4 e 8.
Quindi permetta di scegliere quale operazione fare tra:
- 1 mostrare la media dei due voti
- 2 mostrare il voto maggiore tra i due
- 3 mostrare il voto minore tra i due.
- 4 mostrare il numero di voti sufficiente tra i due.
Verificare che il voto inserito sia compreso tra 2 e 10.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    float voto1;
    float voto2;
    int scelta;
    printf("Inserisci il primo voto: ");
    scanf("%f", &voto1);
    srand(time(NULL));
    voto2 = rand()%5+4;
    printf("Il voto casuale è %f \n", voto2);
    printf("Scegli un'operazione \n- 1 mostrare la media dei due voti \n- 2 mostrare il voto maggiore tra i due\n- 3 mostrare il voto minore tra i due. \n- 4 mostrare il numero di voti sufficiente tra i due. \n Quale scegli: ");
    scanf("%d", &scelta);
    
    switch(scelta)
    {
        case 1:
            printf("La media dei due voti è: %f \n", (voto1+voto2)/2);
            break;
        case 2:
            if (voto1 > voto2) 
            { 
                printf("Il voto maggiore è: %f \n", voto1); 
            } 
            else if (voto2 > voto1) 
            { 
                printf("Il voto maggiore è: %f \n", voto2); 
            } 
            else 
            { 
                printf("I voti sono uguali: %f \n", voto1); 
            }
            break;
        case 3:
            if (voto1 < voto2) 
            { 
                printf("Il voto minore è: %f \n", voto1); 
            } 
            else if (voto2 < voto1) 
            { 
                printf("Il voto minore è: %f \n", voto2); 
            } 
            else
            { 
                printf("I voti sono uguali: %f \n", voto1); 
            }
            break;
        case 4:
            if(voto1 >= 6)
            {
                printf("Il primo voto e SUFFICIENTE: %f \n", voto1);
            }
            else
            {
                printf("I primo voto NON e SUFICIENTI: %f \n",voto1);
            }
            if(voto2 >= 6)
            {
                printf("Il secondo voto e SUFFICIENTE: %f \n", voto2);
            }
             else
            {
                printf("I secondo voto NON e SUFICIENTE: %f \n", voto2);
            }
            break;
        default:
            printf("La SCELTA che hai messo non e disponibile");
            break;
    }

    if(voto1 >=2 && voto1 <=10)
    {
         printf("Il voto %f è compreso tra 2 e 10.\n", voto1);
    }
    else 
    { 
        printf("Il voto %f NON è compreso tra 2 e 10.\n", voto1); 
    }

    if(voto2 >=2 && voto2 <=10)
    {
         printf("Il voto %f è compreso tra 2 e 10.\n", voto2);
    }
    else
    {
         printf("Il voto %f NON e compreso tra 2 e 10.\n", voto2);
    }
    
    return 0;
}