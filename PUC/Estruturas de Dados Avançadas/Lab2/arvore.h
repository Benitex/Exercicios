
typedef struct arvno ArvNo;

int info (ArvNo* p);

ArvNo* criano (int v, ArvNo* esq, ArvNo* dir);
void imprime (ArvNo* r);
void libera (ArvNo* r);
int num_nos (ArvNo* r);

ArvNo* busca (ArvNo* r, int v);
ArvNo* insere (ArvNo* r, int v);
ArvNo* retira (ArvNo* r, int v);

ArvNo* menor_no (ArvNo* r);
ArvNo* maior_no (ArvNo* r);
ArvNo* predecessor (ArvNo* r);
ArvNo* sucessor (ArvNo* r);

int altura (ArvNo* r);
int e_balanceada (ArvNo* r);
ArvNo* balancear (ArvNo* r);