#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
				              int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}



int main(void) {
	// leggi la matrice irregolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q, from, to;
	scanf("%zu", &q);
	
	/*
	per capire:
	leggo 0 e 1 e cerco nella riga 0 il valore 1, lo trovo e scrivo "DIRETTO"
	leggo 2 e 4 e cerco nella riga 2 il vlaore 4, non lo trovo e allora cerco nella riga 0 e 1 (valori della riga 2) il valore 4, lo trovo e scrivo "UN CAMBIO"
	leggo 0 e 3 e cerco nella riga 0 il valore 3, non lo trovo e allora cerco nella riga 1 e 2 (valori della riga 0) il valore 3, non lo trovo e scrivo "NO"
	*/
	
	// scorro finchè non arrivo a q
	for(size_t i = 0; i < q; i++){
	    // recupero i valori from e to
	    scanf("%zu %zu", &from, &to);
	    // scorro la riga from cercando il valore to
	    bool diretto = false;
	    for(size_t j = 0; j < rags[from] && !diretto; j++){
	        if(to == mat[from][j]) diretto = true;
	    }
	    // se ho trovato uno scambio diretto restituisco quello e sono a posto
	    if(diretto) printf("DIRETTO\n");
	    // se non ho trovato un valore diretto lo cerco nelle righe dei valori della riga from
	    else{
	        bool cambio = false;
	        for(size_t j = 0; j < rags[from] && !cambio; j++){
	            // scorro la riga di indice: valore j della riga from
	            for(size_t k = 0; k < rags[mat[from][j]] && !cambio; k++){
	                if(to == mat[mat[from][j]][k]) cambio = true;
	            }
	        }
	        // se ho trovato uno scambio lo dico altrimenti rispondo no
	        printf("%s\n", cambio ? "UN CAMBIO" : "NO");
	    }
	}
}
