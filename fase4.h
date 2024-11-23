#ifndef FASE4_H
#define FASE4_H

#define LINHAS 8
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
} PosicaoFase4_t;

void CampoPadraoFase4(PosicaoFase4_t *posicao);
void tamanhoMatrizFase4(PosicaoFase4_t *posicao);
int CampoFase4(PosicaoFase4_t *posicao, int campoBombas[LINHAS][COLUNAS]);
void campobombasFase4(int campoBombas[LINHAS][COLUNAS]);
void contarbombasFase4(int campocomBombas[LINHAS][COLUNAS]);
void limpartelaFase4();
int tratarEntradaFase4(PosicaoFase4_t *posicao);
void liberarMemoriaFase4(PosicaoFase4_t *posicao);


#endif
