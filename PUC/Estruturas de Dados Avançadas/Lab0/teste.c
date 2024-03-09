#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fila.h"
#include "processo.h"

#define MAX 8

int main (void) {
  srand(time(NULL));

  Fila* mf = fila_cria();
  Processo* pl[MAX];

  int i;
  for (i = 0; i < MAX; i++) {
    double d = (double)(rand() % 1000) / 100.0;
    printf("Inserindo \"processo\" %d com tempo de %.2lf segundos\n", i, d);
    pl[i] = proc_cria(d);
    fila_insere(mf, i);
  }

  while (!fila_vazia(mf)) {
    int id = fila_retira(mf);
    printf("Processo %d: removido", id);
    Processo* p = pl[id];

    double t = proc_passo(p, 2.0);
    printf(", passo %.2lf", t);

    if (proc_terminou(p)) {
      proc_libera(p);
      printf(", liberado\n");
    }
    else {
      fila_insere(mf, id);
      printf(", reinserido\n", id);
    } 
  }

  fila_libera(mf);

  return 0;
}