#include <stdio.h>

int fat (int n){
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;

}

int main (){
    int numero;
    printf("Insira o valor do fatorial: ");
    scanf("%d", &numero);
    printf("Fatorial de %d é: %d", numero, fat(numero));
}