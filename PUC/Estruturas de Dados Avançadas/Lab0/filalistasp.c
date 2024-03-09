#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no No;
struct no {
  int id;
  No* prox;
};

struct fila {
  No* prim;
};

Fila* fila_cria (void) {
  printf("Fila implementada com lista, com apena um ponteiro para o primeiro valor\n");
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->prim = NULL;
  return f;
}

void fila_insere (Fila* f, int i) {
  No* novo = (No*)malloc(sizeof(No));
  novo->id = i;
  novo->prox = NULL;
  
  if (f->prim == NULL) {
    f->prim = novo;
  }
  else {
    No* n = f->prim;
    while(n->prox != NULL) {
      n = n->prox;
    }
    n->prox = novo;
  }
}

int fila_retira (Fila* f) {
  No* n = f->prim;
  int v = n->id;
  f->prim = n->prox;
  free(n);
  return v; 
}

int fila_vazia (Fila *f) {
  return (f->prim == NULL);
}

void fila_libera (Fila* f) {
  No* n = f->prim;
  while (n != NULL) {
    No* t = n->prox;
    free(n);
    n = t;
  }
  free(f);
}


