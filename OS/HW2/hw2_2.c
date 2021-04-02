/*
 * hw2_2.c
 * writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;

	dp = opendir("."); // open the current directory

	// Read the dirctory entry
	while((entry = readdir(dp)) != NULL) {
		// process dirctory
		if(entry->d_type == 4)
			printf("%s [directory]\n", entry->d_name);
		else
			printf("%s\n", entry->d_name);
	}
	closedir(dp);
	return 0;
}
