#include <stdio.h>

int power(n, a); // 함수 power의 선언

main()
{
	int num1, num2; // 사용자로부터 입력받은 수를 저장할 2개의 변수선언
	int result; // 결과값을 저장할 변수선언

	printf("숫자 2개를 입력하세요. : ");
	scanf("%d %d", &num1, &num2);
	result = power(num1, num2);
	printf("%d의 %d 승은 %d 입니다. \n", num1, num2, result);
	return 0;
}

// 함수 power의 정의부
int power(int n, int a)
{
	if (a == 0)
		return 1;
	else if (a == 1)
		return n;
	else if (a > 1 && a % 2 == 0)
		return power(n, a / 2)*power(n, a / 2);
	else if (a > 1 && a % 2 == 1)
		return power(n, a / 2)*power(n, a / 2)*n;
}