#include <stdio.h>
#include <stdbool.h>

bool incremento_matrice(const size_t lenRiga, const size_t maxLen, int riga[maxLen], const int elemento){
    bool ret = true;
    
    if(lenRiga < maxLen){
        int i = 0;
        while(i < lenRiga) i++;
        riga[i] = elemento / 3;
    } 
    else ret = false;
    
    return ret;
}

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool ret = true;
    
    for(size_t i = 0; i < rows; i++){
        int cont = 0;
        for(size_t j = 0; j < rags[i]; j++){
            if(mat[i][j] > 0 && mat[i][j] % 3 == 0){
                if(incremento_matrice(rags[i], cols, mat[i], mat[i][j])){
                    cont++;
                    rags[i]++;
                }
            }
        }
        if(cont <= 0) ret = false;
    }
    
    return ret;
}