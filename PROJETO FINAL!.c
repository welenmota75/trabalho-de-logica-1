/*bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h> /*para usar gets; e para usar strcat*/

/*var�veis globais*/
char nome[100+1];
char prontuario[9+1];
int retorno;
/***************************************************************************************/
char nome_arquivo [150];
char chamada [100];
/***************************************************************************************/
char opcao;
/***************************************************************************************/
char frase_1[100]; //[100] cole��o de char ou elemento, no m�nimo 2
char frase_2[100]; //[100] cole��o de char ou elemento, no m�nimo 2
char frase_3[100]; //[100] cole��o de char ou elemento, no m�nimo 2
char frase_4[100]; //[100] cole��o de char ou elemento, no m�nimo 2
char frase_5[100]; //[100] cole��o de char ou elemento, no m�nimo 2
char item1_1[100], item2_1[100],item3_1[100],item4_1[100],item5_1[100] ;
char item1_2[100], item2_2[100],item3_2[100],item4_2[100],item5_2[100] ;
char item1_3[100], item2_3[100],item3_3[100],item4_3[100],item5_3[100] ;
char item1_4[100], item2_4[100],item3_4[100],item4_4[100],item5_4[100] ;
char item1_5[100], item2_5[100],item3_5[100],item4_5[100],item5_5[100] ;
/***************************************************************************************/
int r [5][4], aud, dig, cin, vis;
char caracter;
/***************************************************************************************/
FILE *Arq;
FILE *Arqref;
FILE *Arqquest;
/***************************************************************************************/
/*FUN��ES*/
/*Tipo do retorno      nome_da_fun��o           (parametros) */
  void 			   	   gera_nome_do_arquivo     (void)
  {
  		/*MONTA NOME DE ARQUIVO GERADO*/
	
	strcat (nome_arquivo, "RESULTADO_");/*strcat para concatenar*/
	strcat (nome_arquivo, nome        ); 
	strcat (nome_arquivo, "_"         );
	strcat (nome_arquivo, prontuario  );
	strcat (nome_arquivo, ".TXT"      );
	
	/*exibe na tela*/
	/*printf("\nNome do arquivo %s", nome_arquivo);
	getch();*/
  }
/***************************************************************************************/
/*Tipo do retorno      nome_da_fun��o           (parametros) */  
  void                limpa_variaveis           (void)
  {
  		/*limpa vari�veis de mem�ria*/
	memset (nome, '\0', 100        ); /*preenche o nome com 100 NULL TERMINATORS ('\0')*/
	memset (prontuario, '\0', 9    ); /*preenche o nome com 9 NULL TERMINATORS ('\0')*/
	memset (nome_arquivo, '\0', 150); /*preenche o nome com 150 NULL TERMINATORS ('\0')*/
	memset (chamada, '\0', 100     );
  }
/***************************************************************************************/
void    tela_login    (void)
{
/*PERSONALIZAR TELA*/
	setlocale (LC_ALL, "Portuguese");
	system ("color 0f");
	//system ("mode 60,18");
	system ("cls");
	
	getch ();
	
	/*limpa vari�veis de mem�ria*/
	memset (nome, '\0', 100); /*preenche o nome com 100 NULL TERMINATORS ('\0')*/
	memset (prontuario, '\0', 9); /*preenche o nome com 9 NULL TERMINATORS ('\0')*/
		
	/*solicitar o nome do avaliado*/
	printf ("===========================================================\n");
	printf (" Entre com Usu�rio/Prontu�rio para iniciar uma nova sess�o \n");
	printf ("===========================================================\n\n");
	
	printf (" Digite seu nome: "); fflush (stdin);
	gets (nome); /*---> exibe toda a string, considerando espa�os*/
	
	/*solicitar o prontu�rio do avaliado*/	
	printf ("\n\nDigite seu prontuario: "); fflush (stdin);
	gets (prontuario); /*---> exibe toda a string, considerando espa�os*/
	
	printf("\nNome = %s \nProntu�rio = %s", nome, prontuario);
	getch();
	/*Dependendo de quem se logou,
	 faz teste ou mostra  tela de cadastro*/
	
	if ((strcmp (nome, "MASTER") == 0) 
		&& 
	   (strcmp (prontuario, "SP0000000") == 0)) //modifiquei o prontuario do master para ficar mais facil de digitar... ainda n�o decorei seu prontuario XD
	{
	//printf ("\nMASTER LOGADO\n");
	master_menu ();
	}
	else
	{
		printf ("\nALUNO LOGADO");
	menu_aluno ();
	}
	getch ();

}

