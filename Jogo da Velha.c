#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "portuguese");

	//variáveis
	int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
	char jogo[3][3];


	do
	{
		system("cls");
		jogador = 1;
		ganhou = 0;
		jogadas = 0;

		// inicializando a estrutura
		for(l = 0; l < 3; l++)
		{
			for(c = 0; c < 3; c++)
			{
				jogo[c][l] = ' ';
			}
		}

		do
		{
			system("cls");
			//imprimir jogo - estrutura
			printf("\n\n\t 0   1   2 \n\n");
			for(l = 0; l < 3; l++)
			{
				for(c = 0; c < 3; c++)
				{
					printf(" %c ", jogo[c][l]);
					if(c == 0)
					{
						printf("\t");
						printf(" %c ", jogo[c][l]);
					}

					if(c < 2)
					{
						printf("|");
					}
					if(c == 2)
					{
						printf(" %d", l);
					}
				}
				if(l < 2)
				{
					printf("\n\t...........\n");
				}
			}
			printf("\n\n");

			//ler coordenadas

			do
			{
				printf("\n\tJOGADOR %d - digite a coordenada desejada. \n COLUNA e a LINHA, RESPECTIVAMENTE, separadas por espaço, e depois basta cllicar enter.. ", jogador);
				scanf("%d %d", &coluna, &linha);
			}
			while( linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[coluna][linha] != ' ');

			//salvar coordenadas

			if(jogador == 1)
			{
				jogo[coluna][linha] = 'O';
				jogador++;
			}
			else
			{
				jogo[coluna][linha] = 'X';
				jogador = 1;
			}
			jogadas++;

			//Ganhador por linha

			if((jogo[0][0] == 'O') && (jogo[0][1] == 'O') && (jogo[0][2] == 'O') ||
					(jogo[1][0] == 'O') && (jogo[1][1] == 'O') && (jogo[1][2] == 'O') ||
					(jogo[2][0] == 'O') && (jogo[2][1] == 'O') && (jogo[2][2] == 'O'))
			{
				printf("\n\tParabéns! O jogador 1 venceu por Coluna!\n");
				ganhou = 1;
			}
			if((jogo[0][0] == 'X') && (jogo[0][1] == 'X') && (jogo[0][2] == 'X') ||
					(jogo[1][0] == 'X') && (jogo[1][1] == 'X') && (jogo[1][2] == 'X') ||
					(jogo[2][0] == 'X') && (jogo[2][1] == 'X') && (jogo[2][2] == 'X'))
			{
				printf("\n\tParabéns! O jogador 2 venceu por Coluna!\n");
				ganhou = 1;
			}

			//Ganhador por coluna

			if((jogo[0][0] == 'O') && (jogo[1][0] == 'O') && (jogo[2][0] == 'O') ||
					(jogo[0][1] == 'O') && (jogo[1][1] == 'O') && (jogo[2][1] == 'O') ||
					(jogo[0][2] == 'O') && (jogo[1][2] == 'O') && (jogo[2][2] == 'O'))
			{
				printf("\n\tParabéns! O jogador 1 venceu por Linha!\n");
				ganhou = 1;
			}
			if((jogo[0][0] == 'X') && (jogo[1][0] == 'X') && (jogo[2][0] == 'X') ||
					(jogo[0][1] == 'X') && (jogo[1][1] == 'X') && (jogo[2][1] == 'X') ||
					(jogo[0][2] == 'X') && (jogo[1][2] == 'X') && (jogo[2][2] == 'X'))
			{
				printf("\n\tParabéns! O jogador 2 venceu por Linha!\n");
				ganhou = 1;
			}

			//Ganhador por diagonal principal

			if((jogo[0][0] == 'O') && (jogo[1][1] == 'O') && (jogo[2][2] == 'O'))
			{
				printf("\n\tParabéns! O jogador 1 venceu por Diagonal Principal!\n");
				ganhou = 1;
			}
			if((jogo[0][0] == 'X') && (jogo[1][1] == 'X') && (jogo[2][2] == 'X'))
			{
				printf("\n\tParabéns! O jogador 2 venceu por Diagonal Principal!\n");
				ganhou = 1;
			}

			//Ganhador por diagonal secundária

			if((jogo[0][2] == 'O') && (jogo[1][1] == 'O') && (jogo[2][0] == 'O'))
			{
				printf("\n\tParabéns! O jogador 1 venceu por Diagonal Secundária!\n");
				ganhou = 1;
			}
			if((jogo[0][2] == 'X') && (jogo[1][1] == 'X') && (jogo[2][0] == 'X'))
			{
				printf("\n\tParabéns! O jogador 2 venceu por Diagonal Secundária!\n");
				ganhou = 1;
			}
		}
		while(ganhou == 0 && jogadas < 9);

		if(ganhou == 0)
		{
			printf("\n\tO jogo finalizou sem ganhador!\n");
		}
		printf("\n\tDigite 1 para jogar novamente, ou outro número para sair do jogo: \n");
		scanf("%d", &opcao);
	}
	while(opcao == 1);


	return 0;
}
