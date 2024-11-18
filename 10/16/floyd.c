#include <stdio.h>

int main(void) {
	int n;
	int cont = 1;
	
	printf("\ninserisci un numero n: ");
	scanf("%d", &n);
	
	for(size_t i = 1; i <= n; i++) {
		for(size_t j = 0; j < i; j++) {
			printf("%-3d ", cont++);
		}
		puts("");
	}
}