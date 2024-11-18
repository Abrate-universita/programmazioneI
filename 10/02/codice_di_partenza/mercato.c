#include <stdio.h>
#define PREZZO_ORECCHIETTE 1.50
#define PREZZO_POMODORI 2.50

int main(void) {
	// orecchiette in pacchi
	int orecchiette;
	
	// pomodori in kg
	double pomodori;
	
	printf("mercato di pomodori e orecchiette");
	printf("\nprezzo orecchiette al pacco -> %.2f", PREZZO_ORECCHIETTE);
	printf("\nprezzo pomodori al kg -> %.2f\n", PREZZO_POMODORI);
	
	printf("\ninserire i pacchi di orecchiette comprate -> ");
	scanf("%d", &orecchiette);
	
	printf("\ninserire i kg di pomodori acquistati -> ");
	scanf("%lf", &pomodori);

	printf("\n%d %f %f %f", orecchiette, pomodori, PREZZO_ORECCHIETTE, PREZZO_POMODORI);
	const double somma = (double)(orecchiette * PREZZO_ORECCHIETTE) + (pomodori * PREZZO_POMODORI);
	printf("\nil prezzo totale della spesa -> %.2f euro", somma);
}