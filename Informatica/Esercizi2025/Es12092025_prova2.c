/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/
#include <stdio.h>
#define N 3  // Dimensione della matrice quadrata

void stampa_matrice(int mat[3][3])
{
    for(int i=0; i< N; i++)
    {
        for(int j=0; j< N; j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrice[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matrice originale:\n");
    stampa_matrice(matrice);

    // scmbio delle diagonali
    for (int i = 0; i < N ; i++)
    {
        int temp = matrice[i][i];
        matrice[i][i] = matrice[i][N - 1 - i];
        matrice[i][N - 1 - i] = temp;
    }

    printf("\nMatrice dopo lo scambio delle diagonali:\n");
    stampa_matrice(matrice);

    return 0;
}