#include <stdio.h>

int main(void) {
	int n;
	
	printf("inserisci un numero n: ");
	scanf("%d", &n);
	
	printf("\na salire\n");
	for(size_t i = 0; i <= n; i++)
		printf("%Iu\n", i);
	
	printf("\na scendere\n");
	for(int i = n; i >= 0; i--)
		printf("%d\n", i);
		
	printf("\nsolo dispari a salire\n");
	for(size_t i = 1; i <= n; i += 2)
		printf("%Iu\n", i);
	
	size_t fattoriale = 1;
	for(size_t i = 1; i <= n; i++)
		fattoriale *= i;
	printf("\nfattoriale: %Iu", fattoriale);
}