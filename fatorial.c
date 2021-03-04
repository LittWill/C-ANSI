#include <stdio.h>
int main(){
    int n, fatorial;
    printf("Insira um número: ");
    scanf("%d", &n);
    fatorial = 1;
    for(int i = 1; i <= n; i++)
    fatorial *= i;
    printf("Fatorial: %d\n", fatorial);
    return 0;



}