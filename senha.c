#include <stdio.h>
#include <string.h>

int main (void){
    char s[256];
    printf("Insira a senha: ");
    gets(s);
    if(strcmp(s, "abracadabra") == 0) puts("Ok!");
    else puts("Senha incorreta!");
    return 0;
}