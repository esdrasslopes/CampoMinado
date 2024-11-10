#include <stdio.h>
#include "campoMinado.h"
#include <stdlib.h>


int main() {
    Posicao_t posicao;
    posicao.chances = 0;
    posicao.erros = 0;
    posicao.acertos = 0;
    posicao.play = 0;
    printf("--------------------------\n");
    printf("Bem vindo ao campo minado!\n");
    printf("1 - Jogar\n");
    printf("2 - SAIR\n");
    printf("----------------------------\n");
    scanf("%d", &posicao.play); 

    if(posicao.play == 1){
        limpartela();
        printf("--------------------------------------------\n");
        printf("Voce tera 10 chances e podera errar 3 vezes!\n");
        printf("--------------------------------------------\n");
        CampoPadrao(&posicao);
        do{
            printf("\n\nEscolha uma posicao no campo minado:\nDigite a linha e a coluna no formato: [linha] [coluna]\nExemplo: 1 10 (linha 1, coluna 10)\n");
            scanf("%d %d", &posicao.PosicaoLinha, &posicao.PosicaoColuna);
            if(tratarEntrada(&posicao) == 1){
                printf("Posicoes invalidas! Recomece o jogo!");
                return 3;
            }
            posicao.chances++;
            Campo(&posicao);
            printf("\n\n");
        }while(posicao.chances < 10);
        limpartela();
        printf("FIM DE JOGO!\n");
        printf("STATUS:\n");
        printf("ERROS: %d\n", posicao.erros);
        printf("ACERTOS: %d\n", posicao.acertos);
        
    }else{
        return 3;
    }
    return 0;
}
