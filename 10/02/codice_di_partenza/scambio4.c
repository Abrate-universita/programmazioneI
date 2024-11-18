#include <stdio.h>

void swap4(int* n1, int* n2, int* n3, int* n4) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = *n3;
	*n3 = *n4;
	*n4 = temp;
}

int main(void) {
	int n1 = 1;
	int n2 = 2;
	int n3 = 3;
	int n4 = 4;
	
	// dopo lo scambio quello che ci si aspetta e'
	// n1 = 2, n2 = 3, n3 = 4, n4 = 1
	printf("prima dello scambio:\nn1 = %d\nn2 = %d\nn3 = %d\nn4 = %d\n", n1, n2, n3, n4);
	
	swap4(&n1, &n2, &n3, &n4);
	
	printf("dopo lo scambio:\nn1 = %d\nn2 = %d\nn3 = %d\nn4 = %d\n", n1, n2, n3, n4);
}