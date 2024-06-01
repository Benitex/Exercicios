#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "grafo.h"

static void percorrerRecursivamente(Grafo *grafo, int no_inicial, int *nos_visitados);

/* estrutura auxiliar para fila pilha(stack) / fila(queue) */
typedef struct _lista Lista;
struct _lista {
  int info;
  Lista* prox;
};

static Lista* criaLista () {
  return NULL;
}

static Lista* enfileira (Lista* fila, int info) {
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  Lista* aux = fila;
  assert(novo);
  novo->info = info;
  novo->prox = NULL;
  if (!fila) {
    return novo;
  }
  while (aux->prox) {
    aux = aux->prox;
  }
  aux->prox = novo;
  return fila;
}

static Lista* desenfileira (Lista* fila, int* info) {
  Lista* removido;
  if (!fila) {
    *info = -1;
    return NULL;
  }
  *info = fila->info;
  removido = fila;
  fila = fila->prox;
  free(removido);
  return fila;
}

static Lista* empilha (Lista* pilha, int info) {
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  assert(novo);
  novo->info = info;
  novo->prox = pilha;
  return novo;
}

static Lista* desempilha (Lista* pilha, int* info) {
  Lista* removido;
  if (!pilha){
    *info = -1;
    return NULL;
  }
  *info = pilha->info;
  removido = pilha;
  pilha = pilha->prox;
  free(removido);
  return pilha;
}

typedef struct _viz Viz;
struct _viz {
  int   noj;
  float peso;
  Viz*  prox;
};

struct _grafo {
  int   nv;  /* numero de nos ou vertices */
  int   na;  /* numero de arestas */
  Viz** viz; /* viz[i] aponta para a lista de arestas vizinhas do no i */
};

static Viz* criaViz (Viz* head, int noj, float peso) {
/* insere vizinho no inicio da lista */
  Viz* no = (Viz*) malloc(sizeof(Viz));
  assert(no);
  no->noj = noj;
  no->peso = peso;
  no->prox = head;
  return no;
}

static Grafo* grafoCria (int nv, int na) {
  int i;
  Grafo* g = (Grafo *) malloc(sizeof(Grafo));
  g->nv = nv;
  g->na = na;
  g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
  for (i = 0; i < nv; i++)
    g->viz[i] = NULL;
  return g;
}

Grafo* grafoLe (char* filename) {
  /* cria grafo nao orientado - supoe que arquivo esta correto! */
  FILE* arquivo = fopen(filename, "r");
  if (!arquivo) exit(1);

  int numero_de_nos, numero_de_arestas;
  fscanf(arquivo, "%d\n", &numero_de_nos);
  fscanf(arquivo, "%d\n", &numero_de_arestas);

  Grafo* grafo = grafoCria(numero_de_nos, numero_de_arestas);

  while (!feof(arquivo)) {
    int i, j, peso;
    fscanf(arquivo, "%d %d %d\n", &i, &j, &peso);
    grafo->viz[i] = criaViz(grafo->viz[i], j, peso);
    grafo->viz[j] = criaViz(grafo->viz[j], i, peso);
  }

  return grafo;
}

Grafo*  grafoLibera (Grafo* grafo) {
  if (grafo) {
    int i = 0;
    Viz*no,*aux;
    for (i = 0; i < grafo->nv; i++){
      no = grafo->viz[i];
      while (no){
        aux = no->prox;
        free(no);
        no = aux;
      }
    }
    free(grafo->viz);
    free(grafo);
  }
  return NULL;
}

void grafoMostra (char* title, Grafo * grafo) {
  int i;
  if (title)
    printf("%s", title);
  if (grafo) {
    printf("NV: %d, NA: %d\n", grafo->nv, grafo->na);
    for (i = 0; i < grafo->nv; i++){
    Viz* viz = grafo->viz[i];
    printf("[%d]->", i);
    while (viz) {
      printf("{%d, %g}->", viz->noj, viz->peso);
      viz = viz->prox;
    }
    printf("NULL\n");
    }
  }
}

void grafoPercorreProfundidadeRec (Grafo *grafo, int no_inicial) {
  int* nos_visitados = (int*) malloc(grafo->na * sizeof(int));
  for (int i = 0; i < grafo->na; i++) nos_visitados[i] = -1;

  percorrerRecursivamente(grafo, no_inicial, nos_visitados);
  printf("\n");
}

static void percorrerRecursivamente(Grafo *grafo, int no_inicial, int *nos_visitados) {
  int quantidade_de_nos_visitados = 0;
  for (int i = 0; i < grafo->na; i++) {
    if (nos_visitados[i] == -1) break;
    quantidade_de_nos_visitados++;
  }

  // para se o nó já foi percorrido
  for (int i = 0; i < quantidade_de_nos_visitados; i++) {
    if (nos_visitados[i] == no_inicial) return;
  }

  printf("%d ", no_inicial);
  nos_visitados[quantidade_de_nos_visitados] = no_inicial;

  Viz* viz = grafo->viz[no_inicial];
  if (viz == NULL) return;
  do {
    percorrerRecursivamente(grafo, viz->noj, nos_visitados);
    viz = viz->prox;
  } while (viz != NULL);
}

void grafoPercorreLargura (Grafo *grafo, int no_inicial) {
  Lista *fila = criaLista();

  int *nos_visitados = (int*) malloc(grafo->na * sizeof(int));
  int quantidade_de_nos_visitados = 0;
  nos_visitados[quantidade_de_nos_visitados++] = no_inicial;

  while (no_inicial != -1) {
    printf("%d ", no_inicial);

    Viz* viz = grafo->viz[no_inicial];
    while (viz != NULL) {
      int adicionado = 0;
      for (int i = 0; i < quantidade_de_nos_visitados; i++) {
        if (viz->noj == nos_visitados[i]) {
          adicionado = 1;
          break;
        }
      }

      if (!adicionado) {
        nos_visitados[quantidade_de_nos_visitados++] = viz->noj;
        fila = enfileira(fila, viz->noj);
      }

      viz = viz->prox;
    }

    fila = desenfileira(fila, &no_inicial);
  }

  printf("\n");
} 

void grafoPercorreProfundidade (Grafo *grafo, int no_inicial) {
  Lista *pilha = criaLista();

  int *nos_visitados = (int*) malloc(grafo->na * sizeof(int));
  int quantidade_de_nos_visitados = 0;
  nos_visitados[quantidade_de_nos_visitados++] = no_inicial;

  while (no_inicial != -1) {
    printf("%d ", no_inicial);

    Viz* viz = grafo->viz[no_inicial];
    while (viz != NULL) {
      int adicionado = 0;
      for (int i = 0; i < quantidade_de_nos_visitados; i++) {
        if (viz->noj == nos_visitados[i]) {
          adicionado = 1;
          break;
        }
      }

      if (!adicionado) {
        nos_visitados[quantidade_de_nos_visitados++] = viz->noj;
        pilha = empilha(pilha, viz->noj);
      }

      viz = viz->prox;
    }

    pilha = desempilha(pilha, &no_inicial);
  }

  printf("\n");
}
