/* Esse programa � respons�vel por simular um jogo de domin�,com 2 ou 4 jogarores em cada partida.
 Feito por:
 Fernando Schettini (o mais foda) Github:https://github.com/FernandoSchett */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h> 
#include <time.h>
#include "Pilha.h"
#include "Fila.h"	

void EscolhePrimeiro(int *escolhido, char *j1, char *j2, char *j3, char *j4){
	switch (*escolhido){
		case 1:
			printf ("Jogador %s comeca!\n", j1);	
		case 2:
			printf ("Jogador %s comeca!\n", j2);	
		case 3:
			printf ("Jogador %s comeca!\n", j3);	
		case 4:	
			printf ("Jogador %s comeca!\n", j4);	
	}
	printf ("A ordem do escolhido sempre segue no sentido crescente! 1 -> 2 -> 3 -> 4\n");	
	system("pause");
	system("cls"); 

}

void Sorteador(int *possibilidade, int *escolhido){ //Esse funcao vai sortear com base no inteiro que recebeu.
	int random, nrandom;
	long double	chance;
	
	srand(time (NULL)); //Generate seed for rand(),based in your pc time.
	//printf("%d\n", *possibilidade);
	random = (rand() % 100); //Generate random number in range 1-100.
	//printf("random: %d\n", random);
	chance =  100 / *possibilidade; //chance of getting any number.
	//printf("chance: %lf \n", chance);

	nrandom = 0;
	*escolhido = 0;
	
	while(nrandom < random){ //Look for the range.
		nrandom = nrandom  + chance;
	//	printf("escolhido: %d\n", *escolhido);
	//	printf("nrandom: %d\n", nrandom);
		*escolhido = *escolhido + 1;	
	}
	//printf("escolhido: %d\n", *escolhido);
}
void MenuDoJogo(int *res){ //Fun��o repons�vel pelo menu inicial do jogo.
 
	printf("Bem-vindo ao MELHOR jogo de domin� da AMERA-LATINA e afiliados.\n");
	printf("Insira o n�mero 1 para jogar ou 0 para arregar :'(\n");
	scanf(" %d", res);
	while(*res != 0 & *res != 1 ){
		printf("Valor inv�lido.\n");
    	printf("Insira um valor v�lido, 1 para jogar ou 0 para arregar:\n");
    	scanf(" %d", res);
	}
	system("pause");
	system("cls"); //Limpa o terminal.
}

void EscolheOsNomesDosJogadores(int *numj, char *j1, char *j2, char *j3, char *j4){
	printf("Quantos jogadores vao jogar?\n");
	scanf(" %d", numj);
	
	while(*numj != 2 & *numj != 4 ){
		printf("Valor inv�lido.\n");
		printf("Insira um valor v�lido, pode-se apenas jogar com 2 ou 4 jogadores:\n");
    	scanf(" %d", numj);
	}
	
	if( *numj == 4){ //4 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %[^\n]s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2);
		printf("Nome do terceiro jogador:\n");
		scanf(" %[^\n]s", j3);
		printf("Nome do quarto jogador:\n");
		scanf(" %[^\n]s", j4);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de domin� tem nome!\n");
		printf("Jogador n�mero 1: %s\n", j1);
		printf("Jogador n�mero 2: %s\n", j2);
		printf("Jogador n�mero 3: %s\n", j3);
		printf("Jogador n�mero 4: %s\n", j4);
	}
	
	if( *numj == 2){ //2 jogadores.
		//Recolhe o nome dos jogaores.
		printf("Nome do primeiro jogador:\n");
		scanf(" %[^\n]s", j1);
		printf("Nome do segundo jogador:\n");
		scanf(" %[^\n]s", j2);
		
		system("pause");
		system("cls"); //Limpa o terminal.
		
		//Apresenta os jogadores.
		printf("Os melhores jogadores de domin� tem nome!\n");
		printf("Jogador n�mero 1: %s \n", j1);
		printf("Jogador n�mero 2: %s \n", j2);	
	}
	system("pause");
	system("cls"); 
}

typedef struct{
  int top, bottom; //EITA BIXO SEXO
}tp_pedra;

tp_pedra pedra00, pedra01, pedra02, pedra03, pedra04, pedra05, pedra06;
tp_pedra pedra11, pedra21, pedra31, pedra41, pedra51, pedra61, pedra22;
tp_pedra pedra32, pedra42, pedra52, pedra62, pedra33, pedra43, pedra53; 
tp_pedra pedra63, pedra44, pedra54, pedra64, pedra55, pedra65, pedra66; // Declarando todas as pecas do jogo ** NAO SEI SE VAI SER ASSIM **


void embaralhandoPecas(){

}
int main(){
	//Declarando as v�riaveis.
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem para portugu�s.
	int res, numj, choosen;
	char j1[100], j2[100],j3[100],j4[100];
	
	//Come�ando o jogo.
	//textbackground(1); // PINTA O FUNDO DO TEXTO
	//textcolor(3); //Pinta a cor da fonte nao sei usar
	

	MenuDoJogo(&res); //Iniciando o menu jogo.
	
	if (res == 0){  //N�o vai jogar/Deistencia.
		printf("Percebi que voce desistiu. FRACO!\n"); 
	}
	else{      //Vai jogar.
		EscolheOsNomesDosJogadores(&numj, j1, j2, j3, j4);
		Sorteador(&numj, &choosen); //sorteia quem comeca.
		EscolhePrimeiro(&choosen, j1, j2, j3, j4);
		
	}
	return 0;
} 
