#include <unistd.h>
#include <stdio.h>
#include <sdtlib.h>
#include <string.h>





#define BUFF_SIZE 1024


int main(int argc, char *argv[])
{
	char buff[BUFF_SIZE + 1];
	printf("$> ");

	fgets(buff, BUFF_SIZE, stdin);

	system(buff);
}
