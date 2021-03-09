#include <stdio.h>

main()
{
	int first_day; // 1일의 요일에 대한 값을 저장할 변수선언
	int total_day; // 그 달의 날짜수 값을 저장할 변수선언
	int i, j; // 반복문을 사용하기 위한 변수 선언

	printf("1일의 요일을 입력해 주세요. (예: 일-1, 월-2, 화-3, 수-4, 목-5, 금-6, 토-7) : ");
	scanf("%d", &first_day);
	printf("해당하는 달의 날짜 수를 입력해 주세요. : ");
	scanf("%d", &total_day);

	printf("일\t월\t화\t수\t목\t금\t토\t \n");
	printf("\n");

	if (first_day == 1) {
		for (i = 1; i <= total_day; i++) {
			if (i % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 2) {
		printf("\t");
		for (j = 1; j <= 6; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 7; i <= total_day; i++) {
			if ((i-6) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 3) {
		printf("\t");
		printf("\t");
		for (j = 1; j <= 5; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 6; i <= total_day; i++) {
			if ((i-5) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 4) {
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j <= 4; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 5; i <= total_day; i++) {
			if ((i-4) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 5) {
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j<= 3; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 4; i <= total_day; i++) {
			if ((i-3) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 6) {
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j <= 2; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 3; i <= total_day; i++) {
			if ((i-2) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (first_day == 7) {
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j <= 1; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 2; i <= total_day; i++) {
			if ((i-1) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	printf("\n");
	return 0;
}