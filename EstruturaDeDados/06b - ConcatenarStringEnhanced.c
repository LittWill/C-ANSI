#include <stdio.h>
#include "08 - length.c"

int main(){

    void concatenarStrings(char string1[], int t1,
                          char string2[], int t2,
                          char stringFinal[]);

    int numCaracteresPalavra1, numCaracteresPalavra2;
    printf("Insira o número aproximado de caracteres da palavra 1 e 2: ");
    scanf("%d %d", &numCaracteresPalavra1, &numCaracteresPalavra2);

    char palavra1[numCaracteresPalavra1];
    char palavra2[numCaracteresPalavra2];

    printf("Insira as duas palavras a serem unificadas: ");
    scanf("%s %s", &palavra1, &palavra2);

    int numCaracteres = length(palavra1) + length(palavra2);
    char novaPalavra[numCaracteres];


    concatenarStrings(palavra1, length(palavra1), palavra2, length(palavra2), novaPalavra);

    int i = 0;
    int erro = 0;

    for (i = 0; i < numCaracteres; ++i){
        printf("%c", novaPalavra[i]);
    } 
    printf("\n");

}

void concatenarStrings(char string1[], int t1,
                      char string2[], int t2,
                      char stringFinal[])
{
    int i = 0, j = 0;
    for(i = 0; i < t1; i++){
        stringFinal[i] = string1[i];
        
    }

    for(j = 0; j < t2; j++){
        stringFinal[i++] = string2[j];
        
    }

}