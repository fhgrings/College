// Uso de fork

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   pid_t childpid;
   pid_t ppid;

   ppid =  getpid();

   int primeiraVariavel = 1;
   int segundaVariavel = 2;
    
     printf("Pai com PID %d\n", ppid);
    printf("segundaVariavel %d\n", primeiraVariavel);
    printf("segundaVariavel %d\n\n\n", segundaVariavel);   
   childpid = fork();
   

    //fork() cria um processo filho. Retorno (childpid) s? ? zero dentro do processo filho,
	// dentro do pai o retorno ? o pid do filho
	// ent?o esse if separa os c?digos que devem ser executados pelo filho e pelo pai
	// fork() retorna um valor negativo em caso de erro.
    if (childpid == 0) {
        primeiraVariavel = 3;
        segundaVariavel = 4;
 	    printf("Filho executando com PID %d\n", getpid());
        printf("primeiraVariavel %d\n", primeiraVariavel);
        printf("segundaVariavel %d\n\n\n", segundaVariavel);
        
        childpid = fork();
        
        if (childpid == 0) {
            printf("Neto PID: %d\n", getpid());
            wait(0);
        }
        
        if (childpid > 0) {
            printf("Filho PID: %d\n", getpid());
        }
	}
	else if (childpid > 0) {

 	    printf("Pai com PID %d\n", ppid);
	    printf("segundaVariavel %d\n", primeiraVariavel);
        printf("segundaVariavel %d\n\n\n", segundaVariavel);
        primeiraVariavel = 5;
        segundaVariavel = 6;
		printf("segundaVariavel %d\n", primeiraVariavel);
        printf("segundaVariavel %d\n\n\n", segundaVariavel);
        wait(0); // Aguarda filho encerrar a execucao e n?o armazena raz?o da morte do filho
	}
}