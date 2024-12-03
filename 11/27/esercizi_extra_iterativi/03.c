#include <stdio.h>
#include <stdbool.h>

int prodotto_riga_array(const int lenRiga, const int riga[lenRiga], const int aLen, const int a[aLen]){
    int ret = 0;
    
    int i = 0;
    while(i < lenRiga && i < aLen){
        ret += riga[i] * a[i];
        i++;
    }
    
    return ret;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    bool ret = false;
    *pSum = 0;
    
    for(size_t i = 0; i < rows; i++){
        int p_riga_array = prodotto_riga_array(rags[i], mat[i], aLen, a);
        if(p_riga_array > 0 && p_riga_array % 5 == 0){
            ret = true;
            *pSum += p_riga_array;
        }
    }
    
    return ret;
}