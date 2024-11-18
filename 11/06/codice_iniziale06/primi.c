#include <stdio.h>
#include <stdbool.h>

// Prototipo della funzione:
bool verifica_primalita(int n);


int main(void) {
	bool primo = false;
	// stampa i numeri primi minori di 100
	for(size_t i = 1; i < 100; i++){		
		// Chiama la funzione dichiarata
		primo = verifica_primalita(i);
	
		if(primo)
			printf("%Iu  ", i);
	}
}


// Implementazione della funzione verifica_primalita()
// ritorna true se n è primo, false altrimenti
// ritorna sempre false per qualsiasi n < 2
bool verifica_primalita(int n) {
	bool primo = true;
	size_t i = 2;
	
	while(i < n - 1 && primo){
		primo = (n % i != 0);
		i++;
	}
	
	return primo;
}