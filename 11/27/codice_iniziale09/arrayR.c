#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// capovolgi gli elementi dell'array a[]
void capovolgi_array(const size_t aLen, int a[]);
void capovolgi_arrayR(const size_t aLen, int a[], const size_t i, const size_t j);

// ritorna true se tutti gli elementi dell'array sono pari
bool tutti_pari(const size_t aLen, const int a[]);
bool tutti_pariR(const size_t aLen, const int a[], const size_t i);

// ritorna la somma di tutti gli elementi dispari dell'array
// ritorna 0 se non ci sono elementi
int somma_elem_dispari(const size_t aLen, const int a[]);
int somma_elem_dispariR(const size_t aLen, const int a[], const size_t i);

// ritorna l'indice dell'elemento più grande dell'array
// se l'array è vuoto, ritornare -1.
size_t indice_elem_massimo(const size_t aLen, const int a[]);
size_t indice_elem_massimoR(const size_t aLen, const int a[], size_t i, size_t ret);

// raddoppia il valore di tutti gli elementi dell'array a[]
void raddoppia_elem(const size_t aLen, int a[]);
void raddoppia_elemR(const size_t aLen, int a[], const size_t i);

// copia in b[] tutti gli elementi di a[] che sono uguali o maggiori di val
// fino alla capacita' massima di b[] passata per puntatore come *p_bLen.
// Al ritorno, il valore puntato da p_bLen viene aggiornato per riflettere
// la dimensione effettiva di b[] (gli elementi effettivamente copiati)
// SUGGERIMENTO: aggiungere due parametri alla funzione ricorsiva:
// - un indice di ricorsione i che scorre l'array a[]
// - un indice j che avanza ogni volta che viene copiato un elemento in b[]
void copia_maggiori_di(const size_t aLen, const int a[],
                       size_t* p_bLen, int b[], const size_t val);
void copia_maggiori_diR(const size_t aLen, const int a[], size_t *p_bLen, int b[], const size_t val, const size_t i, const size_t j);

// modifica in-place l'array a[] mantenendo solo gli elementi compresi
// compresi nell'intervallo chiuso [min, max]. Al ritorno, il valore puntato 
// da p_aLen viene aggiornato al numero di elementi mantenuti in a[].
void filtro_intervallo(size_t* p_aLen, int a[], 
                       const int min, const int max);
void filtro_intervalloR(size_t *p_aLen, int a[], const int min, const int max, const size_t i, const size_t j);
void sposta_valori(const size_t aLen, int a[], const size_t i);
void sposta_valoriR(const size_t aLen, int a[], const size_t i);

//------------------------------------------------------------------

