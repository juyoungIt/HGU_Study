#include <stdio.h>

main()
{
	int size;
	int space;
	int i, j, k;

	printf("도형의 크기(홀수)와 여백을 입력하시오. : ");
	scanf("%d %d", &size, &space);

	
	
	for (i = 1; i <= size; i++) {
		for (k = 1; k <=space; k++) {
			printf(" ");
		}
		for (j = 1; j <= 2 * size - 1; j++) {
			if ((j == size + 1 - i) || (j == size + i - 1)) {
				printf("*");
			}
			else if (i == size) {
					if ((j >= size + 1 - i) && (j <= size + i - 1)) {
						printf("*");
					}
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}