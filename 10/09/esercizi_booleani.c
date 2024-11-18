#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d%d", &a, &b);

    // a) dati i due interi a e b, stampa 1 se il primo intero 
    //    è multiplo del secondo, 0 altrimenti;
	printf("\na e' multiplo di b -> %d", b % a == 0 ? 1 : 0);

    // b) dato l'intero a (un voto), stampa "true" se a 
    //    è compreso fra 1 e 30 (inclusi), "false" altrimenti;
	printf("\n\ninserisci un voto: ");
	scanf("%d", &a);
	printf("\nil voto e' compreso fra 1 e 30 (inclusi) -> %s", (a >= 1 && a <= 30) ? "true" : "false");

    bool b1 = a > 10;
    bool b2 = b <= 5;
    // c) dati i due booleani b1 e b2, stampa a video il booleano 
    //    "false" se b1 e b2 sono entrambi veri, "true" altrimenti;
	printf("\n\n%d e %d -> %s", b1, b2, b1 && b2 ? "false" : "true");

    // d) dati i due interi a e b, stampa a video il massimo; se sono 
    //    uguali stampa a video "I due valori sono uguali".
	printf("\n\nInserisci due numeri: ");
    scanf("%d%d", &a, &b);
	
	if(a == b)
		printf("\ni due valori sono uguali");
	else
		printf("\n%d", a > b ? a : b);

    int c = 20;
    // e) dati tre interi a, b e c, stampa a video il massimo 
    //    (si usi una variabile di supporto max);
	int max = 0;
	if(a > b && a > c)
		max = a;
	else if(b > a && b > c)
		max = b;
	else
		max = c;
	
	printf("\n\nil valore massimo e' %d", max);

    // f) dati tre interi a, b e c, stampa a video "ordinati" se questi sono 
    //    ordinati in modo crescente, altrimenti non stampare nulla.
	printf("\n\n%s", a < b && b < c ? "ordinati" : "");
}
