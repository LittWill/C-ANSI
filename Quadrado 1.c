#include <stdio.h>
#include <locale.h>
#define quadrado(n) n * n
int main (void){
    setlocale("LC_ALL", "Portuguese");
    int a;
    printf("Insira um número: ");
    scanf("%d", &a);
    printf("O quadrado de %d é: %d", a, quadrado(a));
}
