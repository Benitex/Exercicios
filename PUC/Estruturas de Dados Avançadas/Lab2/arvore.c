#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "arvore.h"

struct arvno {
  int info;
  ArvNo* esq;
  ArvNo* dir;
};

int info (ArvNo* p)
{
  if (p == NULL) return -1;
  return p->info;
}

ArvNo* criano (int v, ArvNo* esq, ArvNo* dir)
{
  ArvNo* p = (ArvNo*)malloc(sizeof(ArvNo));
  if (p != NULL) {
    p->info = v;
    p->esq = esq;
    p->dir = dir;
  }
  return p;
}

void imprime (ArvNo* r)
{
  printf("(");
  if (r != NULL) {
    printf("%d ", r->info);
    imprime(r->esq);
    printf(", ");
    imprime(r->dir);
  }
  printf(")");
}

void libera (ArvNo* r)
{
  if (r != NULL) {
    libera(r->esq);
    libera(r->dir);
    free(r);
  }
}

int num_nos (ArvNo* r)
{
  if (r == NULL) return 0;
  return num_nos(r->esq) + num_nos(r->dir) + 1;
}

ArvNo* busca (ArvNo* r, int v)
{
#if 1 // implementacao recursiva
  if (r == NULL) return NULL;
  else if (v < r->info) return busca(r->esq, v); 
  else if (v > r->info) return busca(r->dir, v); 
  else return r;
#else // implementacao iterativa  
  while (r != NULL) {
    if (v < r->info)
      r = r->esq;
    else if (v > r->info)
      r = r->dir;
    else
      return r;
  }
  return NULL;
#endif
}

ArvNo* insere (ArvNo* r, int v)
{
  if (r == NULL)
    return criano(v, NULL, NULL);
  else if (v < r->info)
    r->esq = insere(r->esq, v);
  else if (v > r->info)
    r->dir = insere(r->dir, v);
  // se for igual, nao sera adicionado
  return r;  
}

ArvNo* retira (ArvNo* r, int v)
{
  if (r == NULL) return NULL;

  if (v < r->info) {
    r->esq = retira(r->esq, v);
  } else if (v > r->info) {
    r->dir = retira(r->dir, v);

  } else {
    if (r->esq == NULL && r->dir == NULL) {
      free(r);
      r = NULL;
    } else if (r->esq == NULL || r->dir == NULL) {
      ArvNo* no_removido = r;
      r = (r->esq == NULL ? r->dir : r->esq);
      free(no_removido);
    } else {
      ArvNo* no = sucessor(r);
      r->info = no->info;
      no->info = v;
      r->dir = retira(r->dir, v);
    }
  }

  return r;
}

ArvNo* menor_no (ArvNo* r)
{
  while (r->esq != NULL) {
    if (r->esq == NULL) return r;
    r = r->esq;
  }
  return r;
}

ArvNo* maior_no (ArvNo* r)
{
  while (r->dir != NULL) {
    if (r->dir == NULL) return r;
    r = r->dir;
  }
  return r;
}

ArvNo* predecessor (ArvNo* r)
{
  return maior_no(r->esq);
}

ArvNo* sucessor (ArvNo* r)
{
  return menor_no(r->dir);
}

int altura (ArvNo* r)
{
  if (r == NULL) return -1;

  int altura_esquerda = altura(r->esq);
  int altura_direita = altura(r->dir);
  int maior_altura = (altura_esquerda > altura_direita ? altura_esquerda : altura_direita);

  return maior_altura + 1;
}

int no_balanceado (ArvNo* r) 
{
  int diferenca = altura(r->esq) - altura(r->dir);
  diferenca = abs(diferenca);
  return diferenca <= 1;
}

int e_balanceada (ArvNo* r)
{
  if (r == NULL) return 1;

  if (!no_balanceado(r)) return 0;

  if (!e_balanceada(r->esq)) return 0;
  if (!e_balanceada(r->dir)) return 0;

  return 1;
}

ArvNo* balancear (ArvNo* r)
{
  if (e_balanceada(r)) return r;

  float valor_raiz_original = r->info;
  ArvNo* no = sucessor(r);
  r->info = no->info;
  r = retira(r, no->info);
  r = insere(r, valor_raiz_original);

  if (!no_balanceado(r)) r = balancear(r);

  if (!e_balanceada(r->esq)) r->esq = balancear(r->esq);
  if (!e_balanceada(r->dir)) r->dir = balancear(r->dir);

  return r;
}
