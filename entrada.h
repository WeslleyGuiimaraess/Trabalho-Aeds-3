#ifndef ENTRADA_H
#define ENTRADA_H

typedef struct {
    int peso;
    int habilidade;
} povo;

typedef struct {
    povo *povos;
    int qtdpovos;
    unsigned int **dist;
    int maxdist;
    int capacidade;
} nave;

nave *leEntrada(char *arq, int *qtd);

#endif
