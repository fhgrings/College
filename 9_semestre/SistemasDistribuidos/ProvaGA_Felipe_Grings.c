#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void preencherVetorAleatorio(void *arg);
void lerVetor(void *arg);
void verificarAlarme(void *arg);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t escritora, leitora, alarme;

int status[10];
int main()
{
        pthread_create( &escritora, NULL, &preencherVetorAleatorio, NULL);
        pthread_create( &leitora, NULL, &lerVetor, NULL);
        pthread_create( &alarme, NULL, &verificarAlarme, NULL);

        pthread_join( escritora, NULL);
        pthread_join( leitora, NULL);
        pthread_join( alarme, NULL);

}

void verificarAlarme(void *arg)
{
    while(1) {
        pthread_mutex_lock(&mutex);
            if(status[0] > 20)
                printf("======== Parâmetro status[0] com valor alto ===========\n");
            if(status[1] > 20)
                printf("======== Parâmetro status[1] com valor alto ===========\n");
        pthread_mutex_unlock(&mutex);
    
        sleep(10);
    }
}

void lerVetor(void *arg)
{
    while(1) {

        printf(" Vetor []");

        pthread_mutex_lock(&mutex);
        
        for(int i = 0; i < 10; i++) {
        printf(" - [ %d ]", status[i]);
        }
        pthread_mutex_unlock(&mutex);
        printf("\n\n");
    
        sleep(6);
    }
}

void preencherVetorAleatorio(void *arg) {
    while (1) {
        srand(time(NULL));
    
        pthread_mutex_lock(&mutex);
    
        for(int i = 0; i < 10; i++) {
        status[i] = 1 + rand() % 25;
        }
        pthread_mutex_unlock(&mutex);
        
        sleep(5);
    }
}

