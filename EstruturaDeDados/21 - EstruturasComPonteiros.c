#include <stdio.h>

int main(){

    struct horario{
        int *pointerHora;
        int *pointerMinuto;
        int *pointerSegundo;

    };

    struct horario hoje;

    int hora = 200;
    int minuto = 300;
    int segundo = 400;
        
    hoje.pointerHora = &hora;
    hoje.pointerMinuto = &minuto;
    hoje.pointerSegundo = &segundo;

    printf("Hora - %d\n", *hoje.pointerHora);
    printf("Minuto - %d\n", *hoje.pointerMinuto);
    printf("Segundo - %d\n", *hoje.pointerSegundo);

    *hoje.pointerSegundo = 1000;

    printf("Segundo - %d\n", *hoje.pointerSegundo);


    

}