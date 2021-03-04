#include <stdio.h>
#include "pilha.h"

int main (void){
    char c[81];
    Pilha P = pilha (81);
    printf("Insira uma cadeia de caracteres: ");
    gets(c);

    for(int i = 0; c[i]; i++)
    empilha(c[i], P);
    printf("Inverso: ");

    while(!vaziap(P))
        printf("%c", desempilha(P));
    destroip(&P);

    return 0;    






}