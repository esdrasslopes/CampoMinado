#include "fase5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10
#define NUM_BOMBAS 70
#define NUM_LIMPOS 30

void limpartelaFase5(){
    system("cls");
}

int tratarEntradaFase5(PosicaoFase5_t *posicao) {
    if (posicao->PosicaoLinha < 1 || posicao->PosicaoLinha > LINHAS || 
        posicao->PosicaoColuna < 1 || posicao->PosicaoColuna > COLUNAS) {
        return 1; 
    }
    return 0; 
}


void tamanhoMatrizFase5(PosicaoFase5_t *posicao){
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

void CampoPadraoFase5(PosicaoFase5_t *posicao){
   tamanhoMatrizFase5(posicao);
}

void campobombasFase5(int campoBombas[LINHAS][COLUNAS]){
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

void contarbombasFase5(int campoBombas[LINHAS][COLUNAS]){
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

int CampoFase5(PosicaoFase5_t *posicao, int campoBombas[LINHAS][COLUNAS]){
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

void liberarMemoriaFase5(PosicaoFase5_t *posicao) {
    int i;
    for (i = 0; i < LINHAS; i++) {
        free(posicao->campo[i]);
    }
    free(posicao->campo);
    posicao->campo = NULL; 
}


int main() {
    PosicaoFase5_t posicao;
    posicao.chances = 0;
    posicao.erros = 0;
    posicao.acertos = 0;
    posicao.play = 0;
    int campoBombas[LINHAS][COLUNAS];
    limpartelaFase5();
    printf("--------------------------\n");
    printf("Bem vindo a fase 5!\n");
    printf("1 - JOGAR\n");
    printf("2 - SAIR\n");
    printf("----------------------------\n");
    scanf("%d", &posicao.play); 

    if (posicao.play == 1) { 
        limpartelaFase5();
        printf("---------------------------------------------\n");
        printf("Bem-vindo a quinta fase do campo minado!!\n");
        printf("O campo tera  30 espacos livres e 70 bombas!!\n");
        printf("Voce tera 10 chances e podera errar 3 vezes!\n");
        printf("---------------------------------------------\n");
        CampoPadraoFase5(&posicao);
        campobombasFase5(campoBombas);
        contarbombasFase5(campoBombas);
        do {
            do {
                printf("\n\nEscolha uma posicao no campo minado:\nDigite a linha e a coluna no formato:[linha] [coluna]\nExemplo: 1 10 (linha 1, coluna 10)\n");
                scanf("%d %d", &posicao.PosicaoLinha, &posicao.PosicaoColuna);

                if (tratarEntradaFase5(&posicao) == 1) {
                    printf("Posicoes invalidas! Escolha outra!\n");
                }
            } while (tratarEntradaFase5(&posicao) == 1);
            posicao.chances++; 
            limpartelaFase5();
            CampoFase5(&posicao, campoBombas);
            printf("\n\n");
        } while (posicao.chances < 10 && posicao.erros <= 3);  

        limpartelaFase5();

        if(posicao.erros >= 4){
            printf("Voce passou de 3 erros e perdeu!");    
        }
        printf("FIM DA FASE 5!\n");
        printf("STATUS:\n");
        printf("ERROS: %d\n", posicao.erros);
        printf("ACERTOS: %d\n", posicao.acertos);
        printf("PARABENS POR FINALIZAR A JORNADA\n");

        liberarMemoriaFase5(&posicao);
    }else{
        return 3;
    }
    
    return 0;
}


