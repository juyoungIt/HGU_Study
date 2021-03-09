//E06 - 2차원 숫자 출력하기

#include <stdio.h>

main() {
	int rows, columns; // 행과 열에 대한 값을 저장할 변수선언
	int i, j; // 반복문을 사용하기 위한 변수선언

	printf("출력하려는 행렬에서 행의 개수를 입력해주세요. : ");
	scanf("%d", &rows);
	printf("출력하려는 행렬에서 열의 개수를 입력해주세요. : ");
	scanf("%d", &columns);

	for (i = 1; i <= rows; i++) {
		for (j = 1; j <= columns; j++) {
			printf(" %d\t", i*j);
		}
		printf("\n");
	}
	return 0;
}