void stampa_array(const size_t aLen, int a[]) {
    for (size_t i=0; i<aLen; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}

//------------------------------------------------------------------


int main(void) {
    #define A1_LEN 9
    int a1[A1_LEN] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    #define A2_LEN 5
    int a2[A2_LEN] = { 16, 8, 24, 22, 6 };

    #define A3_LEN 13
    int a3[A3_LEN] = { 61, 39, 10, 70, 3, 88, 35, 49, 71, 89, 90, 6, 73 };

    puts("Unit test per capovolgi_array:");
    stampa_array(A1_LEN, a1);
    capovolgi_array(A1_LEN, a1);
    stampa_array(A1_LEN, a1);

    puts("\nUnit test tutti_pari:");
    printf("tutti_pari(a1) = %d [atteso: 0]\n", tutti_pari(A1_LEN, a1));
    printf("tutti_pari(a2) = %d [atteso: 1]\n", tutti_pari(A2_LEN, a2));

    puts("\nUnit test per somma elementi dispari:");
    printf("somma_elem_dispari(a1) = %3d [atteso:  16]\n", somma_elem_dispari(A1_LEN, a1));
    printf("somma_elem_dispari(a2) = %3d [atteso:   0]\n", somma_elem_dispari(A2_LEN, a2));
    printf("somma_elem_dispari(a3) = %3d [atteso: 420]\n", somma_elem_dispari(A3_LEN, a3));

    #define MARI_LEN  10
    const char* nomi_mari[MARI_LEN] = {
        "Oceano Atlantico", "Golfo del Messico", "Mar Mediterraneo", 
        "Oceano Artico", "Mar dei Caraibi", "Mare di Bering", 
        "Mar del Giappone", "Oceano Indiano", "Oceano Pacifico", 
        "Mar cinese meridionale", 
    };
    const int profondita_media[MARI_LEN] = { 
        3926, 1486, 1429, 1205, 2647, 
        1547, 1350, 3963, 4028, 1652, 
    };

    puts("\nUnit test per indice_elem_massimo:");
    int a_empty[] = {};
    size_t i_max = indice_elem_massimo(0, a_empty);
    printf("indice_elem_massimo(a_empty) = %3d [atteso:  -1]\n", (int)i_max);

    i_max = indice_elem_massimo(MARI_LEN, profondita_media);
    printf("Maggior profondita' media: '%s' con %d metri.\n",
           nomi_mari[i_max], profondita_media[i_max]);

    puts("\nUnit test per raddoppio elementi:");
    raddoppia_elem(A2_LEN, a2);
    stampa_array(A2_LEN, a2);
    printf("32 16 48 44 12  [atteso]\n");

    puts("\nUnit test per copia elementi:");
    #define BUF1_LEN 10
    int buf1[BUF1_LEN];
    size_t buf1_len = 2;
    copia_maggiori_di(A2_LEN, a2, &buf1_len, buf1, 20);
    stampa_array(buf1_len, buf1);
    printf("32 48    [atteso]\n");

    buf1_len = 8;
    copia_maggiori_di(A2_LEN, a2, &buf1_len, buf1, 20);
    stampa_array(buf1_len, buf1);
    printf("32 48 44 [atteso]\n");

    puts("\nUnit test per filtro intervallo:");
    size_t a3Len = A3_LEN;
    filtro_intervallo(&a3Len, a3, 10, 71);
    stampa_array(a3Len, a3);
    printf("61 39 10 70 35 49 71  [atteso]\n");
}

//------------------------------------------------------------------

// capovolgi gli elementi dell'array a[]
void capovolgi_array(const size_t aLen, int a[]){
	capovolgi_arrayR(aLen, a, aLen, 0);
}

void capovolgi_arrayR(const size_t aLen, int a[], const size_t i, const size_t j){
	if(i == aLen / 2) { }
	else{
		int temp = a[j];
		a[j] = a[i - 1];
		a[i - 1] = temp;
		capovolgi_arrayR(aLen, a, i - 1, j + 1);
	}
}

// ritorna true se tutti gli elementi dell'array sono pari
bool tutti_pari(const size_t aLen, const int a[]){
	return tutti_pariR(aLen, a, 0);
}

bool tutti_pariR(const size_t aLen, const int a[], const size_t i){
	if(i == aLen)
		return true;
	else
		return (a[i] % 2 == 0) && tutti_pariR(aLen, a, i + 1);
}

// ritorna la somma di tutti gli elementi dispari dell'array
// ritorna 0 se non ci sono elementi
int somma_elem_dispari(const size_t aLen, const int a[]){
	return somma_elem_dispariR(aLen, a, 0);
}

int somma_elem_dispariR(const size_t aLen, const int a[], const size_t i){
	if(tutti_pari(aLen, a))
		return 0;
	if(i == aLen)
		return 0;
	else{
		if(a[i] % 2 != 0)
			return a[i] + somma_elem_dispariR(aLen, a, i + 1);
		else
			return somma_elem_dispariR(aLen, a, i + 1);
	}
}

// ritorna l'indice dell'elemento più grande dell'array
// se l'array è vuoto, ritornare -1.
size_t indice_elem_massimo(const size_t aLen, const int a[]){
	return indice_elem_massimoR(aLen, a, 0, 0);
}

size_t indice_elem_massimoR(const size_t aLen, const int a[], size_t i, size_t ret){
	if(i == aLen)
		return (aLen == 0) ? -1 : ret;
	else{
		if(a[ret] < a[i]) ret = i;
		return indice_elem_massimoR(aLen, a, i + 1, ret);
	}
}

// raddoppia il valore di tutti gli elementi dell'array a[]
void raddoppia_elem(const size_t aLen, int a[]){
	raddoppia_elemR(aLen, a, 0);
}

void raddoppia_elemR(const size_t aLen, int a[], const size_t i){
	if(i == aLen) {}
	else{
		a[i] = a[i] * 2;
		raddoppia_elemR(aLen, a, i + 1);
	}
}

// copia in b[] tutti gli elementi di a[] che sono uguali o maggiori di val
// fino alla capacita' massima di b[] passata per puntatore come *p_bLen.
// Al ritorno, il valore puntato da p_bLen viene aggiornato per riflettere
// la dimensione effettiva di b[] (gli elementi effettivamente copiati)
// SUGGERIMENTO: aggiungere due parametri alla funzione ricorsiva:
// - un indice di ricorsione i che scorre l'array a[]
// - un indice j che avanza ogni volta che viene copiato un elemento in b[]
void copia_maggiori_di(const size_t aLen, const int a[], size_t* p_bLen, int b[], const size_t val){
	copia_maggiori_diR(aLen, a, p_bLen, b, val, 0, 0);
}

void copia_maggiori_diR(const size_t aLen, const int a[], size_t *p_bLen, int b[], const size_t val, const size_t i, const size_t j){
	if(i == aLen || j == *p_bLen)
		*p_bLen = j;
	else{
		if(a[i] >= val){
			b[j] = a[i];
			copia_maggiori_diR(aLen, a, p_bLen, b, val, i + 1, j + 1);
		}
		else
			copia_maggiori_diR(aLen, a, p_bLen, b, val, i + 1, j);
	}
}

// modifica in-place l'array a[] mantenendo solo gli elementi compresi
// compresi nell'intervallo chiuso [min, max]. Al ritorno, il valore puntato 
// da p_aLen viene aggiornato al numero di elementi mantenuti in a[].
void filtro_intervallo(size_t* p_aLen, int a[], const int min, const int max){
	filtro_intervalloR(p_aLen, a, min, max, 0, *p_aLen);
}

void filtro_intervalloR(size_t *p_aLen, int a[], const int min, const int max, const size_t i, const size_t j){
	if(i == *p_aLen || i == j)
		*p_aLen = j;
	else{
		if((a[i] >= min) && (a[i] <= max))
			filtro_intervalloR(p_aLen, a, min, max, i + 1, j);
		else{
			sposta_valori(*p_aLen, a, i);
			filtro_intervalloR(p_aLen, a, min, max, i, j - 1);
		}
	}
}

void sposta_valori(const size_t aLen, int a[], const size_t i){
	sposta_valoriR(aLen, a, i);
}

void sposta_valoriR(const size_t aLen, int a[], const size_t i){
	if(i == aLen - 1) {}
	else {
		int temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
		sposta_valoriR(aLen, a, i + 1);
	}
}

//------------------------------------------------------------------