/*********************************************************************************************************************/
void gera_arquivo (void)
{
		/*ABRE O ARQUIVO PARA GERAR O RELAT�RIO*/
	Arq = fopen(nome_arquivo,"w"); /*abre um arquivo; neste caso para grava��o, "w" abre novo*/
	
	/*Testar se abertura de arquivo deu certo*/
		if (Arq == NULL) /*NULL = 0000.0000*/
		{
			/*Informo o erro*/
						system ("cls");
						printf("\n\a ERRO AO ABRIR %s!\a", nome_arquivo);
						getch();/*aguarda o pressionar de uma tecla*/
				/*Encerro o programa*/			
						exit (EXIT_FAILURE);
		}
	/*GRAVA CABE�ALHO DO ARQUIVO EM TXT*/
	fprintf (Arq, "================PERFIL REPRESENTACIONAL DE %s ================\n" , nome);
	fprintf(Arq, "Perfil Visual %0.2d %%    ", vis*2);			
					fprintf(Arq, "Perfil Cinest�sico %0.2d %%    ", cin*2);
					fprintf(Arq, "Perfil Auditivo %0.2d %%    ", aud*2);
					fprintf(Arq, "Perfil Digital %0.2d %%", dig*2);
					fprintf(Arq, "\n===================================================================================================\n");
					fprintf(Arq, "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas\n");
					fprintf(Arq, "chamadas auditivas.\n"); 
					fprintf(Arq, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos.\n");
					fprintf(Arq, "Estas s�o as digitais.\n"); 
 					fprintf(Arq, "As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade,\n");
					fprintf(Arq, "as sensa��es internas e as emo��es.\n");
					fprintf(Arq, "J� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
					fprintf(Arq, "\n===================================================================================================\n");
					fprintf(Arq, "\nSEU PERFIL �: ");
	
					/*CONDI��O PARA VERIFICAR QUAL PERFIL OBTEVE MAIS PONTO*/
					/*TENTAR MONTAR UM VOID apresenta_perfil*/
					if (aud == dig || aud == cin|| aud == vis)
					{
						fprintf(Arq, "PERFIL PECULIAR = MULTI-PERFIL\n");
					}
					else
						if (dig == aud || dig == cin|| dig == vis)
							{
								fprintf(Arq, "PERFIL PECULIAR = MULTI-PERFIL\n");
							}
							else
								if (cin == aud || cin == dig|| cin == vis)
									{
										fprintf(Arq, "PERFIL PECULIAR = MULTI-PERFIL\n");
									}
									else
										if (vis == aud || vis == dig|| vis == cin)
											{
												fprintf(Arq, "PERFIL PECULIAR = MULTI-PERFIL\n");
											}
											else
											// PARA VER SE RESULTADOS IGUAIS OCORREM 
					
					if (aud > dig && aud > cin && aud > vis)
					{
						fprintf (Arq, "AUDITIVO\n");
					}
					else
						if (dig > aud && dig > cin && dig > vis)
						{
							fprintf(Arq, "DIGITAL\n");
						}
						else
							if (cin > aud && cin > dig && cin > vis)
							{
								fprintf (Arq, "CINEST�SICO\n");
							}
							else
							fprintf (Arq, "VISUAL\n");
							
					/*FIM DA CONDI��O apresenta_perfil*/		
					
					fprintf(Arq, "\n===================================================================================================\n");

	/*FECHA ARQUIVO*/
	fclose (Arq);
}
/***************************************************************************************/
/***************************************************************************************/
/*abre arquivo*/
void monta_chamada (void)

{
	strcat (chamada, "NOTEPAD ");
	strcat (chamada, nome_arquivo);
	system (chamada);
}
/***************************************************************************************/
/*TELA USU�RIO MASTER*******************************************************************/
void menu (void)
{
	
	system ("cls");	
	system ("color 47");
	system ("mode 80,23");
	
    int i, j;
    
    for(i=0; i<79; i++){
        printf("%c", 177);
    }
    printf("\n");
    
    for(j=0; j<4; j++) //lINHAS LATERAIS SUPERIOR
	{
        printf("%c", 177);
        for(i=0; i<77; i++){
            printf(" ");
        }
        printf("%c\n", 177);
    }
    
    printf("%c", 177);
    for(i=0; i<17; i++)
	    {
        printf(" ");
 		 }
    	printf("=========================================");
    	        printf("\n");
        for(i=0; i<20; i++)
		{
        printf(" ");
	    }
		printf("        ACESSO USUARIO MASTER  ");
		        printf("\n");
		for(i=0; i<20; i++)
		{
        printf(" ");
	    }
		printf("TESTE DOS SISTEMAS RESPRESENTACIONAIS");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("=========================================");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       1.CADASTRAR QUESTIONARIO      ");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       2.VISUALIZAR QUESTIONARIO     ");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       3.REALIZAR TESTE              ");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       4.SOBRE O TESTE               ");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       F.FIM                         ");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("=========================================");
		        printf("\n");
		for(i=0; i<18; i++)
		{
        printf(" ");
	    }		
		printf("       ESCOLHA    --->                  ");
				        printf("\n");
		fflush (stdin);
		
		    
    printf("%c\n", 177);

    for(j=0; j<4; j++) //LINHAS LATERAIS INFERIOR
	{
        printf("%c", 177);
        for(i=0; i<77; i++)
		{
            printf(" ");
        }
        printf("%c\n", 177);
    }
    
    for(i=0; i<79; i++)
	{
       printf("%c", 177);
    }
    printf("\n"); //FIM DAS BORDAS
		
		opcao = getche(); //getche s� para vari�vel char // CAPTURA OP��O DIGITADA PELO USU�RIO
		
	getch();/*para aguardar ou pressionar uma tecla*/	
	
	/*Analisa qual tecla foi digitada*/
			switch (opcao)
			{
				case '1': 
				{
					system ("cls");
					system ("mode 80,23");
					system ("color a");
					setlocale (LC_ALL, "Portuguese");					

					printf ("********************************************\n");
					printf ("          CADASTRO DE QUESTION�RIO          \n");
					printf ("********************************************\n\n");
					printf("Escreva sua 1� Frase:\n"); fflush (stdin); gets(frase_1);
					printf("\n ITEM 1:"); fflush (stdin); gets(item1_1);
					printf("\n ITEM 2:"); fflush (stdin); gets(item1_2);
					printf("\n ITEM 3:"); fflush (stdin); gets(item1_3);
					printf("\n ITEM 4:"); fflush (stdin); gets(item1_4);
					system ("cls");
					printf ("********************************************\n");
					printf ("          CADASTRO DE QUESTION�RIO          \n");
					printf ("********************************************\n\n");
					printf("Escreva sua 2� Frase:\n"); fflush (stdin); gets(frase_2);
					printf("\n ITEM 1:"); fflush (stdin); gets(item2_1);
					printf("\n ITEM 2:"); fflush (stdin); gets(item2_2);
					printf("\n ITEM 3:"); fflush (stdin); gets(item2_3);
					printf("\n ITEM 4:"); fflush (stdin); gets(item2_4);
					system ("cls");
					printf ("********************************************\n");
					printf ("          CADASTRO DE QUESTION�RIO          \n");
					printf ("********************************************\n\n");
					printf("Escreva sua 3� Frase:\n"); fflush (stdin); gets(frase_3);
					printf("\n ITEM 1:"); fflush (stdin); gets(item3_1);
					printf("\n ITEM 2:"); fflush (stdin); gets(item3_2);
					printf("\n ITEM 3:"); fflush (stdin); gets(item3_3);
					printf("\n ITEM 4:"); fflush (stdin); gets(item3_4);
					system ("cls");
					printf ("********************************************\n");
					printf ("          CADASTRO DE QUESTION�RIO          \n");
					printf ("********************************************\n\n");
					printf("Escreva sua 4� Frase:\n"); fflush (stdin); gets(frase_4);
					printf("\n ITEM 1:"); fflush (stdin); gets(item4_1);
					printf("\n ITEM 2:"); fflush (stdin); gets(item4_2);
					printf("\n ITEM 3:"); fflush (stdin); gets(item4_3);
					printf("\n ITEM 4:"); fflush (stdin); gets(item4_4);
					system ("cls");
					printf ("********************************************\n");
					printf ("          CADASTRO DE QUESTION�RIO          \n");
					printf ("********************************************\n\n");
					printf("Escreva sua 5� Frase:\n"); fflush (stdin); gets(frase_5);
					printf("\n ITEM 1:"); fflush (stdin); gets(item5_1);
					printf("\n ITEM 2:"); fflush (stdin); gets(item5_2);
					printf("\n ITEM 3:"); fflush (stdin); gets(item5_3);
					printf("\n ITEM 4:"); fflush (stdin); gets(item5_4);
					
					Arq = fopen ("TESTE_SISTEMA_REPRESENTACIONAL.DAT", "w"); //fopen tenta abrir arquivo ///= 'a' adiciona
					if (Arq==NULL) /*NULL = 0000.0000*/
					{
						system ("cls");
						printf("\n erro ao abrir arquivo");
						getch();
						exit (EXIT_FAILURE);
						
					}
					printf ("\n arquivo aberto no endere�o [%p]", Arq); //endere�o do ponteiro [p]
					
					// Gravar dados no arquivo
					fprintf (Arq,"NroFrase;Frase   ; cinestesico;ITEM_1   ; auditivo;ITEM_2   ; visual;ITEM_3   ; digital;ITEM_4   ;\n");
					fprintf (Arq,"1       ;%s   ; ""%i       ;""%s  ; ""%i    ;""%s  ; ""%i  ;""%s  ; ""%i   ;""%s  ;\n", frase_1, cin, item1_1, aud, item1_2, vis, item1_3, dig, item1_4 );
					fprintf (Arq,"2       ;%s   ; ""%i       ;""%s  ; ""%i    ;""%s  ; ""%i  ;""%s  ; ""%i   ;""%s  ;\n", frase_2, cin, item2_1, aud, item2_2, vis, item2_3, dig, item2_4 );
					fprintf (Arq,"3       ;%s   ; ""%i       ;""%s  ; ""%i    ;""%s  ; ""%i  ;""%s  ; ""%i   ;""%s  ;\n", frase_3, cin, item3_1, aud, item3_2, vis, item3_3, dig, item3_4 );
					fprintf (Arq,"4       ;%s   ; ""%i       ;""%s  ; ""%i    ;""%s  ; ""%i  ;""%s  ; ""%i   ;""%s  ;\n", frase_4, cin, item4_1, aud, item4_2, vis, item4_3, dig, item4_4 );
					fprintf (Arq,"5       ;%s   ; ""%i       ;""%s  ; ""%i    ;""%s  ; ""%i  ;""%s  ; ""%i   ;""%s  ;\n", frase_5, cin, item5_1, aud, item5_2, vis, item5_3, dig, item5_4 );
					//%s = string ";" � o separador					
					// Fecha o arquivo
					
					fclose (Arq);
					//abre o arquivo com o NOTEPAD
					system ("NOTEPAD TESTE_SISTEMA_REPRESENTACIONAL.DAT");
					getch();
				}
				break;
				
				case '2':
				
					/*************************GRAVA ARQUIVO*******************************/
					Arqquest = fopen("QUESTION�RIO_1.TXT", "w"); /*abre um arquivo; neste caso para grava��o, "w" abre novo*/
	
					/*Testar se abertura de arquivo deu certo*/
						if (Arqquest == NULL) /*NULL = 0000.0000*/
						{
					/*Informo o erro*/
										system ("cls");
										printf("\n\a ERRO AO ABRIR %s!\a");
										getch();/*aguarda o pressionar de uma tecla*/
					/*Encerro o programa*/			
										exit (EXIT_FAILURE);
						}
					/*GRAVA CABE�ALHO DO ARQUIVO EM TXT*/
					/********************************************************************************************************************************************************************************************************************************************************************************************************************************************************/					
					fprintf(Arqquest, "NroFrase                   Frase                              C  item_1                                                            A  item_2                                                  V  item_3                                                     D  item_4                                                             \n");
					fprintf(Arqquest, "==================================================================================================================================================================================================================================================================================================================================\n");
					fprintf(Arqquest, "1                   %s:  ""%i  ""%s.                                                         ""%i  ""%s.                                    ""%i  ""%s.                                    ""%i  ""%s.                    \n", frase_1, cin, item1_1, aud, item1_2, vis, item1_3, dig, item1_4 );
					fprintf(Arqquest, "2        %s:  ""%i  ""%s.  ""%i  ""%s.                           ""%i  ""%s.         ""%i  ""%s.                             \n", frase_2, cin, item2_1, aud, item2_2, vis, item2_3, dig, item2_4 );
					fprintf(Arqquest, "3         %s:  ""%i  ""%s.                                ""%i  ""%s.                                  ""%i  ""%s.                           ""%i  ""%s.                                        \n", frase_3, cin, item3_1, aud, item3_2, vis, item3_3, dig, item3_4 );
					fprintf(Arqquest, "4                                    %s:  ""%i  ""%s.                             ""%i  ""%s.  ""%i  ""%s.    ""%i  ""%s.  \n", frase_4, cin, item4_1, aud, item4_2, vis, item4_3, dig, item4_4 );
					fprintf(Arqquest, "5                                       %s:  ""%i  ""%s.  ""%i  ""%s.  ""%i  ""%s.  ""%i  ""%s.          \n", frase_5, cin, item5_1, aud, item5_2, vis, item5_3, dig, item5_4 );
					fprintf(Arqquest, "==================================================================================================================================================================================================================================================================================================================================\n");
					
					fclose (Arqquest);
					
					printf ("\n\n\n");
					system ("NOTEPAD QUESTION�RIO_1.TXT");
					getch();
					
				break;
				
				case '3': 
				{
					system ("cls");
					setlocale (LC_ALL, "Portuguese");					
					printf ("REGRAS - Teste do sistema representacional\n\n");
					printf ("********************************************\n");
					printf ("Nas frases a seguir, pontue com:            \n");
					printf ("4 a que melhor descreve voc�;               \n");
					printf ("3 a pr�xima melhor descri��o;               \n");
					printf ("2 a pr�xima melhor;                         \n");
					printf ("1 aquela que menos descreve voc�.           \n");
					printf ("********************************************\n\n");

					
					//*************************************************************************************************************************************************************
					//Explica��o
					//fiz uma compara��o em cada while, alem dele n�o aceitar os caracteres ele est� vereficando cada op��o digitada. 
					//n�o deixando repetir. O unico que n�o possui o vereficador � o primeiro de cada quest�o, pois n�o h� necessidade de comparar a primeiro op��o XD
					// e a mensagem eu modifiquei um pouco retirei o "Digite valores de 1 a 4", deixei um adentro bem educado nas regras do sistema representacional XD
					//*************************************************************************************************************************************************************								
					
					printf("1. Eu tomo decisoes importantes baseado em:\n A- intuicao\n B- o que me soa melhor\n C- o que me parece melhor\n D- um estudo preciso e minucioso do assunto\n");
					refaz_1a:             //*****EDILENE <- O GOTO AQUI EST� EVITANDO UM LOOPING INFINITO NA MENSAGEM********
					printf("\n A- intuicao\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[0][0]);	
					
					while (r[0][0] < 1 || r[0][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1a;   //*****EDILENE <- O GOTO AQUI EST� EVITANDO UM LOOPING INFINITO NA MENSAGEM********** TESTA SEM ELE PRA VOC� VER O QUE OCORRE
					}
														
					fflush (stdin);
					refaz_1b:
					printf("\n B- o que me soa melhor\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[0][1]);
					
					
					while (r[0][1]< 1 || r[0][1] > 4 || r[0][1] == r[0][0])  //COMPARA O PRIMEIRO COM O SEGUNDO E SE FOREM IGUAL VAI PARA O WHILE   | enquanto resposta for maior que 4 sistema fica em looping
					{
						printf("\a\nOP��O INV�LIDA\n"); //getche ();
						goto refaz_1b;
					}
					
					
					fflush(stdin);
					refaz_1c:
					printf("\n C- o que me parece melhor\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[0][2]);
					
					
					while (r[0][2]< 1 || r[0][2] > 4 || r[0][2] == r[0][1] || r[0][2] == r[0][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1c;
					}

					fflush(stdin);
					refaz_1d:
					printf("\n D- um estudo preciso e minucioso do assunto\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[0][3]);
					
					while (r[0][3]< 1 || r[0][3] > 4 || r[0][3] == r[0][2]|| r[0][3] == r[0][1] || r[0][3] == r[0][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1d;
					}
										
					system ("cls");
					
					printf("2. Durante uma discussao eu sou mais influenciado por:\n A- o tom da voz da outra pessoa\n B- se eu posso ou nao ver o argumento da outra pessoa\n C- a logica do argumento da outra pessoa\n D- se eu entro em contato ou n�o com os sentimentos reais do outro\n");
					fflush(stdin);
					refaz_2a:
					printf("\n A- o tom da voz da outra pessoa\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[1][0]);
									
					while (r[1][0]< 1 || r[1][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2a;
					}
					
					fflush(stdin);
					refaz_2b:					
					printf("\n B- se eu posso ou nao ver o argumento da outra pessoa\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[1][1]);
									
					while (r[1][1]< 1 || r[1][1] > 4 || r[1][1] == r[1][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2b;
					}					
					
					fflush(stdin);
					refaz_2c:
					printf("\n C- a logica do argumento da outra pessoa\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[1][2]);
					
					while (r[1][2]< 1 || r[1][2] > 4 || r[1][2] == r[1][1] || r[1][2] == r[1][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2c;
					}
					
					fflush(stdin);
					refaz_2d:					
					printf("\n D- se eu entro em contato ou n�o com os sentimentos reais do outro\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[1][3]);
				
					while (r[1][3]< 1 || r[1][3] > 4 || r[1][3] == r[1][2]|| r[1][3] == r[1][1] || r[1][3] == r[1][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2d;
					}					
					
					system ("cls");
					
					printf("3. Eu comunico mais facilmente o que se passa comigo:\n A- do modo como me visto e aparento\n B- pelos sentimentos que compartilho\n C- pelas palavras que escolho\n D- pelo tom da minha voz\n");
					fflush(stdin);
					refaz_3a:
					printf("\n A- do modo como me visto e aparento\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[2][0]);

					while (r[2][0]< 1 || r[2][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3a;
					}					
					
					fflush(stdin);
					refaz_3b:
					printf("\n B- pelos sentimentos que compartilho\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[2][1]);
					
					while (r[2][1]< 1 || r[2][1] > 4 || r[2][1] == r[2][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3b;
					}
					
					fflush(stdin);
					refaz_3c:					
					printf("\n C- pelas palavras que escolho\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[2][2]);
					
					while (r[2][2]< 1 || r[2][2] > 4 || r[2][2] == r[2][1] || r[2][2] == r[2][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3c;
					}
					
					fflush(stdin);
					refaz_3d:
					printf("\n D- pelo tom da minha voz\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[2][3]);
					
					while (r[2][3]< 1 || r[2][3] > 4 || r[2][3] == r[2][2]|| r[2][3] == r[2][1] || r[2][3] == r[2][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3d;
					}
					
					system ("cls");
					
					printf("4. E muito facil para mim:\n A- achar o volume e a sintonia ideais num sistema de som\n B- selecionar o ponto mais relevante relativo a um assunto interessante\n C- escolher os moveis mais confortaveis\n D- escolher as combinacoes de cores mais ricas e atraentes\n");
					fflush(stdin);
					refaz_4a:
					printf("\n A- achar o volume e a sintonia ideais num sistema de som\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[3][0]);
					
					while (r[3][0]< 1 || r[3][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4a;
					}
					
					fflush(stdin);	
					refaz_4b:				
					printf("\n B- selecionar o ponto mais relevante relativo a um assunto interessante\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[3][1]);
					
					while (r[3][1]< 1 || r[3][1] > 4 || r[3][1] == r[3][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4b;
					}					
					
					fflush(stdin);
					refaz_4c:					
					printf("\n C- escolher os moveis mais confortaveis\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[3][2]);
					
					while (r[3][2]< 1 || r[3][2] > 4 || r[3][2] == r[3][1] || r[3][2] == r[3][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4c;
					}
					
					fflush(stdin);
					refaz_4d:
					printf("\n D- escolher as combinacoes de cores mais ricas e atraentes\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[3][3]);
					
					while (r[3][3]< 1 || r[3][3] > 4 || r[3][3] == r[3][2]|| r[3][3] == r[3][1] || r[3][3] == r[3][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4d;
					}
					
					system ("cls");
					
					printf("5. Eu me percebo assim:\n A- se estou muito em sintonia com os sons do ambientes\n B- se sou muito capaz de raciocinar com fatos e dados novos\n C- eu sou muito sens�vel � maneira como a roupa veste o meu corpo\n D- eu respondo fortemente �s cores e � apar�ncia de uma sala\n");
					fflush(stdin);
					refaz_5a:
					printf("\n A- se estou muito em sintonia com os sons do ambientes\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[4][0]);
					
					while (r[4][0]< 1 || r[4][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5a;
					}
					
					fflush(stdin);
					refaz_5b:					
					printf("\n B- se sou muito capaz de raciocinar com fatos e dados novos\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[4][1]);
					
					while (r[4][1]< 1 || r[4][1] > 4 || r[4][1] == r[4][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5b;
					}					
					
					fflush(stdin);
					refaz_5c:					
					printf("\n C- eu sou muito sens�vel � maneira como a roupa veste o meu corpo\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[4][2]);
					
					while (r[4][2]< 1 || r[4][2] > 4 || r[4][2] == r[4][1] || r[4][2] == r[4][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5c;
					}					
					
					fflush(stdin);
					refaz_5d:
					printf("\n D- eu respondo fortemente �s cores e � apar�ncia de uma sala\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[4][3]);
					
					while (r[4][3]< 1 || r[4][3] > 4 || r[4][3] == r[4][2]|| r[4][3] == r[4][1] || r[4][3] == r[4][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5d;
					}					
					system ("cls");
					
					
				    aud=(r[0][1]+r[1][0]+r[2][3]+r[3][0]+r[4][0]);
				    dig=(r[0][3]+r[1][2]+r[2][2]+r[3][1]+r[4][1]);
				    cin=(r[0][0]+r[1][3]+r[2][1]+r[3][2]+r[4][2]);
				    vis=(r[0][2]+r[1][1]+r[2][0]+r[3][3]+r[4][3]);
				    
				    printf("\n======================================PERFIL REPRESENTACIONAL======================================\n");
				    printf("Perfil Visual %0.2d %%    ", vis*2);			
					printf("Perfil Cinest�sico %0.2d %%    ", cin*2);
					printf("Perfil Auditivo %0.2d %%    ", aud*2);
					printf("Perfil Digital %0.2d %%\n", dig*2);
					printf("\n===================================================================================================\n");
					printf("Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas\n");
					printf("chamadas auditivas.\n"); 
					printf("Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos.\n");
					printf("Estas s�o as digitais.\n"); 
 					printf("As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade,\n");
					printf("as sensa��es internas e as emo��es.\n");
					printf("J� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
					printf("\n===================================================================================================\n");
					printf("\nSEU PERFIL �: ");
					
					/*CONDI��O PARA VERIFICAR QUAL PERFIL OBTEVE MAIS PONTO*/
					if (aud > dig && aud > cin && aud > vis)
					{
						printf ("AUDITIVO\n");
					}
					else
						if (dig > aud && dig > cin && dig > vis)
						{
							printf("DIGITAL\n");
						}
						else
							if (cin > aud && cin > dig && cin > vis)
							{
								printf ("CINEST�SICO\n");
							}
							else
							printf ("VISUAL\n");
							
					/*FIM DA CONDI��O apresenta_perfil*/		
					
					printf("\n===================================================================================================\n");
					getch();
					system ("cls");
					
					/**************************************************************************************************************************/
					/*CHAMA FUN��O PARA EXIBIR E CRIAR ARQUIVO COM RESULTADO*******************************************************************/
					/*************************GRAVA ARQUIVO*******************************/
					/*ABRE O ARQUIVO PARA GERAR O RELAT�RIO*/
					/*cria fun��o*/
						gera_nome_do_arquivo ();	
					/*cria fun��o*/
						gera_arquivo ();
					/*cria fun��o*/
						monta_chamada ();
					
					/*****************************************************************************************************************************************************************************************************************/
					getch();
				}
					/*****************************************************************************************************************************************************************************************************************/
				break;
				
				case '4': 
					system ("cls");
					
					/*************************GRAVA ARQUIVO*******************************/

							/*ABRE O ARQUIVO PARA GERAR O RELAT�RIO*/
					Arqref = fopen("REFERENCIAL_TEORICO.TXT", "w"); /*abre um arquivo; neste caso para grava��o, "w" abre novo*/
	
					/*Testar se abertura de arquivo deu certo*/
						if (Arqref == NULL) /*NULL = 0000.0000*/
						{
										/*Informo o erro*/
										system ("cls");
										printf("\n\a ERRO AO ABRIR %s!\a");
										getch();/*aguarda o pressionar de uma tecla*/
										/*Encerro o programa*/			
										exit (EXIT_FAILURE);
						}
					/*GRAVA REFERENCIAL TE�RICO EM TXT*/
					fprintf(Arqref, "REFERENCIAL TE�RICO\n");
					fprintf(Arqref, "==============================================================================================================================");
					fprintf(Arqref, "\nSegundo Albert Merabian, em seu livro 'Silent Messages, o poder de influ�ncia das palavras n�o passa de 7%, \n");
				    fprintf(Arqref, "enquanto a forma como as palavras s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.\n");			
					fprintf(Arqref, "\nPara Merabian 55% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da\n");
					fprintf(Arqref, "pessoa enquanto se comunica.\n");
					fprintf(Arqref, "\nO tom da voz representa 38%% do impacto da comunica��o.\n");
					fprintf(Arqref, "\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.\n");
					fprintf(Arqref, "\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.\n");
					fprintf(Arqref, "\nAs portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de\n"); 
					fprintf(Arqref, "contato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias,\n");
					fprintf(Arqref, "utilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o.\n"); 
 					fprintf(Arqref, "\nDe acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.\n\n");
					fprintf(Arqref, "- Auditivo\n");
					fprintf(Arqref, "- Digital\n");
					fprintf(Arqref, "- Cinest�sico\n");
					fprintf(Arqref, "- Visual\n");
					fprintf(Arqref, "\n");
					fprintf(Arqref, "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n");
					fprintf(Arqref, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\n");
					fprintf(Arqref, "As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas \n");
					fprintf(Arqref, "J� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n");
					fprintf(Arqref, "e as emo��es.\n\n");
					fprintf(Arqref, "Cada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional \n");
					fprintf(Arqref, "dominante dela � fundamental para di�logos eficientes.\n");
					fprintf(Arqref, "==============================================================================================================================");
					/*FECHA ARQUIVO*/
					fclose (Arqref);
					
					printf ("\n\n\n");
					system ("NOTEPAD REFERENCIAL_TEORICO.TXT");
					getch();
				
				break;
				case 'F' : 
				case 'f' : exit (0); // exite encerra o menu
				break;
				default : printf ("\a ERROU!!!!!"); //se n�o escolher op��o valida
    } 
    getch();	
}
/***************************************************************************************/
/*TELA USU�RIO ALUNO*******************************************************************/
void menu_aluno (void)
{
		//setlocale (LC_ALL, "Portuguese");
	char frase[100]; //[100] cole��o de char ou elemento, no m�nimo 2
	char item_1[100];
	char item_2[100];
	char item_3[100];
	char item_4[100];	
	INICIAR: /*LABEL (MARCA��O)*/
	
	system ("cls");	

		printf("====================================="); printf("\n");
		printf("TESTE DOS SISTEMAS RESPRESENTACIONAIS"); printf("\n");
		printf("====================================="); printf("\n");
		printf("       1.CADASTRAR QUESTIONARIO      "); printf("\n");
		printf("       2.VISUALIZAR QUESTIONARIO     "); printf("\n");	
		printf("       3.REALIZAR TESTE              "); printf("\n");		
		printf("       4.SOBRE O TESTE               "); printf("\n");
		printf("       F.FIM                         "); printf("\n");		
		printf("====================================="); printf("\n");	
		printf("       ESCOLHA    --->               "); printf("\n");
		fflush (stdin);
			
		opcao = getche(); //getche s� para vari�vel char // CAPTURA OP��O DIGITADA PELO USU�RIO
		system ("cls");
	/*para aguardar ou pressionar uma tecla*/	
	
	/*Analisa qual tecla foi digitada*/
			switch (opcao)
			{
				case '1': 
					system ("cls");	
					printf("\n");
					printf ("\axxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\a");
					printf("\n");
					printf ("\aAPENAS USU�RIO MASTER PODE ACESSAR!\a");
					printf("\n");
					printf ("\axxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\a");
				break;
				
				case '2':
					system ("cls");
					
					/*************************GRAVA ARQUIVO*******************************/
					Arqquest = fopen("QUESTION�RIO_1.TXT", "w"); /*abre um arquivo; neste caso para grava��o, "w" abre novo*/
	
					/*Testar se abertura de arquivo deu certo*/
						if (Arqquest == NULL) /*NULL = 0000.0000*/
						{
					/*Informo o erro*/
										system ("cls");
										printf("\n\a ERRO AO ABRIR %s!\a");
										getch();/*aguarda o pressionar de uma tecla*/
					/*Encerro o programa*/			
										exit (EXIT_FAILURE);
						}
					/*GRAVA CABE�ALHO DO ARQUIVO EM TXT*/
					/********************************************************************************************************************************************************************************************************************************************************************************************************************************************************/
					//EDILENE, EU SEI QUE NESSE CAMPO TEM QUE SER UM ARQUIVO .DAT QUE DEPOIS SER� ABERTO COMO .TXT, MAS COMO A TELA ALUNO � UM PROGRAMA FIXO, ACHEI MELHOR DEIXAR ASSIM, E AT� FACILITA NA HORA QUE EU FOR IDENTAR NO PROGRAMA MASTER, S� TEM UMA COISA AQUI, SABE OS CAMPOS COM VALOR "O", NAS COLUNAS C,A,V,D? ENT�O, PODE TENTAR COLOCAR O CONTE�DO DAS VARI�VEIS DO QUESTION�RIO?
					//SE N�O ENTENDER, DEPOIS TE EXPLICO XD
					
					fprintf(Arqquest, "NroFrase                   Frase                              C  item_1                                                            A  item_2                                                  V  item_3                                                     D  item_4                                                             \n");
					fprintf(Arqquest, "==================================================================================================================================================================================================================================================================================================================================\n");
					fprintf(Arqquest, "1                   Eu tomo decis�es importantes baseado em:  0  intui��o.                                                         0  o que me soa melhor.                                    0  o que me parece melhor.                                    0  um estudo preciso sobre e minucioso do assunto.                    \n");
					fprintf(Arqquest, "2        Durante uma discuss�o eu sou mais influenciado por:  0  se eu entro em contato ou n�o com os sentimentos reais do outro.  0  o tom da voz da outra pessoa.                           0  se eu posso ou n�o ver o argumento da outra pessoa         0  a l�gica do argumento da outra pessoa.                             \n");
					fprintf(Arqquest, "3         Eu comunico mais facilmente o que se passa comigo:  0  pelos sentimentos que compartilho.                                0  pelo tom da minha voz.                                  0  do modo como me visto e aparento                           0  pelas palavras que escolho.                                        \n");
					fprintf(Arqquest, "4                                    � muito f�cil para mim:  0  escolher os m�veis mais confort�veis.                             0  achar o volume e a sintonia ideais num sistema de som.  0  escolher as combina��es de cores mais ricas e atraentes    0  selecionar o ponto mais relevante relativo ao assunto interessante.\n");
					fprintf(Arqquest, "5                                       Eu me percebo assim:  0  eu sou muito sens�vel � maneira como a roupa veste o meus corpo.  0  se estou muito em sintonia com os sons dos ambientes.   0  eu respondo fortemente �s cores e � apar�ncia de uma sala  0  se sou muito capaz de raciocinar com fatos e dados novos.          \n");
					fprintf(Arqquest, "==================================================================================================================================================================================================================================================================================================================================\n");
					
					fclose (Arqquest);
					
					printf ("\n\n\n");
					system ("NOTEPAD QUESTION�RIO_1.TXT");
					getch();
				break;
				
				case '3': 
				{
					system ("cls");
					setlocale (LC_ALL, "Portuguese");					
					printf ("REGRAS - Teste do sistema representacional\n\n");
					printf ("********************************************\n");
					printf ("Nas frases a seguir, pontue com:            \n");
					printf ("4 a que melhor descreve voc�;               \n");
					printf ("3 a pr�xima melhor descri��o;               \n");
					printf ("2 a pr�xima melhor;                         \n");
					printf ("1 aquela que menos descreve voc�.           \n");
					printf ("********************************************\n\n");
					printf ("Por favor digite valores de 1 � 4 sem repetir.\n");
					printf ("********************************************\n\n");
					
				//	do
				//	{
				
					//*************************************************************************************************************************************************************
					//Explica��o
					//fiz uma compara��o em cada while, alem dele n�o aceitar os caracteres ele est� vereficando cada op��o digitada. 
					//n�o deixando repetir. O unico que n�o possui o vereficador � o primeiro de cada quest�o, pois n�o h� necessidade de comparar a primeiro op��o XD
					// e a mensagem eu modifiquei um pouco retirei o "Digite valores de 1 a 4", deixei um adentro bem educado nas regras do sistema representacional XD
					//*************************************************************************************************************************************************************								
					
					printf("1. Eu tomo decisoes importantes baseado em:\n A- intuicao\n B- o que me soa melhor\n C- o que me parece melhor\n D- um estudo preciso e minucioso do assunto\n");
					refaz_1a:             //*****EDILENE <- O GOTO AQUI EST� EVITANDO UM LOOPING INFINITO NA MENSAGEM********
					printf("\n A- intuicao\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[0][0]);	
					
					while (r[0][0] < 1 || r[0][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1a;   //*****EDILENE <- O GOTO AQUI EST� EVITANDO UM LOOPING INFINITO NA MENSAGEM********** TESTA SEM ELE PRA VOC� VER O QUE OCORRE
					}
														
					fflush (stdin);
					refaz_1b:
					printf("\n B- o que me soa melhor\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[0][1]);
					
					
					while (r[0][1]< 1 || r[0][1] > 4 || r[0][1] == r[0][0])  //COMPARA O PRIMEIRO COM O SEGUNDO E SE FOREM IGUAL VAI PARA O WHILE   | enquanto resposta for maior que 4 sistema fica em looping
					{
						printf("\a\nOP��O INV�LIDA\n"); //getche ();
						goto refaz_1b;
					}
					
					
					fflush(stdin);
					refaz_1c:
					printf("\n C- o que me parece melhor\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[0][2]);
					
					
					while (r[0][2]< 1 || r[0][2] > 4 || r[0][2] == r[0][1] || r[0][2] == r[0][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1c;
					}

					fflush(stdin);
					refaz_1d:
					printf("\n D- um estudo preciso e minucioso do assunto\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[0][3]);
					
					while (r[0][3]< 1 || r[0][3] > 4 || r[0][3] == r[0][2]|| r[0][3] == r[0][1] || r[0][3] == r[0][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_1d;
					}
										
					system ("cls");
					
					printf("2. Durante uma discussao eu sou mais influenciado por:\n A- o tom da voz da outra pessoa\n B- se eu posso ou nao ver o argumento da outra pessoa\n C- a logica do argumento da outra pessoa\n D- se eu entro em contato ou n�o com os sentimentos reais do outro\n");
					fflush(stdin);
					refaz_2a:
					printf("\n A- o tom da voz da outra pessoa\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[1][0]);
									
					while (r[1][0]< 1 || r[1][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2a;
					}
					
					fflush(stdin);
					refaz_2b:					
					printf("\n B- se eu posso ou nao ver o argumento da outra pessoa\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[1][1]);
									
					while (r[1][1]< 1 || r[1][1] > 4 || r[1][1] == r[1][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2b;
					}					
					
					fflush(stdin);
					refaz_2c:
					printf("\n C- a logica do argumento da outra pessoa\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[1][2]);
					
					while (r[1][2]< 1 || r[1][2] > 4 || r[1][2] == r[1][1] || r[1][2] == r[1][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2c;
					}
					
					fflush(stdin);
					refaz_2d:					
					printf("\n D- se eu entro em contato ou n�o com os sentimentos reais do outro\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[1][3]);
				
					while (r[1][3]< 1 || r[1][3] > 4 || r[1][3] == r[1][2]|| r[1][3] == r[1][1] || r[1][3] == r[1][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_2d;
					}					
					
					system ("cls");
					
					printf("3. Eu comunico mais facilmente o que se passa comigo:\n A- do modo como me visto e aparento\n B- pelos sentimentos que compartilho\n C- pelas palavras que escolho\n D- pelo tom da minha voz\n");
					fflush(stdin);
					refaz_3a:
					printf("\n A- do modo como me visto e aparento\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[2][0]);

					while (r[2][0]< 1 || r[2][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3a;
					}					
					
					fflush(stdin);
					refaz_3b:
					printf("\n B- pelos sentimentos que compartilho\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[2][1]);
					
					while (r[2][1]< 1 || r[2][1] > 4 || r[2][1] == r[2][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3b;
					}
					
					fflush(stdin);
					refaz_3c:					
					printf("\n C- pelas palavras que escolho\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[2][2]);
					
					while (r[2][2]< 1 || r[2][2] > 4 || r[2][2] == r[2][1] || r[2][2] == r[2][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3c;
					}
					
					fflush(stdin);
					refaz_3d:
					printf("\n D- pelo tom da minha voz\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[2][3]);
					
					while (r[2][3]< 1 || r[2][3] > 4 || r[2][3] == r[2][2]|| r[2][3] == r[2][1] || r[2][3] == r[2][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_3d;
					}
					
					system ("cls");
					
					printf("4. E muito facil para mim:\n A- achar o volume e a sintonia ideais num sistema de som\n B- selecionar o ponto mais relevante relativo a um assunto interessante\n C- escolher os moveis mais confortaveis\n D- escolher as combinacoes de cores mais ricas e atraentes\n");
					fflush(stdin);
					refaz_4a:
					printf("\n A- achar o volume e a sintonia ideais num sistema de som\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[3][0]);
					
					while (r[3][0]< 1 || r[3][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4a;
					}
					
					fflush(stdin);	
					refaz_4b:				
					printf("\n B- selecionar o ponto mais relevante relativo a um assunto interessante\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[3][1]);
					
					while (r[3][1]< 1 || r[3][1] > 4 || r[3][1] == r[3][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4b;
					}					
					
					fflush(stdin);
					refaz_4c:					
					printf("\n C- escolher os moveis mais confortaveis\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[3][2]);
					
					while (r[3][2]< 1 || r[3][2] > 4 || r[3][2] == r[3][1] || r[3][2] == r[3][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4c;
					}
					
					fflush(stdin);
					refaz_4d:
					printf("\n D- escolher as combinacoes de cores mais ricas e atraentes\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[3][3]);
					
					while (r[3][3]< 1 || r[3][3] > 4 || r[3][3] == r[3][2]|| r[3][3] == r[3][1] || r[3][3] == r[3][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_4d;
					}
					
					system ("cls");
					
					printf("5. Eu me percebo assim:\n A- se estou muito em sintonia com os sons do ambientes\n B- se sou muito capaz de raciocinar com fatos e dados novos\n C- eu sou muito sens�vel � maneira como a roupa veste o meu corpo\n D- eu respondo fortemente �s cores e � apar�ncia de uma sala\n");
					fflush(stdin);
					refaz_5a:
					printf("\n A- se estou muito em sintonia com os sons do ambientes\n"); fflush (stdin); //gets(item_1);
					scanf("%d", &r[4][0]);
					
					while (r[4][0]< 1 || r[4][0] > 4)
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5a;
					}
					
					fflush(stdin);
					refaz_5b:					
					printf("\n B- se sou muito capaz de raciocinar com fatos e dados novos\n"); fflush (stdin); //gets(item_2);
					scanf("%d",&r[4][1]);
					
					while (r[4][1]< 1 || r[4][1] > 4 || r[4][1] == r[4][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5b;
					}					
					
					fflush(stdin);
					refaz_5c:					
					printf("\n C- eu sou muito sens�vel � maneira como a roupa veste o meu corpo\n"); fflush (stdin); //gets(item_3);
					scanf("%d",&r[4][2]);
					
					while (r[4][2]< 1 || r[4][2] > 4 || r[4][2] == r[4][1] || r[4][2] == r[4][0])
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5c;
					}					
					
					fflush(stdin);
					refaz_5d:
					printf("\n D- eu respondo fortemente �s cores e � apar�ncia de uma sala\n"); fflush (stdin); //gets(item_4);
					scanf("%d",&r[4][3]);
					
					while (r[4][3]< 1 || r[4][3] > 4 || r[4][3] == r[4][2]|| r[4][3] == r[4][1] || r[4][3] == r[4][0] )
					{
						printf("\a\nOP��O INV�LIDA\n");
						goto refaz_5d;
					}					
					system ("cls");
					
					// faz a conta
					
				    aud=(r[0][1]+r[1][0]+r[2][3]+r[3][0]+r[4][0]);
				    dig=(r[0][3]+r[1][2]+r[2][2]+r[3][1]+r[4][1]);
				    cin=(r[0][0]+r[1][3]+r[2][1]+r[3][2]+r[4][2]);
				    vis=(r[0][2]+r[1][1]+r[2][0]+r[3][3]+r[4][3]);
				    
				    printf("\n======================================PERFIL REPRESENTACIONAL======================================\n");
				    printf("Perfil Visual %0.2d %%    ", vis*2);			
					printf("Perfil Cinest�sico %0.2d %%    ", cin*2);
					printf("Perfil Auditivo %0.2d %%    ", aud*2);
					printf("Perfil Digital %0.2d %%\n", dig*2);
					printf("\n===================================================================================================\n");
					printf("Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas\n");
					printf("chamadas auditivas.\n"); 
					printf("Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos.\n");
					printf("Estas s�o as digitais.\n"); 
 					printf("As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade,\n");
					printf("as sensa��es internas e as emo��es.\n");
					printf("J� as pessoas visuais aprendem melhor quando se valendo da vis�o.");
					printf("\n===================================================================================================\n");
					printf("\nSEU PERFIL �: ");
					/*CONDI��O PARA VERIFICAR QUAL PERFIL OBTEVE MAIS PONTO*/
					/*TENTAR MONTAR UM VOID apresenta_perfil*/
					if (aud > dig && aud > cin && aud > vis)
					{
						printf ("AUDITIVO\n");
					}
					else
						if (dig > aud && dig > cin && dig > vis)
						{
							printf("DIGITAL\n");
						}
						else
							if (cin > aud && cin > dig && cin > vis)
							{
								printf ("CINEST�SICO\n");
							}
							else
							printf ("VISUAL\n");	
					/*FIM DA CONDI��O apresenta_perfil*/		
					printf("\n===================================================================================================\n");
					getch();
					system ("cls");
					/*CHAMA FUN��O PARA EXIBIR E CRIAR ARQUIVO COM RESULTADO*******************************************************************/
					/*************************GRAVA ARQUIVO*******************************/
					/*ABRE O ARQUIVO PARA GERAR O RELAT�RIO*/
					/*cria fun��o*/
						gera_nome_do_arquivo ();	
					/*cria fun��o*/
						gera_arquivo ();
					/*cria fun��o*/
						monta_chamada ();
/*****************************************************************************************************************************************************************************************************************/					
				//	printf("\nDeseja realizar um novo teste?(s/n)\n");
				//	if (opcao=='n')
				//	 return main();
				//	}					
				//	while(opcao!='n');
					getch();
				}
/*****************************************************************************************************************************************************************************************************************/
				break;
				case '4': 
				system ("cls");
					/*************************GRAVA ARQUIVO*******************************/
							/*ABRE O ARQUIVO PARA GERAR O RELAT�RIO*/
					Arqref = fopen("REFERENCIAL_TEORICO.TXT", "w"); /*abre um arquivo; neste caso para grava��o, "w" abre novo*/
	
					/*Testar se abertura de arquivo deu certo*/
						if (Arqref == NULL) /*NULL = 0000.0000*/
						{
							/*Informo o erro*/
										system ("cls");
										printf("\n\a ERRO AO ABRIR %s!\a");
										getch();/*aguarda o pressionar de uma tecla*/
								/*Encerro o programa*/			
										exit (EXIT_FAILURE);
						}
					/*GRAVA REFERENCIAL TE�RICO EM TXT*/
					fprintf(Arqref, "REFERENCIAL TE�RICO\n");
					fprintf(Arqref, "==============================================================================================================================");
					fprintf(Arqref, "\nSegundo Albert Merabian, em seu livro 'Silent Messages, o poder de influ�ncia das palavras n�o passa de 7%, \n");
				    fprintf(Arqref, "enquanto a forma como as palavras s�o ditas e a fisiologia representam 38%% e 55%% deste poder, respectivamente.\n");			
					fprintf(Arqref, "\nPara Merabian 55% do impacto da comunica��o � n�o-verbal. Corresponde � postura, gestos e contato visual da\n");
					fprintf(Arqref, "pessoa enquanto se comunica.\n");
					fprintf(Arqref, "\nO tom da voz representa 38%% do impacto da comunica��o.\n");
					fprintf(Arqref, "\nPor fim, as palavras propriamente ditas det�m 7%% do impacto da comunica��o.\n");
					fprintf(Arqref, "\nAssim sendo, conclui Merabian, n�o � o que dizemos, mas como dizemos que faz a diferen�a na comunica��o.\n");
					fprintf(Arqref, "\nAs portas da percep��o s�o os nossos sentidos, nossos olhos, nariz, ouvidos, boca e pele, nossos �nicos pontos de\n"); 
					fprintf(Arqref, "contato com o mundo exterior. Da mesma forma que utilizamos os sentidos para filtrarmos as experi�ncias,\n");
					fprintf(Arqref, "utilizamos os sentidos para estruturar nosso pensamento e nossa comunica��o.\n"); 
 					fprintf(Arqref, "\nDe acordo com a Programa��o Neurolingu�stica existem os seguintes sistemas representacionais.\n\n");
					fprintf(Arqref, "- Auditivo\n");
					fprintf(Arqref, "- Digital\n");
					fprintf(Arqref, "- Cinest�sico\n");
					fprintf(Arqref, "- Visual\n");
					fprintf(Arqref, "\n");
					fprintf(Arqref, "Algumas pessoas captam melhor as mensagens do mundo exterior atrav�s da audi��o, s�o as pessoas chamadas auditivas.\n");
					fprintf(Arqref, "Outras pessoas sentem necessidade de perguntar muito, necessitam de muitas informa��es e fatos. Estas s�o as digitais.\n");
					fprintf(Arqref, "As cinest�sicas aprendem melhor por meio das sensa��es t�teis, como o tato, a temperatura, a umidade, as sensa��es internas \n");
					fprintf(Arqref, "J� as pessoas visuais aprendem melhor quando se valendo da vis�o.\n");
					fprintf(Arqref, "e as emo��es.\n\n");
					fprintf(Arqref, "Cada pessoa tem um sistema representacional predominante e adequar a comunica��o ao sistema representacional \n");
					fprintf(Arqref, "dominante dela � fundamental para di�logos eficientes.\n");
					fprintf(Arqref, "==============================================================================================================================");
					/*FECHA ARQUIVO*/
					fclose (Arqref);
					printf ("\n\n\n");
					system ("NOTEPAD REFERENCIAL_TEORICO.TXT");
					getch();
				
				break;	
				case 'F' : 
				case 'f' : exit (0); // exite encerra o menu
				break;
				default : printf ("\a ERRO AO ESCOLHER!"); //se n�o escolher op��o valida
    }
    getch();
	goto INICIAR;
    return 0;
}
/***************************************************************************************/
void master_menu (void)
{
	opcao ='*';
 	while (opcao!='F'|| opcao!='f')
 	{//RODAMENU
    menu ();
    }
    return 0;
}
/***************************************************************************************/
/*CORPO DO PROGRAMA*/
int main ()
{
	/*PERSONALIZAR TELA*/
	setlocale (LC_ALL, "Portuguese");
	system ("cls");	
	system ("color 47");
	system ("mode 80,23");
/*cria fun��o*/	
    limpa_variaveis ();
/*cria fun��o*/    
    tela_login();
/***************************************************************************************/     
    master_menu (); 
/***************************************************************************************/    
    menu_aluno ();
/***************************************************************************************/    
	return 0;
}
