#include "campoMinado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 10
#define NUM_BOMBAS 10
#define NUM_LIMPOS 40

void limpartela(){
    system("cls");
}

int tratarEntrada(Posicao_t *posicao) {
    if (posicao->PosicaoLinha < 0 || posicao->PosicaoLinha > 5 || posicao->PosicaoColuna < 0 || posicao->PosicaoColuna > 10) {
        return 1;
    }
    return 0; 
}

void tamanhoMatriz(Posicao_t *posicao){
    int i, j;

    posicao->campo = (char **)malloc(LINHAS * sizeof(char *));

    for (i = 0; i < COLUNAS; i++){
        posicao->campo[i] = (char *)malloc(COLUNAS * sizeof(char));
    }

    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            posicao->campo[i][j] = 'X';
        }
    }

    printf("\nCampo Minado:\n\n");
    printf("     ");

    for (j = 0; j < COLUNAS; j++){
        if (j < 9){
            printf("0%d  ", j + 1);
        }else{
            printf("%d  ", j + 1);
        }
    }

    printf("\n");

    for (i = 0; i < LINHAS; i++){
        printf(" %2d ", i + 1);
        for (j = 0; j < COLUNAS; j++){
            printf("[%c] ", posicao->campo[i][j]);
        }
        printf("\n");
    }
}

void CampoPadrao(Posicao_t *posicao){
    tamanhoMatriz(posicao);
}

int Campo(Posicao_t *posicao){
    int local;
    posicao->PosicaoLinha--;
    posicao->PosicaoColuna--;
    int i, j, b;
    char campocomBombas[LINHAS][COLUNAS];
    srand(time(NULL));


    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            campocomBombas[i][j] = 'L';
        }
    }

    for (b = 0; b < NUM_BOMBAS; b++){
        do{
            local = rand() % (LINHAS * COLUNAS);
            i = local / COLUNAS;
            j = local % COLUNAS;
        } while (campocomBombas[i][j] == 'B');

        campocomBombas[i][j] = 'B';
    }

    if (campocomBombas[posicao->PosicaoLinha][posicao->PosicaoColuna] == 'B'){
        posicao->campo[posicao->PosicaoLinha][posicao->PosicaoColuna] = 'B';
        printf("BOMBAA!\n");
        posicao->erros += 1;
        if (posicao->erros >= 3){
            printf("Voce perdeu!\n");
            return 3;
        }
    }else{
        posicao->campo[posicao->PosicaoLinha][posicao->PosicaoColuna] = 'L';
        printf("LIMPO!\n");
        posicao->acertos++;
    }
    printf("Acertos: %d\n", posicao->acertos);
    printf("Erros: %d\n", posicao->erros);
    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            if (posicao->campo[i][j] == 'X' && !(i == posicao->PosicaoLinha && j == posicao->PosicaoColuna)){
                 posicao->campo[i][j] = 'X';
            }
        }
    }

    printf("Campo atualizado\n");
    printf("    ");
    for (j = 0; j < COLUNAS; j++){
        if (j < 9) {
            printf("0%d  ", j + 1);
        }
        else
        {
            printf(" %d", j + 1);
        }
    }

    printf("\n");

    for (i = 0; i < LINHAS; i++){
        printf(" %2d ", i + 1);
        for (j = 0; j < COLUNAS; j++){
            printf("[%c] ", posicao->campo[i][j]);
        }
        printf("\n");
    }
    
     return 0;
}

