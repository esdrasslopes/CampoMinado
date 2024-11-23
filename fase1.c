#include "fase1.h"
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

    for (i = 0; i < LINHAS; i++){
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

void campobombas(int campoBombas[LINHAS][COLUNAS]){
    int local;
    int i, j, b;

    srand(time(NULL));
        for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            campoBombas[i][j] = 48;
        }
    }

    for (b = 0; b < NUM_BOMBAS; b++){
        do{
            local = rand() % (LINHAS * COLUNAS);
            i = local / COLUNAS;
            j = local % COLUNAS;
        } while (campoBombas[i][j] == 'B');

        campoBombas[i][j] = 'B';
    }
}

void contarbombas(int campoBombas[LINHAS][COLUNAS]){
    int i, j;
        for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if (campoBombas[i][j] == 'B'){
                continue;
            }
            
            int count = 0;
            // Verificar vizinhos ao redor de cada célula, com checagem de limites
            if (i > 0 && j > 0 && campoBombas[i-1][j-1] == 'B'){
                count++;
            }  // Cima-Esquerda
            if (i > 0 && campoBombas[i-1][j] == 'B') {
                count++;
            }  // Cima
            if (i > 0 && j < COLUNAS-1 && campoBombas[i-1][j+1] == 'B') {
                count++;
            }  // Cima-Direita
            if (j > 0 && campoBombas[i][j-1] == 'B') {
                count++;
            }  // Esquerda
            if (j < COLUNAS-1 && campoBombas[i][j+1] == 'B') {
                count++;
            }  // Direita
            if (i < LINHAS-1 && j > 0 && campoBombas[i+1][j-1] == 'B') {
                count++;
            }  // Baixo-Esquerda
            if (i < LINHAS-1 && campoBombas[i+1][j] == 'B') {
                count++;
            }  // Baixo
            if (i < LINHAS-1 && j < COLUNAS-1 && campoBombas[i+1][j+1] == 'B') {
                count++;
            }  // Baixo-Direita

            campoBombas[i][j] = count + '0';
        }
    }
}

int Campo(Posicao_t *posicao, int campoBombas[LINHAS][COLUNAS]){
    posicao->PosicaoLinha--;
    posicao->PosicaoColuna--;
    int i, j;
    srand(time(NULL));

    if (campoBombas[posicao->PosicaoLinha][posicao->PosicaoColuna] == 'B'){
        posicao->campo[posicao->PosicaoLinha][posicao->PosicaoColuna] = 'B';
        printf("BOMBAA!\n");
        posicao->erros += 1;
    }else{
        posicao->campo[posicao->PosicaoLinha][posicao->PosicaoColuna] = campoBombas[posicao->PosicaoLinha][posicao->PosicaoColuna];
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

void liberarMemoria(Posicao_t *posicao) {
    int i;
    
    for (i = 0; i < LINHAS; i++) {
        free(posicao->campo[i]);
    }
   
    free(posicao->campo);
    posicao->campo = NULL; 
}