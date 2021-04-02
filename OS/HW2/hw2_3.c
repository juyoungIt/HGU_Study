/*
 * hw2_3.c
 * writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 256

// function declaration
int FindFile(char *start_dir, char *target, char *path);

// main function
int main(int argc, char *argv[])
{
	if(argc < 3) {
		printf("Usage : %s <start_dir> <target_file>\n", argv[0]);
		return 0;
	}
	char *start_dir = argv[1];
	char *target = argv[2];
	char path[MAX_PATH] = "";
	int ret = FindFile(start_dir, target, path);

	if(ret)
		printf("path = %s\n", path);
	else
		printf("Cannot find %s\n", target);
	return 0;
}

// Function Definition
int FindFile(char *start_dir, char *target, char *path)
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char tmp[MAX_PATH]; // for temporary store

	dp = opendir(start_dir); // open the start dirctory
	// Exception Handling - 1
	if(dp == NULL) {
		printf("Error! - invalid path.\n");
		exit(0);
	}

	// search the valid file
	while((entry = readdir(dp)) != NULL) {
		// except '.' & '..' directory in search
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name,"..") == 0)
			continue;
		// if current file or dir is target
		if(strcmp(entry->d_name, target) == 0) {
			// write target path
			strcpy(path, start_dir);
			strcat(path, "/");
			strcat(path, entry->d_name);
			closedir(dp);
			return 1;
		}
		// if current file or dir is not target
		else {
			// if current element is directory
			if(entry->d_type == 4) {
				// write new start_dir - for recursion call
				strcpy(tmp, start_dir);
				strcat(tmp, "/");
				strcat(tmp, entry->d_name);
				// search the current directory
				if(FindFile(tmp, target, path)) {
					closedir(dp);
					return 1;
				}
			}
		}
	}
	closedir(dp); // close the dir
	return 0;
}	
