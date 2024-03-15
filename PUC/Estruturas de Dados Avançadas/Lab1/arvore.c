#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "arvore.h"

struct arvno {
  int info;
  ArvNo* esq;
  ArvNo* dir;
};

ArvNo* cria_no (int v, ArvNo* esq, ArvNo* dir)
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
  return 1 + num_nos(r->esq) + num_nos(r->dir);
}

static int e_abb_preordem (ArvNo* r, int min, int max)
{
  if (r == NULL) return 1;

  if (r->info < min || r->info > max) return 0;
  if (!e_abb_preordem(r->esq, min, r->info)) return 0;
  if (!e_abb_preordem(r->dir, r->info, max)) return 0;

  return 1;
}

static int e_abb_simetrica (ArvNo *r, int *corrente)
{
  // COMPLETAR: Escolha entre completar 'e_abb_preordem' OU 'e_abb_simetrica'
  return 0;
}

int e_abb (ArvNo* r)
{
# if 0 // Troque para 0 se optar por implementar a função e_abb_preordem
  int corrente = INT_MIN;
  return e_abb_simetrica(r, &corrente);
#else
  return e_abb_preordem(r, INT_MIN, INT_MAX);
#endif
}

int arvores_iguais (ArvNo* r1, ArvNo* r2)
{
  if (r1 == NULL || r2 == NULL) {
    return r1 == r2;
  }

  if (r1->info != r2->info) return 0;
  if (!arvores_iguais(r1->esq, r2->esq)) return 0;
  if (!arvores_iguais(r1->dir, r2->dir)) return 0;

  return 1;
}

int num_maiores_que (ArvNo* r, int v)
{
  if (r == NULL) return 0;

  int nos = 0;

  if (r->info > v) {
    nos++;
    nos += num_maiores_que(r->esq, v);
  }
  nos += num_maiores_que(r->dir, v);

  return nos;
}

ArvNo* insere (ArvNo* r, int v)
{
  if (r == NULL)
    return cria_no(v, NULL, NULL);
  else if (v < r->info)
    r->esq = insere(r->esq, v);
  else // v > r->info
    r->dir = insere(r->dir, v);
  return r;  
}
