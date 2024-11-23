#ifndef FASE3_H
#define FASE3_H

#define LINHAS 7
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
} PosicaoFase3_t;

void CampoPadraoFase3(PosicaoFase3_t *posicao);
void tamanhoMatrizFase3(PosicaoFase3_t *posicao);
int CampoFase3(PosicaoFase3_t *posicao, int campoBombas[LINHAS][COLUNAS]);
void campobombasFase3(int campoBombas[LINHAS][COLUNAS]);
void contarbombasFase3(int campocomBombas[LINHAS][COLUNAS]);
void limpartelaFase3();
int tratarEntradaFase3(PosicaoFase3_t *posicao);
void liberarMemoriaFase3(PosicaoFase3_t *posicao);


#endif
