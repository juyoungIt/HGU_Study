//E03 - 입력한 숫자 크기의 높이를 갖는 이등변 삼각형 출력하기

#include <stdio.h>

main() {
	int height; // 사용자로부터 입력받은 높이에 대한 값을 저장할 변수 선언
	int i, j, k,l; // 반복문을 사용하기 위한 변수 선언

	printf("출력할 이등변 삼각형의 높이 값을 입력해 주세요. : ");
	scanf("%d", &height);

	for (i = 1; i <= height; i++) {
		for (j = 1; j <= 2*height - 1; j++) {
			if ((j>=height+1-i)&&(j<=height+i-1)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}