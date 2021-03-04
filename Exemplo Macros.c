#include <stdio.h>
#include <locale.h>
#define par(n) n + n
int main (void){
    int a;
    printf("Insira um numero: ");
    scanf("%d", &a);
    printf("%d", par(a));
}
