#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    int max = INT_MIN;
    bool ret = true;
    
    for(size_t i = 0; i < rows && ret; i++){
        int somma = 0;
        // controlla che venga eseguita almeno un'iterazione
        bool riga_non_zero = false;
        // controllo che la riga non sia 0
        for(size_t j = 0; j < rags[i] && rags[i] > 0 && ret; j++){
            somma += mat[i][j];
            riga_non_zero = true;
        }
        if(somma % k != 0)
            ret = false;
        if(ret && max < somma && riga_non_zero)
            max = somma;
    }

    if(max == INT_MIN) ret = false;
    if(ret) *pMaxSum = max;
    return ret;
}