#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "arvtrie.h"

struct arvtrie {
  int n;
  ArvTrie* nos[M];
  bool palavra;
};

static int transformaparaindice (char c) {
  if (c < 'a' || c > 'z') {
    printf(">>> digito desconhecido\n");
    exit(1);
  }
  int d = c - 'a';
  return d;
}

static char transformaparadigito (int d) {
  char c = d + 'a';
  if (c < 'a' || c > 'z') {
    printf(">>> digito desconhecido\n");
    exit(1);
  }
  return c;
}

static ArvTrie* criano (void) {
  ArvTrie* t = (ArvTrie*)malloc(sizeof(ArvTrie));
  t->n = 0;
  t->palavra = false;
  for (int i = 0; i < M; i++)
    t->nos[i] = NULL;
  return t;  
}

ArvTrie* cria (void) {
  return criano();
}

void destroi (ArvTrie* t) {
  for (int i = 0; i < M; i++) {
    if (t->nos[i]) {
      destroi(t->nos[i]);
    }
  }
  free(t);
}

bool insere (ArvTrie* t, const char* chave) {
  char *caractere = chave;  

  while (*caractere != '\0') {
    int indice = transformaparaindice(*caractere);

    if (t->nos[indice] == NULL) {
      t->nos[indice] = criano();
      t->n++;
    }

    t = t->nos[indice];
    caractere++;
  }

  if (t == NULL || t->palavra) {
    printf("I: Chave \"%s\" nao inserida\n", chave);
    return false;
  }
  t->palavra = true;
  printf("I: Chave \"%s\" inserida\n", chave);
  return true;
}

bool retira (ArvTrie* t, const char* chave) {
  ArvTrie* no = t;
  ArvTrie* primeiroNoParaRemover;
  int indiceDoPrimeiroCaractereRemovido = 0;

  char *caractere = chave;
  int i = 0;
  while (*caractere != '\0') {
    char *proximoCaractere = caractere + 1;
    if (no->n > 1 || (no->palavra && *proximoCaractere != '\0')) {
      primeiroNoParaRemover = no;
      indiceDoPrimeiroCaractereRemovido = i;
    }

    no = no->nos[transformaparaindice(*caractere)];
    if (no == NULL) {
      printf("R: Chave \"%s\" nao encontrada\n", chave);
      return false;
    }
    caractere++;
    i++;
  }

  printf("R[");
  if (!no->palavra) {
    printf("]: Chave \"%s\"nao e' palavra\n", chave);
    return false;
  }

  if (no->n >= 1) {
    no->palavra = !no->palavra;
    printf("]: Chave \"%s\" removida (sem remover nos)\n", chave);
    return true;

  } else {
    if (primeiroNoParaRemover == NULL) primeiroNoParaRemover = t;
    no = primeiroNoParaRemover;
    caractere = chave + indiceDoPrimeiroCaractereRemovido;

    while (*caractere != '\0') {
      printf("%c", *caractere);
      no = no->nos[transformaparaindice(*caractere)];
      if (no == NULL) {
        printf("]: Chave \"%s\" nao encontrada depois\n", chave);
        return false;
      }
      caractere++;
    }
    printf("]: Chave \"%s\" removida\n", chave);

    destroi(primeiroNoParaRemover);
    no->n--;
    return true;
  }
}

static void imprimechaves (ArvTrie* t, char* chave) {
  if (t == NULL) return;

  // se for uma palavra, imprime o que foi acumulado
  if (t->palavra)
    printf("%s\n", chave);
  
  // se nao tiver nenhum proximo no, deve ser uma palavra, ou temos um erro 
  if (t->n == 0) {
    if (!t->palavra) {
      printf(">>> No folha e nao e' palavra, arvore contem algum erro\n");
      exit(1);
    }
  }
  else {
    // adiciona novo \0, em s+1, deixando a posicao s livre para o novo digito
    int s = strlen(chave);
    chave[s+1] = FIMDECHAVE;
    for (int d = 0; d < M; d++) {
      if (t->nos[d]) {
        // define digito na posicao s
        chave[s] = transformaparadigito(d);
        imprimechaves(t->nos[d], chave);
      }
    }
    // "reseta" o final da palavra
    chave[s] = FIMDECHAVE;
  }
}

void imprime (ArvTrie* t) {
  printf("Imprime chaves da arvore:\n");
  char chave[KMAX];
  chave[1] = FIMDECHAVE; 
  for (int d = 0; d < M; d++) {
    if (t->nos[d]) {
      chave[0] = transformaparadigito(d);
      imprimechaves(t->nos[d], chave);
    }
  }
}

static void sugerirchaves (ArvTrie* t, const char* prefixo) {
  printf("\n");

  int indice = 0;
  char chave[KMAX];

  while (prefixo[indice] != '\0') {
    if (t->nos[transformaparaindice(prefixo[indice])] != NULL) {
      t = t->nos[transformaparaindice(prefixo[indice])];
    } else {
      printf("Prefixo \"%s\" nao encontrado\n", prefixo);
      return;
    }
    indice++;
  }

  imprimechaves(t, strcpy(chave, prefixo));
}

void sugerir (ArvTrie* t, const char* prefixo) {
  printf("Sugerir completacoes para \"%s\": ", prefixo);
  sugerirchaves(t, prefixo);
  printf("\n");
}
