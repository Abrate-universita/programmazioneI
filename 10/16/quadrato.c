#include <stdio.h>

int main(void) {
	int n;
	
	printf("\ninserisci un numero n: ");
	scanf("%d", &n);
	
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			if(j == i)
				printf("\\");
			else if(j < i)
				printf("*");
			else
				printf(":");
		}
		puts("");
	}
}