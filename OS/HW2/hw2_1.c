/*
 * hw2_1.c
 * writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_CMD 2048
#define MAX_ARG 256

// function declaration
void ParseCommand(char *command, int *argc, char *argv[]);
void ExecuteCommand(char *type, char *path);

// main function
int main()
{
	char command[MAX_CMD];
	command[0] = command[MAX_CMD-1] = 0;

	int argc = 0;
	char *argv[MAX_ARG] = { NULL };

	while(1) {
		printf("$ ");
		fgets(command, MAX_CMD-1, stdin);
		command[strlen(command)-1] = 0;

		if(strcmp(command, "quit") == 0)
			break;

		ParseCommand(command, &argc, argv);
		ExecuteCommand(argv[0], argv[1]); // analyze and launch the command	

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

	strcpy(str, command);
	char *ptr = strtok(str, " ");

	while(ptr != NULL)
	{
		argv[*argc] = (char*)malloc(sizeof(char) * (strlen(str)+1));
		strcpy(argv[*argc], ptr);
		*argc += 1;
		ptr = strtok(NULL, " ");
	}
	argv[*argc] = 0;

	return;
}

void ExecuteCommand(char *type, char *path)
{
	int result; // store execute result
	char curPath[1024];

	// mkdir
	if(strcmp(type, "mkdir") == 0) {
		result = mkdir(path, 0777);
		if(result == -1)
			printf("Failed.\n");
	}
	// rmdir
	else if(strcmp(type, "rmdir") == 0) {
		result = rmdir(path);
		if(result == -1)
			printf("Failed\n");
	}
	// cd
	else if(strcmp(type, "cd") == 0) {
		result = chdir(path);
		if(result == -1)
			printf("Failed.\n");
	}
	// curdir
	else if(strcmp(type, "curdir") == 0) {
		getcwd(curPath, 1024);
		printf("current directory = %s\n", curPath);
	}
	// ls
	else if(strcmp(type, "ls") == 0) {
		system("ls");
	}
	// undefined command
	else {
		printf("Error! - Undefined Command.\n");
		return;
	}
	return;
}
