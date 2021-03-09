//E05 - 홀수단 또는 짝수단의 구구단을 열의 개수를 맞추어 출력하기

#include <stdio.h>

main() {
	int mode; // 출력모드에 대한 값을 저장할 변수선언
	int column; // 열 개수
	int i, j; //반복문을 사용하기 위한 변수선언

	printf("구구단의 출력모드 (1: 홀수단, 2: 짝수단)를 입력해세요. : ");
	scanf("%d", &mode);
	printf("한 줄에 출력할 개수를 입력해 주세요. : ");
	scanf("%d", &column);

	if (mode == 1) {
		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++) {
				if (i % 2 != 0) {
					printf("%d X %d = %d\t", i, j, i*j);
					if (j % column == 0) {
						printf("\n");
					}
				}
			}
			printf("\n");
		}
	}
	else if (mode == 2) {
		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++) {
				if (i % 2 == 0) {
					printf("%d X %d = %d\t", i, j, i*j);
					if (j % column == 0) {
						printf("\n");
					}
				}
			}
			printf("\n");
		}
	}
}