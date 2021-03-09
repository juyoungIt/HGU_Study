#include <stdio.h>

main() {
	int width, height;

	printf("사각형의 가로의 길이를 입력해 주세요. : ");
	scanf("%d", &width);
	printf("사각형의 세로의 길이를 입력해 주세요. : ");
	scanf("%d", &height);

	if (width == height) {
		printf("사용자가 입력한 사각형은 정사각형에 해당합니다. \n");
	}
	else if (width >= height * 2) {
		printf("사용자가 입력한 사각형은 좌우로 길쭉한 사각형에 해당합니다. \n");
	}
	else if (width * 2 <= height) {
		printf("사용자가 입력한 사각형은 위아래로 길쭉한 사각형에 해당합니다. \n");
	}
	else if (width > height) {
		printf("사용자가 입력한 사각형은 일반적인 가로형 직사각형 입니다. \n");
	}
	else if (width < height) {
		printf("사용자가 입력한 사각형은 일반적인 세로형 직사각형 입니다. \n");
	}
	return 0;
}