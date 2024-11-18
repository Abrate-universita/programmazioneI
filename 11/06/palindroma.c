#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50

bool valida_palindroma(char parola[]);
void rovescia(char src[], char dst[]);

int main(void) {
    char parola[WORD_MAX];
    scanf("%50s", parola);
    
    bool palindroma;
    
    palindroma = valida_palindroma(parola);
    
    char dst[WORD_MAX];
    if(!palindroma){
        rovescia(parola, dst);
        printf("%s %s", parola, dst);
    }
}

bool valida_palindroma(char parola[]){
    bool palindroma = true;
    size_t j = strlen(parola) - 1;
    
    for(size_t i = 0; i < strlen(parola) && palindroma; i++, j--){
        if(parola[i] != parola[j])
            palindroma = false;
    }
    
    if(palindroma)
        printf("PALINDROMA\n");
        
    return palindroma;
}

void rovescia(char src[], char dst[]){
    size_t j = strlen(src) - 1;
    
    for(size_t i = 0; i < strlen(src); i++, j--)
        dst[i] = src[j];
}