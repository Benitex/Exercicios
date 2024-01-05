//Listas simplesmente encadeadas

#include<stdio.h>
#include<stdlib.h>
struct list{
    int value;
    struct list *next;
};
struct list *inicio;

void ldelete(struct list *aux);
void lnew(int tempo);
void lshow(int tempo,struct list *aux);
int lnumber_elements(int tempo,struct list *aux);
void lbiggest_smallest(int tempo,struct list *aux,int biggest,int smallest);
float lmedia(int tempo,struct list *aux, float media);
void leinsert(int tempo,struct list *aux,int nvalue);
void lsinsert(int tempo,struct list *aux,struct list *smallest,struct list *biggest,int nvalue);

main(){
    lnew(0);
    lshow(0,inicio);
    printf("\nA lista possui %d elementos.",lnumber_elements(0,inicio));
    lbiggest_smallest(0,inicio,0,0);
    lmedia(0,inicio,0);
    printf("\nA media dos elementos da lista e %.2f.", lmedia(0,inicio,0));
    leinsert(0,inicio,0);
    lshow(0,inicio);
    lsinsert(0,inicio,0,inicio,0);
    lshow(0,inicio);
    ldelete(inicio);
}

void ldelete(struct list *aux){
    if(inicio!=(struct list *)NULL){
        inicio=inicio->next;
        aux->next=(struct list *)NULL;
        free(aux);
        ldelete(inicio);
    }
}

//1. Geração de uma LSE onde os elementos são inseridos na ordem inversa em que são obtidos. Condição de parada é um valor negativo.
void lnew(int tempo){
    struct list *aux;
    int nvalue;
    if(tempo=0){
        inicio=(struct list *)NULL;
    }
    printf("Qual e o valor do proximo elemento da lista?\n");
    scanf("%d",&nvalue);
    if(nvalue>=0){
        aux=(struct list *)malloc(sizeof(struct list));
        aux->value=nvalue;
        aux->next=inicio;
        inicio=aux;
        aux=(struct list *)NULL;
        lnew(tempo+1);
    }
}

//2. Mostrar o conteúdo de uma LSE na tela.
void lshow(int tempo,struct list *aux){
    if((tempo==0)&&(aux==(struct list *)NULL))
        printf("\nLista vazia.");
    if(aux!=(struct list *)NULL){
        printf("%d\t",aux->value);
        lshow(tempo+1,aux->next);
    }
}

//3. Conta o número de elementos da LSE.
int lnumber_elements(int tempo,struct list *aux){
    if(aux!=(struct list *)NULL)
        lnumber_elements(tempo+1,aux->next);
    else
        return tempo;
}

//4. Maior e Menor Elemento de uma LSE.
void lbiggest_smallest(int tempo,struct list *aux,int biggest,int smallest){
    if(tempo==0)
        if(aux==(struct list *)NULL){
            tempo=-1;
            printf("\nLista vazia, nao ha maior ou menor elemento.");
        }
        else{
            biggest=aux->value;
            smallest=aux->value;
        }
    if(tempo!=-1)
        if(aux!=(struct list *)NULL){
            if(biggest<aux->value)
                biggest=aux->value;
            if(smallest>aux->value)
                smallest=aux->value;
            lbiggest_smallest(tempo+1,aux->next,biggest,smallest);
        }
        else
            printf("\n%d e o maior numero da lista e %d e o menor.",biggest,smallest);
}

//5. Média dos Elementos de uma LSE.
float lmedia(int tempo,struct list *aux, float media){
    if((tempo==0)&&(aux==(struct list *)NULL))
        return media;
    else
        if(aux!=(struct list *)NULL)
            lmedia(tempo+1,aux->next,media+aux->value);
        else
            return media/tempo;
}

//6. Inserção de um elemento no fim de uma LSE
void leinsert(int tempo,struct list *aux,int nvalue){
    if(tempo==0){
        printf("\nQual e o valor que sera inserido no final da lista?\n");
        scanf("%d",&nvalue);
    }
    if(inicio==(struct list *)NULL){
        inicio=(struct list *)malloc(sizeof(struct list));
        inicio->value=nvalue;
        inicio->next=(struct list *)NULL;
    }
    else
        if(aux->next!=(struct list *)NULL)
            leinsert(tempo+1,aux->next,nvalue);
        else{
            aux->next=(struct list *)malloc(sizeof(struct list));
            aux=aux->next;
            aux->value=nvalue;
            aux->next=(struct list *)NULL;
            aux=(struct list *)NULL;
        }
}

//7. Inserção de um elemento na LSE mantendo a LSE ordenada. Supor que se a LSE existir, ela está ordenada.
void lsinsert(int tempo,struct list *aux,struct list *smallest,struct list *biggest,int nvalue){
    if(tempo==0){
        printf("\nQual e o valor do elemento a ser inserido na lista?\n");
        scanf("%d",&nvalue);
        aux=(struct list *)malloc(sizeof(struct list));
        aux->value=nvalue;
        aux->next=(struct list *)NULL;
    }
    if(inicio==(struct list *)NULL){
        inicio=aux;
        smallest=(struct list *)NULL;
        biggest=(struct list *)NULL;
        aux=(struct list *)NULL;
    }
    else
        if(inicio->value>nvalue){
            aux->next=inicio;
            inicio=aux;
            aux=(struct list *)NULL;
        }
        else
            if((biggest->value<nvalue)&&(biggest->next!=(struct list *)NULL))
                lsinsert(tempo+1,aux,biggest,biggest->next,nvalue);
            else
                if(nvalue>biggest->value){
                    biggest->next=aux;
                    smallest=(struct list *)NULL;
                    biggest=(struct list *)NULL;
                    aux=(struct list *)NULL;
                }
                else{
                    smallest->next=aux;
                    aux->next=biggest;
                    smallest=(struct list *)NULL;
                    biggest=(struct list *)NULL;
                    aux=(struct list *)NULL;
                }
}
 
