#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no No;
struct no {
  int info;
  No* prox;
};

struct fila {
  No* ini;
  No* fim;
};

Fila* fila_cria (void) {
  printf("Fila implementada com lista\n");
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->ini = f->fim = NULL;
  return f;
}

void fila_insere (Fila* f, int v) {
  No* novo_no = (No*) malloc(sizeof(No));
  if (!novo_no) exit(1);
  novo_no->info = v;
  novo_no->prox = NULL;

  if (f->ini == NULL) f->ini = novo_no;
  if (f->fim != NULL) {
    f->fim->prox = novo_no;
  }
  f->fim = novo_no;
}

int fila_retira (Fila* f) {
  No* no_removido = f->ini;
  int valor_removido = no_removido->info;

  f->ini = no_removido->prox;
  if (f->ini == NULL) f->fim == NULL;
  free(no_removido);

  return valor_removido;
}

int fila_vazia (Fila *f) {
  return (f->ini == NULL);
}

void fila_libera (Fila* f) {
  No* n = f->ini;
  while (n != NULL) {
    No* t = n->prox;
    free(n);
    n = t;
  }
  free(f);
}


