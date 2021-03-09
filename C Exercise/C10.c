#include <stdio.h>

main() {
	int num1, num2;
	char operator;
	int result1, result2;

	printf("연산에 사용할 두 개의 정수를 입력해 주세요. : ");
	scanf("%d %d", &num1, &num2);
	printf("입력하신 두 정수로 어떤 연산을 할 것인지 산술연산자를 선택해 주세요. \n ex. + , -, *, /  : ");
	scanf("\n%c", &operator);

	if (operator == '+') {
		result1 = num1 + num2;
		printf("입력받은 산술연산자를 바탕으로 연산한 결과는 %d 입니다. \n", result1);
	}
	else if (operator == '-') {
		result1 = num1 - num2;
		printf("입력받은 산술연산자를 바탕으로 연산한 결과는 %d 입니다. \n", result1);
	}
	else if (operator == '*') {
		result1 = num1 * num2;
		printf("입력받은 산술연산자를 바탕으로 연산한 결과는 %d 입니다. \n", result1);
	}
	else if (operator == '/') {
		result1 = num1 / num2;
		result2 = num1%num2;
		printf("입력받은 산술연산자를 바탕으로 연산한 결과 몫은 %d 이고, \n나머지는 %d 입니다. \n", result1, result2);
	}
	else {
		printf("입력해주신 기호는 해당 프로그램에서 정의하는 산술연산자의 범주에 포함되지 않습니다. \n 값을 재입력 해주세요. \n");
	}
	return 0;
}