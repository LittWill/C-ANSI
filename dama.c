#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>//BIBLIOTECA  QUE CALCULA O TEMPO...

struct{//Estrutura para armazenar os dados que serão colocanos no arquivo
       char game1[20], game2[20], ganhador[20];//nomes dos jogadores e ganhador
       int cont1, cont2, pont_max;//Contadores das peças e maior número de peças
       }dama;

  FILE *historico;//Iniciação do arquivo que armazena os nomes dos jogadores, o vencedor e seu número de peças.


  void jogador1(char matriz[8][8],char jogador, int oposto)//Função tabuleiro e jogadores
  {
  int i,j,l,c,li,co,opcao=0;

  do//Laço do jogo de dama
  {
    system("cls");

    if(jogador==1)//Definição do jogador de peça @
       printf("\n\n----------------    A vez é a do jogador peça @  ----------\n\n\n\n");
    if(jogador==2)//Definição do jogador de peça branca #
       printf("\n\n----------------    A vez é a do jogador peça #  ------------\n\n\n\n");
       printf("\t \t\t    0 1 2 3 4 5 6 7 \n");//Coordenadas do tabuleiro

    for(i=0;i<8;i++)//Desenho do tabuleiro, matriz e índices
   {

       printf("\n\t\t\t%d  ",i);
						printf("|");
    for(j=0;j<8;j++)
       printf("%c ",matriz[i][j]);
			printf("|");
   }

  printf("\n\n\t***************  Coordenada da peça  **********************");//Escolha da peça
  printf("\n\tLINHA: ");
  scanf("%d",&l);
  printf("\n\tCOLUNA: ");
  scanf("%d",&c);

  printf("\n\n\t****Coordenada da posição que a peça vai ocupar***");//Pra onde a posição da peça irá
  printf("\n\tLINHA: ");
  scanf("%d",&li);
  printf("\n\tCOLUNA: ");
  scanf("%d",&co);
  if((li+co)%2==1)//A condição só é satisfeita quando a soma dos índices for ímpar
  {
     if((jogador==1&&l<li)||(jogador==2&&l>li))//Faz com que a peça ande só uma casa e jogue um jogador de cada vez
     {
        printf("linha\n");
      //Condições para comer uma peça
        if(c-1==co||c+1==co)
        {
                        if(co==c-1)
                        {
                        matriz[li][co] = jogador;
                        matriz[l][c] = 0;
                        opcao++;
                        }
                        if(co==c+1)
                        {
                        matriz[li][co] = jogador;
                        matriz[l][c] = 0;
                        opcao++;
                        }
        }

        if(matriz[l+1][c+1]==oposto)
        {
                        if(c+2==co)
                        {
                                 matriz[li][co] = jogador;
                                 matriz[l][c] = 0;
                                 opcao++;
                                 matriz[l+1][c+1]=0;
                        }
        }

        if(matriz[l+1][c-1]==oposto)
        {
                        if(c-2==co)
                        {
                                 matriz[li][co] = jogador;
                                 matriz[l][c] = 0;
                                 matriz[l+1][c-1]=0;
                                 opcao++;
                        }
        }

        if(matriz[l-1][c+1]==oposto)
        {
                        if(c+2==co)
                        {
                                 matriz[li][co] = jogador;
                                 matriz[l][c] = 0;
                                 opcao++;
                                 matriz[l-1][c+1]=0;
                        }
        }

        if(matriz[l-1][c-1]==oposto)
        {
                        if(c-2==co)
                        {
                                matriz[li][co] = jogador;
                                matriz[l][c] = 0;
                                matriz[l-1][c-1]=0;
                                opcao++;
                        }
        }
  }
  else printf("\n\n\t\t__________MOVIMENTO INVÁLIDO!_________\n\t\t_________JOGUE NOVAMENTE________\n");//Caso o jogador escolha uma posição inválida
  }
  system("pause");
  }while(opcao!=1);//Termina o laço jogo da dama
}

void ganhador(char matriz[8][8])//Função que define quem ganhou
{
       int i,j;
         for(i=0;i<8;i++)
           for(j=0;j<8;j++)
           {
             if(matriz[i][j]==2)
             dama.cont1++;//Quantidade de peças do jogador 2
             if(matriz[i][j]==1)
             dama.cont2++;//Quantidade de peças do jogador 1
           }
             if(dama.cont1>dama.cont2)//Verifica qual jogador possui mais peças, mostrando quem é o vencedor
             {
               printf("\n\tVENCEDOR -> %s TOTAL DE PECAS: %d\n\n",dama.game1,dama.cont1);
               strcpy(dama.ganhador, dama.game1);// Pontuação do contador de peça
               dama.pont_max=dama.cont1;//Pontuação do contador de peça
              }
             else
             {
             if(dama.cont1<dama.cont2)//Verifica quem tem mais peças
             {
               printf("\n\tVENCEDOR -> %s TOTAL DE PEÇAS: %d\n\n",dama.game2,dama.cont2);
               strcpy(dama.ganhador, dama.game2);
               dama.pont_max=dama.cont2;//Pontuação máxima do contador peça branca
             }
            else{
               printf("\n\tEmpate!\n\t%s: %d\n\t%s: %d\n\n\n",dama.game1,dama.cont1,dama.game2,dama.cont2);//Caso de empate
               strcpy(dama.ganhador,"EMPATE");
               dama.pont_max=dama.cont2;//Pontuação máxima
                }
             }
 }
   void registro(void){//Função registro do jogo no arquivo
       fwrite(&dama, sizeof(dama), 1, historico);
                       }
   void escreve(void){//Função registro do jogo no arquivo
       while(fread(&dama, sizeof(dama), 1, historico)==1)//ler a informação até a última
       printf("\nJogador peça #: %s\nJogador peça @: %s\nVencedor: %s        Total de peças: %d\n\n",dama.game1, dama.game2, dama.ganhador, dama.pont_max);
                     }

