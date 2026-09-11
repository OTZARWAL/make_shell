#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "global.h"

// MACROS
#define BUFF_SIZE 1024





int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int status;
	char buff[BUFF_SIZE + 1];

	signal(SIGQUIT, SIG_IGN);


	while(1){
		printf(GREEN "shell> " WHITE);

		char *pt = fgets(buff, BUFF_SIZE, stdin);

		if(pt == NULL){
			printf("Exit with signal\n");
			exit(1);
		}
		if(buff[0] == '\n'){
			continue;
		}
		if(strncmp(buff, "exit", 4) == 0){
			printf("Exiting shell...\n");
			break;
		}
		char *newline = strchr(buff, '\n');
		if (newline != NULL)
			*newline = '\0';


		char *ar[BUFF_SIZE / 2];
		int i = 0;
		ar[i] = strtok(buff, " ");
		while(ar[i] != NULL) {
			ar[++i] = strtok(NULL, " ");
		}
		ar[i] = NULL;

		trim_quotes(ar);

		pid_t pid = fork();
		if (pid > 0){
			wait(&status);
			// printf("Child process exited with status: %d\n", WEXITSTATUS(status));
		}else
		{
			int code = handle_redirection(ar);
			if(code == 0){
				exit(1);
			}
			
			int exit_code = execvp(ar[0],ar);
			if (exit_code == -1) {
				perror("execvp");
				exit(1);
			}
		}
		memset(buff, 0, BUFF_SIZE + 1);
	}
	printf(RED "shell exited\n" WHITE);

}




