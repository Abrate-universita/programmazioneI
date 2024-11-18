#include <stdio.h>
#define NMAX  10

// copia in b (capacità bCap) tutti gli elementi 
// dell'array a (dimensione aLen) seguendo le regole.
// Aggiorna *p_bLen con il numero di elementi copiati.
void trasforma_array(const size_t aLen, const int a[],
                     size_t *p_bLen, const size_t bCap, int b[])
{
    *p_bLen = 0;
    for(size_t i = 0; i < aLen && *p_bLen < bCap; i++){
        if(a[i] >= 10){
            if(a[i] % 2 == 0){
                if(a[i] % 4 == 0){
                    for(size_t j = 0; j < 4 && *p_bLen < bCap; j++){
                        b[*p_bLen] = a[i];
                        (*p_bLen)++;
                    }
                }
                else if(a[i] % 4 != 0){
                    for(size_t j = 0; j < 2 && *p_bLen < bCap; j++){
                        b[*p_bLen] = a[i];
                        (*p_bLen)++;
                    }
                }
                else{
                    b[*p_bLen] = a[i];
                    (*p_bLen)++;
                }
            }
            else if(a[i] % 3 != 0) {
                b[*p_bLen] = a[i];
                (*p_bLen)++;
            }
        }
    }
}

//------------------------------------------------------------------
// stampa gli elementi dell'array a[] (di dimensione aLen)
void stampa_array(const size_t aLen, const int a[]) 
{
    printf("len=%zu: [ ", aLen);
    for (size_t i=0; i<aLen; i++) {
        printf("%d ", a[i]);
    }
    printf("]\n");
}

//------------------------------------------------------------------
// leggi da standard input un array, riempi il buffer a[]
// di capacità aCap, e aggiorna *p_aLen con il numero 
// di elementi letti
void leggi_array(size_t *p_aLen, const size_t aCap, int a[]) 
{
    size_t j = 0, num;
    scanf("%zu", &num); // numero di elementi da leggere
    for (size_t i=0; i<num; i++) {
        int elem;
        scanf("%d", &elem);
        if (j < aCap) {
            a[j] = elem;
            j++;
        }
    }
    *p_aLen = j;
}

//------------------------------------------------------------------
int main(void) {
    int a[NMAX], b[NMAX]; 
    size_t aLen=0, bLen=0;
    leggi_array(&aLen, NMAX, a); 
    trasforma_array(aLen, a, &bLen, NMAX, b); 
    stampa_array(bLen, b);
}

//------------------------------------------------------------------
