/*Scrivi un programma in C che disegni usando degli asterischi * un triangolo rettangolo di lato 8 e poi un triangolo isoscele di base 9 e altezza 9.*/
#include <stdio.h>
int main()
{
    for(int i=0; i < 9; i++)
    {   //stampo lo spazio per centrare il triangolo
        for(int j = 0; j < 9 - i; j++)
            printf(" ");
        {   // stampo gli asterischi per formare i bordi del triangolo
            for(int j = 0; j <= i; j++) 
                if(j == 0 || j == i || i== 8)
                    printf(" *");
                else
                    printf("  ");
        }
        printf("\n");
    }
}