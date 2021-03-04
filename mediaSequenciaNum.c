#include <stdio.h>
#include <stdlib.h>

float media(float v[], int n){
    float s = 0;
    for(int i = 0; i < n; i++)
        s+= v[i];

    return s/n;

}

int main(){
    int n;
    printf("Insira a quantidade de números: ");
    scanf("%d", &n);
    float *v = malloc(n*sizeof(float));
    for(int i = 0; i < n; i++){
        printf("%ddo número: ", i+1);
        scanf("%f", &v[i]);
    }
    printf("Média = %.2f\n", media(v, n));
    return 0;

}