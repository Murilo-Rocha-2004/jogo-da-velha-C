#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_CTYPE, "");
	srand(time(NULL));
    int i,j;
    int m[3][3];
    int turno, jogador,ganhou,menu;
	int sair=0;
	int opcao;

    while (!sair) { // Loop para jogar novamente
	system("cls"); // LIMPAR TERMINAL
	ganhou = 0;
    // EXIBIR JOGO DA VELHA
	printf("\tJOGO DA VELHA\n");
		printf("\t+---+---+---+\n");
		
    	for(i=0;i<3;i++){
			printf("\t|");
			
				for(j=0;j<3;j++){
					m[i][j]=0;
	            	printf("   |"); // EXIBI O JOGO DA VELHA VAZIO
	            }
	            
	        printf("\n\t+---+---+---+\n");
        }
	printf("1 - Jogar\n2 - Jogar contra bot (em desenvolvimento)\n3 - Como jogar\n4 - Sair\n"); 
	printf("Insira o que deseja fazer (1 - 4): ");
	scanf("%i",&menu);

	switch (menu) { // Menu 
	case 1:	// JOGAR
		// DEFINIR TURNOS DE CADA JOGADOR
		for(turno=1;ganhou!=1;turno++){ // JOGO SÓ ACABA QUANDO VALOR DE GANHOU FOR IGUAL A 1
	        if(turno%2!=0){ // JOGADOR 1 (X)- IMPAR
	           	do{ 
		            printf("\n\tJogador 1\nDigite a coordenada da linha: ");
		            scanf("%i",&i); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              i=i-1;	 
              		
		            printf("Digite a coordenada da coluna: ");
		            scanf("%i",&j); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              j=j-1;
            
				}while(m[i][j]!=0 || i<0 || i>2 || j<0 || j>2); // VERIFICAR SE COORDENADA ESTA VAZIA
	            
	            m[i][j]=1; // VALOR DA MATRIZ
            	jogador = 1; // JOGADOR QUE FEZ A JOGADA 
				           
	        }
	        else if(turno%2==0){ // JOGADOR 2 (O)- PAR
	            do{
		            printf("\n\tJogador 2\nDigite a coordenada da linha: ");
		            scanf("%i",&i); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              i=i-1;
              		
		            printf("Digite a coordenada da coluna: "); 
		            scanf("%i",&j); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              j=j-1;
            

				}while(m[i][j]!=0 || i<0 || i>2 || j<0 || j>2); // VERIFICAR SE COORDENADA ESTA VAZIA
	            
	            m[i][j]=2; // VALOR DA MATRIZ
            	jogador = 2; // JOGADOR QUE FEZ A JOGADA
            	
	        }
	        
	        // EXIBI JOGO DA VELHA APÓS A JOGADA
	        printf("\t+---+---+---+\n");
	        for(i=0;i<3;i++){
		        printf("\t|");
		        
		            for(j=0;j<3;j++){
		            	if(m[i][j]==1){
		            		printf(" X |"); // SE O VALOR FOR 1 COLOCAR UM X NO LUGAR
		            	}
						else if(m[i][j]==2){
		            		printf(" O |"); // SE O VALOR FOR 2 COLOCAR UM O NO LUGAR
		            	}
		            	else{
		            		printf("   |"); // SENAO DEIXA VAZIO
						}
		            }
		            
		            printf("\n\t+---+---+---+\n");
	        }
	        
	        // VERIFICADOR DE VITORIA
	        // TODAS POSSIBILIDADES DE VITORIA
	        if((m[0][0] == m[0][1] && m[0][0] == m[0][2] && m[0][0] != 0)|| // HORIZONTAL 1
			   (m[1][0] == m[1][1] && m[1][0] == m[1][2] && m[1][0] != 0)|| // HORIZONTAL 2
			   (m[2][0] == m[2][1] && m[2][0] == m[2][2] && m[2][0] != 0)|| // HORIZONTAL 3
			   
			   (m[0][0] == m[1][0] && m[0][0] == m[2][0] && m[0][0] != 0)|| // VERTICAL 1
			   (m[0][1] == m[1][1] && m[0][1] == m[2][1] && m[0][1] != 0)|| // VERTICAL 2
			   (m[0][2] == m[1][2] && m[0][2] == m[2][2] && m[0][2] != 0)|| // VERTICAL 3
			   
			   (m[0][0] == m[1][1] && m[0][0] == m[2][2] && m[0][0] != 0)|| // DIAGONAL 1
			   (m[2][0] == m[1][1] && m[2][0] == m[0][2] && m[2][0] != 0)){ // DIAGONAL 2
				
				// SE EXISTIR ALGUMA VITORIA
				printf("\t\n\aPARABENS! Jogador %d ganhou!!", jogador); // MOSTRAR GANHOU JOGADOR GANHOU
				ganhou = 1; // ENCERRA O FOR DE TURNOS
				
			}
			else if(turno==9){ // SE TODAS JOGADAS FOREM USADAS
				printf("\t\a\nDeu velha");	// EXIBIR EMPATE
				ganhou = 1; // ENCERRAR TURNOS	
				
			}  
	    }
		do{ // Sair ou voltar ao menu
			printf("\nDigite 1 para jogar novamente ou 2 para sair: ");
            scanf("%d", &opcao);
			} while (opcao != 1 && opcao != 2);
            	if (opcao == 2) {
					printf("Obrigado por jogar");
                    sair = 1; // Encerra o loop e sai do programa
                }
		break;
	case 2: // Jogar contra IA
		for(turno=1;ganhou!=1;turno++){ // JOGO SÓ ACABA QUANDO VALOR DE GANHOU FOR IGUAL A 1
	        if(turno%2!=0){ // JOGADOR 1 (X)- BOT
	           	do{ 
					i = (rand() % 3); // Sera gerado um numero aleatorio entre 1 e 3 
					j = (rand() % 3);
					
				}while(m[i][j]!=0 || i<0 || i>2 || j<0 || j>2); // VERIFICAR SE COORDENADA ESTA VAZIA
				
				printf("\n\tBOT\nJogou na linha: %i",i+1);
	            printf("\nJogou na coluna: %i\n",j+1);
	            m[i][j]=1; // VALOR DA MATRIZ
            	jogador = 1; // JOGADOR QUE FEZ A JOGADA 	           
	        }
	        else if(turno%2==0){ // JOGADOR 2 (O)- IMPAR
	            do{
		            printf("\n\tJogador 2\nDigite a coordenada da linha: ");
		            scanf("%i",&i); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              i=i-1; 		
		            printf("Digite a coordenada da coluna: "); 
		            scanf("%i",&j); // COLETA COORDENADA DE UM NUMERO DE 1 A 3
              j=j-1;
				}while(m[i][j]!=0 || i<0 || i>2 || j<0 || j>2); // VERIFICAR SE COORDENADA ESTA VAZIA
	            
	            m[i][j]=2; // VALOR DA MATRIZ
            	jogador = 2; // JOGADOR QUE FEZ A JOGADA
	        }
	        // EXIBI JOGO DA VELHA APÓS A JOGADA
	        printf("\t+---+---+---+\n");
	        for(i=0;i<3;i++){
		        printf("\t|");
		        
		            for(j=0;j<3;j++){
		            	if(m[i][j]==1){
		            		printf(" X |"); // SE O VALOR FOR 1 COLOCAR UM X NO LUGAR
		            	}
						else if(m[i][j]==2){
		            		printf(" O |"); // SE O VALOR FOR 2 COLOCAR UM O NO LUGAR
		            	}
		            	else{
		            		printf("   |"); // SENAO DEIXA VAZIO
						}
		            }
		            
		            printf("\n\t+---+---+---+\n");
	        }
	        
	        // VERIFICADOR DE VITORIA
	        // TODAS POSSIBILIDADES DE VITORIA
	        if((m[0][0] == m[0][1] && m[0][0] == m[0][2] && m[0][0] != 0)|| // HORIZONTAL 1
			   (m[1][0] == m[1][1] && m[1][0] == m[1][2] && m[1][0] != 0)|| // HORIZONTAL 2
			   (m[2][0] == m[2][1] && m[2][0] == m[2][2] && m[2][0] != 0)|| // HORIZONTAL 3
			   
			   (m[0][0] == m[1][0] && m[0][0] == m[2][0] && m[0][0] != 0)|| // VERTICAL 1
			   (m[0][1] == m[1][1] && m[0][1] == m[2][1] && m[0][1] != 0)|| // VERTICAL 2
			   (m[0][2] == m[1][2] && m[0][2] == m[2][2] && m[0][2] != 0)|| // VERTICAL 3
			   
			   (m[0][0] == m[1][1] && m[0][0] == m[2][2] && m[0][0] != 0)|| // DIAGONAL 1
			   (m[2][0] == m[1][1] && m[2][0] == m[0][2] && m[2][0] != 0)){ // DIAGONAL 2
				
				// SE EXISTIR ALGUMA VITORIA
				if(jogador==1){
					printf("\t\n\aNao foi desse vez, o BOT ganhou!!"); // MOSTRAR GANHOU JOGADOR GANHOU		
				}
				else{
					printf("\t\n\aPARABENS! Voce ganhou!!"); // MOSTRAR GANHOU JOGADOR GANHOU	
				}
				
				ganhou = 1; // ENCERRA O FOR DE TURNOS
				
			}
			else if(turno==9){ // SE TODAS JOGADAS FOREM USADAS
				printf("\t\a\nDeu velha");	// EXIBIR EMPATE
				ganhou = 1; // ENCERRAR TURNOS	
				
			}  
	    }
		do{ // Sair ou voltar ao menu
			printf("\nDigite 1 para jogar novamente ou 2 para sair: ");
            scanf("%d", &opcao);
			} while (opcao != 1 && opcao != 2);
            	if (opcao == 2) {
					printf("Obrigado por jogar");
                    sair = 1; // Encerra o loop e sai do programa
                }
		break;
	case 3: // TUTORIAL
		printf("\t\n\aCOMO JOGAR JOGO DA VELHA:\n");
		printf("O Jogo da Velha eh um jogo de tabuleiro para dois jogadores.\n");
        printf("O objetivo eh formar uma linha com tres símbolos iguais, seja na horizontal, vertical ou diagonal.\n\n");
            printf("\tREGRAS:\n");
        printf("1. O tabuleiro eh uma matriz 3x3.\n");
        printf("2. Cada jogador alterna turnos e escolhe uma celula para colocar seu símbolo.\n");
            printf("\t- Jogador 1 usa o simbolo 'X'.\n");
            printf("\t- Jogador 2 usa o simbolo 'O'.\n");
        printf("3. O jogador deve informar a linha e a coluna com numeros de 1 a 3, para fazer a jogada.\n");
        printf("4. O jogo termina quando um jogador forma uma linha com tres simbolos iguais ou quando todas as celulas sao preenchidas sem vitoria (empate).\n");
        printf("5. Para vencer, o jogador deve colocar tres simbolos iguais em linha (horizontal, vertical ou diagonal).\n");
            printf("\n\tDivirta-se jogando!\n");
			do{ // Sair ou voltar ao menu
				printf("\nDigite 1 para voltar ao menu principal ou 2 para sair: ");
                scanf("%d", &opcao);
			} while (opcao != 1 && opcao != 2);
            	if (opcao == 2) {
					printf("Obrigado por jogar");
                    sair = 1; // Encerra o loop e sai do programa
                }
		break;
	case 4: // Sair
		printf("Obrigado por jogar");
		
		sair = 1;
		break;
	default:
		
		break;
	}
}	    
	
    return 0;
}