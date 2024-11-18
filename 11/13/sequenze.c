#include <stdio.h>
#include <stdbool.h>

#define NMAX 50
int main(void) {
    //recupero la lunghezza di A
    int len_a = 0;
    scanf("%d", &len_a);
    
    // definisco l'array a e ne recupero i valori
    int a[len_a];
    for(size_t i = 0; i < len_a; i++) scanf("%d", &a[i]);
    
    // recupero il massimo numero di errori consentiti
    int max_errori;
    scanf("%d", &max_errori);
    
    int len_b = 0;
    
    do{
        // recupero la lunghezza di b
        scanf("%d", &len_b);
        
        // definisco l'array b e ne recupero i valori
        int b[len_b];
        for(size_t i = 0; i < len_b; i++) scanf("%d", &b[i]);
        
        size_t right = 0;
        size_t left = 0;
        bool match = true, match2 = false;
        if(len_b > 0){
            for(left = 0; left <= (len_b - len_a) && !match2; left++){
                int cont = 0;
                match = true;
                // printf("%zu e %zu", left, right);
                for(right = 0; right < len_a; right++){
                    // printf("%zu e %zu\n%d\n", left, right, b[left + right]);
                    if(b[left + right] != a[right]){
                        cont++;
                    }
                    
                    match = (cont <= max_errori);
                }
                if(match) {
                    printf("[%zu, %zu) errori=%d\n", left, left + right, cont);
                    match2 = true;
                }
            }
            if(!match2)
                printf("NO\n");
        }
    }while(len_b != 0);
}