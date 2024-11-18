#include <stdio.h>

int main(void) {
	int ora;
	
	printf("inserisci l'ora: ");
	scanf("%d", &ora);
	
	if(ora < 12)
		printf("\nbuongiorno");
	else if(ora < 19)
		printf("\nbuon pomeriggio");
	else if(ora < 22)
		printf("\nbuonasera");
	else
		printf("\nbuonanotte");
}