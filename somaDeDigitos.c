#include <stdio.h>
int main(){
    int n;
    printf("Insira um número: ");
    scanf("%d", &n);
    int s = 0;

    while(n > 0){
        s+= n%10;
        n /= 10;
    }

    printf("Soma dos dígitos = %d\n", s);
    return 0;


}