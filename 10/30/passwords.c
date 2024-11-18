#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {
	// iteratore per scorrere la stringa
    size_t i = 0;
	
	// password fornita in input
    char password[21];
    
	// contatori che servono per risolvere 2 dei 5 punti
    int cont_cifra_maiusc = 0;
    int cont_cifra_cons = 0;
    
	// bool finali per l'output
    bool cifra = false;
    bool tutte_lettere = true;
    bool due_maiusc = false;
    bool due_cifre_consec = false;
    bool ultimi_car_punt = false;
    
	// recupero in input la password
    scanf("%21s", password);
    
    while(password[i] != '\0') {
        // esiste un carattere qualsiasi che sia una cifra
        // se esiste allora non ci sono solo caratteri
        if(isdigit(password[i])) {
            cifra = true;
            tutte_lettere = false;
            
            // aumento il contatore delle cifre
            cont_cifra_cons++;
            
            if(cont_cifra_cons == 2)
                due_cifre_consec = true;
        }
        else
            // per logica, il contatore delle due cifre consecutive dev'essere resettato se non è numerico il carattere
            cont_cifra_cons = 0;
            
        if(ispunct(password[i]))
            tutte_lettere = false;
            
        // ci sono almeno due lettere maiuscole
        if(isupper(password[i])) {
            cont_cifra_maiusc++;
            
            if(cont_cifra_maiusc >= 2)
                due_maiusc = true;
        }
        
        i++;
    }
    
	// se i > 1 e le ultime due cifre sono dei caratteri di punteggiatura
    if(i > 1 && (ispunct(password[i - 2]) && ispunct(password[i - 1]))) 
		ultimi_car_punt = true;
    
    printf("%s %d %d %d %d %d", password, cifra, tutte_lettere, due_maiusc, due_cifre_consec, ultimi_car_punt);
}