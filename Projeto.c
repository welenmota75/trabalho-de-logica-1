#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define DIM 3
int vez;
 
int menu(void);
void clear(void);
void zeraTabuleiro(int tabuleiro[][DIM]);
void exibeTabuleiro(int tabuleiro[][DIM]);
void jogar(int tabuleiro[][DIM]);
int checaLocal(int tabuleiro[][DIM], int linha, int coluna);
int checaLinha(int tabuleiro[][DIM]);
int checaColuna(int tabuleiro[][DIM]);
int checaDiagonal(int tabuleiro[][DIM]);
int checaEmpate(int tabuleiro[][DIM]);
int checaTermino(int tabuleiro[][DIM], int vez);
void jogada(int tabuleiro[][DIM]);
 
 //texto do arquivo basicamente
  void falencia(){
  	
  	char historia[500];
 	
    FILE *fp = fopen("basicamente.txt", "r"); 

    char ch; 
    int i = 0;
    while ((ch = fgetc(fp)) != EOF){
        historia[i] = ch;
        i++;
    }
    fclose(fp);	
 		
printf(historia);

 }
 
 
 void ajuda(){
//clear();
system("cls");
 	printf("Siga as instrucoes na tela, entre parenteses, para jogar\n\n\n\n"); 	 	
 	printf("(Pressione algo para continuar)\n");
 		getchar();
 }
 
int main(void)
{
	
  		int resposta;
  		
 		//narrativa
 		printf("Recrutadora diz - Voces estao confortaveis?\n\n\n\n");
 		printf("(Digite '1' para ajuda ou qualquer outra coisa para continuar)\n");
 		scanf("%d", &resposta);
 		
 		
 		if (resposta==1){ 			
 			ajuda();
			resposta = 0;
		 }
		 
 			fflush(stdin);
 			getchar();
 			fflush(stdin);
 		//clear();
 		system("cls");
 		
 		printf("Recrutadora diz - Certo, a reposta nao me importa. Voces dois foram os unicos a virem pra dinamica de grupo... Realmente, eu achei que ninguem viria...\n\n\n\n");
 		printf("(Pressione algo para continuar)\n");
 		
 		getchar();
 		fflush(stdin);
 		
 		//clear();
 		system("cls");
 		
 		printf("Recrutadora diz - Nao vao dizer que voces nao viram o que aconteceu?\n\n\n\n");
 		
 		printf("(Digite o numero de uma resposta) \n 1 - Vimos o que? \n 2 - Vimos sim\n");
 		scanf("%d", &resposta);
 		
 		//clear();
 		system("cls");
 		
 		switch(resposta){
 		case 1:
			falencia();
 			printf("\n\n(Pressione algo para continuar)\n");
 			scanf("%d", &resposta);
 			fflush(stdin);
 			getchar();
 			fflush(stdin);
 			//clear();
 			system("cls");
 			break;
 			
 		case 2:
 			printf("Recrutadora diz - Sei que estao mentindo ou nao estariam aqui... entao, basicamente...\n");
			falencia();
 			printf("\n\n(Pressione algo para continuar)\n");
 			fflush(stdin);
 			getchar();
 			fflush(stdin);
 			//clear();
 			system("cls");
 			break;
 			
 		default:
 			
 			printf("Recrutadora diz - Vi que voces nao sao muito de falar... bem, basicamente...\n");
			falencia();
			
 			printf("\n\n(Digite e envie qualquer coisa para continuar)\n");
 			
 			fflush(stdin);
 			getchar();
 			fflush(stdin);

 			//clear();
 			system("cls");
 		}
 		
 		printf("Recrutadora diz - Entao, chega de papo furado. A verdade e que o processo de falencia leva tempo, entao ainda temos que preencher a vaga.");
 		printf("\nRecrutadora diz - So de voces terem vindo, mesmo que desinformados, ja posso considerar um dos dois como novo integrante da firma...");
 		printf("\nRecrutadora diz - Pra facilitar a minha vida e a de voces, vou mudar a dinamica que tinha preparado... ");
 		printf("\nRecrutadora diz - Ja sei. Quem ganhar no jogo da velha, considere-se empregado. Boa sorte.");
 		printf("\n\n\n A recrutadora entrega um papel e duas canetas. E hora de... \n");
 		
 		printf("(Pressione algo para continuar)\n");

 		getchar();
 		//clear();
 		system("cls");
	
	
    int tabuleiro[DIM][DIM],
        continuar;
 
    do
    {
        vez=1;
        continuar = menu();
        if(continuar == 1)
            jogar(tabuleiro);
 
    }while(continuar);
 
    return 0;
}
 
 

 
int menu(void)
{
	
 			
    int opcao;
 

 		
 		
        printf("\t\tJogo da Velha");
        printf("\n1.Comecar dinamica de grupo\n");
        printf("0.Voltar pra casa\n");
        printf("\nOpcao: ");
 
        scanf("%d", &opcao);
 
        switch(opcao)
        {
           case 1:
           case 0:
                break;
           default:
                clear();
                printf("Opcao invalida. Tente de novo!\n");
        }
 
    return opcao;
}
 
