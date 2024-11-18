#include <stdio.h>

int main(void) {
    // esercizio 1
    printf("riga 1\n");
    printf("riga 2\n");

    // esercizio 2
    printf("riga 1\n riga 2\n");

    // esercizio 3
    int n1, n2;

    printf("\nscrivi due numeri che ti piacciono -> ");
    scanf("%d %d", &n1, &n2);
    printf("\necco i tuoi numeri -> %d %d", n1, n2);

    //esercizio 4
    printf("\nla loro somma e' -> %d", n1 + n2);

    // esercizio 5
    int x = 5, y = 8, z = 11;

    printf("\nil prodotto di %d * %d * %d = %d", x, y, z, x * y * z);
}