#include<stdio.h>
#include<stdlib.h>
struct list{
    int value;
    struct list *next;
};
struct list *inicio;

void lshow(int tempo,struct list *aux);
void lnewo(int tempo);
void leledelete(int tempo,struct list *smallest,struct list *biggest,int nvalue);
void ldelete(struct list *aux);
void lnews(int tempo,struct list *aux);

main(){
    lnewo(0);
    lshow(0,inicio);
    leledelete(0,inicio,inicio,0);
    lshow(0,inicio);
    ldelete(inicio);
    lnews(0,0);
    lshow(0,inicio);
    ldelete(inicio);
}

void lshow(int tempo,struct list *aux){
    if((tempo==0)&&(aux==(struct list *)NULL))
        printf("Lista vazia.");
    if(aux!=(struct list *)NULL){
        printf("%d\t",aux->value);
        lshow(tempo+1,aux->next);
    }
}

//8. Criação de uma LSE em ordem crescente de valor.
void lnewo(int tempo){
    void lsinsert(int tempo,struct list *aux,struct list *smallest,struct list *biggest,int nvalue){
        if(tempo==0){
            aux=(struct list *)malloc(sizeof(struct list));
            aux->value=nvalue;
            aux->next=(struct list *)NULL;
        }
        if(inicio==(struct list *)NULL){
            inicio=aux;
            smallest=(struct list *)NULL;
            biggest=(struct list *)NULL;
            aux=(struct list *)NULL;
        }
        else
            if(inicio->value>nvalue){
                aux->next=inicio;
                inicio=aux;
                aux=(struct list *)NULL;
            }
            else
                if((biggest->value<nvalue)&&(biggest->next!=(struct list *)NULL))
                    lsinsert(tempo+1,aux,biggest,biggest->next,nvalue);
                else
                    if(nvalue>biggest->value){
                        biggest->next=aux;
                        smallest=(struct list *)NULL;
                        biggest=(struct list *)NULL;
                        aux=(struct list *)NULL;
                    }
                    else{
                        smallest->next=aux;
                        aux->next=biggest;
                        smallest=(struct list *)NULL;
                        biggest=(struct list *)NULL;
                        aux=(struct list *)NULL;
                    }
    }
    int nvalue;
    if(tempo=0)
        inicio=(struct list *)NULL;
    printf("\nInsira o valor de um elemento da lista. Insira um negativo para parar.\n");
    scanf("%d",&nvalue);
    if(nvalue>=0){
        lsinsert(0,inicio,0,inicio,nvalue);
        lnewo(tempo++);
    }
}

//9. Remoção de um elemento de uma LSE.
void leledelete(int tempo,struct list *smallest,struct list *biggest,int nvalue){
    if(inicio==(struct list *)NULL)
        printf("\nLista vazia, nao ha elemento para ser removido.");
    else
        if(tempo==0){
            printf("\nQual e o valor do elemento a ser retirado da lista?\n");
            scanf("%d",&nvalue);
        }
        if(inicio->next==(struct list *)NULL){
            if(nvalue==inicio->value){
                free(inicio);
                inicio=(struct list *)NULL;
            }
            else
                printf("Nao ha um elemento com esse valor na lista.");
        }
        else{
            if(nvalue==inicio->value){
                inicio=inicio->next;
                smallest->next=(struct list *)NULL;
                free(smallest);
            }
            else{
                if((nvalue!=biggest->value)&&(biggest->next!=(struct list *)NULL))
                    leledelete(tempo+1,biggest,biggest->next,nvalue);
                else
                    if(nvalue==biggest->value){
                        smallest->next=biggest->next;
                        biggest->next=(struct list *)NULL;
                        free(biggest);
                    }
                    else
                        printf("Nao ha um elemento com esse valor na lista.");
            }
            
        }
    biggest=(struct list *)NULL;
    smallest=(struct list *)NULL;
}

//10. Remoção de toda LSE da memória.
void ldelete(struct list *aux){
    if(inicio!=(struct list *)NULL){
        inicio=inicio->next;
        aux->next=(struct list *)NULL;
        free(aux);
        ldelete(inicio);
    }
}

//11. Criação de uma LSE na ordem em que os elementos foram inseridos pelo usuário.
void lnews(int tempo,struct list *aux){
    int nvalue;
    printf("\nInsira o proximo valor da lista. Insira um numero negativo para parar.\n");
    scanf("%d",&nvalue);
    if(tempo==0){
        inicio=(struct list *)NULL;
        if(nvalue>=0){
            inicio=(struct list *)malloc(sizeof(struct list));
            inicio->value=nvalue;
            inicio->next=(struct list *)NULL;
            lnews(tempo+1,inicio);
        }
    }
    else
        if(nvalue>=0){
            aux->next=(struct list *)malloc(sizeof(struct list));
            aux=aux->next;
            aux->value=nvalue;
            aux->next=(struct list *)NULL;
            lnews(tempo+1,aux);
        }
        else
            aux=(struct list *)NULL;
}