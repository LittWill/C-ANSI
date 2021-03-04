#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
void gera (int m [MAX] [MAX]);
void exige (int m [MAX] [MAX]);

int main (void){
    int m [MAX] [MAX];
    srand(time(NULL));
    gera(m);
    exige(m);
    return 0;


}

void gera (int m [MAX][MAX]){
int l, c;
for (l = 0; l < 15; l++)
for (c = 0; c < 15; c++){

m [l] [c] = rand() % 2;

}


}

void exige (int m [MAX][MAX]){
int l, c;
for (l = 0; l < 15; l++)
for (c = 0; c < 15; c++){

printf("%s", m [l] [c] ? " | " : " > ");
}

puts("");


}
