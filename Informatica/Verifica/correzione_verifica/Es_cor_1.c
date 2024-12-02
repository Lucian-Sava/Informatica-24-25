/*CONTARE IL NUMERO DI CIFRE DI CUI SI COMPONE UN NUMERO DATO E
COMUNICARE QUANTE VOLTE COMPARE LA CIFRA DI VALORE K CHIESTA
ALL’UTENTE.
N.B.: accettare valori che vanno da 0 a 9999
ES: 3 è composto da 1 cifra e supponendo k=5 allora k compare 0 volte, 56 è composto
da 2 cifre e k compare 1 volta*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int num,k=0,cnt=0,resto,quoz,cntk=0;
    num=rand()%10000;
    printf("il numero generato è: %d ",num);
    printf("inserisci una cifra tra 0 e 9");
    scanf("%d", &k);


    if(k>=0 && k<=9){
        resto=num%10;           // Estrae l'ultima cifra {  Puoi fare qualcosa con 'resto' qui num = num / 10; // Rimuove l'ultima cifra }
        if(resto==k){
            cntk++;
        }
        cnt++;
        quoz=num/10;
        if(quoz!=0){            //Verifica se la variabile quoz è diversa da zero. Se quoz è zero, il ciclo termina.
            resto=quoz%10;      //Calcola il resto della divisione di quoz per 10. Questo estrae l'ultima cifra di quoz
            if(resto==k){       //Verifica se resto è uguale a k. Se lo è, incrementa la variabile cntk
                cntk++;         //Incrementa la variabile cnt di 1, che potrebbe essere un contatore generale.
            }
            cnt++;              
            quoz=quoz/10;       //Divide quoz per 10, effettivamente eliminando l'ultima cifra
            if(quoz!=0){
                resto=quoz%10;
                if(resto==k){
                    cntk++;
                }
                cnt++;
                quoz=quoz/10;
                if(quoz!=0){
                    resto=quoz%10;
                    if(resto==k){
                        cntk++;
                    }
                    cnt++;
                    quoz=quoz/10;    
                }   
            } 
        }

        printf("il numero è composto da %d cifre", cnt);
        printf("la cifra %d compare %d volte", k,cntk);
    }else
        printf("hai inserito un valore non valido");


    return 0;
}