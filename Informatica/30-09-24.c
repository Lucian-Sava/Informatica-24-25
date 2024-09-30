/*Esercizio:
 Calcola il perimetro di un rettangolo dati i valori della base e dell'altezza*/
 #include <stdio.h>
 int main()
 {
    float base, altezza, perimetro;
    printf("Inserisci il valore della base: ");
    scanf("%f",&base);
    printf("Inserisci il valore dell'altezza: ");
    scanf("%f",&altezza);
    perimetro=2*(base+altezza);
    printf("Il valore del perimetro vale: %f", perimetro);
    return 0;
 } 