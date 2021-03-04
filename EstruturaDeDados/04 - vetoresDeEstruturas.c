#include <stdio.h>

int main(){
int aux = 0;
    struct horario{
        int hora;
        int minuto;
        int segundo;
    };

    struct horario teste[2];

    for (int i = 0; i < 2; i++)
    {
       teste[i].hora = 2;
       teste[i].minuto = 2;
       teste[i].segundo = 2;

    }

    for (int i = 0; i < 2; i++){

    printf("Índice %d: %d:%d:%d ", aux, teste[i].hora, teste[i].minuto, teste[i].segundo);
    aux++;
    
    }
    


}

