#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "arvrb.h"

#define RED_NODE 1
#define BLACK_NODE 0

struct arvnorb {
  int chave;
  char vermelho;
  struct arvnorb* esq;
  struct arvnorb* dir;
};

typedef enum result {OK, RED, LEFTRED, RIGHTRED} Result;
static char *strstatus[] = {"ok", "red", "leftred", "rightred"};

ArvNoRb* busca (ArvNoRb* r, int chave) {
  if (r == NULL) {
    return NULL;
  }
  else if (r->chave == chave) {
    return r;
  }
  else if (chave < r->chave) {
  return busca(r->esq, chave);
  }
  else if (chave > r->chave) {
    return busca(r->dir, chave);
  }
  else {
    return NULL;
  }
}

void libera (ArvNoRb* r) {
  if (r != NULL) {
    libera(r->esq);
    libera(r->dir);
    free(r);
  }
}

static ArvNoRb* rotaciona_dir (ArvNoRb* r) {
  ArvNoRb* esq = r->esq;
  r->esq = esq->dir;
  esq->dir = r;
  return esq;
}

static ArvNoRb* rotaciona_esq (ArvNoRb* r) {
  ArvNoRb* dir = r->dir;
  r->dir = dir->esq;
  dir->esq = r;
  return dir;
}

static void troca_cores (ArvNoRb* r) {
  char corpai = r->vermelho; 
  r->vermelho = !corpai;     /* troca a cor do pai */
  r->esq->vermelho = corpai; /* os filhos recebem a cor inversa da do pai */
  r->dir->vermelho = corpai;
}

static ArvNoRb* cria_no (int c) {
  ArvNoRb* r = (ArvNoRb*)malloc(sizeof(ArvNoRb));
  if (r != NULL) {
    r->esq = r->dir = NULL;
    r->chave = c;
    r->vermelho = RED_NODE;
  }
  return r;
}

static ArvNoRb* corrige_esq (ArvNoRb* r, Result* status) {
  switch (*status) {
    case OK:  /* nada a corrigir */
      break;
    case RED: /* filho vermelho */
      *status = LEFTRED;
      if (r->vermelho == BLACK_NODE) *status = OK;
      break;
    case LEFTRED: /* LL */
      if (!r->dir || !r->dir->vermelho) {  /* filho direito preto: LLb */
        r = rotaciona_dir(r);
        troca_cores(r);
        *status = OK;
      }
      else { /* filho direito vermelho: LLr */
        troca_cores(r);
        *status = RED;
      }
      break;
    case RIGHTRED: /* LR */
      if (!r->dir || !r->dir->vermelho) {  /* filho direito preto: LRb */
        r->esq = rotaciona_esq(r->esq);
        r = rotaciona_dir(r);
        troca_cores(r);
        *status = OK;
      }
      else { /* filho direito vermelho -> LRr */
        troca_cores(r);
        *status = RED;
      }
      break;
  }
  return r;
}

static ArvNoRb* corrige_dir (ArvNoRb* r, Result* status) {
  switch (*status) {
    case OK: /* nada a corrigir */
      break;
    case RED: /* filho vermelho */
      if (r->vermelho) *status = RIGHTRED;
      else *status = OK;
      break;
    case RIGHTRED: /* RR */
      if (!r->esq || !r->esq->vermelho) { /* filho esquerdo preto: RRb */
        r = rotaciona_esq(r);
        troca_cores(r);
        *status = OK;
      }
      else { /* filho esquerdo vermelho: RRr */
        troca_cores(r);
        *status = RED;
      }
      break;
    case LEFTRED: /* RL */
      if (!r->esq || !r->esq->vermelho) { /* filho esquerdo preto: RLb */
        r->dir = rotaciona_dir(r->dir);
        r = rotaciona_esq(r);
        troca_cores(r);
        *status = OK;
      }
      else { /* filho esquerdo vermelho: RLr */
        troca_cores(r);
        *status = RED;
      }
      break;
  }
  return r;
}

static ArvNoRb* insere_rec (ArvNoRb* r, int chave, Result* status){
  if (r == NULL) {
    r = cria_no(chave);
    *status = RED;
  }
  else if (chave < r->chave) {
    r->esq = insere_rec(r->esq, chave, status);
    r = corrige_esq(r, status);
  }
  else if (chave > r->chave) {
    r->dir = insere_rec(r->dir, chave, status);
    r = corrige_dir(r, status);
  }
  return r;
}

ArvNoRb* insere (ArvNoRb* r, int chave) {
  Result status;
  r = insere_rec(r, chave, &status);
  if (status == RED) r->vermelho = BLACK_NODE;
  else if (status != OK) {
    printf ("erro ao voltar para a raiz: status invalido %s !\n", strstatus[status]);
    imprime(r);
    exit(1);
  }
  return r;
}

void imprime (ArvNoRb* r) {
  printf("[");
  if (r != NULL) {
    printf("<%d - %c> ", r->chave,(r->vermelho) ?  'r' : 'b');
    imprime(r->esq);
    imprime(r->dir);
  }
  printf("] ");
}

int num_nos_pretos (ArvNoRb* r) {
  if (r == NULL) return 0;

  int quantidade = 0;
  if (r->vermelho == BLACK_NODE) quantidade++;
  quantidade += num_nos_pretos(r->esq) + num_nos_pretos(r->dir);

  return quantidade;
}

int num_nos_vermelhos (ArvNoRb* r) {
  if (r == NULL) return 0;

  int quantidade = 0;
  if (r->vermelho == RED_NODE) quantidade++;
  quantidade += num_nos_vermelhos(r->esq) + num_nos_vermelhos(r->dir);

  return quantidade;
}
