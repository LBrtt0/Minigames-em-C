#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

void show();

int x =0, y = 0, aux, vitoria=0, i, j;
char mp[4][4] = {'A','B','C','D',
				 'E', 'F', 'G', 'H',
				 'I', 'J', 'K', 'L',
				 'M', 'N', ' ', 'O'};
				
int main(){
	
	setlocale(LC_ALL,"portuguese");
	
	show();
	
while(!GetAsyncKeyState(VK_ESCAPE)){
	
	//Movimento das chaves
	if(GetAsyncKeyState(VK_LEFT) != 0 && x > 0) {x--; show();}
	if(GetAsyncKeyState(VK_RIGHT) != 0 && x < 3) {x++; show();}
	if(GetAsyncKeyState(VK_DOWN) != 0 && y < 3) {y++; show();}
	if(GetAsyncKeyState(VK_UP) != 0 && y > 0){y--; show();}
		
		//Troca as peças
		if(GetAsyncKeyState(VK_SPACE) != 0){
			for(i = 0; i < 4; i++){
				for(j = 0; j < 4; j ++){
					if(j==x && i==y){					
					if(j>0 && mp[i][j-1] == ' '){mp[i][j-1] = mp[i][j];	mp[i][j] = ' ';}
					if(j<3 && mp[i][j+1] == ' '){mp[i][j+1] = mp[i][j];	mp[i][j] = ' ';}
					if(i<3 && mp[i+1][j] == ' '){mp[i+1][j] = mp[i][j];	mp[i][j] = ' ';}
					if(i>0 && mp[i-1][j] == ' '){mp[i-1][j] = mp[i][j];	mp[i][j] = ' ';}
				}
				}	
			}
		}
		

		
	//animação vitória
	
	show();
	if(vitoria==8){
		printf("\t\t JOGO COMPLETADO ");
		Sleep(100);
		getch();
	}	
		getch();
}
	
}

void show(){
	
	system("cls"); // limpar a tela
	vitoria = 0;
	
	printf("\n\t\tOlá! Este é o jogo dos 15 e \n\t\tseu objetivo é colocar as letras na ordem alfabética.\n");
	printf("\n\t\tPressione as SETAS para selecionar uma letra perto do espaço vazio,\n\t\tESPAÇO na letra que deseja mover e\n\t\tESC 2x para sair do jogo.\n");
	printf("\n\n\t\tBom jogo e boa sorte!\n\n");
	
	printf("\t\t__________________________\n\n");
	
	for(i = 0; i < 4; i++){
		printf("\t\t| ");
		for(j = 0; j < 4; j++){
			if (j==x && i == y){
				printf("[ %c ] | ", mp[i][j]);
			}
			else
			{
				printf("  %c  | ", mp[i][j]);
			}
			if(i==0 && j==0 && mp[i][j] == 'A'){
				vitoria++;
			}
			if(i==0 && j==3 && mp[i][j] == 'D'){
				vitoria++;
			}
			if(i==1 && j==0 && mp[i][j] == 'E'){
				vitoria++;
			}
			if(i==1 && j==3 && mp[i][j] == 'H'){
				vitoria++;
			}
			if(i==2 && j==0 && mp[i][j] == 'I'){
				vitoria++;
			}
			if(i==2 && j==3 && mp[i][j] == 'L'){
				vitoria++;
			}
			if(i==3 && j==0 && mp[i][j] == 'M'){
				vitoria++;
			}
			if(i==3 && j==2 && mp[i][j] == 'O'){
				vitoria++;
			}
		}
		printf("\n\n");
	}
	
	printf("\t\t__________________________\n\n");
	
	Sleep(100);
}