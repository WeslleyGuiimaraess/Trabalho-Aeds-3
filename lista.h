#ifndef LISTA_H
#define LISTA_H

typedef struct _elemento {
    int valor;
    struct _elemento *prox;
} elemento;

typedef struct {
    int qtd;
    elemento *inicio;
} lista;

lista *listaInit() {
    lista *l = (lista*) malloc(sizeof(lista));
    l->qtd = 0;
    l->inicio = NULL;

    return l;
}

void listaInsere(lista *l, int valor) {
    elemento *e = (elemento*) malloc(sizeof(elemento));
    e->valor = valor;
    e->prox = l->inicio;
    l->inicio = e;
}

void listaFree(lista *l) {
    elemento *a, *b;
    b = l->inicio;

    while (b->prox != NULL) {
        a = b;
        b = b->prox;
        free(a);
    }

    free(l);
}
