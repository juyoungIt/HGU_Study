#include <stdio.h>

main() {
	int income;
	int tax;

	printf("사용자의 연봉을 원단위로 입력해 주세요. : ");
	scanf("%d", &income);

	if (income < 10000000) {
		tax = income * 0.095;
		printf("사용자의 연봉에 대한 소득세는 %d원 입니다. \n", tax);
	}
	else if (income >= 10000000 && income < 40000000) {
		tax = income * 0.19;
		printf("사용자의 연봉에 대한 소득세는 %d원 입니다. \n", tax);
	}
	else if (income >= 40000000 && income < 80000000) {
		tax = income * 0.28;
		printf("사용자의 연봉에 대한 소득세는 %d원 입니다. \n", tax);
	}
	else if (income >= 80000000) {
		tax = income * 0.37;
		printf("사용자의 연봉에 대한 소득세는 %d원 입니다. \n", tax);
	}
	else {
		printf("유효하지 않은 값 입니다. 입력하신 값을 다시한 번 확인해보시고 다시 입력해 주세요. \n");
	}
	return 0;
}