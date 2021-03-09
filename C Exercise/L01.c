#include <stdio.h>

int fibonacci(int x); // 함수 fibonacci의 선언

main()
{
	int fibo; // 결과값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	printf("1부터 20까지의 피보나치 수열은 다음과 같습니다. \n");
	for (i = 0; i < 20; i++)
	{
		fibo = fibonacci(i);
		printf("%d번째 : %d\n", i + 1, fibo);
	}
	return 0;
}

// 함수 fibonacci의 정의부
int fibonacci(int x)
{
	if (x == 0)
		return 1;
	else if (x == 1)
		return 1;
	else
		return fibonacci(x - 2) + fibonacci(x - 1);
}