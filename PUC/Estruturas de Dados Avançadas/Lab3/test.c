#include "set.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
  Set *s1 = set_create();
  Set *s2 = set_create();
  Set *t1, *t2, *t3;
	
  set_insert(s1, 10); 	set_insert(s1, 13); 	set_insert(s1, 20);
  set_insert(s1, 25); 	set_insert(s1, 28); 	set_insert(s1, 30);
  set_show("s1", s1);

  set_remove(s1, 25);
  set_show("s1 com 25 removido", s1);

  set_insert(s2, 5); 	set_insert(s2, 10); 	set_insert(s2, 20);
  set_insert(s2, 21); 	set_insert(s2, 24); 	set_insert(s2, 28);
  set_show("s2", s2);
	
  printf ("1 está em s1? %s\n", set_is_member(s1, 1)?"sim":"não");
  printf ("28 está em s1? %s\n", set_is_member(s1, 28)?"sim":"não");
               
  printf ("s1 igual a s1? %s\n", set_is_equal(s1, s1)?"sim":"não");
  printf ("s1 igual a s2? %s\n", set_is_equal(s1, s2)?"sim":"não");

  t1 = set_copy (s1); 
  printf ("copia t1 igual a s1? %s\n", set_is_equal(t1, s1)?"sim":"não");
  set_destroy (t1);

  printf("\n");

  t1 = set_union(s1, s2);
  set_show("s1 U s2", t1);
  set_destroy (t1);
	
  t1 = set_intersection(s1, s2);   
  set_show("s1 I s2", t1);
  set_destroy (t1);
	
  t1 = set_difference(s1, s2); 
  set_show("s1 - s2", t1);
  t2 = set_difference(s2, s1); 
  set_show("s2 - s1", t2);
     
  t3 = set_union (t1, t2); /* (s1-s2) U (s2-s1) */
  set_destroy (t1);
  set_destroy(t2);

  t1 = set_intersection(s1,s2); /* (s1 I s2) */
  t2 = set_union (t1, t3); /* (s1-s2) U (s2-s1) U (s1 I s2) */
  set_destroy(t1);
  set_destroy(t3);

  t1 = set_union (s1, s2); /* s1 U s2 */
        
  printf ("(s1-s2) U (s2-s1) U (s1 I s2) = s1 U s2? %s\n", set_is_equal(t1, t2)?"sim":"não");
  printf("\n");

  t1 = set_intersection(s1, s2);
  printf("s1 é subconjunto de s1? %s\n", set_is_subset(s1, s1)?"sim":"nao");
  printf("s2 é subconjunto de s1? %s\n", set_is_subset(s1, s2)?"sim":"nao");
  printf("(s1 I s2) é subconjunto de s1? %s\n", set_is_subset(s1, t1)?"sim":"nao");

  set_destroy(t1);
  t1 = set_complement(s1);
  set_show("\ncomplemento de s1",t1);

  printf("cardinalidade de s1: %d\n", set_number_of_elements(s1));
  printf("cardinalidade de s2: %d\n", set_number_of_elements(s2));

  set_destroy(s1);
  set_destroy(s2);
  set_destroy (t1);
  set_destroy(t2);

  return 0;
}
