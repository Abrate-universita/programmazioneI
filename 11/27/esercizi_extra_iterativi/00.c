#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
    int ret = 0;
    
    // si considera che tutte le righe siano almeno lunghe quanto rows
    bool condizione1 = true;
    for(size_t i = 0; i < rows && condizione1; i++) condizione1 = rags[i] >= rows;
    
    // se la condizione1 è valida
    if(condizione1){
        for(size_t i = 0; i < rows; i++){
            bool multiplo7 = false;
            for(size_t j = 0; j < rags[i] && !multiplo7; j++){
                if(mat[i][j] % 7 == 0) {
                    multiplo7 = true;
                    ret += mat[i][j];
                }
            } 
        }
    }
    
    return ret;
}