int main(int argc, char *argv[])
{
    //Declaração dos caracteres no tabuleiro, quem está vazio, quem é peça @ ou # e os espaços livres
   char matriz[8][8], opcao2;
   int i,j, jogador=2,oposto=1,opcao=0;
     dama.cont1=dama.cont2=0;

  matriz[0][0]= 0;     matriz[0][1]= 88;   	matriz[0][2]= 0;	matriz[0][3] = 88; 		matriz[0][4] = 0;    matriz[0][5]= 88; 		matriz[0][6]= 0;     matriz[0][7]= 88;
  matriz[1][0]= 88;/*64;*/    matriz[1][1]= 0; 	matriz[1][2]= 88; 	matriz[1][3] = 0; 	matriz[1][4] = 88;	 matriz[1][5]= 0; 	matriz[1][6]= 88; 	 matriz[1][7]= 0;
  matriz[2][0]= 0;   matriz[2][1]= 88;   	matriz[2][2]= 0;  matriz[2][3] = 88; 		matriz[2][4] = 0;  matriz[2][5]= 88; 		matriz[2][6]= 0;   matriz[2][7]= 88;
  matriz[3][0]= 0;     matriz[3][1]= 0;   matriz[3][2]= 0; 	matriz[3][3] = 0; 	matriz[3][4] = 0;	 matriz[3][5]= 0; 	matriz[3][6]= 0;	 matriz[3][7]= 0;
  matriz[4][0]= 0;   matriz[4][1]= 0;   	matriz[4][2]= 0;  matriz[4][3] = 0; 		matriz[4][4] = 0;  matriz[4][5]= 0; 		matriz[4][6]= 0;   matriz[4][7]= 0;
  matriz[5][0]= 79;     matriz[5][1]= 0;   matriz[5][2]= 79; 	matriz[5][3] = 0; 	matriz[5][4] = 79;	 matriz[5][5]= 0; 	matriz[5][6]= 79; 	 matriz[5][7]= 0;
  matriz[6][0]= 0;   matriz[6][1]= 79;   	matriz[6][2]= 0;  matriz[6][3] = 79; 		matriz[6][4] = 0;  matriz[6][5]= 79; 		matriz[6][6]= 0;   matriz[6][7]= 79;
  matriz[7][0]= 79;     matriz[7][1]= 0;   matriz[7][2]= 79; 	matriz[7][3] = 0; 	matriz[7][4] = 79;	 matriz[7][5]= 0; 	matriz[7][6]= 79;	 matriz[7][7]= 0;


  do{
    //Pergunta o nome dos jogadores de cada tipo de peça (@ ou #)

    printf("\n\n");
    printf("\n");
    printf("\n");
    printf("															\n");
    printf("                   					\n");
    printf("\t 						DAMAS  					\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("\tEscolha uma das opções abaixo:\n\n");
    printf("\t a - Jogar.\n\t \n\t b - Sair.\n\n");
    printf("\tOpção: ");
    scanf("%c",&opcao2);//Escolha de opção do menu
    system("cls");


    switch(opcao2){
                case 'a' :

                     system("cls");
                     printf("\n\n\t\tInforme o nome do jogador da peça #:\n\n\t\t\t\t");//Inserção do nome do jogador #
                     scanf("%s",dama.game1);
                     printf("\n\n\t\tInforme o nome do jogador da peça @:\n\n\t\t\t\t ");//Inserção do nome do jogador @
                     scanf("%s",dama.game2);



                      int tempo = clock();
                      while(clock()-tempo<500000){


                      jogador=1;oposto=2;
                      jogador1(matriz,jogador,oposto);
                      jogador=2;oposto=1;
                      jogador1(matriz,jogador,oposto);
                      }

                     system("cls");
                     printf("\n\t\t..........Passaram-se 3 minutos.\nFIM DO JOGO...........\n\n\n");//Aparece na tela quando o tempo se encerra
                         ganhador(matriz);//Chamada da função ganhador
                         registro();//Chamada da função registro ...Responsável por gravar as informações
                     system("pause");
                     system("cls");
                     break;


				//Removido case 'B':
                case 'b'://Para sair do jogo

                     printf("\n\n\n\n\t\t\t  Saindo do Jogo\n\n\n\n\n");
                     break;


    }
  }while(opcao2!= 'b');//Laço que encerra o switch
      fclose(historico);//Fechamento do arquivo
      system("PAUSE");
  return 0;
}
