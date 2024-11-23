#ifndef FASE5_H
#define FASE5_H

#define LINHAS 10
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
} PosicaoFase5_t;

void CampoPadraoFase5(PosicaoFase5_t *posicao);
void tamanhoMatrizFase5(PosicaoFase5_t *posicao);
int CampoFase5(PosicaoFase5_t *posicao, int campoBombas[LINHAS][COLUNAS]);
void campobombasFase5(int campoBombas[LINHAS][COLUNAS]);
void contarbombasFase5(int campocomBombas[LINHAS][COLUNAS]);
void limpartelaFase5();
int tratarEntradaFase5(PosicaoFase5_t *posicao);
void liberarMemoriaFase5(PosicaoFase5_t *posicao);


#endif
