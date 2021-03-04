#include <stdio.h>

int main(void){

    int tamanhoString(char string[]);

    char stringUsuario[20];

    printf("Insira uma palavra (string): ");
    scanf("%s", stringUsuario);

    printf("%d", tamanhoString(stringUsuario));

}

int tamanhoString(char string[]){

    int numCaracteres = 0;

    while(string[numCaracteres] != '\0'){
            numCaracteres++;

    }
        return ++numCaracteres;
    
}