#include <stdio.h>
#include <math.h>

int main(void) {
	double a, b, c;
	
	printf("inserisci a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	printf("\n%fx^2 + %fx + %f = ", a, b, c);
	
	const double delta = pow(b, 2) - (4 * a * c);
	printf("%f", delta);
	
	if(a == 0)
		printf("\nrisultato: %f", -c / b);

	if(delta > 0 && a != 0) {
		double x1, x2;
		
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		
		printf("\nrisultati: %f, %f", (double)x1, (double)x2);
	}
	else if(delta == 0) {
		double x1;
		
		x1 = -b / 2 * a;
		
		printf("\nrisultato: %f", x1);
	}
	else if(delta < 0)
		printf("\nradici complesse coniugate");
}