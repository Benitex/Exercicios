#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "set.h"

struct set {
  int n;
  unsigned int members;
};

static int set_member_valid(int i) {
  if ((i<0) || (i>=MAX_MEMBERS)) return 0;
  return 1;
}

/* cria um conjunto com n elementos */
Set *set_create(void){
  Set *set;
  set = (Set *)malloc(sizeof(Set));
  if (set != NULL) {
    set->n = MAX_MEMBERS;
    set->members = 0;
  }
  return set;
}

/* destroi (desaloca) o conjunto */
void set_destroy(Set *set) {
  if (set) free(set);
}

/* mostra os elementos do conjunto */
void set_show(char* title, Set *set){
  int i, first=1;
  printf("%s = {", title);
  for (i = 0; i < MAX_MEMBERS; i++) {
    if (set_is_member(set, i)) {
      if (first) { 
      	printf("%d", i); 
      	first = 0; 
      }
      else 
      	printf(",%d", i);
    }
  }
  printf("}\n\n");
}

/* insere o elemento i no conjunto */
void set_insert(Set *set, int i) {
  if (set == NULL || !set_member_valid(i)) return;
  set->members |= 0x1 << i;
}

/* remove o elemento i do conjunto */
void set_remove(Set *set, int i){
  if (set == NULL || !set_is_member(set, i)) return;
  set->members &= ~(0x1 << i);
}

/* cria uma copia do conjunto */
Set* set_copy(Set *set){
  if (set==NULL) return NULL;

  Set* new_set = set_create();
  new_set->members = set->members;

  return new_set;
}

/* cria conjunto com a uniao de dois conjuntos */
Set *set_union(Set *set1,  Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;

  Set* set = set_create();
  set->members = set1->members | set2->members;

  return set;
}

/* cria conjunto com a intersecao de dois conjuntos */
Set *set_intersection(Set *set1,  Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;

  Set* set = set_create();
  set->members = set1->members & set2->members;

  return set;
}

/* cria conjunto com a diferenca de set1-set2 */
Set *set_difference(Set *set1, Set *set2){
  if (set1==NULL || set2 == NULL) return NULL;

  Set* set = set_create();
  set->members = set1->members ^ set_intersection(set1, set2)->members;

  return set;
}

/* verifica se o elemento i pertence ao conjunto */
int set_is_member(Set *set, int i){
  if (set==NULL) return 0;
  if (!set_member_valid(i)) return 0;
  return ((1<<i) & (set->members));
}

/* verifica se set2 e' um subconjunto de set1 */
int set_is_subset(Set *set1,  Set *set2) {
  if (set1==NULL || set2 == NULL) return 0;
  return set_is_equal(set_intersection(set1, set2), set2);
}

/* verifica se dois conjuntos sao iguais */
int set_is_equal(Set *set1,  Set *set2) {
  if (set1==NULL || set2 == NULL) return 0;
  return set1->members == set2->members;
}

/* informa a cardinalidade do conjunto */
int set_number_of_elements(Set *set){
  if (set==NULL) return 0;

  unsigned int set_members = set->members;

  int elements_amount = 0;
  while (set_members > 0) {
    if (set_members & 0x1 > 0) elements_amount++;
    set_members >>= 1;
  }

  return elements_amount;
}

/* cria um novo conjunto que e' complementar ao primeiro */
Set *set_complement(Set *set){
  if (set == NULL) return NULL;
  
  Set* new_set = set_create();
  new_set->members = ~set->members;

  return new_set;
}
