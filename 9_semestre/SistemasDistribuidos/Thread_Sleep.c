#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *first_thread(void *arg);
void *second_thread(void *arg);
int a=3, b=2;
// Espaço para declaração de varivéis globais (vista por todas as threads).

int main()
{
     pthread_t thread1, thread2, thread3;
     int  ret1, ret2, ret3;

    /* Cria threads independentes, que irão executar funções */

     ret1 = pthread_create( &thread1, NULL, first_thread, NULL);
     ret2 = pthread_create( &thread2, NULL, second_thread, NULL);


     /* Espera que as threads completem suas ações antes de continuar o main */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

     exit(0);
}

void *first_thread(void *arg)
{
    printf("First Value: %d\n", a);
    sleep(3);
}

void *second_thread(void *arg)
{
    printf("Second Value: %d\n", b);
    sleep(4);

}
