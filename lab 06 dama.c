#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <time.h>//BIBLIOTECA  QUE CALCULA O TEMPO...

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"

struct{//ESTRUTURA PARA ARMAZENAR OS DADOS QUE SERAM COLOCADOS NO ARQUIVO
       char game1[20], game2[20], ganhador[20];//NOMES DOS JOGADORES E GANHADOR
       int cont1, cont2, pont_max;//CONTADORES DAS PECAS E MAIOR NUMERO DE PECAS
       }dama;

  FILE *historico;//INICIACAO DO ARQUIVO QUE ARMAZENA OS NOMES DOS JOGADORES,O VENCEDOR, E O NUMERO DE PECAS DO VENCEDOR.


  void jogador1(char matriz[8][8],char jogador, int oposto)//FUNCAO TABULEIRO  E  JOGADORES
  {
	setlocale(LC_ALL, "Portuguese");
  int i=0,j=0,l,c,li,co,opcao=0;
  char a[1];

  do//LACO DO JOGO DA DAMA
  {
    system("cls");

    if(jogador==1)//DEFINICAO JOGADOR PECA
       printf("\n\n                                    <<<<<<<<<<<< A VEZ E A DO JOGADOR PECA @ >>>>>>>>>>>> \n\n\n\n");
    if(jogador==2)//JOGADOR PECA PRETA
        printf("\n\n                                   <<<<<<<<<<<< A VEZ E A DO JOGADOR PECA # >>>>>>>>>>>> \n\n\n\n");
       printf(VERMELHO "\t \t\t                            0 1 2 3 4 5 6 7 \n" RESET);//DCOORDENADAS DO TABULEIRO

    for(i=0;i<8;i++)//DESENHO DO TABULEIRO ...MATRIZ E OS INDICES
   {

       printf(VERMELHO "\n\t\t\t                         %d  ",i, RESET);

    for(j=0;j<8;j++)
       printf(VERDE "%c ",matriz[i][j], RESET);

   }    
   
	printf("\n\n\tEscolha uma das opcoes abaixo:\n\n");
    printf("\t a - Realizar jogada.\n\t \n\t b - Encerrar partida.\n\n");
    printf("\tOpcao: ");
    scanf("%s",&a);

    if ((strcmp(a,"a")==0) || (strcmp(a,"A")==0 )){
	
  printf("\n\n\t***  CORDENADA DA PECA  ****");//ESCOLHE A PECA QUE VAI JOGAR
  printf("\n\tLINHA: ");
  scanf("%d",&l);
  printf("\n\tCOLUNA: ");
  scanf("%d",&c);
  printf("\n\n\t**COORDENADA DA POSICAO QUE A PECA VAI OCULPAR");//PRA ONDE  A PECA VAI ..A POCISAO
  printf("\n\tLINHA: ");
  scanf("%d",&li);
  printf("\n\tCOLUNA: ");
  scanf("%d",&co);
  
  printf("%c", matriz[3][1]);
  if((li+co)%2==0)//CONDICAO SO ANDA QUANDO  A SOMA DOS INDICES  FOR PAR
  {
     if((jogador==1&&l<li)||(jogador==2&&l>li))//FAZ COM QUE A PECA ANDE SO UMA CASA .....E JOQUE UM DE CADA VEZ (PRETA OU BRANCA)
     {
      //ESSAS SAO AS CONDICOES PARA COMER UMA PECA........................................................................
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
  else printf("\n\n\t\t__MOVIMENTO INVALIDO!!_\n\t\t_JOGUE NOVAMENTE__\n");//CASO O JOGADOR ESCOLHA UMA POCISAO INVALIDA
  }
  system("pause");
  
  }
  	else if ((strcmp(a,"b")==0) || (strcmp(a,"B")==0 )){
  		ganhador(matriz);
  		system("pause");
  		exit (0);
	}

  }while(opcao!=1);//TERMINA O LACO JOGO DA DAMA
  

}

//char game1[20],game2[20];//JOGADORES  NOME
	
	
	
void ganhador(char matriz[8][8])//FUNCAO QUE DEFINE QUEM GANHOU
{
       int i,j;
         for(i=0;i<8;i++)
           for(j=0;j<8;j++)
           {
             if(matriz[i][j]==2)
             dama.cont1++;//QUANTIDADE DE PECAS PRETAS DO JOGADOR 2
             if(matriz[i][j]==1)
             dama.cont2++;//QUANTIDADE DE PECAS BRANCAS DO JOGADOR 1
           }
             if(dama.cont1>dama.cont2)//OLHA QUEM TEM MAIS PECAS....MOSTRANDO QUEM E O VENCEDOR
             {
               printf("\n\tVENCEDOR........-> %s TOTAL DE PECAS: %d\n\n",dama.game1,dama.cont1);//GAME 1...E...JOGADOR PECA PRETA
               strcpy(dama.ganhador, dama.game1);//PONTUACAO   DO  CONTADOR DO  BRANCA
               dama.pont_max=dama.cont1;//PONTUCAO MAXIMA DO CONTADOR PECA BRANCA
              }
             else
             {
             if(dama.cont1<dama.cont2)//OLHA QUEM TEM MAIS PECAS...
             {
               printf("\n\tVENCEDOR........-> %s TOTAL DE PECAS: %d\n\n",dama.game2,dama.cont2);//GAME 2 ...E ...JOGADOR PECA BRANCA
               strcpy(dama.ganhador, dama.game2);
               dama.pont_max=dama.cont2;//PONTUACAO MAXIMA DO CONTADOR PECA BRANCA
             }
            else{
               printf("\n\tEmpate!\n\t%s: %d\n\t%s: %d\n\n\n",dama.game1,dama.cont1,dama.game2,dama.cont2);//CASO DE EMPATE
               strcpy(dama.ganhador,"jogo empatado");
               dama.pont_max=dama.cont2;//PONTUACAO MAXIMA
                }
             }
 }
   void registro(void){//FUNCAO REGISTRO DO JOGO NO ARQUIVO
       fwrite(&dama, sizeof(dama), 1, historico);
                       }
   void escreve(void){//FUNCAO QUE ESCREVE NO ARQUIVO
       while(fread(&dama, sizeof(dama), 1, historico)==1)//LER A INFORMACAO ATE A ULTIMA.
       printf("\nJogador peca preta: %s\nJogador peca branca: %s\nVencedor: %s        Total de pecas: %d\n\n",dama.game1, dama.game2, dama.ganhador, dama.pont_max);
                     }




int main(int argc, char *argv[])
{
    //DECLARACAO DOS CARACTERES NO TABULEIRO...QUEM ESTA VAZIO...QUEM E PRETA E BRANCA ...E OS ESPACOS LIVRES
   char matriz[8][8], opcao2='b';
   int i,j, jogador=2,oposto=1,opcao=0;
     dama.cont1=dama.cont2=0;

  matriz[0][0]= 64;     matriz[0][1]= 0;   	matriz[0][2]= 64;	matriz[0][3] = 0; 		matriz[0][4] = 64;    matriz[0][5]= 0; 		matriz[0][6]= 64;     matriz[0][7]= 0;
  matriz[1][0]= 0;     matriz[1][1]= 64; 	matriz[1][2]= 0; 	matriz[1][3] = 64; 	matriz[1][4] = 0;	 matriz[1][5]= 64; 	matriz[1][6]= 0; 	 matriz[1][7]= 64;
  matriz[2][0]= 64;   matriz[2][1]= 0;   	matriz[2][2]= 64;  matriz[2][3] = 0; 		matriz[2][4] = 64;  matriz[2][5]= 0; 		matriz[2][6]= 64;   matriz[2][7]= 0;
  matriz[3][0]= 0;     matriz[3][1]= 0;   matriz[3][2]= 0; 	matriz[3][3] = 0; 	matriz[3][4] = 0;	 matriz[3][5]= 0; 	matriz[3][6]= 0;	 matriz[3][7]= 0;
  matriz[4][0]= 0;   matriz[4][1]= 0;   	matriz[4][2]= 0;  matriz[4][3] = 0; 		matriz[4][4] = 0;  matriz[4][5]= 0; 		matriz[4][6]= 0;   matriz[4][7]= 0;
  matriz[5][0]= 0;     matriz[5][1]= 35;   matriz[5][2]= 0; 	matriz[5][3] = 35; 	matriz[5][4] = 0;	 matriz[5][5]= 35; 	matriz[5][6]= 0; 	 matriz[5][7]= 35;
  matriz[6][0]= 35;   matriz[6][1]= 0;   	matriz[6][2]= 35;  matriz[6][3] = 0; 		matriz[6][4] = 35;  matriz[6][5]= 0; 		matriz[6][6]= 35;   matriz[6][7]= 0;
  matriz[7][0]= 0;     matriz[7][1]= 35;   matriz[7][2]= 0; 	matriz[7][3] = 35; 	matriz[7][4] = 0;	 matriz[7][5]= 35; 	matriz[7][6]= 0;	 matriz[7][7]= 35;


  do{
    //PERGUNTA OS NOMES DOS JOGADORES DAS DETERMINADAS PECAS....

    printf("\n\n");
    printf("\n");
    printf("\n");
    printf("															\n");
    printf("                   					\n");
    printf("\t 						JOGO  DE  DAMA   					\n");
    printf("\t\n\n                                       Realizado por: Caio Caobianco e Wilson Rodrigues\n");
    printf("\t\n\n                                 Para Professora de Linguagem de programacao: Eliane Santiago\n\n");

    printf("\tPrecione a ou A e Enter para jogar:\n\n");
    printf("\t a - Jogar.\n\n");
    printf("\t ");// OS NUMEROS  E PARA COLOCAR  ACENTOS........
    scanf("%c",&opcao2);//ESCOLHA DA OPCAO DO MENU.......
    system("cls");


    switch(opcao2){
				case 'A':
                case 'a' :

                     system("cls");
                     printf("\n\n\t\tINSIRA UM APELIDO PARA O JOGADOR DA PECA #:\n\n\t\t\t\t");//NOME DOS JOGADORES..
                     scanf("%s",dama.game1);
                     printf("\n\n\t\tINSIRA UM APELIDO PARA O JOGADOR DA PECA @:\n\n\t\t\t\t ");//NOME DOS JOGADORES..
                     scanf("%s",dama.game2);

                      {
                      jogador=1;oposto=2;
                      jogador1(matriz,jogador,oposto);
                      jogador=2;oposto=1;
                      jogador1(matriz,jogador,oposto);
                      }
                      
                     system("cls");
                     printf("\n\t\t..........PASSARAM 3 MINUTOS FIM DO JOGO...........\n\n\n");//APARECE NA TELA QUANDO TERMINA O TEMPO
                         ganhador(matriz);//CHAMADA DA FUNCAO GANHADOR .........
                         registro();//CHAMADA DA FUNCAO REGITRO ...RESPONSAVEL POR GRAVAR AS INFORMACOES
                     system("pause");
                     system("cls");
                     break;


    }
  }while(opcao2!='b');//LACO PARA TERMINAR O SWITCH...
      fclose(historico);//FECHAMENTO DO ARQUIVO .....
      system("PAUSE");
  return 0;
}
