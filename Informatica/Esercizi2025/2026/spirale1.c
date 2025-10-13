#include <stdio.h>
#include <stdlib.h>

void RiempiSpirale(int n, int m, int matrix[n][m]) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
}

int main(){
    int n, m;
    printf("Inserisci il numero di righe: ");
    scanf("%d", &n);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &m);

    int matrix[n][m];
    RiempiSpirale(n, m, matrix);

    printf("Matrice in ordine spirale:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}