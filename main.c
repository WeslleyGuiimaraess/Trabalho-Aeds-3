#include "entrada.h"
#include "resolucao.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int opt;
    char *entrada = NULL, *saida = NULL;

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
            case 'i':
                entrada = optarg;
                break;
            case 'o':
                saida = optarg;
                break;
            default:
                fprintf(stderr, "Opção inválida\n");
                return -1;
        }
    }
    int *qtdnaves;
    nave *naves = leEntrada(entrada, qtdnaves);

    for(i = 0; i < *qtdnaves; i++);
        // resolve naves[i]
}
