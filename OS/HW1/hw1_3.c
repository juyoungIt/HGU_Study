/*
 * hw1_3.c
 * writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD 2048
#define MAX_ARG 256

// function declaration
void ParseCommand(char* command, int *argc, char *argv[]);

// main function
int main()
{
	char command[MAX_CMD];
	command[0] = command[MAX_CMD-1] = 0; // for safety

	int argc = 0;
	char *argv[MAX_ARG] = { NULL };

	while(1) {
		printf("$ ");
		fgets(command, MAX_CMD-1, stdin);
		command[strlen(command)-1] = 0;

		if(strcmp(command, "quit") == 0 || strcmp(command, "exit") == 0)
			break;

		ParseCommand(command, &argc, argv);

		printf("argc = %d\n", argc);
		for(int i=0 ; i<argc ; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
		printf("argv[%d] = %p\n", argc, argv[argc]);

		for(int i=0 ; i<argc ; i++)
			free(argv[i]);
		argc = 0;
	}
	printf("Bye\n");
	return 0;
}

// function definition
void ParseCommand(char *command, int *argc, char *argv[])
{
	char str[MAX_CMD];

	strcpy(str, command); // copy the command string
	char *ptr = strtok(str, " ");

	// seperate each part of command
	while(ptr != NULL)
	{
		argv[*argc] = (char*)malloc((sizeof(char)) * (strlen(str)+1)); // for null char space
		strcpy(argv[*argc], ptr);
		*argc += 1;
		ptr = strtok(NULL, " ");
	}
	argv[*argc] = 0;

	return;
}
