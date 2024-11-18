#include <stdio.h>
#include <stdbool.h>

bool leggi_sequenza(int *somma, int *somma_quadrati, int *max, int n);

int main(void) {
    int somma = 0, somma_quadrati = 0, max = 0, n;
    bool sequenza = true;
    
    scanf("%d", &n);
    while(n != 0){
        while(sequenza){
            sequenza = leggi_sequenza(&somma, &somma_quadrati, &max, n);
            if(n != 0)
                scanf("%d", &n);
        }
        printf("%d %d %d\n", somma, somma_quadrati, max);
        
        somma = 0;
        somma_quadrati = 0;
        max = 0;
        sequenza = true;
        scanf("%d", &n);
    }
}


bool leggi_sequenza(int *somma, int *somma_quadrati, int *max, int n) {
    bool sequenza = true;
    if(n != 0) {
        (*somma) += n;
        (*somma_quadrati) += n * n;
        if(*max < n)
            *max = n;
    }
    else
        sequenza = false;
        
    return sequenza;
}
