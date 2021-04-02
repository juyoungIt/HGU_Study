/*
 * hw1_2.c
 * writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// global variables
char buffer[BUFFER_SIZE];
int buffer_size = 0;
int buffer_pos = 0;

// function declaration
int ReadTextLine(int fd, char str[], int max_len); 

// main function
int main()
{
	int sState; // save search state
	double avg1, avg5, avg15;

	// result save
	int coreCount;
	char cpuName[50];
	int memTotal;

	// temporary saving
	char word1[20]; // save keyword part1
	char word2[20]; // save keyword part2

	// declaration of buffer
	char buffer1[BUFFER_SIZE];
	char buffer2[BUFFER_SIZE];
	char buffer3[BUFFER_SIZE];
	char buffer4[BUFFER_SIZE];

	// open file
	int cpuInfo = open("/proc/cpuinfo", O_RDONLY);
	int memInfo = open("/proc/meminfo", O_RDONLY);
	int loadAvg = open("/proc/loadavg", O_RDONLY);
	// Exception Handling
	if(cpuInfo < 0 || memInfo < 0 || loadAvg < 0) {
		printf("Error! - File open error.\n");
		return -1;
	}

	// read the text line from file and search the information
	
	// search cpu core count information
	while(1) {
		sState = ReadTextLine(cpuInfo, buffer1, BUFFER_SIZE);
		if(sState == EOF)
			break;
		sscanf(buffer1, "%s %s", word1, word2); // load keyword
		if(strcmp(word1, "cpu") == 0 && strcmp(word2, "cores") == 0)
			break;
	}

	// search cpu model name information
	lseek(cpuInfo, 0, SEEK_SET); // reset file point location
	while(1) {
		sState = ReadTextLine(cpuInfo, buffer2, BUFFER_SIZE);
		if(sState == EOF)
			break;
		sscanf(buffer2, "%s %s", word1, word2); // load keyword
		if(strcmp(word1, "model") == 0 && strcmp(word2, "name") == 0)
			break;
	}

	// search total memory information
	while(1) {
		sState = ReadTextLine(memInfo, buffer3, BUFFER_SIZE);
		if(sState == EOF)
			break;
		sscanf(buffer3, "%s", word1); // load keyword
		if(strcmp(word1, "MemTotal:") == 0)
			break;
	}

	// read load average information
	ReadTextLine(loadAvg, buffer4, BUFFER_SIZE);

	// extract each value
	sscanf(buffer1, "%s %s %s %d", word1, word1, word1, &coreCount);
	sscanf(buffer3, "%s %d", word1, &memTotal);
	sscanf(buffer4, "%lf %lf %lf", &avg1, &avg5, &avg15);

	// print the result
	printf("# of processor cores = %d\n", coreCount);
	printf("CPU Model = %s\n", buffer2+13);
	printf("MemTotal = %d\n", memTotal);
	printf("loadavg1 = %.6lf, loadavg5 = %.6lf, loadavg15 = %.6lf\n", avg1, avg5, avg15);

	// close the file
	close(cpuInfo);
	close(memInfo);
	close(loadAvg);
	return 0;
}

// function definition
int ReadTextLine(int fd, char str[], int max_len)
{
	int i = 0;
	int j = 0;
	int ret = 0;

	// if current position is 0, reset buffer size and pos
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
