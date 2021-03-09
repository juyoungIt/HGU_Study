#include <stdio.h>

main() {
	int width, height;
	int area;

	printf("직사각형의 가로의 길이를 입력해 주세요 : ");
	scanf("%d", &width);
	printf("정사각형의 세로의 길이를 입력해 주세요 : ");
	scanf("%d", &height);

	area = width * height;

	printf("정사각형의 넓이는 %d 이고, \n", area);

	if (width == height) {
		printf("사용자가 넓이를 구한 직사각형은 정사각형에 해당합니다. \n");
	}
	else if (width != height) {
		printf("사용자가 넓이를 구한 직사각형은 정사각형에 해당하지 않습니다. \n");
	}
	return 0;
}