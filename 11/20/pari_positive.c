#include <stdio.h>
#include <stdbool.h>

void leggi_matrice(const size_t rows, const size_t cols,
				   int mat[rows][cols]) 
{
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

bool riga_pari_positiva(const size_t cols, int v[cols]){
    bool pari_positiva = true;
    
    for(size_t i = 0; i < cols && pari_positiva; i++){
        if((v[i] % 2 != 0) || (v[i] < 0)) pari_positiva = false;
    }
        
    return pari_positiva;
}

void colonna_pari_positiva(const size_t rows, const size_t cols, int mat[rows][cols], const size_t riga_pp){
    bool pari_positiva = true;
    
    for(size_t i = 0; i < cols; i++){
        pari_positiva = true;
        for(size_t j = 0; j < rows && pari_positiva; j++){
            if((mat[j][i] % 2 != 0) || (mat[j][i] < 0)) {
                pari_positiva = false;
            }
        }
        if(pari_positiva)
            printf("%zu %zu\n", riga_pp, i);
    }
}

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);

	for(size_t i = 0; i < rows; i++){
        if(riga_pari_positiva(cols, mat[i]))
            colonna_pari_positiva(rows, cols, mat, i);
	}
}