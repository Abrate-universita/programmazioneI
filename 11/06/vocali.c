#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD 100

bool is_vowel(char c);
bool esistono_vocali(char parola[]);
void stampa_vocali(char parola[]);

int main() {
	char parola[MAX_WORD];
	scanf("%100s", parola);
	
	bool presenza_vocali = false;
	presenza_vocali = esistono_vocali(parola);
	printf("%d\n", presenza_vocali ? 1 : 0);
	
	stampa_vocali(parola);
}

bool is_vowel(char c){
	bool vocale = false;
	
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
	   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		vocale = true;
	
	return vocale;
}

bool esistono_vocali(char parola[]){
	bool ret = false;
	
	for(size_t i = 0; parola[i] != '\0' && !ret; i++)
		ret = is_vowel(parola[i]);
	
	return ret;
}

void stampa_vocali(char parola[]){
	for(size_t i = 0; parola[i] != '\0'; i++){
		bool vocale = false;
		
		vocale = is_vowel(parola[i]);
		
		if(vocale)
			printf("%c", parola[i]);
	}
}