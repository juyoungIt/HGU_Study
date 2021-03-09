// D07 - 1차 함수의 좌표 구하기

#include <stdio.h>

main() {
	int a, b; // 1차함수의 계수에 대한 값을 저장하는 변수 선언
	int x_begin, x_end; // x좌표의 시작과 끝에 대한 값을 저장하는 변수 선언
	int x, y; // x좌표와 y좌표에 대한 값을 저장할 변수 선언
	int i; // 반복문에 사용할 변수 선언
	int count = 0;

	printf("일차함수 y= ax+b 에서 a의 계수를 입력해 주세요. : ");
	scanf("%d", &a);
	printf("일차함수 y = ax+b 에서 b의 계수를 입력해 주세요. : ");
	scanf("%d", &b);

	printf("x좌표의 시작 값을 입력해 주세요. : ");
	scanf("%d", &x_begin);
	printf("x좌표의 끝 값을 입력해 주세요. : ");
	scanf("%d", &x_end);

	for (i = x_begin; i <= x_end; i++) {
		x = i;
		y = a*x + b;

		printf("좌표 (%d, %d) \n", x, y);
		count++;
	}
	return 0;
}