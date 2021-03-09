// E02 - 입력한 숫자 크기의 높이를 갖는 우직각 삼각형 출력하기

#include <stdio.h>

main() {
	int blank, height; // 사용자가 입력한 여백과 높이에 대한 값을 저장할 변수선언
	int i, j, k; // 반복문을 사용하기 위한 변수선언

	printf("출력할 우직각 삼각형의 높이 값을 입력해 주세요. : ");
	scanf("%d", &height);
	printf("사용할 여백의 크기를 입력해 주세요. (단, 여백은 우직각 삼각형의 좌측에 배치됩니다.) : ");
	scanf("%d", &blank);

	for (i = 1; i <= height; i++) {
		for (j = 1; j <= blank + height - i; j++) {
			printf(" ");
		}
		for (k = 1; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
