#include <stdio.h>

main()
{
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 매월 날짜수의 값을 저장한 1차원 배열 선언 및 초기화
	int month, day; // 사용자로부터 입력받은 월, 날짜에 대한 값을 저장할 변수선언
	int day_count = 0; // 날짜수 값을 저장할 변수선언 및 초기화
	int i; // 반복문 사용을 위한 변수선언

	//1. 월과 일에 대한 값을 입력받는 부분
	printf("월을 입력해 주세요. : ");
	scanf("%d", &month);
	printf("일을 입력해 주세요. : ");
	scanf("%d", &day);

	//2. 입력받은 값에 대한 유효성을 판단하는 부분
	if (month < 0 || month>12)
	{
		printf("월에 대한 값을 잘못 입력하셨습니다. \n");
		return 0;
	}
	if (day > month_days[month-1])
	{
		printf("일에 대한 값을 잘못 입력하셨습니다. \n");
		return 0;
	}
	//3. 날짜수를 구하는 부분
	for (i = 0; i < month-1; i++)
	{
		day_count += month_days[i];
	}
	day_count += day;

	//4. 결과를 출력하는 부분
	printf("입력하신 날짜 %d월 %d일은 1년 중 %d번째 날에 해당합니다. \n", month, day, day_count);
	return 0;
}