/* Data una stringa scriverla all'inverso */

#include <stdio.h>
#include <string.h>

void invertiStringa(char *str) {
    int frase = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = frase - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char Stringa[150];
    printf("Inserisci una frase: ");
    scanf("%s", Stringa);
    
    invertiStringa(Stringa);
    printf("Stringa invertita: %s\n", Stringa);
    
    return 0;
}