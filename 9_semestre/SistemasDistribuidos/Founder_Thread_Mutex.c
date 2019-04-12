#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void count_function1(void *arg);
void count_function2(void *arg);
void fullVector();

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_t thread1, thread2;
int  ret1, ret2;
int vector[];

int randomNumber;

int flagFound = 0;

int main()
{

    // SORT RANDOM NUMBER
    srand(time(NULL));   // Initialization, should only be called once.
    randomNumber = rand() % 100;
    fullVector();

    printf("Random number equals %d\n", randomNumber);


    /* Cria threads independentes, que irão executar funções */

     ret1 = pthread_create( &thread1, NULL, &count_function1, NULL);
     ret2 = pthread_create( &thread2, NULL, &count_function2, NULL);

     /* Espera que as threads completem suas ações antes de continuar o main */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

     exit(0);
}

void count_function1(void *arg)
{
    int count = 50;
        while (1) {
                if(count < 100) {
                    if(count == randomNumber){
                pthread_mutex_lock(&mutex1);
                flagFound=1;
                        pthread_mutex_unlock(&mutex1);
                        printf("Thread 1 achou o valor %d\n", count);
                    }
                }
                count++;
        }
}

void count_function2(void *arg)
{
    int count = 0;
        while (1) {
                if(count < 100) {
                    if(count == randomNumber){
                pthread_mutex_lock(&mutex1);
                flagFound=1;
                        pthread_mutex_unlock(&mutex1);
                        printf("Thread 2 achou o valor %d\n", count);
                    }
                }
                count++;
        }
}

void fullVector(){
    for(int i=0;i<100;i++){
        vector[i]=i;
        printf("%d\n", vector[i]);
    }

}

