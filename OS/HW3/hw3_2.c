#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct utsname s1;
	struct sysinfo s2;
	struct stat s3;
	struct tm *tt;

	// no argument - print the system info
	if(argc == 1) {	
		// print the user and process info
		printf("User and Process info:\n");
		printf("     getuid() = %d\n", getuid());
		printf("     getpid() = %d\n", getpid());
		printf("     getppid() = %d\n\n", getppid());

		// print the kernal info
		if(uname(&s1) == -1) {
			printf("Error! - in uname() function.\n");
			exit(0);
		}
		printf("Kernal info:\n");
		printf("     sysname = %s\n", s1.sysname);
		printf("     nodename = %s\n", s1.nodename);
		printf("     release = %s\n", s1.release);
		printf("     version = %s\n", s1.version);
		printf("     machine = %s\n\n", s1.machine);
		
		// print the system info
		if(sysinfo(&s2) == -1) {
			printf("Error! - in sysinfo() function\n");
			exit(0);
		}
		printf("System info:\n");
		printf("     uptime = %ld\n", s2.uptime);
		printf("     totalram = %ld\n", s2.totalram);
		printf("     freeram = %ld\n", s2.freeram);
		printf("     procs = %d\n", s2.procs);
	}
	// exist argument - print the file info
	else if(argc == 2) {
		// print the permission info of file
		printf("Permission of file %s\n", argv[1]);
		if(access(argv[1], F_OK)) {
			printf("Error! - file search was failed.\n");
			exit(0);
		}
		printf("    permission to read: %d\n", access(argv[1], R_OK)+1);
		printf("    permission to write: %d\n", access(argv[1], W_OK)+1);
		printf("    permission to execute: %d\n\n", access(argv[1], X_OK)+1);

		// print the stat of file
		if(stat(argv[1], &s3) == -1) {
			printf("Error! - in stat() function.\n");
			exit(0);
		}
		// ready the time value
		printf("stat of file %s\n", argv[1]);
		printf("      st_dev = %ld\n", s3.st_dev);
		printf("      st_ino = %ld\n", s3.st_ino);
		printf("      st_mode = %o (octal)\n", s3.st_mode);
		printf("      st_uid = %d\n", s3.st_uid);
		printf("      st_gid = %d\n", s3.st_gid);
		tt = localtime(&s3.st_atime);
		printf("      st_size = %ld\n", s3.st_size);
		printf("      st_atime = %d/%d/%d %d:%d:%d\n", 
				1900+tt->tm_year, 1+tt->tm_mon, tt->tm_mday, 
				tt->tm_hour, tt->tm_min, tt->tm_sec);
		tt = localtime(&s3.st_mtime);
		printf("      st_mtime = %d/%d/%d %d:%d:%d\n",
				1900+tt->tm_year, 1+tt->tm_mon, tt->tm_mday, 
				tt->tm_hour, tt->tm_min, tt->tm_sec);
		tt = localtime(&s3.st_ctime);
		printf("      st_ctime = %d/%d/%d %d:%d:%d\n",
				1900+tt->tm_year, 1+tt->tm_mon, tt->tm_mday,
				tt->tm_hour, tt->tm_min, tt->tm_sec);
	}
	// undefined condition
	else {
		printf("Error! - invalid argument.\n");
	}
	return 0;
}
