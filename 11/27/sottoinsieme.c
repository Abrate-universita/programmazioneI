#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni (solo gli involucri)
//------------------------------------------------------------------

void leggi_array(const size_t aLen, int a[]);
void leggi_arrayR(const size_t aLen, int a[], const size_t i);

int somma_array(const size_t aLen, int a[]);
int somma_arrayR(const size_t aLen, const int a[], const size_t i);

bool esiste_val_in_array(const size_t aLen, const int a[], int val);
bool esiste_val_in_arrayR(const size_t aLen, const int a[], int val, const size_t i);


bool sottoinsieme(const size_t aLen, const int a[], const size_t bLen, const int b[]);
bool sottoinsiemeR(const size_t aLen, const int a[], const size_t bLen, const int b[], const size_t i);

//------------------------------------------------------------------

int main(void) {
	size_t aLen, bLen;

	scanf("%zu", &aLen);
	int a[aLen];
	leggi_array(aLen, a);

	scanf("%zu", &bLen);
	int b[bLen];
	leggi_array(bLen, b);

	printf("%d %d\n", somma_array(aLen, a), somma_array(bLen, b));

	printf("%d %d\n", 
		   sottoinsieme(aLen, a, bLen, b),
		   sottoinsieme(bLen, b, aLen, a));
}

//------------------------------------------------------------------

// lettura input
void leggi_array(const size_t aLen, int a[]) { 
	leggi_arrayR(aLen, a, 0);
}

void leggi_arrayR(const size_t aLen, int a[], size_t i) {
    if(i == aLen) {}
    else{
        scanf("%d", &a[i]);
        leggi_arrayR(aLen, a, i + 1);
    }
}

// somma
int somma_array(const size_t aLen, int a[]){
    return somma_arrayR(aLen, a, 0);
}

int somma_arrayR(const size_t aLen, const int a[], const size_t i){
    if(i == aLen)
        return 0;
    else
        return a[i] + somma_arrayR(aLen, a, i + 1);
}

// esiste
bool esiste_val_in_array(const size_t aLen, const int a[], int val){
    return esiste_val_in_arrayR(aLen, a, val, 0);      
}

bool esiste_val_in_arrayR(const size_t aLen, const int a[], int val, const size_t i){
    if(i == aLen)
        return false;
    else 
        return (a[i] == val) || esiste_val_in_arrayR(aLen, a, val, i + 1);
}

// sottoinsieme
bool sottoinsieme(const size_t aLen, const int a[], const size_t bLen, const int b[]){
    return sottoinsiemeR(aLen, a, bLen, b, 0);
}

bool sottoinsiemeR(const size_t aLen, const int a[], const size_t bLen, const int b[], const size_t i){
    if(i == aLen)
        return true;
    else {
        return esiste_val_in_array(bLen, b, a[i]) && sottoinsiemeR(aLen, a, bLen, b, i + 1);
    }
}