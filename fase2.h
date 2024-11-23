#ifndef FASE2_H
#define FASE2_H

#define LINHAS 6
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
} PosicaoFase2_t;

void CampoPadraoFase2(PosicaoFase2_t *posicao);
void tamanhoMatrizFase2(PosicaoFase2_t *posicao);
int CampoFase2(PosicaoFase2_t *posicao, int campoBombas[LINHAS][COLUNAS]);
void campobombasFase2(int campoBombas[LINHAS][COLUNAS]);
void contarbombasFase2(int campocomBombas[LINHAS][COLUNAS]);
void limpartelaFase2();
int tratarEntradaFase2(PosicaoFase2_t *posicao);
void liberarMemoriaFase2(PosicaoFase2_t *posicao);


#endif
