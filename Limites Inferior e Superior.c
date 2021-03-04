#include <stdio.h>
#include <locale.h>
#define MIN_INT 0
#define MAX_INT 100
int main (void){
setlocale("LC_ALL", "Portuguese");
    printf("Inteiro mínimo = %+d\n", MIN_INT);
    printf("Inteiro máximo = %+d\n", MAX_INT);
    return 0;

}
