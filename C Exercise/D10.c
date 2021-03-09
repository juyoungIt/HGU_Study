// D10 - 두 수의 배타적 배수 출력하기

#include <stdio.h>

main() {
	int num1, num2; // 사용자로부터 입력 받은 두 정수의 값을 저장할 변수선언
	int i; // 반복문에 사용할 변수선언

	printf("0보다 큰 두 정수 중에서 첫번째 정수를 입력해 주세요. : ");
	scanf("%d", &num1);
	printf("0보다 큰 두 정수 중에서 두번째 정수를 입력해 주세요. : ");
	scanf("%d", &num2);

	for (i = 1; i <= 100; i++) {
		if ((i%num1 == 0 && i%num2 != 0) || (i%num1 != 0 && i%num2 == 0)) {
			printf("%d", i);
			if (i == 100) {
				printf("\n");
				break;
			}
			printf(", ");
		}
		else if (i == 100) {
			printf("\n");
		}
	}
	return 0;
}