#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int x=0, y=0;

int main()
{
   pid_t childpid;
   pid_t ppid;

   ppid =  getpid();

   printf("\tPai com PID %d criando filho\n", ppid); // getpid() retorna o pid do processo

    if ((childpid = fork()) == 0) //fork() cria um processo filho. childpid so?= o?= zero dentro do processo filho,
									// ento?=o esse if separa os co?=digos que devem ser executados pelo filho e pelo pai
									// fork() retorna um valor negativo em caso de erro.
    {
 	    printf("\tFilho executando com PID %d\n", getpid());
        x=1;
        y=2;
        printf("\tFilho: x=%d, y=%d\n", x, y);

	}
	else
	{
 	    printf("\tPai executando\n");
 	    x=3;
        y=4;
        printf("\tPai: x=%d, y=%d\n", x, y);
		wait(0); // Aguarda filho encerrar a execucao
	}

}