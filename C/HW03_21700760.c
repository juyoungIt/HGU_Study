#include <stdio.h>

main() {
	int num; // 사용자로부터 입력받은 정수를 저장할 변수 선언
	int x; // 소수로 판정된 값들을 저장할 변수 선언
	int y; // 약수에 대한 값을 저장할 변수 선언

	printf("사용자가 입력하고자 하는 수 중에서 2보다 큰 양의 정수 한 개를 입력해 주세요. : ");
	scanf("%d", &num);

	for (x = 2 ; x <= num ; x++) {
		for (y = 2 ; y <= x ; y++) {
			if (x%y == 0) {
				if (y != x) {
					break;
				}
				else {
					printf("사용자가 입력한 범위 내에서 다음 수 %d 는 소수로 판정 되었습니다. \n", x);
					break;
				}
			}
		}
	}
	return 0;
}