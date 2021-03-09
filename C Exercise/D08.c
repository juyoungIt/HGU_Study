// D08 - 2차 함수의 좌표 구하기

#include <stdio.h>

main() {
	int a, b, c; // 사용자가 입력한 계수에 대한 값을 저장할 변수선언
	int x_begin, x_end; // 사용자가 입력한 x좌표의 시작과 끝 값을 저장할 변수선언
	int x, y; // 2차함수의 위의 좌표에 해당하는 값을 저장할 변수 선언
	int i; // 반복문에 사용하기 위한 변수선언

	printf("이차함수 y = ax^2+bx+c 의 계수 a 값을 입력해 주세요. : ");
	scanf("%d", &a);
	printf("이차함수 y = ax^2+bx+c 의 계수 b 값을 입력해 주세요. : ");
	scanf("%d", &b);
	printf("이차함수 y = ax^2+bx+c 의 계수 c 값을 입력해 주세요. : ");
	scanf("%d", &c);

	printf("x좌표의 시작 값을 입력해 주세요. : ");
	scanf("%d", &x_begin);
	printf("x좌표의 끝 값을 입력해 주세요. : ");
	scanf("%d", &x_end);

	for (i = x_begin; i <= x_end; i++) {
		x = i;
		y = a*x*x + b*x + c;
		printf("좌표 (%d, %d) \n", x, y);
	}
	return 0;
}