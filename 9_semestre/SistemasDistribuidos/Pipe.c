#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#define TAM 3

int main(void)
{
        int     envioDoFilho[2], envioDoPai[2], ret=0;
        pid_t   pidfilho = 0;
        unsigned char    string[100];
        unsigned char    readbuffer[100];
		
        pipe(envioDoFilho);
        pipe(envioDoPai);
		       
        if ((pidfilho = fork()) == 0) //fork() cria um processo filho. childpid sC3 C) zero dentro do processo filho, 
									  // entC#o esse if separa os cC3digos que devem ser executados pelo filho e pelo pai
									  // fork() retorna um valor negativo em caso de erro.
        {
            printf("\n\tFilho executando com PID %d\n", getpid());
            string[0] = 1; //valores ate 255 cabem em unsigned char
            string[1] = 2;
            string[2] = 3;
	
            // Processo filho fecha um lado do pipe (entrada)
			// do seu pipe de envio
            close(envioDoFilho[0]);

            // Processo filho fecha um lado do pipe (saida)
			// do pipe do pai (recebimento)
            close(envioDoPai[1]);

            // Envia string para o pai
            write(envioDoFilho[1], string, (strlen(string)+1)); //strlen(string)+1 para mandar o '\0' junto

           // Le string enviada pelo pai
           ret = read(envioDoPai[0], readbuffer, sizeof(readbuffer));
		   //ret contem o numero de bytes lidos
		   
		   if (ret > 0)
				printf("\n\tFilho executando. String recebida do pai: %s\n", readbuffer);
           
		   exit(0);
        }
        else
        {
           printf("\n\tPai executando com PID %d\n", getpid());
           // Processo pai fecha um lado do pipe (saida)
		   // do seu pipe de recebimento
           close(envioDoFilho[1]);

           // Processo pai fecha um lado do pipe (entrada)
		   // do seu pipe de envio
           close(envioDoPai[0]);

           // Le string do pipe
           ret = read(envioDoFilho[0], readbuffer, TAM); //Le 3 bytes para verificar se recebeu a sequencia 123
            
           if((readbuffer[0] == 1) && (readbuffer[1] == 2) && (readbuffer[2] == 3))
           {
               printf("\n\tPai executando. Filho enviou: %d %d %d\n", readbuffer[0], readbuffer[1], readbuffer[2]);
               strcpy(string, "OK\n");
			   printf("\n\tPai: OK\n");
           }
           else
           {
               printf("\n\tPai executando. Filho enviou sequencia invalida\n", readbuffer[0], readbuffer[1], readbuffer[2]);
               printf("\n\tERRO\n");
			   strcpy(string, "Pai: ERRO\n");
           }
           write(envioDoPai[1], string, (strlen(string)+1)); 
           
		   wait(0); // Aguarda filho encerrar a execucao
        }
        
}