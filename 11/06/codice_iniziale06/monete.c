#include <stdio.h>


int main(void) {
	// Chiedi all'utente la somma da convertire
	int cent;
	printf("Scrivere l'ammontare da convertire in monete: ");
	scanf("%d", &cent);

	// Definiamo i tagli delle monete
#	define NUM_TAGLI 6
	const int tagli_monete[NUM_TAGLI] = {1,2,5,10,20,50};

	int i = NUM_TAGLI - 1;
	int moneta = tagli_monete[i];
	int cont = 0;
	// COMPLETARE
	while(cent > 0){
		if(moneta <= cent) {
			cent -= moneta;
			cont++;
			if(cent == 0 && cont > 0)
				printf("\n%d da %d cent", cont, moneta);
		}
		else {
			if(cont > 0)
				printf("\n%d da %d cent", cont, moneta);
			i--;
			moneta = tagli_monete[i];
			cont = 0;
		}
		
	}
}