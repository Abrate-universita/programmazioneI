#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PERS 24

// I nomi dei soggetti fermati
const char* nomi[NUM_PERS] = {
    "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
    "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
    "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred", 
};

// Gli attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
    "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
    "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
    "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz", 
};

void contains(char lettera_indizio, bool sospettati[]);
void not_contains(char lettera_indizio, bool sospettati[]);

int main(void) {
    // vettore booleano per tracciare i sospettati validi
	// all'inizio sono tutti sospettati validi
    bool sospettati[NUM_PERS];
    for(size_t i = 0; i < NUM_PERS; i++) {
        sospettati[i] = true;
    }
	
	// stringa che contiene gli indizi
	char indizi[15];
	scanf("%15s", indizi);
	
	for(size_t i = 0; indizi[i] != '\0'; i++){
		if(isupper(indizi[i]))
			// se e' maiuscola la trasformo in minuscola e poi controllo
			not_contains(tolower(indizi[i]), sospettati);
		else
			contains(indizi[i], sospettati);
	}
	
	// creo un contatore che conta quanti sospettati vengono stampati per poi restituire il numero
	int cont = 0;
	for(size_t i = 0; i < NUM_PERS; i++)
		// se nel vettore di bool il sospettato e' ancora a vero
		// allora posso stampare lo stesso nome nella stessa posizione
		if(sospettati[i]){
			printf("%s\n", nomi[i]);
			cont++;
		}
	printf("%d", cont);
}

/*
	per capire:
		strchr() è una funzione che prende come parametri una stringa e un carattere
		restituisce un puntatore vuoto (NULL) se non trova il carattere
		altrimenti restituisce un puntatore che punta a quell'area di memoria
		
	se io controllo che il sospettato sia ancora valido (non ancora escluso)
	e controllo anche che la stringa sia presente o non presente (in base a maiuscola o minuscola)
	allora posso eliminare in modo semplice i sospettati non validi
*/

void contains(char lettera_indizio, bool sospettati[]){
	for(size_t i = 0; i < NUM_PERS; i++){
		// se il sospettato e' ancora a true e la lettera_indizio compare non all'interno degli attributi di quella persona
		if(sospettati[i] && strchr(attributi[i], lettera_indizio) == NULL)
			sospettati[i] = false;
	}
}

void not_contains(char lettera_indizio, bool sospettati[]){
	for(size_t i = 0; i < NUM_PERS; i++)
		if(sospettati[i] && strchr(attributi[i], lettera_indizio) != NULL)
			sospettati[i] = false;
}