#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *calculate_first_part(void *arg);
void *calculate_second_part(void *arg);
int a=3, b=2, return1=0, return2=0, result;
// Espaço para declaração de varivéis globais (vista por todas as threads).

int main()
{
     pthread_t thread1, thread2, thread3;
     int  ret1, ret2, ret3;

    /* Cria threads independentes, que irão executar funções */

     ret1 = pthread_create( &thread1, NULL, calculate_first_part, NULL);
     ret2 = pthread_create( &thread2, NULL, calculate_second_part, NULL);


     /* Espera que as threads completem suas ações antes de continuar o main */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL);

     result = return1 + return2;
     printf("Thread 1 returns: %d\n", result);
     printf("Thread 2 returns: %d\n", result);

     exit(0);
}

void *calculate_first_part(void *arg)
{
    return1 += a;
}

void *calculate_second_part(void *arg)
{
        return2 += b;
}
