# Programmazione I (2024-2025)

## Struttura delle Cartelle

I file sono organizzati in modo gerarchico seguendo un ordine temporale:

- **Cartelle dei mesi:**  
  Ogni mese ha una propria cartella numerata:
  - `1/` → Gennaio
  - `2/` → Febbraio  
  _(e così via...)_

- **Cartelle dei giorni:**  
  All'interno di ciascun mese, troverai le cartelle numerate per ogni giorno:
  - `1/` → 1 Gennaio
  - `2/` → 2 Gennaio  
  _(e così via...)_

- **File `.c`:**  
  Ogni giorno contiene esclusivamente i file sorgente `.c`.  
  Grazie al file `.gitignore`, i file eseguibili (`.exe`) non verranno inclusi nel repository.


## Esecuzione dei File

Per compilare ed eseguire un file `.c`, segui i comandi sottostanti:

1. **Compilazione:**
   ```bash
   gcc -Wall .\nomefile.c -o .\nomefile.exe
   ```
   Il flag -Wall abilita l'avviso di eventuali errori o situazioni ambigue.

2. **Esecuzione:**
   ```bash
   .\nomefile.exe
   ```

## Possibili problematiche di compilazione
Utilizzo un compilatore diverso da quello standard attuale quindi quando devo utilizzare una variabile **size_t** devo fare:

```c
size_t i;
printf("%Iu", i);
```

Quindi probabilmente dovrai cambiare **"Iu"** in **"zu"**.

*(su notepad++ puoi fare ctrl+h e fare la sostituzione)*
