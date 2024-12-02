#include <stdio.h>
#include <stdbool.h>
#define MAX_STR  100

bool prefixR(char *prefix, char *seq){
    if(*prefix == '\0')
        return true;
    if(*seq == '\0')
        return false;
    else
        return (*prefix == *seq) && prefixR(prefix + 1, seq + 1);
}

size_t len(char *str){
    if(*str == '\0')
        return 0;
    else
        return 1 + len(str + 1);
}

void stampa_filtro_substrR(char *seq, char *del_seq){
    if(*seq == '\0') {}
    else{
        if(prefixR(del_seq, seq)){
            printf("-");
            stampa_filtro_substrR(seq + len(del_seq), del_seq);
        }
        else {
            printf("%c", *seq);
            stampa_filtro_substrR(seq + 1, del_seq);
        }
    }
}

int main(void) {
	char seq[MAX_STR];
	char del_seq[MAX_STR];
	
	scanf("%s", seq);
	scanf("%s", del_seq);
	
	stampa_filtro_substrR(seq, del_seq);
}