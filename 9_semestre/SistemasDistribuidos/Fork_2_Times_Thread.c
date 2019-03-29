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

   printf("\tPai com PID %d criando filho\n", ppid); // getpid() retorna o pid do processo

    if ((childpid = fork()) == 0) //fork() cria um processo filho. childpid s? ? zero dentro do processo filho,
									// ent?o esse if separa os c?digos que devem ser executados pelo filho e pelo pai
									// fork() retorna um valor negativo em caso de erro.
    {
 	    printf("\tFilho executando com PID %d e criando um filho tb.\n", getpid());

        if ((childpid = fork()) == 0)
        {
            printf("\tNeto executando com PID %d.\n", getpid());

        }
        else
        {
            printf("\tFilho executando\n");
            wait(0); // Aguarda filho encerrar a execucao
        }

	}
	else
	{
 	    printf("\tPai executando\n");
		wait(0); // Aguarda filho encerrar a execucao
	}

}