#include <stdio.h>

int main(){

    void concatenarStrings(char string1[], int t1,
                          char string2[], int t2,
                          char stringFinal[]);
    char palavra1[] = {'p', 'a', 'o', ' '};
    char palavra2[] = {'m', 'o', 'r', 't', 'a', 'd', 'e', 'l', 'a'};
    char novaPalavra[13];

    concatenarStrings(palavra1, 4, palavra2, 9, novaPalavra);

    int i = 0;

    for (i = 0; i < 13; ++i){
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