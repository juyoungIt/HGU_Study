//D05 - 직사각형 형태 개수 세기

#include <stdio.h>

main() {
	int width, height; // 사용자가 입력한 사각형의 가로와 세로길이의 값을 저장할 변수선언
	int count1 = 0; // 정사각형의 개수에 대한 값을 저장할 변수 선언 및 초기화
	int count2 = 0; // 좌우로 길쭉한 사각형의 개수에 대한 값을 저장할 변수선언 및 초기화
	int count3 = 0; // 위아래로 길쭉한 사각형의 개수에 대한 값을 저장할 변수선언 및 초기화
	int count4 = 0; // 일반적인 가로형 직사각형의 개수에 대한 값을 저장할 변수선언 및 초기화
	int count5 = 0; // 일반적인 세로형 직사각형의 개수에 대한 값을 저장할 변수선언 및 초기화

	do {
		printf("사용자가 생각하고 있는 사각형을 가로의 길이와 세로의 길이 순서로 입력해 주세요. : ");
		scanf("%d %d", &width, &height);

		//정사각형 case
		if ((width == height)&&(width > 0 && height > 0)) {
			count1++;
		}
		else if ((width > 2 * height)&& (width > 0 && height > 0)) {
			count2++;
		}
		else if ((2 * width < height)&&(width > 0 && height > 0)) {
			count3++;
		}
		else if ((width > height)&&(width > 0 && height > 0)) {
			count4++;
		}
		else if ((width < height)&&(width > 0 && height > 0)) {
			count5++;
		}
	} while (width > 0 && height > 0);


	printf("정사각형의 개수는 %d개 입니다. \n", count1);
	printf("좌우로 길쭉한 직사각형의 개수는 %d개 입니다 \n", count2);
	printf("위아래로 길쭉한 직사각형의 개수는 %d개 입니다. \n", count3);
	printf("일반적인 가로형 직사각형의 개수는 %d개 입니다. \n", count4);
	printf("일반적인 세로형 직사각형의 개수는 %d개 입니다. \n", count5);
	return 0;
}