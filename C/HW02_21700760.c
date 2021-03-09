#include <stdio.h>

main() {
	int num1, num2; // 사용자로부터 입력받은 두 개의 변수를 저장하는 변수선언
	int GCD = 1; // 최대공약수의 값을 저장할 변수 선언
	int x; // 최대공약수를 구하는 과정에서 필요한 변수 선언

	printf("사용자가 원하는 정수 2개를 입력해 주세요. : ");
	scanf("%d %d", &num1, &num2);

	// 최대공약수를 구하는 방법을 구현

	if (num1 > num2) {
		for (x = 1; num2%x != num2; x++) {
			if (num1%x == 0 && num2%x == 0) {
				GCD = GCD*x;
				num1 = num1 / x;
				num2 = num2 / x;
				x = 1;  // 처음부터 다시 공통인수를 찾기 위해서 x = 1로 초기화 하여 반복작업 수행
			}
		}
	}
	else if (num1 < num2) {
		for (x = 1; num1%x != num1; x++) {
			if (num1%x == 0 && num2%x == 0) {
				GCD = GCD*x;
				num1 = num1 / x;
				num2 = num2 / x;
				x = 1; // 처음부터 다시 공통인수를 찾기 위해서 x = 1로 초기화 하여 반복작업 수행
			}
		}
	}
	else {
		GCD = num1; // 두 수가 같을 경우
	}
	printf("사용자가 입력한 두 정수의 최대 공약수는 %d 입니다. \n", GCD);
	return 0;
}