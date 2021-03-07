#include <stdio.h>

int main(){

    struct horario{
        int hora;
        int minuto;
        int segundo;
    };

    struct horario agora, *depois;
    depois = &agora;

    depois->hora = 20;
    depois->minuto = 15;
    depois->segundo = 37;

    int somatoria = 100;

    struct horario antes;
                 //100         //37
    antes.hora = somatoria + depois->segundo; //137
                    //20       //15
    antes.minuto = agora.hora + depois->minuto; //35
                    //15                //37
    antes.segundo = depois->minuto + depois->segundo; //52

    printf("%d:%d:%d", antes.hora, antes.minuto, antes.segundo);
                        //137         //35           //52

}