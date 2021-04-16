// hw3_3.c
// writer : 21700760 Juyoung Ha

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define MAX_CMD 2048
#define MAX_ARG 256

char buffer[BUFFER_SIZE];
int buffer_size = 0;
int buffer_pos = 0;

// function declaration
int ReadTextLine(int fd, char str[], int max_len);
void ParseCommand(char* command, int *argc, char *argv[]);

int main(int argc, char *argv[])
{
	// 0. needed declaration
	int fd;
	char buffer1[BUFFER_SIZE];
	int state;
	int count = 0;
	char *commandArg[MAX_ARG] = { NULL };
	int pState; // the child process state
	int code; // for exit function

	// 1. read the command file name from command line argument
	// 2. open the command file
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		printf("Error! - %s file open failed.\n", argv[1]);
		exit(0);
	}
	// 3. repeat this actions
	// 3-1. Read the command line from the file (using ReadTextLine())
	while(1) {
		state = ReadTextLine(fd, buffer1, BUFFER_SIZE);
		if(state == EOF)
			break;
		// 3-2. Analyze the command (using ParseCommand())
		ParseCommand(buffer1, &count, commandArg);
		// ignore '#' started statement
		if(commandArg[0][0] == '#') {
			for(int i=0 ; i<count ; i++)
				free(commandArg[i]);
			count = 0;
			continue;
		}
		printf("command = [%s]\n", buffer1);

		if(strcmp(commandArg[0], "cd") == 0) {
			if(chdir(commandArg[1]) == -1) {
				printf("Error! - chdir failed.\n");
				exit(0);
			}
		}

		// 3-3. run the command
		pid_t pid = fork(); // make child process
		if(pid < 0) {
			printf("Error - fork() error...");
			exit(0);
		}
		// child process
		else if(pid == 0) {
			execvp(commandArg[0], commandArg);
			exit(0);
		}
		// parent process - wait child process
		else {
			wait(NULL);
		}

		// reset the tmp command space
		for(int i=0 ; i<count ; i++)
			free(commandArg[i]);
		count = 0;
	}

	// 4. close the command file
	close(fd);

	return 0;
}

// function definition
int ReadTextLine(int fd, char str[], int max_len)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	// if current position is zero, reset buffer size and pos
	if(lseek(fd, 0, SEEK_CUR) == 0)
		buffer_pos = buffer_size = 0;

	while(j < max_len-1) {
		if(buffer_pos == buffer_size) {
			buffer[0] = 0;
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
		}
		if(buffer_size == 0) {
			if(j == 0)
				ret = EOF;
			break;
		}
		while(j < max_len-2 && buffer_pos < buffer_size) {
			str[j++] = buffer[buffer_pos++];
			if(str[j-1] == '\0' || str[j-1] == 10) {
				j--;
				max_len = j;
				break;
			}
		}
	}
	str[j] = 0;

	return ret;
}

void ParseCommand(char* command, int *argc, char *argv[])
{
	char str[MAX_CMD];

	strcpy(str, command); // copy the command string
	char *ptr = strtok(str, " ");

	// seperate each part of command
	while(ptr != NULL) {
		argv[*argc] = (char*)malloc(sizeof(char) * (strlen(str)+1)); // for null char space
		strcpy(argv[*argc], ptr);
		*argc += 1;
		ptr = strtok(NULL, " ");
	}
	argv[*argc] = 0;

	return;
}
