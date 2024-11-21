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
	// leggi la matrice irregolare A
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	// leggi la matrice irregolare B
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

    bool prefisso = true;
	for(size_t i = 0; i < rowsA; i++){
        for(size_t k = 0; k < rowsB; k++){
            prefisso = true;
	        for(size_t j = 0; j < ragsA[i] && ragsA[i] <= ragsB[i] && prefisso; j++)
                if(matA[i][j] != matB[k][j]) prefisso = false;
            if(prefisso && ragsA[i] <= ragsB[i])
            printf("%zu %zu\n", i, k);
        }
	}
}