#include <stdio.h>

int main(void) {
	int n1, n2;
	
	printf("\ninserisci il valore n1: ");
	scanf("%d", &n1);
	
	printf("\ninserisci il valore n2: ");
	scanf("%d", &n2);
	
	printf("\nil valore della somma fra n1 e n2 e' %d", n1 + n2);
	
	printf("\nprodotto: %d", n1 * n2);
	printf("\ndivisione intera: %d", n1 / n2);
	printf("\ndivisione reale: %f", (double) n1 / n2);
	printf("\nil resto della divisione intera: %d", n1 % n2);
}