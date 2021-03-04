#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAB 8
#define casa_vazia 0
#define A 1
#define B 2
#define AD 3
#define BD 4
#define casa_branca -1

/*Lab 06 - Wilson Rodrigues
Status: incompleto
*/

int matriz[TAB][TAB] = /*{{-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1},
	                        {-1, -1, -1, -1, -1, -1, -1, -1}};*/

char pecas[3] = {' ', 'A', 'B'};

void campo() {
	system("cls");

	int i = 0, j = 0, lin = 0, col = 0, l = 0, c = 0;

	printf("\033[36;40;1m     0    1    2    3    4    5    6    7  \n");
	for (i = 0; i < TAB; i++) //peças brancas
	{
		printf("\033[36;40;1m%d  ", i);
		for (j = 0; j < TAB; j++)
		{
			if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 == 1) && (j % 2 == 1)))
			{
				if (i<3) matriz[i][j]= 1; //brancas
				else if (i>4) matriz[i][j] = 2; //pretas
				else matriz[i][j] = 0;//vazio

			}
			//if (matriz[i][j] == 0)
			{
			    if (i % 2 == 0)
			     if (j % 2 == 0) printf("\033[41m  %c  ", pecas[matriz[i][j]]);
			     else printf("\033[45m  %c  ", pecas[matriz[i][j]]);
			    else
			     if (j % 2 == 0) printf("\033[45m  %c  ", pecas[matriz[i][j]]);
			     else printf("\033[41m  %c  ", pecas[matriz[i][j]]);
			}
			//else printf("\033[0m%c\t", pecas[matriz[i][j]]);
		}
		printf("\n");
	}


	printf("\n\n\t\t\tLINHA => ");
	scanf("\n%d", &l);
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int lin = 0, col = 0, i = 0, j = 0, opcao=0, menu = 0;
	do
	{
		printf("\n\t Bem vindo ao jogo de Damas!");
		printf("\n\t 1 - Iniciar jogo.");
		printf("\n\t 2 - Informações do jogo.");
		printf("\n\t 3 - Sair do jogo.");
		printf("\n\n\t Selecione uma opção => ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1: //COMEÇAR O JOGO (FUNÇÃO JOGO)
			campo();

			break;

		case 2: // INFORMAÇÕES DO JOGO
			break;

		case 3: //SAIR DO JOGO
			system("cls");
			printf("\n\tVOCÊ SAIU DO JOGO!");
			break;

		default:
			system("cls");
			printf("\n\tOPÇÃO INVÁLIDA, TENTE NOVAMENTE!");

			//return 0
		}
	} while (menu != 3);
    return 0;
}
