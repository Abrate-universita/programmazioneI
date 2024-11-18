#include <stdio.h>

int main(void) {
	double sommatoria = 0;
	int cont = 0;
	int n;
	
	while(1 == scanf("%d", &n) && n != 0) {
		sommatoria += n;
		cont++;
	}
	
	printf("\nmedia: %lf", sommatoria / (float)cont); 
}