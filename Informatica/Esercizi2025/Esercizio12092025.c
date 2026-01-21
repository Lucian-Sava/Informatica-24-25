/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/
#include <stdio.h>
#define N 3  // Dimensione della matrice quadrata

void scambia_diagonali(int mat[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        int temp = mat[i][i];           // salva l'elemento della diagonale principale
        mat[i][i] = mat[i][N - 1 - i];  // sostituisce con quello della diagonale secondaria
        mat[i][N - 1 - i] = temp;       // mette quello salvato nella diagonale secondaria

                                        /*
                                        mat[i][i]→ elemento della diagonale principale
                                        mat[i][N - 1 - i]→ elemento della diagonale secondaria
                                        */
    }
}

void stampa_matrice(int mat[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() { //stampa la matrice con una fonzione stampa_matrice
    int matrice[N][N] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matrice originale:\n");
    stampa_matrice(matrice);

    scambia_diagonali(matrice);

    printf("\nMatrice dopo lo scambio delle diagonali:\n");
    stampa_matrice(matrice);

    return 0;
}