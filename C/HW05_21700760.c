// 날짜 계산기 만들기 - 입력 순서에 관계없이 두 날짜의 차를 계산하여 출력함.
// 프로그렘에서 사용자가 입력한 날짜가 유효한 값인지 판정하고 유효하지 않는 부분을 알려줌

#include <stdio.h>
int yoon; // 윤년에 대한 판정결과를 저장하는 변수선언

main() {
	int year1, year2; // 연도 값을 저장할 변수선언
	int month1, month2; // 월 값을 저장할 변수선언
	int t_month1, t_month2; // 월값의 유효성을 판단하는 데 사용하는 변수선언
	int day1, day2; // 일 값을 저장할 변수선언
	int t_day1, t_day2; // 일 수의 유효성을 판단하는 데 사용하는 변수선언
	int total_day1 = 0; // 0년 0월 0일을 기준으로 계산한 일수의 대한 값 저장 - 1
	int	total_day2 = 0; // 0년 0월 0일을 기준으로 계산한 일수의 대한 값 저장 - 2
	int total_day; // 결과값을 저장할 변수선언
	int i, j; //반복문을 사용하기 위한 변수선언

	int t_yoon(int x); // 윤년판정 함수선언
    
    // 사용자로부터 값을 입력받고 그 값을 유효함을 판정하는 파트 - 시작
	printf("첫 번째 날짜를 년, 월, 일 순서로 입력해 주세요. : ");
	scanf("%d %d %d", &year1, &month1, &day1);

	// 연도의 유효값 및 윤년에 대한 판정 - 1
	if (year1 >= 0) {
		yoon = t_yoon(year1);
	}
	else {
		printf("첫번째 날짜의 연도에 대한 값이 유효하지 않습니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
		return 0;
	}
	if (month1 < 1 || month1>12) {
		printf("첫번째 날짜의 월 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
		return 0;
	}
	if (month1 == 4 || month1 == 6 || month1 ==  9 || month1 == 11) {
		t_day1 = 30;
		if (day1<0 || day1>t_day1) {
			printf("첫번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
	}
	else if (month1 == 1 || month1 ==  3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12) {
		t_day1 = 31;
		if (day1<0 || day1>t_day1) {
			printf("첫번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
	}
	else if (month1 == 2) {
		if (yoon == 1) {
			t_day1 = 29;
			if (day1 < 0 || day1>t_day1) {
				printf("첫번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
		else if (yoon == 0) {
			t_day1 = 28;
			if (day1 < 0 || day1>t_day1) {
				printf("첫번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
	}
	printf("두 번째 날짜를 년, 월, 일 순서로 입력해 주세요. : ");
	scanf("%d %d %d", &year2, &month2, &day2);

	//연도의 유효성 및 윤년에 대한 판정 - 2
	if (year2 >= 0) {
		yoon = t_yoon(year2);
	}
	else {
		printf("두번째 날짜의 연도에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
	}
	if (month2 < 1 || month2>12) {
		printf("두번째 날짜의 월 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
		return 0;
	}
	if (month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11) {
		t_day2 = 30;
		if (day2<0 || day2>t_day1) {
			printf("두번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
	}
	else if (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12) {
		t_day2 = 31;
		if (day2<0 || day2>t_day2) {
			printf("두번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
	}
	else if (month2 == 2) {
		if (yoon == 1) {
			t_day2 = 29;
			if (day2 < 0 || day2>29) {
				printf("두번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
		else if (yoon == 0) {
			t_day2 = 28;
			if (day2 < 0 || day2>28) {
				printf("두번째 날짜의 일 수에 대한 값이 유효한 값이 아닙니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
	}
	// 사용자로부터 값을 입력받고 그 값을 유효함을 판정하는 파트 - 끝

	//두 날짜 사이의 차이를 일단위로 계산하는 연산파트 - 시작

	//연도와 관련된 연산파트
	for (i = 0; i < year1; i++) 
	{ 
		yoon = t_yoon(i);
		if (yoon == 1) {
			total_day1 = total_day1 + 366;
		}
		else if (yoon == 0) {
			total_day1 = total_day1 + 365;
		}
	}
	for (j = 1; j < month1; j++)
	{
		if (j == 1|| j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
			total_day1 = total_day1 + 31;
		}
		else if (j == 4 || j == 6 || j == 9 || j == 11) {
			total_day1 = total_day1 + 30;
		}
		else if (j == 2) {
			yoon = t_yoon(year1);
			if (yoon == 1) {
				total_day1 = total_day1 + 29;
			}
			else if (yoon == 0) {
				total_day1 = total_day1 + 28;
			}
		}
	}
	total_day1 = total_day1 + day1;

	for (i = 0; i < year2; i++)
	{
		yoon = t_yoon(i);
		if (yoon == 1) {
			total_day2 = total_day2 + 366;
		}
		else if (yoon == 0) {
			total_day2 = total_day2 + 365;
		}
	}
	for (j = 1; j < month2; j++)
	{
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12) {
			total_day2 = total_day2 + 31;
		}
		else if (j == 4 || j == 6 || j == 9 || j == 11) {
			total_day2 = total_day2 + 30;
		}
		else if (j == 2) {
			yoon = t_yoon(year2);
			if (yoon == 1) {
				total_day2 = total_day2 + 29;
			}
			else if (yoon == 0) {
				total_day2 = total_day2 + 28;
			}
		}
	}
	total_day2 = total_day2 + day2;

	if (total_day1 > total_day2) {
		total_day = total_day1 - total_day2+1;
	}
	else if (total_day1 < total_day2) {
		total_day = total_day2 - total_day1+1;
	}
	else {
		printf("입력된 두 날짜는 서로 같은 값입니다. \n");
		return 0;
	}
	printf("입력된 두 날짜의 차는 총 %d일 입니다. \n", total_day);
	return 0;
	}
	// 두 날짜 사이의 차이를 일단위로 계산하는 연산파트 - 끝

	// t_yoon 함수에 대한 정의부
	int t_yoon(int x) {
		if (x % 400 == 0) {
			yoon = 1;
		}
		else if (x % 100 == 0) {
			yoon = 0;
		}
		else if (x % 4 == 0) {
			yoon = 1;
		}
		else {
			yoon = 0;
		}
		return yoon;
	}