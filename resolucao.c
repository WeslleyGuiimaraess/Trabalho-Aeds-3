#include "resolucao.h"
#include "lista.h"
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

void insertionSort(double *v, int *ind, int n) {
    int i, j, indk;
    double vk;

    for (i = 1; i < n; i++) {
        vk = v[i];
        indk = ind[i];
        j = i - 1;

        while (j >= 0 && v[j] > vk) {
            v[j+1] = v[j];
            ind[j+1] = ind[j];
            j--;
        }

        v[j+1] = vk;
        ind[j+1] = indk;
    }
}

void resolveGuloso(nave *n, int *poder, int *peso, int *qtdguerreiros, lista *caminho) {
    int i, j, pesoatual = 0, poderatual = 0;
    double v[n.qtdpovos];
    int ind[n.qtdpovos];
    qtdguerreiros[n.qtdpovos]; // Quantidade de guerreiros por cada povo
    // Alocação dinâmica ^ ??
    // lista *caminho = listaInit();

    for (i = 0; i < n.qtdpovos; i++) {
        v[i] = n.povos[i].habilidade / n.povos[i].peso;
        ind[i] = i;
        qtdguerreiros[i] = 0;
    }
    insertionSort(v, ind, n.qtdpovos);
    // listaInsere(caminho, ind[i]);

    for (i = n.qtdpovos; i >= 0; i--) {
        // Caminho entre vértices aqui
        j = (n.capacidade - pesoatual) / n.povos[ind[i]].peso;
        pesoatual += j * n.povos[ind[i]].peso;
        poderatual += j * n.povos[ind[i]].habilidade;
        qtdguerreiros[ind[i]] = j;
    }

    poder = &poderatual;
    peso = &pesoatual;
}
