#include <stdio.h>

#define len_alfabeto 27
#define ascii_A 65

int main(void) {
	char alfabeto[len_alfabeto];
	
	for(size_t i = 0; i < len_alfabeto - 1; i++)
		alfabeto[i] = ascii_A + i;
	
	alfabeto[len_alfabeto - 1] = '\0';
	
	for(size_t i = 0; i < len_alfabeto; i++)
		printf("%c\n", alfabeto[i]);
}