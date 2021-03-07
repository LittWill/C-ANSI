#include <stdio.h>

int main(){

    int x = 10;
    double y = 20.50;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    double soma = *pX  + *pY; //30.50
    //printf("Soma entre %d e %f: %f", *pX, *pY, soma);

    int *resultado;
    resultado = &x;

  /*  printf("Endereço x = %d e valor x = %d\n", pX, *pX);
    printf("Endereço y = %d e valor y = %f\n", pY, *pY);
    printf("Endereço z = %d e valor z = %c\n", pZ, *pZ);
    */
   printf("valor x = %d\n", resultado);
    
    


}