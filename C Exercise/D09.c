// D09 - 원하는 구구단의 단 출력하기

#include <stdio.h>

main() {
	int dan; // 사용자에게 입력 받은 단 수에 대한 값을 저장하는 변수선언
	int i = 1; // 단에 곱하는 수에 대한 값을 저장하는 변수 선언 및 초기화
	
	while (1) {
		printf("사용자가 출력하기 원하는 단을 입력해 주세요. : ");
		scanf("%d", &dan);
		if (dan < 2 || dan > 9) {
			printf("프로그램에서 지원하는 값이 아닙니다. 입력값을 확인 후 다시 입력해 주세요. \n");
			continue;
		}
		while (1) {
			printf("%d X %d = %d \n", dan, i, dan*i);
			i++;
			if (i > 9) {
				break;
			}
		}
		if (i > 9) {
			break;
		}
	}
	return 0;
}