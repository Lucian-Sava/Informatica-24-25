/* PROGGETARE UN ALGORITMO CHE LEGGA UN NUMERO b<a E SCRIVA QUANTE VOLTE a A E' DIVISIBILE PER b
    Es: a=162 e b=3 a è divisibile 4 volte per b
*/
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    int q = 0;
    int r = 0;
    int cnt = 0;

     do{
        printf("Inserisci un numero: ");
        scanf("%d", &a);
        
        printf("Inserisci un secondo numero. ");
        scanf("%d", &b);
    }while(b<a);

    q=a;
    while(q>b && r!=0){
        if(q%b==0){
            r=q%b;
            cnt++;
            q=q/b;
        }
        printf("A ")
    }
    
    return 0;
}