void clear(void)
{
    int count=0;
 
    while(count != 100)
    {
        putchar('\n');
        count++;
    }
}
 
void zeraTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            tabuleiro[linha][coluna] = 0;
}
 
void exibeTabuleiro(int tabuleiro[][DIM])
{
    int linha, coluna;
    putchar('\n');
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        for(coluna = 0 ; coluna < DIM ; coluna++)
        {
            if(tabuleiro[linha][coluna] == 0)
                printf("    ");
            else
                if(tabuleiro[linha][coluna] == 1)
                    printf("  X ");
                else
                    printf("  O ");
 
            if(coluna != (DIM-1))
                printf("|");
        }
        putchar('\n');
    }
    putchar('\n');
}
 
void jogar(int tabuleiro[][DIM])
{
    int continua;
    zeraTabuleiro(tabuleiro);
 
    do
    {
        clear();
        exibeTabuleiro(tabuleiro);
        jogada(tabuleiro);
 
    }while(checaTermino(tabuleiro, vez) != 1);
}
 
 
int checaLocal(int tabuleiro[][DIM], int linha, int coluna)
{
    if(linha < 0 || linha > (DIM-1) || coluna < 0 || coluna > (DIM-1) || tabuleiro[linha][coluna] != 0)
        return 0;
    else
        return 1;
}
 
int checaLinha(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        soma=0;
 
        for(coluna = 0 ; coluna < DIM ; coluna++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }
 
    return 0;
}
 
int checaColuna(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;
 
 
    for(coluna = 0 ; coluna < DIM ; coluna++)
    {
        soma=0;
 
        for(linha = 0 ; linha < DIM ; linha++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }
 
    return 0;
}
 
int checaDiagonal(int tabuleiro[][DIM])
{
    int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][DIM-linha-1];
    }
 
    if(diagonal_principal==DIM || diagonal_principal==(-1)*DIM ||
       diagonal_secundaria==DIM || diagonal_secundaria==(-1)*DIM)
       return 1;
 
    return 0;
}
 
int checaEmpate(int tabuleiro[][DIM])
{
    int linha, coluna;
 
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;
 
    return 1;
}
 
int checaTermino(int tabuleiro[][DIM], int vez)
{
    if(checaLinha(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d esta contratado !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaColuna(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d esta contratado !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaDiagonal(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d esta contratado !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaEmpate(tabuleiro))
    {
        printf("Jogo encerrado. Ocorreu um empate! Para que nao teremos nenhum funcionario novo!\n\n");
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    return 0;
}
 
void jogada(int tabuleiro[][DIM])
{
    int linha, coluna;
    vez++;
    printf("\n--> Jogador %d \n", (vez % 2) + 1);
 
    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;
 
        if(checaLocal(tabuleiro, linha, coluna) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 
    } while(checaLocal(tabuleiro, linha, coluna) == 0);
 
    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}
