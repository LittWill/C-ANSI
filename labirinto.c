#include <stdio.h>
#define MAX 8
#define BAIXO m [l - 1] [c]
#define ACIMA m [l + 1] [c]
#define ESQUERDA m [l] [c - 1]
#define DIREITA m [l] [c + 1]
#define ONDEESTOU m [l] [c]
exibe(int m [MAX][MAX]);

int main(void){
int m [MAX] [MAX] = {{1, 1, 1, 1, 1, 1, 1, 1},
                    {0, 0, 1, 0, 0, 0, 0, 1},
                    {1, 0, 1, 0, 1, 0, 1, 1},
                    {1, 0, 1, 0, 1, 0, 0, 1},
                    {1, 0, 0, 0, 1, 1, 0, 1},
                    {1, 0, 1, 0, 0, 1, 0, 1},
                    {1, 0, 1, 0, 1, 1, 0, 0},
                    {1, 1, 1, 1, 1, 1, 1, 1}};

exibe(m);
}

exibe (int m [MAX][MAX]){
int l, c = 0;

for(int l = 0; l < 8; l++){
for (int c = 0; c < 8; c++){

    //printf("%s", m [l] [c] == 1 ? " * " : " / ");
    printf("%s", DIREITA == 1 ? " | " : " > ");

 /*  //Condição seta para cima
    if ((ESQUERDA != 0) && (DIREITA != 0) && (BAIXO != 0) && (ACIMA == 0) && (ONDEESTOU == 0)){
    printf("↑");
    }

   //Condição seta para a direita
    if ((ESQUERDA == 0) && (DIREITA == 0)){
    printf("→");
    }
    else if ((BAIXO != 0) && (ACIMA != 0) && (ESQUERDA != 0) && (DIREITA == 0) && (ONDEESTOU == 0)){
    printf("→");
    }

    //Condição seta para a esquerda
    else if ((DIREITA != 0) && (ACIMA != 0) && (BAIXO != 0) && (ESQUERDA == 0) && (ONDEESTOU == 0)){
    printf("←");
    }
    //Condição seta pra baixo
    else if ((ESQUERDA != 0) && (ACIMA != 0) && (DIREITA != 0) && (BAIXO == 0) && (ONDEESTOU == 0)){
    printf("↓");
    }
    */












}
puts("");

}
}












