#include <stdio.h>
#include <stdbool.h> //Biblioteca que provê opções para booleanos
#define NUMERODEDEFINICOES 7

struct dicionario{
    char palavra[20];
    char definicao[50];
        
};

bool compararString(const char palavra1[], const char palavra2[]){

    int i = 0;
    while (palavra1[i] == palavra2[i] &&
    palavra1[i] != '\0' && palavra2[i] != '\0')
    {i++;}
    
    if (palavra1[i] == '\0' && palavra2[i] == '\0'){
        return true;
    }
    else {
        return false;
    }

}

int procurarStrings(const struct dicionario lingua[], const char procurar[],
                    const int numDePalavras) {

    int i = 0;
    while (i < numDePalavras){
        if(compararString(procurar, lingua[i].palavra)){
            return i;
        }
         i++;    
    }
    return -1;

}



int main(){
    
    
    char palavra[20] = {'\0'};
    int resultadoPesquisa = 0;

     struct dicionario portugues[NUMERODEDEFINICOES] =
      {{"Pão", "Feito à base de farinha"},
        {"Mortadela", "Feito à base de restos de carne"},
        {"Feijão", "Iguaria brasileira."},
        {"Tropeiro", "Tipo de feijão."},
        {"Queijo", "Iguaria mineira."},
        {"Macarronada", "Iguaria italiana"},
        {"Pizza", "Outra iguaria italiana"}};
        
        
   do{
        printf("Insira uma palavra: ");
        scanf("\n%s", palavra);

        resultadoPesquisa = procurarStrings(portugues, palavra, NUMERODEDEFINICOES);

            if (resultadoPesquisa != -1) {
                printf("\nPalavra buscada: %s\nDefinição: %s\nPosição %d \n\n", portugues[resultadoPesquisa].palavra, portugues[resultadoPesquisa].definicao, resultadoPesquisa);
            }
            else {
                printf("Palavra não encontrada!\n\n");
            }
   }while(true);
  
    
}
