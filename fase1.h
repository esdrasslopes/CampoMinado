#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

#define LINHAS 5
#define COLUNAS 10

typedef struct {
    char opcao;
    int play;
    int PosicaoLinha;
    int PosicaoColuna;
    char **campo;
    int chances;
    int erros;
    int acertos;
    int sair;
    int proximafase;
} Posicao_t;

void CampoPadrao(Posicao_t *posicao);
void tamanhoMatriz(Posicao_t *posicao);
int Campo(Posicao_t *posicao, int campoBombas[LINHAS][COLUNAS]);
void campobombas(int campocomBombas[LINHAS][COLUNAS]);
void contarbombas(int campocomBombas[LINHAS][COLUNAS]);
void limpartela();
int tratarEntrada(Posicao_t *posicao);
void liberarMemoria(Posicao_t *posicao);

#endif
