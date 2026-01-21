/* Verificare se un numero dato in input è divisibile sia per 3 sia per 5 */
#include <stdio.h>
int main()
{
    int A;
    A=0;
    printf("Inserisci il primo valore: ");
    scanf("%d", &A);
    if(A % 3 == 0 && A % 5 == 0)
    {
        printf("Il numero %d e divisibile per 3 sia per 5.\n", A);
    }
    else
    {
        printf("Il numero %d non e divisibile per 3 sia per 5.\n", A);
    }
    return 0;
}
/* if (a % 3 == 0)
{
    if (a % 5 == 0)
    {
    printf("%d è divisibile sia per 3 sia per 5",a);
    }
    else
    {
    printf("5d è divisibile per 3 ma non per 5",a);
    }
}
else
{
    printf("%d non è divisibile per 3",a);
}
*/