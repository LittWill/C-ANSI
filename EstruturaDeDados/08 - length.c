#include <stdio.h>

int main(){
    int length(char string1[]);
    char palavra[50];

    printf("Insira uma frase/palavra para saber seu tamanho: ");
    gets(palavra);

    printf("%d", length(palavra));
}

int length(char string1[]){
    int i = 0;
    while(string1[i] != NULL){
        i++;
        
    }

    return i;
}
