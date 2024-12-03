#include <stdio.h>
#include <stdbool.h>

bool presenza_r(const size_t lenRiga, const int riga[lenRiga], const int elemento){
    bool presenza = false;
    
    for(size_t j = 0; j < lenRiga && !presenza; j++)
        if(riga[j] == elemento) presenza = true;
    
    return presenza;
}

void cancella_elemento(const size_t rows, size_t rags[rows], const size_t i, int riga[rags[i]], const size_t j){
    if(j + 1 < rags[i]){
        for(size_t k = j; k < rags[i]; k++){
            int temp = riga[k];
            riga[k] = riga[k + 1];
            riga[k + 1] = temp;
        }
    }
    rags[i]--;
}

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows])
{
    bool ret = false;
    
    for(size_t i = 1; i < rows; i++){
        for(size_t j = 0; j < rags[i]; j++){
            bool presenza = presenza_r(rags[i - 1], mat[i - 1], mat[i][j]);
            if(presenza) {
                cancella_elemento(rows, rags, i, mat[i], j);
                j--;
            }
            
            if(presenza && !ret) ret = true;
        }
    }
    
    return ret;
}