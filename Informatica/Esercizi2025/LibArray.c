#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libArray.h"

void scambia(int *var1, int *var2){
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void stampaVettore(int vettore[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c", vettore[i], sep);
    }
    printf("\n");
}
void riempiVettore(int vettore[], int dim){
    for(int i=0; i<dim; i++){
        printf("inserici v'elemento in posizione di %d: ", i);
        scanf("%d", &vettore[i]);
    }
}
void riempiVettoreCasuale(int vettore[], int dim, int minimo, int massimo){
    for(int i=0; i<dim; i++){
        vettore[i]=rand()%(massimo-minimo+1)+minimo;
    }
}

int contaOccorrenze(int vettore[], int dim, int valore){
    int cnt=0;

    for(int i=0; i<dim; i++){
        if(vettore[i] == valore){
            cnt++;
        }
    }
    return cnt;
}


int ricercaSequenziale(int *vettore, int dim, int valore){
    for(int i = 0; i<dim; i++){
        if(vettore[i]==valore){
            return i;
        }
    }
    return -1;

}

int ricercaBinaria(int vettore[], int dim, int estInf, int estSup, int valore){
    int media = (estSup+estInf)/2;
    if(estInf > estSup)
        return -1;
    if(vettore[media]== valore)
        return media;
    if(vettore[media] > valore)
        return ricercaBinaria( vettore,dim, estInf, media-1, valore);
    else 
        return ricercaBinaria( vettore,dim, media+1, estSup, valore);
}

void shiftDx (int vett[], int dim, int pos){
    for(int i=dim; i>pos; i--){
        vett[i]=vett[i-1];
    }
}
int trovaPosizione (int vett[], int dim, int num){
    int i=0;
    while(vett[i]<num && i<dim){
        i++;
    }
    return i;
}

void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo) {
    
    int num, pos;
    vett[0] = rand()%(massimo-minimo+1)+minimo;
    for(int i=1; i<dim; i++){
        num = rand()%(massimo-minimo+1)+minimo;
        pos = trovaPosizione(vett, i, num); 
        shiftDx(vett, i, pos);
        vett[pos] = num;
    }
}

void bubbleSort(int vett[], int dim){
    int temp;
    int flag=0;
    int i=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j]>vett[j+1]){
                flag=0;
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
        i++;
    }
}

void selectionSort(int vett[], int dim){
    int min=0;
    int temp=0;
    for(int i=0; i<dim; i++){
        min=i;
       for(int j=i+1; j<dim ;j++){
            if(vett[j]<vett[min]){
                min=j;
            }
       }
       temp=vett[min];
       vett[min]=vett[i];
       vett[i]=temp;

    }
}

void quickSort(int v[], int dim, int inizio, int fine) {
        int i, j, pivot;
       
        if(inizio < fine){
            pivot = inizio;
            i = inizio;
            j = fine;
            
            while(i < j){
                while(v[i] <= v[pivot] && i < fine)
                    i++;
                while(v[j] > v[pivot])
                    j--;
                if(i < j){
                    scambia(&v[i], &v[j]);
                }
            }
            
            scambia(&v[pivot], &v[j]);
            //stampaVettore(v, dim, '\t');
            quickSort(v, dim, inizio, j - 1);
            quickSort(v, dim, j + 1, fine);
        }
    
}