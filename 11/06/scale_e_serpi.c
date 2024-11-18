#define len_scale 8
void posizione_scala(int* pos){
	// definisco le scale
	const int scale_partenza[len_scale] = {1, 4, 8, 21, 28, 50, 71, 80 };
	const int scale_arrivo[len_scale] = {38, 14, 30, 42, 76, 67, 92, 99 };
	
	// for che controlla se il player è su una base di una scala e cambia la sua posizione
    for(size_t i = 0; i < len_scale; i++) {
        if(*pos == scale_partenza[i]){
            *pos = scale_arrivo[i]; 
            i = len_scale;
        }
    }
}

#define len_serpenti 7
void posizione_serpente(int* pos){
	// definisco i serpenti
	const int serpenti_partenza[len_serpenti] = { 32, 36, 48, 62, 88, 95, 97 };
	const int serpenti_arrivo[len_serpenti] = { 10, 6, 26, 18, 24, 56, 78 };
	
	// for che controlla se il player è su una base di una scala e cambia la sua posizione
    for(size_t i = 0; i < len_serpenti; i++) {
        if(*pos == serpenti_partenza[i]){
            *pos = serpenti_arrivo[i]; 
            i = len_serpenti;
        }
    }
}

// Avanza la posizione del giocatore nella casella *pos
// in funzione del lancio del dado.
// Parametri:
//   dado   La quantità ottenuta dal lancio del dado (compresa tra 1 e 6)
//  *pos    La cella del giocatore che muove
// Ritorna true se il giocatore gioca ancora il prossimo turno, false altrimenti.
// Al ritorno, il valore di *pos è stato modificato aggiungendo il lancio 
// del dado, ed applicando tutte le rimanenti reole sulle scale e sulle serpi
bool muovi_giocatore(int dado, int* pos) {
	// stabilisco la nuova posizione del giocatore
	*pos += dado;
	
	// controllo se la sua posizione risulta su una scala oppure su un serpente
	posizione_scala(pos);
	posizione_serpente(pos);
	
	return dado == 6;
}

// Simula il lancio di un dado a 6 facce
int lancia_dado() {
	return (rand() % 6) + 1;
}

// Realizza i turni del gioco delle scale e delle serpi
void scale_e_serpi(void) {
	int pos1 = 0, pos2 = 0; // la posizione dei due giocatori, inizialmente 0
	int turno = 1; 			// puo' valere 1 o 2

	// Esegui i turni
	while (pos1<100 && pos2<100) {
		// il giocatore lancia il dado
		int dado = lancia_dado();
		// muovi il giocatore attivo, e determina chi gioca il prossimo turno
		if (turno == 1) { 
			// muove il giocatore 1
			if (!muovi_giocatore(dado, &pos1))
				turno = 2; // passa il turno al giocatore 2
		}
		else { 
			// muove il giocatore 2
			if (!muovi_giocatore(dado, &pos2))
				turno = 1; // passa il turno al giocatore 1
		}
	}
	// Stampa il vincitore e le posizioni finali dei due giocatori
	printf("%d %d %d\n", turno, pos1, pos2);
}