//E04 - 홀수단 또는 짝수단의 구구단 출력하기

#include <stdio.h>

main() {
	int mode; // 사용자가 입력한 단에 대한 값을 저장할 변수선언
	int i, j; // 반복문을 사용하기 위한 변수선언

	printf("구구단의 출력모드 (1: 홀수단, 2: 짝수단)를 입력해세요. : ");
	scanf("%d", &mode);

	if (mode == 1) {
		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++) {
				if (i % 2 != 0) {
					printf("%d X %d = %d\t", i, j, i*j);
					if (j % 3 == 0) {
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
					if (j % 3 == 0) {
						printf("\n");
					}
				}
			}
			printf("\n");
		}
	}
}