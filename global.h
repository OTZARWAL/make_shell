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
void trim_quotes(char *ar[]);
void get_in_out_file(char *ar[], char **input_file, char **output_file);