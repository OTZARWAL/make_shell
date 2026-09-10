#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "./libft/libft.h"


#define BUFF_SIZE 1024

// colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// prototype
int handle_redirection(char *ar[]);



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

		// char **cmds = ft_split(buff, ' ');
		// if(!cmds || !cmds[0])
		// 	break;


		char *ar[BUFF_SIZE / 2];
		int i = 0;
		ar[i] = strtok(buff, " ");
		while(ar[i] != NULL) {
			ar[++i] = strtok(NULL, " ");
		}
		ar[i] = NULL;

		
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

int handle_redirection(char *ar[])
{
	char *input_file = NULL;
	char *output_file = NULL;

	for(int i = 0; ar[i] != NULL; i++)
	{
		if(ar[i] == NULL)
			break;

		if(strcmp(ar[i], "<") == 0){
			if(ar[i + 1] == NULL){
				fprintf(stderr, "Error: No input file specified\n");
				return(0);
			}
			input_file = ar[i + 1] ;
			ar[i] = NULL;
			// ar[i + 1] = NULL;
			i++;
		}else if(strcmp(ar[i], ">") == 0){
			if(ar[i + 1] == NULL){
				fprintf(stderr, "Error: No output file specified\n");
				return(0);
			}
			output_file = ar[i + 1];
			ar[i] = NULL;
			// ar[i + 1] = NULL;
			i++;
		}
	}

	printf("Input file: %s\n", input_file);
	printf("Output file: %s\n", output_file);

	// pause();
	if(input_file != NULL){
		int fd = open(input_file, O_RDONLY);
		if(fd == -1){
			perror("open input file");
			return(0);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	if(output_file != NULL){
		int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(fd == -1){
			perror("open output file");
			return(0);
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return(1);
}