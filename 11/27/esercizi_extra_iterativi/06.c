#include <stdio.h>
#include <stdbool.h>

bool max_riga(const size_t lenRiga, const int riga[lenRiga], const int elemento){
    bool ret = true;
    
    for(size_t i = 0; i < lenRiga && ret; i++)
        if(riga[i] > elemento) ret = false;
        
    return ret;
}

bool min_colonna(const size_t rows, const size_t cols, const int mat[rows][cols], const int elemento, const size_t j){
    bool ret = true;
    
    for(size_t i = 0; i < rows; i++)
        if(elemento > mat[i][j]) ret = false;
        
    return ret;
}

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
    bool ret = true;
    
    for(size_t i = 0; i < rows; i++){
        bool elemento_sella = false;
        for(size_t j = 0; j < cols; j++){
            if(max_riga(cols, mat[i], mat[i][j]) && min_colonna(rows, cols, mat, mat[i][j], j)){
                printf("%zu %zu\n", i, j);
                elemento_sella = true;
            }
        }
        if(!elemento_sella) ret = false;
    }
    
    return ret;
}