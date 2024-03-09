#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct processo Processo;

Processo* proc_cria (double tempo);
int proc_terminou (Processo* p);
double proc_passo (Processo* p, double max_passo);
void proc_libera (Processo* f);

#endif
