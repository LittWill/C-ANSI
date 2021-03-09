#include <stdio.h>

int atributo = 10;

int main(){
     
setAtributo(10+5);

printf("%d", getAtributo());

}

int getAtributo(){
    return atributo;
}

void setAtributo(int atributoParam){
    atributo = atributoParam;
}

