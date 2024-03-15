
typedef struct arvno ArvNo;

ArvNo* cria_no (int v, ArvNo* esq, ArvNo* dir);
void imprime (ArvNo* r);
void libera (ArvNo* r);

int num_nos (ArvNo* r);

int e_abb (ArvNo* r);
int arvores_iguais (ArvNo* r1, ArvNo* r2);

int num_maiores_que (ArvNo* r, int v);

ArvNo* insere (ArvNo* r, int v);
