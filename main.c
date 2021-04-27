///Jogo da Velha///
#include <stdio.h> //INCLUSÃO DAS BIBLIOTECAS NECESSÁRIAS AO PROGRAMA
#include <stdlib.h>
#include <locale.h>

void tabuleiro(char t[3][3]){ //Exibição do tabuleiro

    system("cls");
    printf("\n");
    printf("\t\t\t%c | %c | %c \n", t[0][0], t[0][1], t[0][2]);
    printf("\t\t\t---------\n");
    printf("\t\t\t%c | %c | %c \n", t[1][0], t[1][1], t[1][2]);
    printf("\t\t\t---------\n");
    printf("\t\t\t%c | %c | %c \n", t[2][0], t[2][1], t[2][2]);

}

int main(){

    char tab[3][3]; //VARIÁVEL QUE RECEBE OS VALORES DO TABULEIRO (JOGADAS)
    int vez, contJogadas; //"vez" SERVE PARA IDENTIFICAR O JOGADOR. "contJogadas" CONTROLE O NPUMERO DE JOGADAS PERMITIDAS.
    int linha, coluna, i, j; //"linha" e "coluna" serão digitadas pelos jogadores e armazenadas em "tab".
    char resposta;        //Verifica se haverá uma nova partida ou se o programa se encerrará.

    setlocale(LC_ALL, ""); //Para correta exibição de caracteres especiais e acentuação gráfica.
    printf("\t\t----- JOGO DA VELHA -----\n");
    printf("\tPressione qualquer tecla para iniciar!\n");
    getch();
    do{  //Laço externo, contém a inicialização das variáveis para uma nova partida e controla e reincia um novo jogo ou finaliza o programa ao final da partida.

        tabuleiro(tab);     //Exibição do tabuleiro.
        //Inicialização do tabuleiro, para verificação futura de "lugar ocupado".
        for(i = 0; i < 3; i++){   //Laço externo para linhas
            for(j = 0; j < 3; j++){ //Laço interno para colunas
                tab[i][j] = ' ';    //Atribuição de espaço em branco à respectiva casa.
            }
        }
        vez = 0;   //Inicialização da variável "vez" para verificação da identidade do jogador(X ou O)
        contJogadas = 0;   //Incialização da variável "contJogadas" para delimitar o preenchimento do tabuleiro.
        do{        //Laço interno que controla o npumero de jogadas.
            tabuleiro(tab);   //Exibição do tabuleiro.
            printf("\nEscolha a linha: ");  //Interações com o usuário para preenchimento do tabuleiro
            scanf("%i", &linha);
            printf("Escolha a coluna: ");
            scanf("%i", &coluna);
            if((linha < 1 || coluna > 3)||(coluna < 0 || coluna > 3)){   //Verifica jogada inexistente
                printf("Jogada INVÁLIDA!\nTente novamente!");
                getch();
            }else{
                if(tab[linha - 1][coluna - 1] != ' '){   //Verifica se o lugar está livre para a jogada.
                    printf("Lugar OCUPADO!\nTente novamente!");
                    getch();
            }else{
                if(vez % 2 == 0){      //Verifica o valor da variável "vez" para identificação do jogador (X ou O)
                    tab[linha - 1][coluna - 1] = 'X';
                }else{
                    tab[linha - 1][coluna - 1] = 'O';
                    }
                    vez++;            //Caso a jogada tenha sido efetivada: incrementar "vez" e "contJogadas".
                    contJogadas++;
                }
            }
            //CONDIÇÕES DE VITÓRIA PARA X
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
            //CONDIÇÕES DE VITÓRIA PARA O
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
        tabuleiro(tab);            //Exibição do estado final do tabuleiro.
        if(contJogadas == 10){     //Verificando o resultado da partida.
            printf("Vencedor, jogador X\n");
        }else{
            if(contJogadas == 11){
                printf("Vencedor, jogador O\n");
            }else{
                printf("EMPATE!\n");
            }
        }
        printf("Deseja jogar outra partida? s/n ");   //Interação com usuário para uma nova partida ou fim do programa.
        fflush(stdin);           //Limpeza de buffer.
        scanf("%c", &resposta);
    }while(resposta == 's');     //Condição de nova partida ou encerramento do jogo.

    return 0;
}
