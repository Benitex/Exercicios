#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mapa.h"

#define TAMINICIAL 11

typedef struct {
  int chave;
  int dados;
  int prox;
} ttabpos;

struct smapa {
  int tam;
  int ocupadas;
  ttabpos *tabpos;
};

static unsigned int hash (Mapa* m, int a) {
  return a % (m->tam);
}
  
Mapa* cria () {
  int i;
  Mapa* m = (Mapa*)malloc(sizeof(Mapa));
  if (m==NULL) {
    printf("erro na alocacao!\n");
    exit(1);
  }
  m->tabpos = (ttabpos*)malloc(TAMINICIAL*sizeof(ttabpos)); 
  if (m->tabpos==NULL) {
    printf("erro na alocacao!\n");
    exit(1);
  }
  m->tam = TAMINICIAL;
  m->ocupadas = 0;
  for (i=0;i<TAMINICIAL;i++) {
    m->tabpos[i].chave = -1;
    m->tabpos[i].prox = -1;
  }
  return m;
}

static void redimensiona (Mapa* m) {
#if 1
  int i;
  int tamanterior = m->tam;
  ttabpos* anterior = m->tabpos;

  /* aumenta o tamanho */
  printf ("Mapa: Inicia redimensiona... tamanho: %d-------\n", m->tam);
  m->tam = 1.947*m->tam;

  m->tabpos = (ttabpos*)malloc(m->tam*sizeof(ttabpos));

  /* 1. Inicializar nova tabela */
  m->ocupadas = 0;
  for (i=0;i<m->tam;i++) {
    m->tabpos[i].chave = -1;
    m->tabpos[i].prox = -1;
  }

  /* 2. reinserir os elementos da tabela anterior para a nova tabela porque o tamanho mudou! */
  for (int i = 0; i < tamanterior; i++) {
    if (anterior[i].chave == -1) continue;
    insere(m, anterior[i].chave, anterior[i].dados);
  }

  /* libera a tabela anterior */
  free (anterior);

  printf("Mapa: Fim de Redimensiona... novo tamanho: %d-------\n", m->tam);
#endif
}

Mapa* insere (Mapa* m, int chave, int dados) {
  /* verificar se a chave ja esta inserida, utilizando a funcao busca */
  int _;
  if (busca(m, chave, &_) != -1) {
    printf("Mapa: chave %d ja inserida na tabela.\n", chave);
    return m;
  }

  printf("Mapa: Inserir chave %d\n", chave);

  printf("Mapa: tam %d | ocupadas %d\n",m->tam, m->ocupadas);
  if (m->ocupadas > 0.75*m->tam) redimensiona(m);

  if (m->ocupadas == m->tam) {
    printf ("Mapa: tabela cheia! Algo de errado nao esta certo!\n");
    exit(1);
  }

  int pos = hash(m, chave);
  /* esta vazia, apenas adiciona o valor, caso simples */
  if (m->tabpos[pos].chave == -1) {
    m->tabpos[pos].chave = chave;
    m->tabpos[pos].dados = dados;
    m->tabpos[pos].prox = -1;
  }
  /* conflito */
  else {
    /* primeiro, procuramos a proxima posicao livre */
    int poslivre = pos;
    do 
      poslivre = (poslivre+1) % (m->tam);
    while ((poslivre!=pos) && (m->tabpos[poslivre].chave!=-1));

    /* tabela cheia -- não deveria acontecer */
    if (poslivre==pos) {
      printf ("Mapa: tabela cheia! Algo de errado nao esta certo!\n");
      exit(1);
    }

    /* achou posicao livre  - verificar quem vai para ela */
    int hashocupadora = hash(m, m->tabpos[pos].chave);
    /* conflito primario: encadeia */
    if (hashocupadora == pos) {
      printf ("Mapa: Conflito primario %d %d...\n", hashocupadora, pos);

      m->tabpos[poslivre].chave = chave;
      m->tabpos[poslivre].dados = dados;
      m->tabpos[poslivre].prox = m->tabpos[pos].prox;

      m->tabpos[pos].prox = poslivre;
    }
    /* conflito secundario: expulsa o item atual de pos */
    else {
      printf ("Mapa: Conflito secundario %d %d...\n", hashocupadora, pos);

      int posicaoDoAnterior = hashocupadora;
      while (m->tabpos[posicaoDoAnterior].prox != pos) {
        posicaoDoAnterior = m->tabpos[posicaoDoAnterior].prox;
      }
      m->tabpos[posicaoDoAnterior].prox = poslivre;

      m->tabpos[poslivre].chave = m->tabpos[pos].chave;
      m->tabpos[poslivre].dados = m->tabpos[pos].dados;
      m->tabpos[poslivre].prox = m->tabpos[pos].prox;

      m->tabpos[pos].chave = chave;
      m->tabpos[pos].dados = dados;
      m->tabpos[pos].prox = -1;
    }
  }

  /* aumentou o numero de itens na tabela */
  (m->ocupadas)++; 
  return m;
}

