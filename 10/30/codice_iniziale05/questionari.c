#include <stdio.h>

#define NUM_RISP 20 // numero risposte al questionario
#define lenFrequenze 5 // numero di possibili frequenze diverse

int main() {
	// valori delle risposte ai questionari
	const int risposte[NUM_RISP] = {
		1, 2, 5, 4, 3,  5, 2, 1, 3, 1, 
		4, 3, 3, 3, 2,  3, 3, 2, 2, 5 
	};

	// calcola le frequenze delle risposte
	int frequenze[lenFrequenze];
	
	// imposto il vettore a un vettore vuoto
	for(size_t i = 0; i < lenFrequenze; i++)
		frequenze[i] = 0;
	
	// conto il numero delle frequenze
	for(size_t i = 0; i < NUM_RISP; i++)
		frequenze[(risposte[i] - 1)]++;
	
	printf("\nStelle   Frequenze\n");
	// stampo il risultato
	for(size_t i = 0; i < lenFrequenze; i++){
		printf("%Iu        %d       ", i + 1, frequenze[i]);
		
		for(size_t j = 0; j < frequenze[i]; j++)
			printf("#");
		
		printf("\n");
	}
}
