#include <stdio.h>

int main(){
   
    int x = 10;
    int *y;
    y = &x;

    x = 20;
   
   printf("x: %d y: %d\n", x, *y);
   //Saída: x: 20 y: 20


}