int busca (Mapa *m, int chave, int* posencontrada) {
  if (m==NULL) return -1;
  int posicao = hash(m, chave);

  while (m->tabpos[posicao].prox != -1) {
    if (m->tabpos[posicao].chave == chave) break;
    posicao = m->tabpos[posicao].prox;
  }

  if (m->tabpos[posicao].chave == chave) {
    *posencontrada = posicao;
    return m->tabpos[posicao].dados;
  }

  *posencontrada = -1;
  return -1;
}

Mapa* retira (Mapa *m, int chave, int* removeu) {
  int posicao = hash(m, chave);

  if (m->tabpos[posicao].chave == chave) {
    if (m->tabpos[posicao].prox == -1) {
      m->tabpos[posicao].chave = -1;
      m->tabpos[posicao].dados = -1;
      m->tabpos[posicao].prox = -1;
    } else {
      int proximo = m->tabpos[posicao].prox;

      m->tabpos[posicao].chave = m->tabpos[proximo].chave;
      m->tabpos[posicao].dados = m->tabpos[proximo].dados;
      m->tabpos[posicao].prox = m->tabpos[proximo].prox;

      m->tabpos[proximo].chave = -1;
      m->tabpos[proximo].dados = -1;
      m->tabpos[proximo].prox = -1;
    }
    m->ocupadas--;
    *removeu = 1;
    return m;
  }

  int anterior = posicao;
  while (m->tabpos[posicao].prox != -1) {
    if (m->tabpos[posicao].chave == chave) break;
    anterior = posicao;
    posicao = m->tabpos[posicao].prox;
  }

  if (m->tabpos[posicao].chave == chave) {
    m->tabpos[anterior].prox = m->tabpos[posicao].prox;

    m->tabpos[posicao].chave = -1;
    m->tabpos[posicao].dados = -1;
    m->tabpos[posicao].prox = -1;

    m->ocupadas--;
    *removeu = 1;
  }

  return m;
}

void destroi (Mapa *m) {
  free(m->tabpos);
  free(m);
}

int iguais (Mapa* m1, Mapa* m2) {
  int i;

  if (m1==NULL || m2==NULL) return (m1==NULL && m2==NULL);
  if (m1->tam != m2->tam) return 0;
  ttabpos* tp1 = m1->tabpos;
  ttabpos* tp2 = m2->tabpos;
  for (i = 0; i < m1->tam; i++)
    if ((tp1[i].chave != tp2[i].chave) || (tp1[i].prox != tp2[i].prox))
      return 0;
  return 1;
}

void mostra (Mapa* m) {
  int i;
  for (i=0;i<m->tam;i++) 
    if (m->tabpos[i].chave!=-1) 
      printf("posicao %d, chave %d, proximo %d (hash %d): %d\n", i, m->tabpos[i].chave, m->tabpos[i].prox, hash(m, m->tabpos[i].chave), m->tabpos[i].dados);
}