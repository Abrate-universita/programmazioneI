#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int x1, x2, x3;
	
	printf("inserisci tre numeri: ");
	scanf("%d %d %d", &x1, &x2, &x3);

	int scelta;
	printf("\ninserisci un numero 1, 2 o 3 per:");
	printf("\n1) calcolare la somma");
	printf("\n2) calcolare il prodotto");
	printf("\n3) calcolare la media\n");
	scanf("%d", &scelta);
	
	bool successo = scelta != 1 || scelta != 2 || scelta != 3;
		
	if(!successo)
		printf("\nerrore, scelta non corretta");
	else {
		if(scelta == 1)
			printf("\nsomma -> %d", x1 + x2 + x3);
		else if(scelta == 2)
			printf("\nprodotto -> %d", x1 * x2 * x3);
		else
			printf("\nmedia -> %f", (double) (x1 + x2 + x3) / 3);
	}
}