#include "entrada.h"
#include <stdio.h>
#include <stdlib.h>

nave *leEntrada(char *arq, int *qtd) {
    /*
     * Recebe o nome do arquivo e retorna um vetor de naves e a quantidade de
     * naves por parâmetro.
     *
     * explicar funcao
     */

    int qtdnaves, i, j, k, caminhos, ind, peso, habilidade;
    int povo1, povo2, dist;
    FILE *f = fopen(arq, "r");
    fscanf(f, "%d", &qtdnaves);
    nave *naves = (nave*) malloc(sizeof(nave) * qtdnaves);

    for (i = 0; i < qtdnaves; i++) {
        fscanf(
            f, "%d%d%d%d",
            &naves[i].qtdpovos, &naves[i].maxdist,
            &naves[i].capacidade, &caminhos
        );

        naves[i].povos = (povo*) malloc(sizeof(povo) * naves[i].qtdpovos);
        naves[i].dist = (int**) malloc(sizeof(int*) * naves[i].qtdpovos);

        // Lê os povos
        for (j = 0; j < naves[i].qtdpovos; j++) {
            fscanf(f, "%d%d%d", &ind, &peso, &habilidade);
            naves[i].povos[ind-1].peso = peso;
            naves[i].povos[ind-1].habilidade = habilidade;
        }

        // Inicializa a matriz com valores de distância inválidos (-1)
        for (j = 0; j < naves[i].qtdpovos; j++) {
            naves[i].dist[j] = (int*) malloc(sizeof(int) * naves[i].qtdpovos);
            for (k = 0; k < naves[i].qtdpovos; k++)
                naves[i].dist[j][k] = -1;
        }

        // Lê as distâncias
        for (j = 0; j < caminhos; j++) {
            fscanf(f, "%d%d%d", &povo1, &povo2, &dist);
            naves[i].dist[povo1-1][povo2-1] = dist;
            naves[i].dist[povo2-1][povo1-1] = dist;
        }
    }

    fclose(f);
    return naves;
}
