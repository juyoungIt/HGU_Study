#include <stdio.h>

main() {
	int month, day; // 월과 일에 대한 값을 저장할 변수 선언
	int day_count; // 변환된 일수의 값을 저장할 변수 선언

	printf("사용자가 지정한 날의 월 수를 입력해 주세요. : ");
	scanf("%d", &month); // 사용자로부터 입력받은 월에 대한 정보를 month라는 변수에 저장
	if (month < 0 || month >12) {
		printf("입력하신 월에 대한 값이 유효하지 않습니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
		return 0;
	}
	printf("사용자가 지정한 날의 일 수를 입력해 주세요. : ");
	scanf("%d", &day); // 사용자로부터 입력받은 일에 대한 정보를 day라는 변수에 저장

	if (month == 1) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 0 * 31 + 0 * 30 + 0 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 1월은 첫번째 달이므로 1월의 경우에는 입력된 일수가 곧 day_count 값이 됨.
	else if (month == 2) {
		if (day > 28) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력한신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 1 * 31 + 0 * 30 + 0 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 2월의 전에는 1월이 있었으므로 31에 day값을 더하여 day_count 값을 구함.
	else if (month == 3) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 1 * 31 + 0 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 3월 전에는 1월과 2월이 있었으므로 31과 28, 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 4) {
		if (day > 30) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 2 * 31 + 0 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 4월 전에는 1,2,3월이 있었으므로 31*2와 28, 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 5) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 2 * 31 + 1 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 5월 전에는 1,2,3,4월이 있었으므로 31*2와 30, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 6) {
		if (day > 30) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 3 * 31 + 1 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 6월 전에는 1,2,3,4,5월이 있었으므로 31*3과 30,28, 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 7) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 3 * 31 + 2 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 7월 전에는 1,2,3,4,5,6월이 있었으므로 31*3과 30*2, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 8) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 4 * 31 + 2 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 8월 전에는 1,2,3,4,5,6,7월이 있었으므로 31*4와 30*2, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 9) {
		if (day > 30) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 5 * 31 + 2 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 9월 전에는 1,2,3,4,5,6,7,8월이 있었으므로 31*5와 30*2, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 10) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 5 * 31 + 3 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 10월 전에는 1,2,3,4,5,6,7,8,9월이 있었으므로 31*5와 30*3, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 11) {
		if (day > 30) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 6 * 31 + 3 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 11월 전에는 1,2,3,4,5,6,7,8,9,10월이 있었으므로 31*6과 30*3, 28 그리고 day 값을 더하여 day_count 값을 구함.
	else if (month == 12) {
		if (day > 31) {
			printf("입력하신 일 값은 유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
			return 0;
		}
		day_count = 6 * 31 + 4 * 30 + 1 * 28 + day;
		printf("사용자가 지정한 날짜는 1년 중 %d 째 날에 해당합니다. \n", day_count);
	} // 12월 전에는 1,2,3,4,5,6,7,8,9,10,11월이 있었으므로 31*6과 30*4, 28 그리고 day 값을 더하여 day_count 값을 구함.
	return 0;
}