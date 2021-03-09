#include <stdio.h>

int Ackermann(int i, int j); // 함수 Ackermann의 선언

main()
{
	int result; // 결과값을 저장할 변수선언
	int i, j; // 반복문 사용을 위한 변수선언

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			result = Ackermann(i, j); // 함수 Ackermann의 호출
			printf("Ackermann(%d, %d) = %d\n", i, j, result);
		}
	}
}

// 함수 Ackermann의 정의부
int Ackermann(int i, int j)
{
	if (i == 0 && j >= 0)
		return j + 1;
	else if (i > 0 && j == 0)
		return Ackermann(i - 1, 1);
	else if (i > 0 && j > 0)
		return Ackermann(i - 1, Ackermann(i, j - 1));
}