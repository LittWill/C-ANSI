#include <stdio.h>

int main(){

  
    for (int i = 1; i <= 20; i++)
    {
        if (i % 9 == 0) {
        
            printf("%i Número divisível por 3 e 9\n", i);
            break;
        }
        else {
            printf("%i Próximo número\n", i);
        }
        
    }
    



}