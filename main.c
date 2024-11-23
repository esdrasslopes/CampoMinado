#include <stdio.h>
#include "fase1.h"
#include <stdlib.h>
#include <string.h>

#define LINHAS 5
#define COLUNAS 10

int main() {
    Posicao_t posicao;
    posicao.chances = 0;
    posicao.erros = 0;
    posicao.acertos = 0;
    posicao.play = 0;
    int campoBombas[LINHAS][COLUNAS];
    limpartela();
    printf("--------------------------\n");
    printf("Bem vindo ao campo minado!\n");
    printf("1 - Jogar\n");
    printf("2 - SAIR\n");
    printf("----------------------------\n");
    scanf("%d", &posicao.play); 

    if (posicao.play == 1) { 
        limpartela();
        printf("---------------------------------------------\n");
        printf("Bem-vindo a primeira fase do campo minado!!");
        printf("O campo tera  40 espacos livres e 10 bombas!!\n");
        printf("Voce tera 10 chances e podera errar 3 vezes!\n");
        printf("---------------------------------------------\n");
        CampoPadrao(&posicao);
        campobombas(campoBombas);
        contarbombas(campoBombas);
        do {
            do {
                printf("\n\nEscolha uma posicao no campo minado:\nDigite a linha e a coluna no formato:[linha] [coluna]\nExemplo: 1 10 (linha 1, coluna 10)\n");
                scanf("%d %d", &posicao.PosicaoLinha, &posicao.PosicaoColuna);

                if (tratarEntrada(&posicao) == 1) {
                    printf("Posicoes invalidas! Escolha outra!\n");
                }
            } while (tratarEntrada(&posicao) == 1);
            posicao.chances++; 
            limpartela();
            Campo(&posicao, campoBombas);
            printf("\n\n");
        } while (posicao.chances < 10 && posicao.erros <= 3); 
        limpartela();
        if(posicao.erros >= 4){
            printf("Voce passou de 3 erros e perdeu!");    
        }
        printf("FIM DA FASE 1!\n");
        printf("STATUS:\n");
        printf("ERROS: %d\n", posicao.erros);
        printf("ACERTOS: %d\n", posicao.acertos);

        liberarMemoria(&posicao);

        printf("Voce quer joga a fase 2?\n1-SIM\n2-NAO\n");
        scanf("%d", &posicao.proximafase);

        if(posicao.proximafase == 1){
            
            int compResult = system("gcc -o fase2.exe fase2.c");


            if (compResult != 0) {
                 printf("Erro na compilaco do codigo C\n");
                return 1;
            }

          

            if (system("fase2.exe") != 0) {
                printf("Erro na compilação do código C\n");
                return 1;
            }
        }
        
    }else{
        return 3;
    }
    
    return 0;
}
