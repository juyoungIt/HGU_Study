#include <stdio.h>

main()
{
	int year; // 사용자로부터 입력받은 연도 값을 저장할 변수선언
	int month; // 사용자로부터 입력받은 달 값을 저장할 변수선언
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 일 수에 대한 값을 저장할 배열선언
	int days[7] = { 0,1,2,3,4,5,6 }; // 1일의 요일을 알아내는 과정에서 사용할 1차원 배열선언
	int total_days = 0; // 1900년 1월 1일을 기준으로 몇일에 해당하는 지의 값을 저장하는 변수선언
	int day_code; // 요일판정 값을 저장할 변수선언
	int Yoon_judge; // 윤년 판정에 대한 값을 저장할 변수선언
	int i,j; // 반복문 사용을 위한 변수선언

	//1. 사용자로부터 월과 일에 대한 정보를 입력받는 부분
	printf("해당하는 연도를 입력해 주세요. : ");
	scanf("%d", &year);
	printf("해당하는 달을 입력해 주세요. : ");
	scanf("%d", &month);

	// 윤년에 대한 값 판정
	Yoon_judge = Yoon(year);
	if (Yoon_judge == 1)
		month_days[1] = 29;

	// 1일의 요일을 알아내는 부분
	for (i = 0; i < year; i++)
	{
		if (Yoon_judge == 1) {
			total_days += 366;
		}
		else if (Yoon_judge == 0) {
			total_days += 365;
		}
	}
	for (j = 1; j < month; j++)
	{
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
			total_days += 31;
		}
		else if (j == 4 || j == 6 || j == 9 || j == 11) {
			total_days += 30;
		}
		else if (j == 2) {
			if (Yoon_judge == 1) {
				total_days = total_days + 29;
			}
			else if (Yoon_judge == 0) {
				total_days = total_days + 28;
			}
		}
	}
	day_code = (total_days-1) % 7; 

	//2. 달력을 그리는 부분
	printf("\n");
	printf("일\t월\t화\t수\t목\t금\t토\t\n"); // 달력에서 요일에 대한 부분을 그리는 부분
	printf("\n");

	if (day_code == 0) {
		for (i = 1; i <= month_days[month-1]; i++) {
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
	else if (day_code == 1) {
		printf("\t");
		for (j = 1; j <= 6; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 7; i <= month_days[month - 1]; i++) {
			if ((i - 6) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (day_code == 2) {
		printf("\t");
		printf("\t");
		for (j = 1; j <= 5; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 6; i <= month_days[month - 1]; i++) {
			if ((i - 5) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (day_code == 3) {
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j <= 4; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 5; i <= month_days[month - 1]; i++) {
			if ((i - 4) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (day_code == 4) {
		printf("\t");
		printf("\t");
		printf("\t");
		printf("\t");
		for (j = 1; j <= 3; j++) {
			printf("%02d \t", j);
		}
		printf("\n");
		printf("\n");
		for (i = 4; i <= month_days[month - 1]; i++) {
			if ((i - 3) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (day_code == 5) {
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
		for (i = 3; i <= month_days[month - 1]; i++) {
			if ((i - 2) % 7 == 0) {
				printf("%02d \n", i);
				printf("\n");
			}
			else
			{
				printf("%02d \t", i);
			}
		}
	}
	else if (day_code == 6) {
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
		for (i = 2; i <= month_days[month - 1]; i++) {
			if ((i - 1) % 7 == 0) {
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
	printf("\n");
	//3. 프로그램을 종료하는 부분
	return 0;
}

//4. 윤년을 판단하는 함수정의
int Yoon(int x)
{
	int Yoon; // 윤년 판정에 대한 값을 저장할 변수선언

	if (x % 400 == 0)
		Yoon = 1;
	else if (x % 100 == 0)
		Yoon = 0;
	else if (x % 4 == 0)
		Yoon = 1;
	else
		Yoon = 0;
	return Yoon;
}