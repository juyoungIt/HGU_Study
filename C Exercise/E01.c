// E01 - 입력한 숫자 크기의 정사각형 출력하기

#include <stdio.h>

main() { 
	int length; // 사용자로부터 입력받은 정사각형의 한 변의 길이 값을 저장할 변수선언
	int x, y; // 반복분에 사용하기 위한 변수선언

	printf("정사각형의 한 변의 길이 값을 입력해 주세요. : ");
	scanf("%d", &length);

	for (x = 1; x <= length; x++) {
		if (x > 1) {
			printf("\n");
		}
		for (y = 1; y <= length; y++) {
			printf("# ");
		}
	}
	printf("\n");
	return 0;
}