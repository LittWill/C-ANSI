#include <stdio.h>
#include <ctype.h>
#define maiuscula(c)//...Sem solução, por enquanto
int main(void){
    char x;
    printf("Insira um caractere: ");
    scanf("%c", &x);
    printf("Maiuscula: %s\n", maiuscula(x) ? "Sim" : "Nao");
}