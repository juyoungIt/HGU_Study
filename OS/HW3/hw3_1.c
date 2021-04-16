// hw3_1.c
// writer : 21700760 Juyoung Ha

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>

// the main function
int main(int argc, char *argv[])
{
	float delay; // the delay valuei
	float realDelay; // store the real delay time

	// 1. Read delay as a float number from commend line arguments
	delay = atof(argv[1]); // update delay value

	// 2. display current date and time
	struct tm *t;
	time_t current = time(NULL);
	t = localtime(&current);
	printf("current date : %d/%d/%d\n", 1900+t->tm_year, 1+t->tm_mon, t->tm_mday);
	printf("current time : %d:%d:%d\n", t->tm_hour, t->tm_min, t->tm_sec);
	
	// 3. Read current time using gettimeofday() timeval  (start_time)
	struct timeval start_time;	
	if(gettimeofday(&start_time, NULL) == -1) {
		printf("Error! - loading start_time was failed.\n");
		exit(0);
	}

	// 4. Wait for delay using usleep()
	printf("waiting for %f sec using usleep()\n", delay);
	usleep(1000 * 1000 * delay);

	// 5. Read current time using gettimeofday(), timeval (end_time)
	struct timeval end_time;
	if(gettimeofday(&end_time, NULL) == -1) {
		printf("Error! - loading end_time was failed.\n");
		exit(0);
	}

	// 6. Display start_time and end_time - warning issue!
	struct tm start, end;
	struct tm *tmp1, *tmp2;

	tmp1 = localtime(&start_time.tv_sec);
	memcpy(&start, tmp1, sizeof(struct tm));
	tmp2 = localtime(&end_time.tv_sec);
	memcpy(&end, tmp2, sizeof(struct tm));
	printf("start_time = (%ld %ld), %d:%d:%d\n", 
			start_time.tv_sec, start_time.tv_usec, start.tm_hour, start.tm_min, start.tm_sec);
	printf("end_time = (%ld %ld), %d:%d:%d\n", 
			end_time.tv_sec, end_time.tv_usec, end.tm_hour, end.tm_min, end.tm_sec);

	// 7. Display the difference between start_time and end_time
	realDelay = (end_time.tv_sec - start_time.tv_sec) + ((float)(end_time.tv_usec - start_time.tv_usec)/1000000);
	printf("elapbsed time : %f sec\n" , realDelay);

	return 0;
}
