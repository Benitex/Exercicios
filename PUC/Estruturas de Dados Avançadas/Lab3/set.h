#define MAX_MEMBERS 32

typedef struct set Set;

/* cria um conjunto com n elementos */
Set* set_create (void);

/* destroi (desaloca) o conjunto */
void set_destroy (Set *set);

/* mostra os elementos do conjunto */
void set_show (char *title, Set *set);

/* insere o elemento i no conjunto */
void set_insert (Set *set, int i);

/* remove o elemento i do conjunto */
void set_remove (Set *set, int i);

/* cria uma copia do conjunto */
Set *set_copy (Set *set);

/* cria conjunto com a uniao de dois conjuntos  */
Set *set_union (Set *set1,  Set *set2);

/* cria conjunto com a intersecao de dois conjuntos */
Set *set_intersection (Set *set1,  Set *set2);

/* cria conjunto com a diferenca de set1-set2 */
Set *set_difference (Set *set1, Set *set2);

/* verifica se o elemento i pertence ao conjunto */
int set_is_member (Set *set, int i);

/* verifica se set2 e' um sub conjunto de set1 */
int set_is_subset (Set *set1,  Set *set2);

/* verifica se dois conjuntos sao iguais */
int set_is_equal (Set *set1,  Set *set2);

/* informa a cardinalidade do conjunto */
int set_number_of_elements (Set *set);

/* cria um novo conjunto que e' complementar ao primeiro */
Set *set_complement (Set *set);
