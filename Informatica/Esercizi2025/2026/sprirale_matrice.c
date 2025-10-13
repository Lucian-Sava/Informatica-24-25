#include <stdio.h>
#define N 4

void riempimatrice(int matrice[][N])
{
    int num=1;
    int top= 0, bottom = N - 1;
    int left = 0, right = N - 1;

    while(num <= N*N)
    {
        //sinistra verso destra
        for(int i=left; i<=right; i++)
        {
            matrice[top][i] = num++;
        }
        top++;
        //alto verso basso
        for(int i=top; i<=bottom; i++)
        {
            matrice[i][right] = num++;
        }
        right--;
        //destra verso sinistra
        for(int i=right; i<=left; i--)
        {
            matrice[bottom][i] = num++;
        }
        bottom--;
        //basso verso alto
        for(int i=bottom; i>=top; i--)    
        {
            matrice[i][left] = num++;
        }
        left++;
    }
}

void stampamatrice(int matrice[][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int matrice[N][N];

    riempimatrice(matrice);
    printf("La matrice a spirale e':\n");
    stampamatrice(matrice);
    return 0;
}