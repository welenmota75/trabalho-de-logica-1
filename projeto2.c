#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM_TABULEIRO 10
#define TRUE 1
#define FALSE 0
#define MAX_PLAYERS 10

char nomePlayers[MAX_PLAYERS][9] = {
"Player_1",
"Player_2",
"Player_3",
"Player_4",
"Player_5",
"Player_6",
"Player_7",
"Player_8",
"Player_9",
"Player10"
};

void aguarde();
void comando(char * comand);
void arpaLogo();
void exibirMenu();
void regras();
void comoJogar();
void renomearPlayers();
void exibirTabuleiro();
int sorteioLinha();
int sorteioColuna(int sort);
int calculoPontuacao(int nsorteado, int numEscolhido);

main() {
	comando("color F1");
	arpaLogo();
	aguarde(5000);
	int condicao = 1,cod;
	do{
		comando("color F1");
		comando("cls");
		printf("\n\t\tBEM VINDO AO JOGO!");
		exibirMenu();
		printf("\n\nInsira o Codigo da Opcao ->");
		scanf("%d",&cod);
		fflush(stdin);
		switch(cod){
			case 1:
				codigoGame();
			break;
			case 2:
				renomearPlayers();
			break;
			case 3:
				comoJogar();
			break;
			case 4:
				regras();
			break;
			case 5:
				condicao = 0;
			break;
			default:
				printf("\nOpção Inválida!\n\n");
				comando("Pause");
				comando("cls");
			break;
		}
	}while(condicao != 0);
}

