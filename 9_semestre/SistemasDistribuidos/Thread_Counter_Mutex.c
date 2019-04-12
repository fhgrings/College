#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void addValue(void *arg);
void printValue(void *arg);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_t thread1, thread2;

int number;
int main()
{

    while(1){


        /* Cria threads independentes, que irão executar funções */

        pthread_create( &thread1, NULL, &addValue, NULL);
        pthread_create( &thread2, NULL, &printValue, NULL);

        /* Espera que as threads completem suas ações antes de continuar o main */

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
    }

}

void addValue(void *arg)
{
    pthread_mutex_lock(&mutex1);
        number += 1;
    pthread_mutex_unlock(&mutex1);

    sleep(3);
}

void printValue(void *arg)
{

    pthread_mutex_lock(&mutex1);
        printf("Number Value = %d\n", number);
    pthread_mutex_unlock(&mutex1);

    sleep(3);
}

