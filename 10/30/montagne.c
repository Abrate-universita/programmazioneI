#include <stdio.h>
#include <string.h>

int main(void) {
	// montagna e altezza in input
    char montagna[50];
    int altezza;
    
	// montagna e altezza piu' alta
    char montagna_max[50];
    int altezza_max = 0;
    
	// scorro finché gli input sono due 
    while(2 == scanf("%50s %d", montagna, &altezza)) {
        if(altezza > altezza_max) {
            altezza_max = altezza;
            strcpy(montagna_max, montagna);
        }
    }
    
    printf("%s", montagna_max);
}