void aguarde(max){
	int tempo = clock();
	while(clock() - tempo < max){}
}
void comando(char * comand){
	system(comand);
}
void arpaLogo(){	
	printf("\n\n\n");
	printf("\t\t\t%c%c%c%c  ", 219,223,223,219);
	printf("%c%c%c%c  ", 219,223,223,219);
	printf("%c%c%c%c  ", 219,223,223,219);
	printf("%c%c%c%c %c", 219,223,223,219,184);
	
	printf("\n\t\t\t");
	printf("%c%c%c%c  ",219,220,220,219);
	printf("%c%c%c%c  ",219,220,220,219);
	printf("%c%c%c%c  ",219,220,220,219);
	printf("%c%c%c%c  ",219,220,220,219);
	
	printf("\n\t\t\t");
	printf("%c  %c  ", 219,219);
	printf("%c %c   ", 219,219);
	printf("%c     ", 219);
	printf("%c  %c  ", 219,219);
	printf("\n\n\t\t\t   ");
	printf("Sortei da sorte",184);
	
}
void exibirMenu(){
	printf(
		"\n\n\t  ESCOLHA UMA DAS OPCOES ABAIXO: \n\n"
		"\t     1 -> JOGAR (PLAY GAME)\n"
		"\t     2 -> RENOMEAR JOGADORES\n"
		"\t     3 -> COMO JOGAR?\n"
		"\t     4 -> REGRAS\n"
		"\t     5 -> SAIR\n");
}
void regras(){
	comando("cls");
			printf(
			"\n\t\t\t   REGRAS DO JOGO\n\n"
			"\t|                                                    |\n"
			"\t|  1. Cada pessoa tem o direito de escolher apenas   |\n"
			"\t|  uma vez por jogada.                               |\n"
			"\t|                                                    |\n"
			"\t|  2. Quem chegar mais perto ganha mais pontos.      |\n"
			"\t|                                                    |\n"
			"\t|  3. A pontuacao maxima por rodada eh de 1000 pon-  |\n"
			"\t|  tos te equivale ao acerto.                        |\n"
			"\t|                                                    |\n"
			"\t|  4. A posicao certa sera sorteada antes do inicio  |\n"
			"\t|  da rodada.                                        |\n"
			"\t|                                                    |\n"
			"\t|  5. Ao fim da rodada sera exibida a posicao cor-   |\n"
			"\t|  reta, as escolhas dos jogadores e suas respecti-  |\n"
			"\t|  vas pontuacoes.                                   |\n"
			"\t|                                                    |\n\n\n\n");
	comando("Pause");
}
void comoJogar(){
	comando("cls");
	printf("\n\t\t\t     COMO JOGAR\n\n"
			"\t|                                                    |\n"
			"\t|  O jogo consiste em uma tabela e funciona por um   |\n"
			"\t|  sistema de linhas e colunas. O objetivo do jogo   |\n"
			"\t|  eh chegar o mais proximo possivel do quadrado     |\n"
			"\t|  sorteado. O primeiro jogador seleciona a linha    |\n"
			"\t|  a coluna e então o proximo escolhe a linha e co-  |\n"
			"\t|  luna também assim sucessivamente até todos terem  |\n"
			"\t|  escolhido os valores da rodada. Ao fim da rodada  |\n"
			"\t|  sera exibido os placares que todos os jogadores   |\n"
			"\t|  obtiveram na rodada. Ao fim de todas as rodadas   |\n"
			"\t|  sera exibido os placares totais dos jogadores.    |\n"
			"\t|                                                    |\n\n\n\n");
	comando("Pause");
}
void renomearPlayers(){
	comando("cls");
	int i,d;
	printf("Quantos nomes vai mudar? -> ");
	scanf("%d", &d);
	fflush(stdin);
	printf("\n\nLembrando que os nomes devem conter exatos 8 caracteres\n\n");
	comando("Pause");
	if(d <= MAX_PLAYERS){
		for(i=0;i<d;i++){
			comando("cls");
			comando("color F1");
			char vetaux[10];
			printf("\n\nDe %s Para -> ", nomePlayers[i]);
			scanf("%8[^\n]s", vetaux);
			fflush(stdin);
			if(strlen(vetaux) < 8){
				printf("\nNome digitado tem menos de 8 caracteres, tente novamente\n\n");
				comando("color CF");
				comando("Pause");
				i--;
			}else{
				strcpy(nomePlayers[i],vetaux);
			}
			
		}
	}else{
		comando("cls");
		comando("color CF");
		printf("\nNosso jogo não comporta essa quantidade de jogadores...\n\nVolte ao menu principal e tente novamente.\n\n");
		comando("Pause");
	}
	
}
void exibirTabuleiro(){
	comando("cls");
	int lin, col;
	printf("\t\t   0 1 2 3 4 5 6 7 8 9");
	for(lin=1; lin<=TAM_TABULEIRO; lin++) {

		printf("\n \t\t%d ",lin-1);
		for(col=1; col<=TAM_TABULEIRO; col++) {
			if( (lin+col)%2 == 0 ) printf("%c%c",219,219);
			else printf("%c%c",177,177);
		}
	}
}
int sorteioLinha(){
	int linha;
	srand((unsigned)time(NULL));
	linha = rand() % 10;
	return linha;
}
int sorteioColuna(int sort){
	int coluna;
	srand((unsigned)sort*971923);
	coluna = rand() % 10;
	return coluna;
}
int calculoPontuacao(int nsorteado, int numEscolhido){
	if(numEscolhido == nsorteado){
		return 1000;
	}else if(numEscolhido == nsorteado-1||numEscolhido == nsorteado+1|| numEscolhido == nsorteado+10 || numEscolhido == nsorteado-10 || numEscolhido == nsorteado+11 || numEscolhido == nsorteado-11 || numEscolhido == nsorteado-9 || numEscolhido == nsorteado+9){
		return 750;
	}else if(numEscolhido == nsorteado+2 || numEscolhido == nsorteado-2 || numEscolhido == nsorteado-20 || numEscolhido == nsorteado+20 || numEscolhido == nsorteado+12 || numEscolhido == nsorteado-12 || numEscolhido == nsorteado+8 || numEscolhido == nsorteado-8 || numEscolhido == nsorteado+18 || numEscolhido == nsorteado-18 || numEscolhido == nsorteado+19 || numEscolhido == nsorteado-19 || numEscolhido == nsorteado+21 || numEscolhido == nsorteado-21 || numEscolhido == nsorteado+22 || numEscolhido == nsorteado-22){
		return 500;
	}else if(numEscolhido == nsorteado-33 || numEscolhido == nsorteado+33 || numEscolhido == nsorteado-32 || numEscolhido == nsorteado+32 || numEscolhido == nsorteado+31 || numEscolhido == nsorteado-31 || numEscolhido == nsorteado-30 || numEscolhido == nsorteado+30 || numEscolhido == nsorteado-29 || numEscolhido == nsorteado+29 || numEscolhido == nsorteado-28 || numEscolhido == nsorteado+28 || numEscolhido == nsorteado-27 || numEscolhido == nsorteado+27 || numEscolhido == nsorteado-23 || numEscolhido == nsorteado+23 || numEscolhido == nsorteado-17 || numEscolhido == nsorteado+17 || numEscolhido == nsorteado-13 || numEscolhido == nsorteado+13 || numEscolhido == nsorteado-3 || numEscolhido == nsorteado+3 || numEscolhido == nsorteado+7 || numEscolhido == nsorteado-7){
		return 250;
	}else {
		return 50;
	}	
}

