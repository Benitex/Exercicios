#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXFILA 8
#define NUMERO_DE_THREADS 2

void *produtor();
void *consumidor();

int buffer[MAXFILA];
int indiceDoProdutor = 0;
int indiceDoConsumidor = 0;
int quantidadeDeItens = 0;

pthread_cond_t podeProduzir = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    pthread_t produtorThread[NUMERO_DE_THREADS];
    pthread_t consumidorThread[NUMERO_DE_THREADS];

    for (int i = 0; i < NUMERO_DE_THREADS; i++) {
        pthread_create(&produtorThread[i], NULL, produtor, NULL);
        pthread_create(&consumidorThread[i], NULL, consumidor, NULL);
    }

    for (int i = 0; i < NUMERO_DE_THREADS; i++) {
        pthread_join(produtorThread[i], NULL);
        pthread_join(consumidorThread[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&podeProduzir);
    return 0;
}

void *produtor() {
    for (int i = 1; i <= 64 / NUMERO_DE_THREADS; i++) {
        sleep(1);
        pthread_mutex_lock(&mutex);

        while (quantidadeDeItens == MAXFILA) {
            pthread_cond_wait(&podeProduzir, &mutex);
        }

        buffer[indiceDoProdutor] = rand() % 64 + 1;
        printf("Produção: %d\n", buffer[indiceDoProdutor]);
        quantidadeDeItens++;

        indiceDoProdutor++;
        if (indiceDoProdutor == MAXFILA) {
            indiceDoProdutor = 0;
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* consumidor() {
    for (int i = 0; i < 64 / NUMERO_DE_THREADS; i++) {
        sleep(2);
        pthread_mutex_lock(&mutex);

        int indice = indiceDoConsumidor % MAXFILA;
        printf("Consumo %d: %d\n", indiceDoConsumidor, buffer[indice]);
        indiceDoConsumidor++;
        quantidadeDeItens--;
        if (quantidadeDeItens <= MAXFILA - 1) {
            pthread_cond_signal(&podeProduzir);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}
