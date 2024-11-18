#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVI 7

int main(void)
{
	// Genera un numero pseudo-casuale tra 0 (incluso) e 100 (escluso)
	srand(time(0));
	int numero = rand() % 100;
	int n = -1;

	// VARIANTE 1:
	// Chiedi all'utente di indovinare il numero.
	// L'utente inserisce un intero t come tentativo
	// - Se t è il numero da indovinare, stampa un messaggio e termina
	// - Se t è maggiore del numero da indovinare, stampa un messaggio
	//   appropriato e procedi con un nuovo tentativo
	// - Procedi similmente se t è minore, con un diverso messaggio.
	for(size_t i = 0; i < MAX_TENTATIVI && n != numero; i++) {
		printf("\ninserisci un numero (tra 0 e 100): ");
		scanf("%d", &n);
				
		if(n == numero)
			printf("\nhai indovinato");
		else if(n > numero)
			printf("\ntroppo alto");
		else
			printf("\ntroppo basso");
	}

	// COMPLETA IL CODICE

	// VARIANTE 2:
	// memorizza in una variabile num_tentativi il numero
	// di tentativi che l'utente ha fatto. Quando il numero da indovinare
	// viene trovato, stampa a video il numero di tentativi effettuati.
	puts("");
	puts("");
	int cont = 0;
	numero = rand() % 100;
	n = -1;
	do {
		printf("\ninserisci un numero (tra 0 e 100): ");
		scanf("%d", &n);
		cont++;
		
		if(n == numero)
			printf("\nhai indovinato in %d tentativi", cont);
		else if(n > numero)
			printf("\ntroppo alto");
		else
			printf("\ntroppo basso");
		
	} while(n != numero);

	// VARIANTE 3:
	// Se l'utente supera MAX_TENTATIVI, termina il ciclo e stampa 
	// un messaggio di sconfitta, svelando anche il numero da indovinare.
	puts("");
	puts("");
	n = -1;
	numero = rand() % 100;
	for(size_t i = 0; i < MAX_TENTATIVI && n != numero; i++) {
		printf("\ninserisci un numero (tra 0 e 100): ");
		scanf("%d", &n);
		
		if(n == numero)
			printf("\nhai indovinato");
		else if(n > numero)
			printf("\ntroppo alto");
		else
			printf("\ntroppo basso");
	}
	
	if(n != numero)
		printf("\nhai perso, il numero era: %d", numero);
}
