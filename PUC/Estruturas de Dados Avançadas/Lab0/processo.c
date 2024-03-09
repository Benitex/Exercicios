#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "processo.h"

#define MIN(a,b) (a < b ? a : b)

typedef struct processo Processo;
struct processo {
  double temporestante;
};

Processo* proc_cria (double tempo) {
  Processo* proc = (Processo*)malloc(sizeof(Processo));
  proc->temporestante = tempo;
  return proc;
}

int proc_terminou (Processo* p) {
  return p->temporestante < 0.0001;
}

double proc_passo (Processo* p, double max_passo) {
  double passo = MIN(max_passo, p->temporestante);
#ifdef _WIN32
  Sleep(500 * passo);
#else
  if (usleep(500000 * passo) < 0) {
    fprintf(stderr, "Error on usleep\n");
  }
#endif
  p->temporestante -= passo;
  return passo; 
}

void proc_libera (Processo* p)
{
  free(p);
}