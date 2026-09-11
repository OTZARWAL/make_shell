#include <string.h>
#include <stdio.h>


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

void trim_quotes(char *ar[])
{
    for(int i = 0; ar[i]; i++)
    {
        char *arg = ar[i];
        size_t len = strlen(arg);
        if(len >= 2 && ((arg[0] == '"' && arg[len - 1] == '"') || (arg[0] == '\'' && arg[len - 1] == '\'')))
        {
            // Remove the quotes by shifting the string left and null-terminating it
            memmove(arg, arg + 1, len - 2);
            arg[len - 2] = '\0';
        }
    }
}


void get_in_out_file(char *ar[], char **input_file, char **output_file)
{
	printf(GREEN "get_in_out_file called\n" WHITE);
	for(int i = 0; ar[i]; i++)
		printf(RED "ar[%d]: %s\n" WHITE, i, ar[i]);
	
	for(int i = 0; ar[i] != NULL; i++)
	{
		if(ar[i] == NULL)
			break;

		if(strcmp(ar[i], "<") == 0){
			if(ar[i + 1] == NULL){
				fprintf(stderr, "Error: No input file specified\n");
			}
			*input_file = ar[i + 1];
			ar[i] = NULL;
			// ar[i + 1] = NULL;
			i++;
		}else if(strcmp(ar[i], ">") == 0){
			printf(GREEN "Output redirection found\n" WHITE);
			if(ar[i + 1] == NULL){
				fprintf(stderr, "Error: No output file specified\n");
			}
			*output_file = ar[i + 1];
			ar[i] = NULL;
			// ar[i + 1] = NULL;
			i++;
		}
	}
}


int handle_redirection(char *ar[])
{
	char *input_file = NULL;
	char *output_file = NULL;

	
	get_in_out_file(ar, &input_file, &output_file);

	printf("Input file: %s\n", input_file);
	printf("Output file: %s\n", output_file);


	if(input_file != NULL){
		if(freopen(input_file, "r", stdin) == NULL){
			perror("freopen input file");
			return(0);
		}
	}
	if(output_file != NULL){
		
		if(freopen(output_file, "w", stdout) == NULL){
			perror("freopen output file");
			return(0);
		}
	}
	return(1);
}