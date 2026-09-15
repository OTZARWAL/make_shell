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
	char buff[BUFF_SIZE + 1];
	signal(SIGQUIT, SIG_IGN);
	int interactive_mode = 0;

	if(argc != 2){
		fprintf(stderr,RED "Usage: %s [input_file]\n" WHITE, argv[0]);
		exit(1);
		
	}

	FILE *input = fopen(argv[1], "r");
	if(input == NULL){
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(1);
	}
	

	while(1){

		if(interactive_mode){
			printf(GREEN "shell> " WHITE);
		}
		char *pt = fgets(buff, BUFF_SIZE, input);

		if(pt == NULL){
			if(input != stdin){
				fclose(input);
				input = stdin;
				interactive_mode = 1;
				continue;
			}else{
				printf(RED "EOF\n" WHITE);
				break;
			}
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
			wait(NULL);
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
