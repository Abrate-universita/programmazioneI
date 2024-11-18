#include <stdio.h>

int main(void) {
    int n;

    printf("scrivi un numero intero: ");
    scanf("%d", &n);

    for(int i = 0; i < 10; i++)
        printf("%d * %d = %d\n", n, i + 1, n * (i + 1));

    return 0;
}