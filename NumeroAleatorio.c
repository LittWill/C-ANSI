#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((unsigned) time (NULL));

    //Gera números de 0 a 99
    int random = rand() % 100;

    //Gera números de 1 a 5
    int randomSegundo = (rand() % 5) + 1;

    printf("%d", randomSegundo);

}
