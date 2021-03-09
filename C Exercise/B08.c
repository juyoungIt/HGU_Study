#include <stdio.h>

main() {
	int num1, num2, num3;

	printf("첫번째 숫자를 입력해주세요. : ");
	scanf("%d", &num1);
	printf("두번째 숫자를 입력해주세요. : ");
	scanf("%d", &num2);
	printf("세번째 숫자를 입력해주세요. : ");
	scanf("%d", &num3);

	if (num1 != num2 && num2 != num3 && num1 != num3) {
	}
	else {
		printf("1번 조건 만족 : 3개의 숫자중 적어도 두 수의 값이 같다. \n");
	}
	if ((num1 <= 50 && num2 <= 50 && num3 <= 50) || (num1 > 50 && num2 <= 50 && num3 <= 50) || (num1 <= 50 && num2 > 50 && num3 <= 50) || (num1 <= 50 && num2 <= 50 && num3 > 50)){
	}
	else {
		printf("2번 조건 만족 : 3개의 숫자중 적어도 두 수의 크기가 50보다 크다. \n");
	}
	if (num1+num2 == num3 || num2+num3 == num1 || num3 + num1 == num2) {
		printf("3번 조건 만족 : 3개의 숫자중 어느 두 수의 합이 나머지 하나의 숫자와 같다. \n");
	}
	if ((num2%num1 == 0 && num3%num1 == 0) || (num1%num2 == 0 && num3%num2 == 0) || (num1%num3 == 0 && num2%num3 == 0)) {
		printf("4번 조건 만족 : 3개의 숫자중 어느 하나의 수로 다른 두 수를 나누면 나누어 떨어지는 경우가 있다. \n");
	}
	return 0;
}