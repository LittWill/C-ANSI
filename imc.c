/*O índice de massa corporal de uma pessoa é o seu peso dividido pelo quadrado
de sua altura. Crie e execute o programa a seguir, que calcular o IMC.
*/
//Necessário incluir -lm no terminal para que execute com sucesso
#include <stdio.h>
#include <math.h>

int main () {
    float peso, altura, indice;
    printf("Insira seu peso e altura: ");
    scanf("%f %f", &peso, &altura);
    indice = peso/pow(altura,2);
    printf("IMC = %.2f\n", indice);
    //Continuação Exercício 2 Estrutura de Dados
    if (indice < 18.5) puts("Magra");
    else if (indice > 30) puts ("Obesa");
    else puts ("Saudável");
    return 0;


}