#include <stdio.h>

int main(void) {
	int somma = 0;
	int n;
	
	while(1 == scanf("%d", &n) && n != 0)
		somma += n;
	
	printf("\nsomma: %d", somma);
}