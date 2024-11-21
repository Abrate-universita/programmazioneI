#include <stdio.h>
#include <stdbool.h>
#define ROWS 3
#define COLS 3

bool occupa_colonna(const size_t i, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[0][i] == gioco[1][i]) && (gioco[0][i] == gioco[2][i]);
}

bool occupa_riga(const size_t j, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[j][0] == gioco[j][1]) && (gioco[j][0] == gioco[j][2]);
}

bool occupa_diagonale_sxA_dxB(const size_t i, const size_t j, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[i][j] == gioco[i + 1][j + 1]) && (gioco[i][j] == gioco[i + 2][j + 2]);
}

bool occupa_diagonale_dxA_sxB(const size_t i, const size_t j, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[i][j] == gioco[i + 1][j - 1]) && (gioco[i][j] == gioco[i + 2][j - 2]);
}

bool occupa_diagonale_sxB_dxA(const size_t i, const size_t j, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[i][j] == gioco[i - 1][j + 1]) && (gioco[i][j] == gioco[i - 2][j + 2]);
}

bool occupa_diagonale_dxB_sxA(const size_t i, const size_t j, char gioco[ROWS][COLS]){
    // essendo 3 posizioni fisse e avendo gìà fatto i controlli posso (tanto il tris è sempre 3x3)
    return (gioco[i][j] == gioco[i - 1][j - 1]) && (gioco[i][j] == gioco[i - 2][j - 2]);
}

int main(void){
    char gioco[ROWS][COLS];
    
    for(size_t i = 0; i < ROWS; i++)
        for(size_t j = 0; j < COLS; j++)
            scanf(" %c", &gioco[i][j]);
            
    bool vincitore = false;
    for(size_t i = 0; i < ROWS && !vincitore; i++) {
        for(size_t j = 0; j < COLS && !vincitore; j++) {
            if(i == 0)
                vincitore = occupa_colonna(j, gioco);
            if(j == 0 && !vincitore)
                vincitore = occupa_riga(i, gioco);
            if(i == 0 && j == 0 && !vincitore)
                vincitore = occupa_diagonale_sxA_dxB(i, j, gioco);
            if(i == 0 && j == (COLS - 1) && !vincitore)
                vincitore = occupa_diagonale_dxA_sxB(i, j, gioco);
            if(i == (ROWS - 1) && j == 0 && !vincitore)
                vincitore = occupa_diagonale_sxB_dxA(i, j, gioco);
            if(i == (ROWS - 1) && j == (COLS - 1) && !vincitore)
                vincitore = occupa_diagonale_dxB_sxA(i, j, gioco);
                
            if(vincitore)
                printf("%c\n", gioco[i][j]);
        }
    }
    if(!vincitore)
        printf("-\n");
}