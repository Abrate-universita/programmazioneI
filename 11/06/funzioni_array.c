#include <stdio.h>
#include <stdbool.h>

void leggi_array(int len, int arr[]);
int conta_univoci(int len, int arr[]);
void stampa_elementi_ripetuti(int len1, int arr1[], int len2, int arr2[]);

int main(void) {
    int n;
    int cont;
    
    scanf("%d", &n);
    int arr[n];

    leggi_array(n, arr);
    cont = conta_univoci(n ,arr);
    printf("%d ", cont);
    
    int m;
    scanf("%d", &m);
    int arr2[m];
    leggi_array(m, arr2);
    cont = conta_univoci(m, arr2);
    printf("%d\n", cont);
    
    stampa_elementi_ripetuti(n, arr, m, arr2);
}

void leggi_array(int len, int arr[]){
    int n;
    
    for(size_t i = 0; i < len; i++){
        scanf("%d", &n);
        arr[i] = n;
    }
}

int conta_univoci(int len, int arr[]){
    int cont = 0;
    
    for(size_t i = 0; i < len; i++){
        bool univoco = true;
        for(size_t j = 0; j < len; j++){
            if(arr[i] == arr[j] && i != j)
                univoco = false;
        }
        if(univoco)
            cont++;
    }
    
    return cont;
}

void stampa_elementi_ripetuti(int len1, int arr1[], int len2, int arr2[]){
    for(size_t i = 0; i < len1; i++){
        for(size_t j = 0; j < len2; j++)
            if(arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                j = len2;
            }
    }
}