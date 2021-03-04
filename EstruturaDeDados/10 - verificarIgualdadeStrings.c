#include <stdio.h>


int main(){

    _Bool stringsIguais (char s1[], char s2[]);
 
   if (stringsIguais("casa", "casa")){
        printf("São iguais!\n");

    }
    else {
        printf("Não são iguais!\n");
    }
    

}

_Bool stringsIguais (char s1[], char s2[]){

int i = 0;
_Bool verify = 1;

         while (s1 [i] == s2 [i] && s1 [i] != '\0' && s2[i] != '\0'){
             i++;
          if (s1 [i] != s2 [i]){
             return 0; 
          }
        }
        return 1;
       
        


    

        
        
        
}
