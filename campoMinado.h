#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H
#define LINHAS 5
#define COLUNAS 10

typedef  struct{
    int play;
    int PosicaoLinha;
    int PosicaoColuna;
    char **campo;
    int chances;
    int erros;
    int acertos;
    int sair;
}Posicao_t;

void CampoPadrao(Posicao_t *posicao);
void tamanhoMatriz(Posicao_t *posicao);
int Campo(Posicao_t *posicao);
void limpartela();
int tratarEntrada(Posicao_t *posicao);
#endif