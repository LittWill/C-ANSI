#include <stdio.h>
struct horario
{
   int hora;
   int minutos;
   int segundos;
};


int main(){
    struct horario teste(struct horario x[5]);
    struct horario agora[5];
    teste(agora);
    
    
}

struct horario teste(struct horario x[5]){
int aux;
for (int i = 0; i < 5; i++)
{
    printf("Insira o hora na posição %d: ", i);
    scanf("%i:%i:%i", &x[i].hora, &x[i].minutos, &x[i].segundos);
}

for(int i = 0; i < 5; i++)
{
    printf("\nHora registrada na posição %d: %i:%i:%i", i, x[i].hora, x[i].minutos, x[i].segundos);
    
}

}