void codigoGame(){
	int matrizDados[TAM_TABULEIRO][TAM_TABULEIRO];
	int lin, col, n_jogadores, n_rodadas,i,j;
	
	//DECLARANDO POSIÇÕES E SEUS RELATIVOS VALORES DO TABULEIRO
	int contadorTotal = 1;
	for(i=0;i<TAM_TABULEIRO;i++){
		for(j=0;j<TAM_TABULEIRO;j++){
			matrizDados[i][j] = contadorTotal;
			contadorTotal++;
		}
	}
	
	comando("cls");
	
	//QUANTIDADE DE JOGADORES
	printf("\n Quantos jogadores? ->");
	scanf("%d", &n_jogadores);
	
	//QUANTIDADE DE RODADAS
	printf("\n Quantas Rodadas? ->");
	scanf("%d", &n_rodadas);
	int teste;
	printf("\n Mudar nome dos jogadores? (1 - sim)-> ");
	scanf("%d", &teste);
	if(teste == 1){
		renomearPlayers(n_jogadores);
	}
	
	//DECLARAÇÃO DOS VETORES RELACIONADOS AO Nº DE JOGADORES
	int l[n_jogadores],c[n_jogadores], score[n_jogadores],dropscore[n_jogadores], scoreALL[n_jogadores], scoreRodada[n_jogadores];
	int rodada = 1;
	for(i=0;i<n_jogadores;i++){
			score[i] = 0;
	}
	do{
		comando("cls");
		comando("color F0");
		printf("\n\n\n\t\t\tROUND %d", rodada);
		aguarde(4000);
		comando("cls");
		//SORTEIO DOS NUMEROS (CHAMANDO AS FUNÇÕES) A CADA RODADA
		int lSorteada = sorteioLinha();
		int cSorteada = sorteioColuna(lSorteada);
		int sorteado = matrizDados[lSorteada][cSorteada];
		
		 printf("Posicao[%d][%d]\n\n%d\n\n",lSorteada,cSorteada,sorteado);
		 system("Pause");
		
		for(i=0;i<n_jogadores;i++){
			exibirTabuleiro();
			printf("\n\n\t\t%s:\n", nomePlayers[i]);
			printf("\nInsira a Linha -> ");
			scanf("%1d",&l[i]);
			fflush(stdin);
			printf("\nInsira a Coluna -> ");
			scanf("%1d",&c[i]);
			scoreRodada[i] = calculoPontuacao(sorteado, matrizDados[l[i]][c[i]]);
			score[i] += scoreRodada[i];
			scoreALL[i] = score[i];
			fflush(stdin);
		}
		
		int aux, jogador_f;
		
		// GNOME SORT 
		i = 0;
	    while (i < n_jogadores){
	        if (i == 0 || scoreALL[i - 1] >= scoreALL[i]){
	        	i++;
			}else{
				
	            aux = scoreALL[i-1];
	            scoreALL[i - 1] = scoreALL[i];
	            scoreALL[i] = aux;
	            i = i - 1;
	        }
	    }
	    // FIM DO GNOME SORT
	    int color = FALSE;
	    comando("cls");
	    //SE ALGUÉM ACERTAR, MUDA A COR PARA AZUL
	    for(i=0;i<n_jogadores;i++){
	    	if( l[i] == lSorteada && c[i] == cSorteada){
	    		color = TRUE;
			}
		}
	    if(color == TRUE){
	    	comando("color F9");
		}
		// SE NINGUÉM ACERTAR, A COR DO RESULTADO FICA VERMELO
		else{
			comando("color F4");
		}
		//EXIBIÇÃO DO JOGADOR E DA SUA PONTUAÇÃO
		for(i=0;i<n_jogadores;i++){
			dropscore[i] = score[i];
		}
		exibirTabuleiro();
		printf("\a\n\n\t  POSICAO SORTEADA NA RODADA %d de %d:\n\t       LINHA -> %d  | COLUNA -> %d\n\n",rodada,n_rodadas,lSorteada,cSorteada);
	
		printf("\t    ================= TABELA =================\n");
	    for(i=0;i<n_jogadores;i++){
	    	for(j=0;j<n_jogadores;j++){
	    		if(scoreALL[i] == dropscore[j]){
	    			dropscore[j] = 0;
					jogador_f= j;
					j = n_jogadores+1;
				}
			}
			if(scoreRodada[jogador_f] < 100){
				if(scoreALL[i] < 100){
					printf("%d%c -> %s | Pontos -   %d | Total -   %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else if(scoreALL[i] < 1000){
					printf("%d%c -> %s | Pontos -   %d | Total -  %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else{
					printf("%d%c -> %s | Pontos -   %d | Total - %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}
			}else if(scoreRodada[jogador_f] < 1000){
				if(scoreALL[i] < 100){
					printf("%d%c -> %s | Pontos -  %d | Total -   %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else if(scoreALL[i] < 1000){
					printf("%d%c -> %s | Pontos -  %d | Total -  %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else{
					printf("%d%c -> %s | Pontos -  %d | Total - %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}
			}else{
				if(scoreALL[i] < 100){
					printf("%d%c -> %s | Pontos - %d | Total -   %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else if(scoreALL[i] < 1000){
					printf("%d%c -> %s | Pontos - %d | Total -  %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}else{
					printf("%d%c -> %s | Pontos - %d | Total - %d | Linha %d | Coluna %d\n",i+1,167, nomePlayers[jogador_f], scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
				}
			}
	    //	printf("%dº -> Jogador %d | Pontos - %d | Total - %d | Linha %d | Coluna %d\n",i+1, jogador_f+1, scoreRodada[jogador_f], scoreALL[i], l[jogador_f],c[jogador_f]);
		}
		printf("\n\n");
		comando("Pause");
		rodada++;
	}while(rodada <= n_rodadas);
	
	comando("color F5");
	int jogador_f;
	//EXIBIÇÃO DO JOGADOR E DA SUA PONTUAÇÃO FINAL
		for(i=0;i<n_jogadores;i++){
			dropscore[i] = score[i];
		}
		exibirTabuleiro();
		//setlocale(LC_ALL,"Portuguese");
		printf("\a\n\n\t\tPONTUACOES FINAIS\n\n");
	
		printf("\t\t============ TABELA ============\n");
	    for(i=0;i<n_jogadores;i++){
	    	for(j=0;j<n_jogadores;j++){
	    		if(scoreALL[i] == dropscore[j]){
	    			dropscore[j] = 0;
					jogador_f= j;
					j = n_jogadores+1;
				}
			}
	    	printf("\t%d%c -> %s | Pontuacao - %d \n",i+1,167, nomePlayers[jogador_f], scoreALL[i]);
		}
		printf("\n");
		getch();
}
