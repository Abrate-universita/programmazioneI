#include <stdio.h>

int main(void) {
	int k;
	int n = 0, m = 1;
	
	printf("inserisci il valore k: ");
	scanf("%d", &k);
	
	printf("\n%d %d ", n, m);
	for(int i = 2; i < k; i++) {
		int temp = n;
		n = m;
		m += temp;
		
		printf("%d ", m);
	}
}