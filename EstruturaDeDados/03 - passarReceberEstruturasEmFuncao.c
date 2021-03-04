#include <stdio.h>

struct horario{
       int horas;
       int minutos;
       int segundos;
   };

int main(){
    //Declaração da função que retorna struct
   struct horario teste(struct horario x);

    //Criação de um objeto struct "agora"
   struct horario agora;

   agora.horas = 10;
   agora.minutos = 42;
   agora.segundos = 58;

    //Criação de um objeto struct "proxima"
    struct horario proxima;
    /*Objeto struct proxima recebe o retorno 
    da função teste, recebendo como parâmetro
    os valores do objeto agora
    */
    proxima = teste(agora);

    printf("%i:%i:%i\n", proxima.horas,
                         proxima.minutos,
                         proxima.segundos);





}

struct horario teste(struct horario x){
//x.horas
    printf("%i:%i:%i\n", x.horas,
                         x.minutos,
                         x.segundos);
    x.horas = 100;
    x.minutos = 100;
    x.segundos = 100;

    return x;
}