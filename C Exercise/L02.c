#include <stdio.h>

int poweroftwo(int n); // 함수 poweroftwo의 선언

main()
{
	int number; // 사용자가 입력한 수의 값을 저장하는 변수선언
	int result; // 결과값을 저장하는 변수선언

	while (1)
	{
		printf("숫자를 입력해 주세요. (0. 종료) : ");
		scanf("%d", &number);
		if (number == 0)
			break;

		result = poweroftwo(number); // 함수 poweroftwo의 호출
		printf("%d의 %d승의 값은 %d 입니다. \n", 2, number, result);
	}
	return 0;
}

// 함수 poweroftwo의 정의부
int poweroftwo(int n)
{
	if (n == 0)
		return 1;
	else
		return 2 * poweroftwo(n - 1);
}