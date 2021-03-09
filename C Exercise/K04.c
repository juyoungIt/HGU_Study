#include <stdio.h>

int CalDate(int month, int days); // 함수 CalDate의 선언
int monthdays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 1월 ~ 12월의 일수에 대한 값을 저장하는 1차원 배열선언

main()
{
	int month1, month2; // 월에대한 값을 저장하는 변수선언
	int days1, days2; // 일에 대한 값을 저장하는 변수선언
	int result; // 두 날짜 사이의 간격을 저장하는 변수선언
	int result1; // 첫번째 날짜가 1년중 몇번째날에 해당하는 지에 대한 값을 저장하는 변수선언
	int result2; // 두번째 날짜가 1년중 몇번째날에 해당하는 지에 대한 값을 저장하는 변수선언

	printf("첫번쨰 날짜를 월, 일 순서로 입력해 주세요. : ");
	scanf("%d %d", &month1, &days1);
	printf("두번째 날짜를 월, 일 순서로 입력해 주세요. : ");
	scanf("%d %d", &month2, &days2);
	
	result1 = CalcDate(month1, days1); // 함수 CalDate 호출 - 1
	result2 = CalcDate(month2, days2); // 함수 CalDate 호출 - 2
	if (result2 > result1)
	{
		result = result2 - result1;
		printf("두 날짜의 간격은 %d일 입니다. \n", result);
	}
	else if (result2 < result1)
	{
		result = result2 - result1 + 1;
		printf("두 날짜의 간격은 %d일 입니다. \n", result);
	}
	else
		printf("두 날짜가 서로 동일 합니다. \n");

}

// 함수 CalDate에 대한 정의부
int CalcDate(int month, int days)
{
	int result = 0; // 1년 중 몇번째 날짜인지에 대한 값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	for (i = 1; i < month; i++)
	{
		if (i == 1)
			result += monthdays[0];
		else if (i == 2)
			result += monthdays[1];
		else if (i == 3)
			result += monthdays[2];
		else if (i == 4)
			result += monthdays[3];
		else if (i == 5)
			result += monthdays[4];
		else if (i == 6)
			result += monthdays[5];
		else if (i == 7)
			result += monthdays[6];
		else if (i == 8)
			result += monthdays[7];
		else if (i == 9)
			result += monthdays[8];
		else if (i == 10)
			result += monthdays[9];
		else if (i == 11)
			result += monthdays[10];
		else if (i == 12)
			result += monthdays[11];
	}
	result += days;
	return result;
}