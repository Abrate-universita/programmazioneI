#include <stdio.h>
#include <stdbool.h>

// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
#   define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}


int main(void) {
    char parola_input[50];
    scanf("%50s", parola_input);
    
    char parola_risultato[50];
    int len_parola_risultato = 0;
    
    for(size_t i = 0; parola_input[i] != '\0'; i++){
        if(!is_vowel(parola_input[i])){
            parola_risultato[len_parola_risultato] = parola_input[i];
            len_parola_risultato++;
        }
    }
    
    printf("%s", parola_risultato);
}
