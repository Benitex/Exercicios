#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

ArvNo* preenche (ArvNo *a, int inicio, int fim)
{
  if (inicio > fim) return a;
  int meio = (fim + inicio) / 2;
  a = insere(a, meio);
  a = preenche(a, inicio, meio - 1);
  a = preenche(a, meio + 1, fim);
  return a;
}

int main (int argc, char **argv) {
  if (argc != 2) {
    printf ("Uso do programa: %s <num_nos>\n", argv[0]);
    exit(0);
  }
  int tam_arv = atoi(argv[1]);

  clock_t tstart = clock();

  /* preenchendo sem balancear */
  ArvNo* a1 = NULL;
  for (int i = 0 ; i < tam_arv ; i++ )
    a1 = insere(a1, i);

  /* preenchendo balanceado */
  ArvNo* a2 = NULL;
  a2 = preenche(a2, 0, tam_arv-1);

  ArvNo* a3 = NULL;
  a3 = insere(a3, 3);
  a3 = insere(a3, 1);
  a3 = insere(a3, 2);
  a3 = insere(a3, 4);
  a3 = insere(a3, 5);
  a3 = insere(a3, 6);

  clock_t tend = clock();

  double total_criacao_sec_t = ((double)(tend-tstart)) / CLOCKS_PER_SEC;
  printf("Tempo em segundos para criar arvores: %lf\n", total_criacao_sec_t);
  // 100 = 0 segundos
  // 1000 = 0.003 segundos
  // 10000 = 0.325 segundos
  // 20000 = 1.336 segundos
  // 100000 = desistiu no meio kk

  printf("Altura da arvore 1: %d\n", altura(a1));
  printf("Altura da arvore 2: %d\n", altura(a2));
  printf("Altura da arvore 3: %d\n", altura(a3));
  
  printf("Arvore 1 balanceada? %s\n", e_balanceada(a1) ? "Sim" : "Nao");
  printf("Arvore 2 balanceada? %s\n", e_balanceada(a2) ? "Sim" : "Nao");
  printf("Arvore 3 balanceada? %s\n", e_balanceada(a3) ? "Sim" : "Nao");

  printf("Busca desbalanceada em arvore 1: ");
  tstart = clock();
  for (int i = 0; i < tam_arv; i++) {
    busca(a1, i);
  }
  tend = clock();
  double total_busca_a1 = ((double)(tend-tstart)) / CLOCKS_PER_SEC;
  printf("Tempo: %.10lf segundos\n", total_busca_a1);
  // 100 = 0 segundos
  // 1000 = 0.003 segundos
  // 10000 = 0.299 segundos
  // 20000 = 1.202 segundos

  printf("Busca balanceada em arvore 2: ");
  tstart = clock();
  for (int i = 0; i < tam_arv; i++) {
    busca(a2, i);
  }
  tend = clock();
  double total_busca_a2 = ((double)(tend-tstart)) / CLOCKS_PER_SEC;
  printf("Tempo: %.10lf segundos\n", total_busca_a2);
  // 100 = 0 segundos
  // 1000 = 0 segundos
  // 10000 = 0.001 segundos
  // 20000 = 0.002 segundos

  printf("Aplicando Balanceamento em arvore 1...\n");
  a1 = balancear(a1);
  
  printf("Altura da arvore 1 apos balanceamento: %d\n", altura(a1));
  printf("Arvore 1 balanceada? %s\n", e_balanceada(a1) ? "Sim" : "Nao");

  printf("Busca apos balanceamento de arvore 1: ");
  tstart = clock();
  for (int i = 0; i < tam_arv; i++) {
    busca(a1, i);
  }
  tend = clock();
  double total_busca_a1_2 = ((double)(tend-tstart)) / CLOCKS_PER_SEC;
  printf("Tempo: %.10lf segundos\n", total_busca_a1_2);
  // 100 = 0 segundos
  // 1000 = 0 segundos
  // 10000 = 0.001 segundos
  // 20000 = 0.002 segundos

  a3 = balancear(a3);
  printf("Arvore 3 balanceada? %s\n", e_balanceada(a3) ? "Sim" : "Nao");

  libera(a1);
  libera(a2);
  libera(a3);

  return 0;
}
