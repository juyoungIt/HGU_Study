#include <stdio.h>

main() {
	int year;

	printf("사용자가 판정 받고자 하는 연도를 입력해 주세요. : ");
	scanf("%d", &year);

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				printf("사용자가 입력한 연도는 윤년에 해당합니다. \n");
			}
			else {
				printf("사용자가 입력한 연도는 윤년에 해당하지 않습니다. \n");
			}
		}
		else {
			printf("사용자가 입력한 연도는 윤년에 해당합니다. \n");
		}
	}
	else {
		printf("사용자가 입력한 연도는 윤년에 해당하지 않습니다. \n");
	}
	return 0;
}