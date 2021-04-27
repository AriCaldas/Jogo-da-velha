///Jogo da Velha///
#include <stdio.h> //INCLUS�O DAS BIBLIOTECAS NECESS�RIAS AO PROGRAMA
#include <stdlib.h>
#include <locale.h>

void tabuleiro(char t[3][3]){ //Exibi��o do tabuleiro

    system("cls");
    printf("\n");
    printf("\t\t\t%c | %c | %c \n", t[0][0], t[0][1], t[0][2]);
    printf("\t\t\t---------\n");
    printf("\t\t\t%c | %c | %c \n", t[1][0], t[1][1], t[1][2]);
    printf("\t\t\t---------\n");
    printf("\t\t\t%c | %c | %c \n", t[2][0], t[2][1], t[2][2]);

}

int main(){

    char tab[3][3]; //VARI�VEL QUE RECEBE OS VALORES DO TABULEIRO (JOGADAS)
    int vez, contJogadas; //"vez" SERVE PARA IDENTIFICAR O JOGADOR. "contJogadas" CONTROLE O NPUMERO DE JOGADAS PERMITIDAS.
    int linha, coluna, i, j; //"linha" e "coluna" ser�o digitadas pelos jogadores e armazenadas em "tab".
    char resposta;        //Verifica se haver� uma nova partida ou se o programa se encerrar�.

    setlocale(LC_ALL, ""); //Para correta exibi��o de caracteres especiais e acentua��o gr�fica.
    printf("\t\t----- JOGO DA VELHA -----\n");
    printf("\tPressione qualquer tecla para iniciar!\n");
    getch();
    do{  //La�o externo, cont�m a inicializa��o das vari�veis para uma nova partida e controla e reincia um novo jogo ou finaliza o programa ao final da partida.

        tabuleiro(tab);     //Exibi��o do tabuleiro.
        //Inicializa��o do tabuleiro, para verifica��o futura de "lugar ocupado".
        for(i = 0; i < 3; i++){   //La�o externo para linhas
            for(j = 0; j < 3; j++){ //La�o interno para colunas
                tab[i][j] = ' ';    //Atribui��o de espa�o em branco � respectiva casa.
            }
        }
        vez = 0;   //Inicializa��o da vari�vel "vez" para verifica��o da identidade do jogador(X ou O)
        contJogadas = 0;   //Incializa��o da vari�vel "contJogadas" para delimitar o preenchimento do tabuleiro.
        do{        //La�o interno que controla o npumero de jogadas.
            tabuleiro(tab);   //Exibi��o do tabuleiro.
            printf("\nEscolha a linha: ");  //Intera��es com o usu�rio para preenchimento do tabuleiro
            scanf("%i", &linha);
            printf("Escolha a coluna: ");
            scanf("%i", &coluna);
            if((linha < 1 || coluna > 3)||(coluna < 0 || coluna > 3)){   //Verifica jogada inexistente
                printf("Jogada INV�LIDA!\nTente novamente!");
                getch();
            }else{
                if(tab[linha - 1][coluna - 1] != ' '){   //Verifica se o lugar est� livre para a jogada.
                    printf("Lugar OCUPADO!\nTente novamente!");
                    getch();
            }else{
                if(vez % 2 == 0){      //Verifica o valor da vari�vel "vez" para identifica��o do jogador (X ou O)
                    tab[linha - 1][coluna - 1] = 'X';
                }else{
                    tab[linha - 1][coluna - 1] = 'O';
                    }
                    vez++;            //Caso a jogada tenha sido efetivada: incrementar "vez" e "contJogadas".
                    contJogadas++;
                }
            }
            //CONDI��ES DE VIT�RIA PARA X
            //HORIZONTAIS
            if(tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X'){contJogadas = 10;}
            if(tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X'){contJogadas = 10;}
            if(tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X'){contJogadas = 10;}
            //VERTICAIS
            if(tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X'){contJogadas = 10;}
            if(tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X'){contJogadas = 10;}
            if(tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X'){contJogadas = 10;}
            //DIAGONAIS
            if(tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X'){contJogadas = 10;}
            if(tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X'){contJogadas = 10;}
            //CONDI��ES DE VIT�RIA PARA O
            //HORIZONTAIS
            if(tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O'){contJogadas = 11;}
            if(tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O'){contJogadas = 11;}
            if(tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O'){contJogadas = 11;}
            //VERTICAIS
            if(tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O'){contJogadas = 11;}
            if(tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O'){contJogadas = 11;}
            if(tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O'){contJogadas = 11;}
            //DIAGONAIS
            if(tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O'){contJogadas = 11;}
            if(tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O'){contJogadas = 11;}

        }while(contJogadas < 9);   //Limite de jogadas permitidas por partida.
        tabuleiro(tab);            //Exibi��o do estado final do tabuleiro.
        if(contJogadas == 10){     //Verificando o resultado da partida.
            printf("Vencedor, jogador X\n");
        }else{
            if(contJogadas == 11){
                printf("Vencedor, jogador O\n");
            }else{
                printf("EMPATE!\n");
            }
        }
        printf("Deseja jogar outra partida? s/n ");   //Intera��o com usu�rio para uma nova partida ou fim do programa.
        fflush(stdin);           //Limpeza de buffer.
        scanf("%c", &resposta);
    }while(resposta == 's');     //Condi��o de nova partida ou encerramento do jogo.

    return 0;
}
